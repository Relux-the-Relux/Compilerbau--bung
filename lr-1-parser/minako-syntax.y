%code requires {
	#include <stdio.h>
	#include <stdlib.h>
	extern void yyerror(const char*);
	extern FILE* yyin;
}

%code {
	extern int yylex();
	extern int yylineno;
	extern char* yytext;
}

%union {
	char* string;
	double floatValue;
	int intValue;
}

%left '+' '-'
%left '*' '/'
%left UMINUS

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

%right KW_IF
%right KW_ELSE

%start program

%%

program :	/* empty */
		|	program declassignment ';'
		|	program functiondefinition
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
			|	returnstatement ';'
			|	dowhilestatement ';'
			|	printf ';'
			|	declassignment ';'
			|	statassignment	';'
			|	functioncall ';'
			;

statblock	:	'{' statementlist '}'
			|	statement
			;

ifstatement	:	KW_IF '(' assignment ')' statblock %prec KW_IF
			|	KW_IF '(' assignment ')' statblock KW_ELSE statblock %prec KW_ELSE
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

extraexpr	:	EQ simpexpr
			|	NEQ simpexpr
			|	LEQ simpexpr
			|	GEQ simpexpr
			|	LSS simpexpr
			|	GRT simpexpr
			;

simpexpr	:	'-' term extraterm %prec UMINUS
			|	term extraterm
			;

extraterm	:	/* empty */
			|	extraterm '+' term
			|	extraterm '-' term
			|	extraterm OR term
			;

term	:	factor extrafactor
		;

extrafactor	:	/* empty */
			|	extrafactor '*' factor
			|	extrafactor '/' factor
			|	extrafactor AND factor
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

int main(int argc, char* argv[])
{
	//yydebug=1;

	if (argc != 2)
		yyin = stdin;
	else
	{
		yyin = fopen(argv[1], "r");
		if (yyin == 0)
		{
			fprintf(stderr, "Fehler: Konnte Datei %s nicht zum lesen oeffen.\n", argv[1]);
			exit(-1);
		}
	}

	return yyparse();
}

void yyerror(const char* msg)
{
	fprintf(stderr, "Line: %d at %c\nERROR: %s\n",yylineno, yytext[0], msg);
	exit(-1);
}
