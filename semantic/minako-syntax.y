%debug

%code requires {
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>
	#include <assert.h>
	#include "symtab.h"
	#include "syntree.h"

	extern void yyerror(const char*, ...);
	extern int yylex(void);
	extern int yylineno;
	extern FILE* yyin;
	extern int yydebug;
	/* main function error */
	#define	NO_MAIN_FUNCTION_ERROR 						"The main function is not defined."
	#define MAIN_ISNOT_FUNCTION_ERROR					"Symbol 'main' is not a function."
	#define	PARAM_IN_MAIN_ERROR		 					"No parameter is allowed in the main function."
	/* Printf error. */
	#define INCOMPATIBLE_PRINTF_ASSIGN_ERROR			"The '%s' assignment is not printable in printf."
	#define NOTHING_PRINTABLE_ERROR						"printf requires printable assignment or const string."
	/* Type error. */
	#define INCOMPATIBLE_ASSIGNMENT_ERROR				"Incompatible type for the assignment of '%s', expected '%s', have '%s'."
	#define NOT_BOOLEAN_ERROR							"The type of the condition in '%s' is not 'Boolean', have '%s'."
	/* Function definition error */
	#define	RETURN_TYPE_ERROR 							"The return type of '%s' is not '%s'."
	#define VOID_PARAMETER_ERROR						"Parameter '%s' in '%s' cannot be void."
	#define ASSGIN_TO_FUNCTION_ERROR					"Assign to function '%s' is not allowed."
	#define INCOMPATIBLE_RETURN_ERROR					"Incompatible type for return in function '%s', expected '%s', have '%s'."
	/* Function call error */
	#define INCOMPATIBLE_ARGUMENT_ERROR					"Incompatible type of argument '%s' in call to function '%s', expected '%s', have '%s'."
	#define TOO_FEW_ARGUMENTS_ERROR						"Too few arguments in call to function '%s', expected %d, have %d."
	#define TOO_MANY_ARGUMENTS_ERROR					"Too many arguments int call to function '%s', expected %d, have %d."
	#define CALL_VARIABLE_AS_FUNCTION_ERROR				"Variable '%s' cannot be called as a function."
	#define READ_FUNCTION_AS_VARIABLE_ERROR				"Function '%s' cannot be read as a variable."
	/* Operator or operand error. */
	#define INVALID_VOID_FOR_OPERATOR_ERROR				"Void is invalid for operator '%s' in function '%s'."
	#define INCOMPATIBLE_OPERAND_ERROR					"Operator '%s' doesn't support operation between left: '%s' and right: '%s'."
	#define INVALID_OPERATOR_ERROR						"Invalid operator '%s' for the type '%s'."
	/* Double declaration error. */
	#define DOUBLE_FUNCTION_DECLARATION_ERROR			"Double declaration of function: '%s'."
	#define DOUBLE_PARAMETER_DECLARATION_ERROR			"Double declaration of parameter '%s' in the definition of function '%s'."
	#define DOUBLE_LOCAL_VARIABLE_DECLARATION_ERROR		"Double declaration of variable '%s' in function '%s'."
	#define DOUBLE_GLOBAL_VARIABLE_DECLARATION_ERROR	"Double declaration of global variable '%s'."
	/* Reference before declaration error. */
	#define UNKNOWN_FUNCTION_ERROR						"Unknown function: '%s'."
	#define UNKNOWN_VARIABLE_ERROR						"Unknown variable: '%s'."
	#define UNKNOWN_OPERATOR_ERROR						"Unknown operator (internal error)."
	/* No return error. */
	#define NO_RETURN_ERROR								"No value is return in function '%s', expected '%s'."
}

%code provides {
	extern symtab_t* tab;
	extern syntree_t* ast;
}

