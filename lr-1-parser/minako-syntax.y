%define parse.error verbose
%define parse.trace

%code requires {
	#include <stdio.h>

	extern void yyerror(const char*);
	extern FILE* yyin;
}

%code {
	extern int yylex();
	extern int yylineno;
}

%union {
	char* string;
	double floatValue;
	int intValue;
}

%token AND           "&&"
%token OR            "||"
%token EQ            "=="
%token NEQ           "!="
%token LEQ           "<="
%token GEQ           ">="
%token LSS           "<"
%token GRT           ">"
%token KW_BOOLEAN    "bool"
%token KW_DO         "do"
%token KW_ELSE       "else"
%token KW_FLOAT      "float"
%token KW_FOR        "for"
%token KW_IF         "if"
%token KW_INT        "int"
%token KW_PRINTF     "printf"
%token KW_RETURN     "return"
%token KW_VOID       "void"
%token KW_WHILE      "while"
%token CONST_INT     "integer literal"
%token CONST_FLOAT   "float literal"
%token CONST_BOOLEAN "boolean literal"
%token CONST_STRING  "string literal"
%token ID            "identifier"

%%

program :	declassignment ';'
		|	functiondefinitions
		;

functiondefinitions	:	/* empty */
					|	functiondefinitions functiondefinition
					;

functiondefinition	:	type id '(' parameterdefinition ')' '{' statementlist '}'
					|	type id '(' ')' '{' statementlist '}'
					;

parameterdefinition	:	type id
					|	type id ',' parameterdefinition
					;

functioncall	:	id '(' ')'
				|	id '(' parameterlist ')'
				;

parameterlist	:	assignment
				|	assignment ',' parameterlist
				;

statementlist	:	/* empty */
				|	statementlist block
				;

block	:	'{' statementlist '}'
		|	statement
		;

statement	:	ifstatement
			|	forstatement
			|	whilestatement
			|	returnstatement
			|	dowhilestatement
			|	printf ';'
			|	declassignment ';'
			|	statassignment	';'
			|	functioncall ';'
			;

ifstatement	:	KW_IF '(' assignment ')' block
			|	KW_IF '(' assignment ')' KW_ELSE block
			;

forstatement	:	KW_FOR '(' statassignment ';' expr ';' statassignment ')' block
				|	KW_FOR '(' declassignment ';' expr ';' statassignment ')' block
				;

dowhilestatement	:	KW_DO block KW_WHILE '(' assignment ')'
					;

whilestatement	:	KW_WHILE '(' assignment ')' block
				;

returnstatement	:	KW_RETURN
				|	KW_RETURN assignment
				;

printf	:	KW_PRINTF '(' assignment ')'
		|	KW_PRINTF '(' CONST_STRING ')'
		;

declassignment	: 	type id
				|	type id '=' assignment
				;

type	:	KW_BOOLEAN
		|	KW_FLOAT
		|	KW_INT
		|	KW_VOID
		;

statassignment	:	id '=' assignment
				;

assignment	:	id '=' assignment
			|	expr
			;

expr	:	simpexpr
		|	simpexpr extraexpr
		;

extraexpr	:	'==' simpexpr
			|	'!=' simpexpr
			|	'<=' simpexpr
			|	'>=' simpexpr
			|	'<' simpexpr
			|	'>' simpexpr
			;

simpexpr	:	'-' term extraterm
			|	term extraterm
			;

extraterm	:	/* empty */
			|	extraterm '+' term
			|	extraterm '-' term
			|	extraterm '||' term
			;

term	:	factor extrafactor
		;

extrafactor	:	/* empty */
			|	extrafactor '*' factor
			|	extrafactor '/' factor
			|	extrafactor '&&' factor
			;

factor	:	CONST_INT
		|	CONST_FLOAT
		|	CONST_BOOLEAN
		|	functioncall
		|	id
		|	'(' assignment ')'
		;

id	:	ID
	;
%%

int main()
{
	yydebug=1;
	return yyparse();
}

void yyerror(const char* msg)
{
	fprintf(stderr, msg);
}