%code {
	/* globale Zeiger auf Symboltabelle und abstrakten Syntaxbaum */
	symtab_t* tab;
	syntree_t* ast;

	/* interner (globaler) Zeiger auf die aktuell geparste Funktion */
	static symtab_symbol_t* func;

	/**@brief Kombiniert zwei Ausdrücke einer binären Operation und stellt
	 * sicher, dass sie auf deren Typen definiert ist.
	 * @param id1  linke Seite
	 * @param id2  rechte Seite
	 * @param op   Operator
	 * @return ID des Operatorknoten
	 */
	static syntree_nid
	combine(syntree_nid id1, syntree_nid id2, syntree_node_tag op);

	/* Hilfsfunktionen */

	/**@brief Gibt den Zeiger auf einen Knoten der entsprechenden ID zurück.
	 */
	static inline syntree_node_t*
	nodePtr(syntree_nid id) { return syntreeNodePtr(ast, id); }

	/**@brief Gibt den Knotentyp zurück.
	 */
	static inline syntree_node_type
	nodeType(syntree_nid id) { return nodePtr(id)->type; }

	/**@brief Gibt den Wert eines Knotens zurück.
	 */
	static inline union syntree_node_value_u*
	nodeValue(syntree_nid id) { return &nodePtr(id)->value; }

	/**@brief Gibt den ersten Kindknoten eines Containers zurück.
	 */
	static inline syntree_nid
	nodeFirst(syntree_nid id) { return nodePtr(id)->value.container.first; }

	/**@brief Gibt den Folgeknoten eines Knotens zurück.
	 */
	static inline syntree_nid
	nodeNext(syntree_nid id) { return nodePtr(id)->next; }

	// Prepend a node to the list
	/* static inline syntree_nid		// already use rightmost derivation to make the right order of parameter.
	syntreeNodePrepend(syntree_t* self, syntree_nid elemId, syntree_nid listId)
	{
		syntree_node_t* list = syntreeNodePtr(self, listId);

		// ignoriere leere Knoten
		if (elemId == 0)
			return listId;

		// teste, ob das Element das erste der Liste ist
		if (list->value.container.first)
		{
			syntreeNodePtr(self, elemId)->next = list->value.container.first;
			list->value.container.first = elemId;
		}
		else
		{
			list->value.container.first = list->value.container.last = elemId;
		}

		return listId;
	} */

	/* Return the string of the operator. */
	static inline char*
	operatorName(syntree_node_tag op)
	{
		switch(op)
		{
			case SYNTREE_TAG_Plus: return "+";
			case SYNTREE_TAG_Minus: return "-";
			case SYNTREE_TAG_Times: return "*";
			case SYNTREE_TAG_Divide: return "/";
			case SYNTREE_TAG_LogOr: return "||";
			case SYNTREE_TAG_LogAnd: return "&&";
			case SYNTREE_TAG_Uminus: return "-";
			case SYNTREE_TAG_Eqt: return "==";
			case SYNTREE_TAG_Neq: return "!=";
			case SYNTREE_TAG_Leq: return "<=";
			case SYNTREE_TAG_Geq: return ">=";
			case SYNTREE_TAG_Lst: return "<";
			case SYNTREE_TAG_Grt: return ">";
			default: return "";
		}
	}

	/* Return the number of the parameters. */
	static inline int
	parameterCount(symtab_symbol_t* param)
	{
		int count = 0;
		while(param != NULL) {
			count++;
			param = symtabParamNext(param);
		}
		return count;
	}

	/* Return the number of the arguments. */
	static inline int
	argumentCount(syntree_nid argumentList)
	{
		int count = 0;
		while(argumentList != 0) {
			count++;
			argumentList = nodeNext(argumentList);
		}
		return count;
	}

	static inline void
	checkConditionType(syntree_nid cond, char *statementName)
	{
		if (nodeType(cond) != SYNTREE_TYPE_Boolean) {
			yyerror(NOT_BOOLEAN_ERROR, statementName, nodeTypeName[nodeType(cond)]);
		}
	}

	static inline int
	isTypeMatchedOrConvertable(syntree_node_type ltype, syntree_node_type rtype)
	{
		return ((ltype == rtype) || (ltype == SYNTREE_TYPE_Float && rtype == SYNTREE_TYPE_Integer));
	}

	static inline int
	isTypeMatched(syntree_node_type ltype, syntree_node_type rtype)
	{
		return (ltype == rtype);
	}
}

%union {
	char* string;
	double floatValue;
	int intValue;

	symtab_symbol_t* symbol;
	syntree_nid node;
	syntree_node_type type;
}

%printer { fprintf(yyoutput, "\"%s\"", $$); } <string>
%printer { fprintf(yyoutput, "%g", $$); } <floatValue>
%printer { fprintf(yyoutput, "%i", $$); } <intValue>
%printer {
	if ($$ != 0)
	{
		putc('\n', yyoutput);
		syntreePrint(ast, $$, yyoutput, 1);
	}
} <node>
%printer {
	putc('\n', yyoutput);
	symtabPrint(tab, yyoutput);
} declassignment functiondefinition

%destructor { free($$); } <string>

/* used tokens (KW is abbreviation for keyword) */
%token AND
%token OR
%token EQ
%token NEQ
%token LEQ
%token GEQ
%token LSS
%token GRT
%token KW_BOOLEAN
%token KW_DO
%token KW_ELSE
%token KW_FLOAT
%token KW_FOR
%token KW_IF
%token KW_INT
%token KW_PRINTF
%token KW_RETURN
%token KW_VOID
%token KW_WHILE
%token <intValue>   CONST_INT
%token <floatValue> CONST_FLOAT
%token <intValue>   CONST_BOOLEAN
%token <string>     CONST_STRING
%token <string>     ID

/* definition of association and precedence of operators */
%left '+' '-' OR
%left '*' '/' AND
%nonassoc UMINUS

/* workaround for handling dangling else */
/* LOWER_THAN_ELSE stands for a not existing else */
%nonassoc LOWER_THAN_ELSE
%nonassoc KW_ELSE

%type <node> program declassignment
%type <node> opt_argumentlist argumentlist
%type <node> statementlist statement block
%type <node> ifstatement forstatement dowhilestatement whilestatement opt_else
%type <node> returnstatement printf statassignment
%type <node> expr simpexpr functioncall assignment

%type <type> type
%type <symbol> parameter

%%

start:
	program {
		symtab_symbol_t* entry = symtabLookup(tab, "main");
        if (entry == NULL) {
			yyerror(NO_MAIN_FUNCTION_ERROR);
		}
		else {

			if (entry->is_function != 1) {
				yyerror(MAIN_ISNOT_FUNCTION_ERROR);
			}
			/* if (entry->par_next != NULL) {	// Done in functiondefinition
				yyerror(PARAM_IN_MAIN_ERROR);
			} */
			/* if (entry->type != SYNTREE_TYPE_Void) {	// Done in functiondefinition
				yyerror(RETURN_TYPE_ERROR, "main", "void");
			} */

			nodeValue(0)->program.body = syntreeNodeAppend(ast, $program, entry->body);
		}

		nodeValue(0)->program.globals = symtabMaxGlobals(tab);
	}
	;

/* see EBNF grammar for further information */
program:
	/* empty */
		{ $$ = syntreeNodeEmpty(ast, SYNTREE_TAG_Sequence); }
	| program[prog] declassignment[decl] ';'
		{ syntreeNodeAppend(ast, $prog, $decl); }
	| program functiondefinition
	;

functiondefinition:
	type ID[name] {
		/* globale Zeiger auf das aktuelle Funktionssymbol */
		func = symtabSymbol($name, $type);										/* Create a function symbol. */
		func->is_function = 1;
		func->body = syntreeNodeEmpty(ast, SYNTREE_TAG_Function);

		if (symtabInsert(tab, func) != 0) {										/* Insert the symbol. */
            yyerror(DOUBLE_FUNCTION_DECLARATION_ERROR, $name);
		} else {
			symtabEnter(tab);													/* Enter a new visable area. */
		}
	}
	'(' opt_parameterlist {
		if (!strcmp($name, "main")) {
			if ($type != SYNTREE_TYPE_Void) { yyerror(RETURN_TYPE_ERROR, "main", "void"); }
			if (func->par_next != NULL) { yyerror(PARAM_IN_MAIN_ERROR); }
		}
	}
	')' '{' statementlist[body] '}' {
		syntreeNodeAppend(ast, func->body, $body);                             	/* Store function body. */
		nodeValue(func->body)->function.locals = symtabMaxLocals(tab);         	/* Record the number of local values. */
		symtabLeave(tab);														/* Leave a visable area. */
		func = NULL;
	}
	;

opt_parameterlist:
	/* empty */
	| parameterlist
	;

parameterlist:
	parameter
		{ symtabParam(func, $parameter); }
	| parameter ',' parameterlist
		{ symtabParam(func, $parameter); }
	;

parameter:
	type ID[name] {

		if ($type == SYNTREE_TYPE_Void) { yyerror(VOID_PARAMETER_ERROR, $name, func->name); }

		if (symtabInsert(tab, symtabSymbol($name, $type)) != 0) {
			yyerror(DOUBLE_PARAMETER_DECLARATION_ERROR, $name, func->name);
		}

		$$ = symtabSymbol($name, $type);
	}
	;

functioncall:
	ID[name] '(' opt_argumentlist[args] ')' {
		symtab_symbol_t* fn = symtabLookup(tab, $name);							/* Look up and get the symbol. */

		if (fn == NULL) {
			yyerror(UNKNOWN_FUNCTION_ERROR, $name);
		} else {

			if (fn->is_function != 1) { yyerror(CALL_VARIABLE_AS_FUNCTION_ERROR, $name); }

			symtab_symbol_t* param = symtabParamFirst(fn);
			syntree_nid argumentID = nodeFirst($args);

			/* Check if the number of the arguments and the number of the parameters are equal. */
			int argument_Count = argumentCount(argumentID);
			int parameter_Count = parameterCount(param);
			if (parameter_Count > argument_Count) {

				yyerror(TOO_FEW_ARGUMENTS_ERROR, $name, parameter_Count, argument_Count);

			} else if (parameter_Count < argument_Count) {

				yyerror(TOO_MANY_ARGUMENTS_ERROR, $name, parameter_Count, argument_Count);

			} else {

				for (; param != NULL && argumentID != 0;
					param = symtabParamNext(param), argumentID = nodeNext(argumentID))
				{
					syntree_node_t* argument = syntreeNodePtr(ast, argumentID);
					syntree_node_type param_type = param->type;
					syntree_node_type argument_type = argument->type;
					if (param_type != argument_type) {	/* No type compatibility for function call! */
						yyerror(INCOMPATIBLE_ARGUMENT_ERROR, param->name, $name, nodeTypeName[param_type], nodeTypeName[argument_type]);
					}
				}
			}
			symtab_symbol_t* par;
			syntree_nid arg;
			for (par = symtabParamFirst(fn), arg = nodeFirst($args);
		     	par != NULL && arg != 0;
		     	par = symtabParamNext(par), arg = nodeNext(arg))
			{
				if (par->type != nodeType(arg))
					yyerror("argument of type '%s' doesn't exactly match "
					        "parameter of type '%s' in call to '%s()'",
					        nodeTypeName[nodeType(arg)],
					        nodeTypeName[par->type], $name);
			}
		}

		$$ = syntreeNodePair(ast, SYNTREE_TAG_Call, $args, fn->body);
		nodePtr($$)->type = fn->type;
	}
	;

opt_argumentlist:
	/* empty */
		{ $$ = syntreeNodeEmpty(ast, SYNTREE_TAG_Sequence); }
	| argumentlist[list] {
		/*  // This part should only be used when it is syntreeNodeAppend used in the argumentList production.
			// Here we need to reverse this argumentList to make the order of the arguments the same as the order of the parameters in the symbol table.
			syntree_node_t *iterator, *nextNode, *firstNode;
			syntree_nid temp_nodeID;

			// Get the first node of the argument list. The node this iterator points to will become the last node finally.
			firstNode = iterator = nodePtr($list);

			while(iterator->next != 0) {
				nextNode = nodePtr(iterator->next);				// Get the next node.
				temp_nodeID = nextNode->next;					// Get the next node of nextNode.
				nextNode->next = syntreeNodeId(ast, firstNode); // The nextNode's next points to the first node.
				firstNode = nextNode;							// This nextNode now becomes the real first node.
				iterator->next = temp_nodeID;
			}

			temp_nodeID = nodePtr($list)->value.container.first;
			nodePtr($list)->value.container.first = nodePtr($list)->value.container.last;
			nodePtr($list)->value.container.last = temp_nodeID;
		*/
	}
	;

argumentlist:
	assignment[expr]
		{ $$ = syntreeNodeTag(ast, SYNTREE_TAG_Sequence, $expr); }
	| argumentlist[list] ',' assignment[elem]
		{ $$ = syntreeNodeAppend(ast, $list, $elem); }	/* Use prepend here to make sure the order is correct. */
	;

statementlist:
	/* empty */
		{ $$ = syntreeNodeEmpty(ast, SYNTREE_TAG_Sequence); }
	| statementlist[list] statement[elem]
		{ $$ = syntreeNodeAppend(ast, $list, $elem); }
	;

block:
	'{' { symtabEnter(tab); }
		statementlist[body]
	'}' { $$ = $body; symtabLeave(tab);   }
	;

statement:
	  ifstatement
	  	{ $$ = $ifstatement; }
	| forstatement
		{ $$ = $forstatement; }
	| whilestatement
		{ $$ = $whilestatement; }
	| returnstatement ';'
		{ $$ = $returnstatement; }
	| dowhilestatement ';'
		{ $$ = $dowhilestatement; }
	| printf ';'
		{ $$ = $printf; }
	| declassignment ';'
		{ $$ = $declassignment; }
	| statassignment ';'
		{ $$ = $statassignment; }
	| functioncall ';'
		{ $$ = $functioncall; }
	| block
		{ $$ = $block; }
	;

ifstatement:
	KW_IF '(' assignment[cond] ')' { checkConditionType($cond, "if-statement"); symtabEnter(tab); } statement[then] { symtabLeave(tab); } opt_else[else] {

		$$ = syntreeNodePair(ast, SYNTREE_TAG_If, $cond, $then);
		$$ = syntreeNodeAppend(ast, $$, $else);
	}
	;

/* KW_ELSE has higher precedence, so an occuring 'else' will cause the */
/* execution of the second rule */
opt_else:
	/* empty */ %prec LOWER_THAN_ELSE
		{ $$ = 0; }
	| KW_ELSE { symtabEnter(tab); } statement[else]
		{ $$ = $else; symtabLeave(tab); }
	;

forstatement:
	KW_FOR '(' { symtabEnter(tab); } declassignment[init] ';' expr[cond] { checkConditionType($cond, "for-loop"); } ';' statassignment[step] ')' statement[body] {

		$$ = syntreeNodePair(ast, SYNTREE_TAG_For, $init, $cond);
		$$ = syntreeNodeAppend(ast, $$, $step);
		$$ = syntreeNodeAppend(ast, $$, $body);
		symtabLeave(tab);
	}
	| KW_FOR '(' { symtabEnter(tab); } statassignment[init] ';' expr[cond] { checkConditionType($cond, "for-loop"); } ';' statassignment[step] ')' statement[body] {

		$$ = syntreeNodePair(ast, SYNTREE_TAG_For, $init, $cond);
		$$ = syntreeNodeAppend(ast, $$, $step);
		$$ = syntreeNodeAppend(ast, $$, $body);
		symtabLeave(tab);
	}
	;

dowhilestatement:
	KW_DO { symtabEnter(tab); } statement[body] KW_WHILE '(' assignment[cond] { { checkConditionType($cond, "do-while-loop"); } } ')' {

		$$ = syntreeNodePair(ast, SYNTREE_TAG_DoWhile, $cond, $body);
		symtabLeave(tab);
	}
	;

whilestatement:
	KW_WHILE '(' assignment[cond] { checkConditionType($cond, "while-loop"); } ')' { symtabEnter(tab); } statement[body] {

		$$ = syntreeNodePair(ast, SYNTREE_TAG_While, $cond, $body);
		symtabLeave(tab);
	}
	;

returnstatement:
	KW_RETURN {
		if (func->type != SYNTREE_TYPE_Void) {
			yyerror(NO_RETURN_ERROR, func->name, nodeTypeName[func->type]);
		} else {
			$$ = syntreeNodeEmpty(ast, SYNTREE_TAG_Return);
		}
	}
	| KW_RETURN assignment[expr] {
		if (func->type != nodeType($expr)) {
			if (!(func->type == SYNTREE_TYPE_Float && nodeType($expr) == SYNTREE_TYPE_Integer)) {
				yyerror(INCOMPATIBLE_RETURN_ERROR, func->name, nodeTypeName[func->type], nodeTypeName[nodeType($expr)]);
			}
			$expr = syntreeNodeCast(ast, func->type, $expr);
		}

		$$ = syntreeNodeTag(ast, SYNTREE_TAG_Return, $expr);
	}
	;

printf:
	KW_PRINTF '(' assignment[arg] ')'
		{
			if (nodeType($arg) == SYNTREE_TYPE_Void) {
				yyerror(INCOMPATIBLE_PRINTF_ASSIGN_ERROR, nodeTypeName[nodeType($arg)]);
			}
			$$ = syntreeNodeTag(ast, SYNTREE_TAG_Print, $arg);
		}
	| KW_PRINTF '(' CONST_STRING[arg] ')'
		{ $$ = syntreeNodeTag(ast, SYNTREE_TAG_Print, syntreeNodeString(ast, $arg)); }
	| KW_PRINTF '(' ')'
		{
			yyerror(NOTHING_PRINTABLE_ERROR);
			$$ = syntreeNodeTag(ast, SYNTREE_TAG_Print, syntreeNodeString(ast, 0));
		}
	;

declassignment:
	type ID[name] {
		symtab_symbol_t* sym = symtabSymbol($name, $type);

		if (symtabInsert(tab, sym) != 0) {
			if (func != NULL) {
				yyerror(DOUBLE_LOCAL_VARIABLE_DECLARATION_ERROR, $name, func->name);
			} else {
				yyerror(DOUBLE_GLOBAL_VARIABLE_DECLARATION_ERROR, $name);
			}

		}
		/* if (func == NULL) {
			sym->is_global = 1;
		} else {
			sym->is_global = 0;
		} */
		$$ = syntreeNodeTag(ast, SYNTREE_TAG_Assign, syntreeNodeVariable(ast, sym));
	}
	| type ID[name] '=' assignment[expr] {

		symtab_symbol_t* sym = symtabSymbol($name, $type);

		if (symtabInsert(tab, sym) != 0) {
			if (func != NULL) {
				yyerror(DOUBLE_LOCAL_VARIABLE_DECLARATION_ERROR, $name, func->name);
			} else {
				yyerror(DOUBLE_GLOBAL_VARIABLE_DECLARATION_ERROR, $name);
			}

		}
		else
		{
			syntree_node_type right_type = nodeType($expr);

			if (!isTypeMatchedOrConvertable(sym->type, right_type)) {
				yyerror(INCOMPATIBLE_ASSIGNMENT_ERROR, $name, nodeTypeName[$type], nodeTypeName[right_type]);
			}
			if (!isTypeMatched(sym->type, right_type)) {
				$expr = syntreeNodeCast(ast, sym->type, $expr);
			}

		}
		$$ = syntreeNodePair(ast, SYNTREE_TAG_Assign,
							 syntreeNodeVariable(ast, sym), $expr);

	}
	;

type:
	KW_BOOLEAN { $$ = SYNTREE_TYPE_Boolean; }
	| KW_FLOAT { $$ = SYNTREE_TYPE_Float; }
	| KW_INT   { $$ = SYNTREE_TYPE_Integer; }
	| KW_VOID  { $$ = SYNTREE_TYPE_Void; }
	;

statassignment:
	ID[name] '=' assignment[expr] {
		symtab_symbol_t* sym = symtabLookup(tab, $name);

		if (sym == NULL) {
			yyerror(UNKNOWN_VARIABLE_ERROR, $name);
		} else {
			if (sym->is_function == 1) {
				yyerror(ASSGIN_TO_FUNCTION_ERROR, sym->name);
			}

			syntree_node_type ltype = sym->type;
			syntree_node_type rtype = nodeType($expr);
			if (!isTypeMatchedOrConvertable(ltype, rtype)) {
				yyerror(INCOMPATIBLE_ASSIGNMENT_ERROR, $name, nodeTypeName[ltype], nodeTypeName[rtype]);
			}
			if (!isTypeMatched(ltype, rtype)) {
				$expr = syntreeNodeCast(ast, sym->type, $expr);
			}
		}

		$$ = syntreeNodePair(ast, SYNTREE_TAG_Assign,
							 syntreeNodeVariable(ast, sym), $expr);
	}
	;

assignment:
	ID[name] '=' assignment[expr] {
		symtab_symbol_t* sym = symtabLookup(tab, $name);

		if (sym == NULL) {
			yyerror(UNKNOWN_VARIABLE_ERROR, $name);
		} else {
			if (sym->is_function == 1) {
				yyerror(ASSGIN_TO_FUNCTION_ERROR, sym->name);
			}

			syntree_node_type ltype = sym->type;
			syntree_node_type rtype = nodeType($expr);
			if (!isTypeMatchedOrConvertable(ltype, rtype)) {
				yyerror(INCOMPATIBLE_ASSIGNMENT_ERROR, $name, nodeTypeName[ltype], nodeTypeName[rtype]);
			}
			if (!isTypeMatched(ltype, rtype)) {
				$expr = syntreeNodeCast(ast, sym->type, $expr);
			}
		}
		$$ = syntreeNodePair(ast, SYNTREE_TAG_Assign,
							 syntreeNodeVariable(ast, sym), $expr);
		if (sym != NULL) { nodePtr($$)->type = sym->type; }
	}
	| expr { $$ = $expr; }
	;

expr:
	simpexpr { $$ = $simpexpr; }
	| simpexpr[lhs] EQ  simpexpr[rhs]
		{ $$ = combine($lhs, $rhs, SYNTREE_TAG_Eqt); }
	| simpexpr[lhs] NEQ simpexpr[rhs]
		{ $$ = combine($lhs, $rhs, SYNTREE_TAG_Neq); }
	| simpexpr[lhs] LEQ simpexpr[rhs]
		{ $$ = combine($lhs, $rhs, SYNTREE_TAG_Leq); }
	| simpexpr[lhs] GEQ simpexpr[rhs]
		{ $$ = combine($lhs, $rhs, SYNTREE_TAG_Geq); }
	| simpexpr[lhs] LSS simpexpr[rhs]
		{ $$ = combine($lhs, $rhs, SYNTREE_TAG_Lst); }
	| simpexpr[lhs] GRT simpexpr[rhs]
		{ $$ = combine($lhs, $rhs, SYNTREE_TAG_Grt); }
	;

simpexpr:
	simpexpr[lhs] '+' simpexpr[rhs]
		{ $$ = combine($lhs, $rhs, SYNTREE_TAG_Plus); }
	| simpexpr[lhs] '-' simpexpr[rhs]
		{ $$ = combine($lhs, $rhs, SYNTREE_TAG_Minus); }
	| simpexpr[lhs] OR simpexpr[rhs]
		{ $$ = combine($lhs, $rhs, SYNTREE_TAG_LogOr); }
	| simpexpr[lhs] '*' simpexpr[rhs]
		{ $$ = combine($lhs, $rhs, SYNTREE_TAG_Times); }
	| simpexpr[lhs] '/' simpexpr[rhs]
		{ $$ = combine($lhs, $rhs, SYNTREE_TAG_Divide); }
	| simpexpr[lhs] AND simpexpr[rhs]
		{ $$ = combine($lhs, $rhs, SYNTREE_TAG_LogAnd); }
	| '-' simpexpr[operand] %prec UMINUS {
		if (nodeType($operand) == SYNTREE_TYPE_Boolean || nodeType($operand) == SYNTREE_TYPE_Void) {
			yyerror(INVALID_OPERATOR_ERROR, "-", nodeTypeName[nodeType($operand)]);
		}
		$$ = syntreeNodeTag(ast, SYNTREE_TAG_Uminus, $operand);
		nodePtr($$)->type = nodeType($operand);
	}
	| CONST_INT[val]
		{ $$ = syntreeNodeInteger(ast, $val); }
	| CONST_FLOAT[val]
		{ $$ = syntreeNodeFloat(ast, $val); }
	| CONST_BOOLEAN[val]
		{ $$ = syntreeNodeBoolean(ast, $val); }
	| functioncall { $$ = $functioncall; }
	| ID[name] {
		symtab_symbol_t* sym = symtabLookup(tab, $name);

		if (sym == NULL) {
			yyerror(UNKNOWN_VARIABLE_ERROR, $name);
		} else {
			if (sym->is_function == 1) {
				yyerror(READ_FUNCTION_AS_VARIABLE_ERROR, sym->name);
			}
		}

		$$ = syntreeNodeVariable(ast, sym);
	}
	| '(' assignment ')'
		{ $$ = $assignment; }
	;

%%

int main(int argc, const char* argv[])
{
	symtab_t symtab;
	syntree_t syntree;

	int rc;

	/* belege die globalen Zeiger mit den lokalen Werten */
	tab = &symtab;
	ast = &syntree;

	/* versuche die Datei aus der Kommandozeile zu öffnen
	 * oder lies aus der Standardeingabe */
	yyin = (argc != 2) ? stdin : fopen(argv[1], "r");

	if (yyin == NULL)
		yyerror("couldn't open file %s\n", argv[1]);

	/* initialisiere die Hilfsstrukturen */
	if (symtabInit(tab))
	{
		fputs("out-of-memory error\n", stderr);
		exit(-1);
	}

	if (syntreeInit(ast))
	{
		fputs("out-of-memory error\n", stderr);
		exit(-1);
	}

	/* parse das Programm */
	yydebug = 1;
	rc = yyparse();

	/* gib' Symboltabelle und Syntaxbaum wieder frei */
	symtabRelease(&symtab);
	syntreeRelease(&syntree);

	return rc;
}

/**@brief Gibt eine Fehlermeldung aus und beendet das Programm mit Exitcode -1.
 * Die Funktion akzeptiert eine variable Argumentliste und nutzt die Syntax von
 * printf.
 * @param msg  die Fehlermeldung
 * @param ...  variable Argumentliste für die Formatierung von \p msg
 */
void yyerror(const char* msg, ...)
{
	va_list args;

	va_start(args, msg);
	fprintf(stderr, "Error in line %d: ", yylineno);
	vfprintf(stderr, msg, args);
	fprintf(stderr, "\n");
	va_end(args);
}

/**@brief Testet, ob eine binäre Operation zwischen zwei getypten Ausdrücken
 * definiert ist und bricht mit einem Fehler ab, falls nicht.
 * @param lhs  Typ des Operanden auf der linken Seite
 * @param rhs  Typ des Operanden auf der rechten Seite
 * @param op   Operator
 * @return resultierender Typ aus der Operation
 */
static syntree_node_type
combineTypes(syntree_node_type lhs_type, syntree_node_type rhs_type, syntree_node_tag op)
{
	/* lhs und rhs können sein:
	 * SYNTREE_TYPE_Void,
	 * SYNTREE_TYPE_Boolean,
	 * SYNTREE_TYPE_Integer,
	 * SYNTREE_TYPE_Float
	 */

	if (lhs_type == SYNTREE_TYPE_Void || rhs_type == SYNTREE_TYPE_Void) {
		yyerror(INVALID_VOID_FOR_OPERATOR_ERROR, operatorName(op), func->name);
		return SYNTREE_TYPE_Integer;
	}

	if (lhs_type != rhs_type) {	/* Boolean can only be operated with Boolean! */
		if (lhs_type == SYNTREE_TYPE_Boolean || rhs_type == SYNTREE_TYPE_Boolean) {
			yyerror(INCOMPATIBLE_OPERAND_ERROR, operatorName(op), nodeTypeName[lhs_type], nodeTypeName[rhs_type]);
		}
	}

	switch (op)
	{
		case SYNTREE_TAG_Eqt:
		case SYNTREE_TAG_Neq: return SYNTREE_TYPE_Boolean;
		case SYNTREE_TAG_Leq:
		case SYNTREE_TAG_Geq:
		case SYNTREE_TAG_Lst:
		case SYNTREE_TAG_Grt: {
			if (lhs_type == SYNTREE_TYPE_Boolean || rhs_type == SYNTREE_TYPE_Boolean) {
				yyerror(INVALID_OPERATOR_ERROR, operatorName(op), nodeTypeName[SYNTREE_TYPE_Boolean]);
			}
			return SYNTREE_TYPE_Boolean;
		}
		case SYNTREE_TAG_LogOr:
		case SYNTREE_TAG_LogAnd: {
			if (lhs_type != SYNTREE_TYPE_Boolean || rhs_type != SYNTREE_TYPE_Boolean) {
				yyerror(INCOMPATIBLE_OPERAND_ERROR, operatorName(op), nodeTypeName[lhs_type], nodeTypeName[rhs_type]);
			}
			return SYNTREE_TYPE_Boolean;
		}
		case SYNTREE_TAG_Plus:
		case SYNTREE_TAG_Minus:
		case SYNTREE_TAG_Times:
		case SYNTREE_TAG_Divide: {
			if (lhs_type == SYNTREE_TYPE_Boolean || rhs_type == SYNTREE_TYPE_Boolean) {
				yyerror(INVALID_OPERATOR_ERROR, operatorName(op), nodeTypeName[SYNTREE_TYPE_Boolean]);
				return SYNTREE_TYPE_Integer;
			} else {
				if (lhs_type == SYNTREE_TYPE_Float || rhs_type == SYNTREE_TYPE_Float) {
					return SYNTREE_TYPE_Float;
				} else {
					return SYNTREE_TYPE_Integer;
				}
			}
			break;
		}
		default: {
		 	yyerror(UNKNOWN_OPERATOR_ERROR);
			return SYNTREE_TYPE_Integer;
		}
	}
}

syntree_nid
combine(syntree_nid lhs, syntree_nid rhs, syntree_node_tag op)
{
	syntree_nid res;
	syntree_node_type lhs_type = nodeType(lhs);
	syntree_node_type rhs_type = nodeType(rhs);

	syntree_node_type type = combineTypes(lhs_type, rhs_type, op);

	if (lhs_type != rhs_type)
	{
		/* Situation: ein Integer und ein Float (impliziter Cast) */
		if (lhs_type != SYNTREE_TYPE_Float)
			lhs = syntreeNodeCast(ast, SYNTREE_TYPE_Float, lhs);
		else if (rhs_type != SYNTREE_TYPE_Float)
			rhs = syntreeNodeCast(ast, SYNTREE_TYPE_Float, rhs);
	}

	res = syntreeNodePair(ast, op, lhs, rhs);
	nodePtr(res)->type = type;
	return res;
}
