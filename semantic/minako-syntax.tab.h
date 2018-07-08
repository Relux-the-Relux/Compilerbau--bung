/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_MINAKO_SYNTAX_TAB_H_INCLUDED
# define YY_YY_MINAKO_SYNTAX_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 2060 of yacc.c  */
#line 3 "minako-syntax.y"

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


/* Line 2060 of yacc.c  */
#line 98 "minako-syntax.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AND = 258,
     OR = 259,
     EQ = 260,
     NEQ = 261,
     LEQ = 262,
     GEQ = 263,
     LSS = 264,
     GRT = 265,
     KW_BOOLEAN = 266,
     KW_DO = 267,
     KW_ELSE = 268,
     KW_FLOAT = 269,
     KW_FOR = 270,
     KW_IF = 271,
     KW_INT = 272,
     KW_PRINTF = 273,
     KW_RETURN = 274,
     KW_VOID = 275,
     KW_WHILE = 276,
     CONST_INT = 277,
     CONST_FLOAT = 278,
     CONST_BOOLEAN = 279,
     CONST_STRING = 280,
     ID = 281,
     UMINUS = 282,
     LOWER_THAN_ELSE = 283
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2060 of yacc.c  */
#line 196 "minako-syntax.y"

	char* string;
	double floatValue;
	int intValue;

	symtab_symbol_t* symbol;
	syntree_nid node;
	syntree_node_type type;


/* Line 2060 of yacc.c  */
#line 152 "minako-syntax.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */
/* "%code provides" blocks.  */
/* Line 2060 of yacc.c  */
#line 54 "minako-syntax.y"

	extern symtab_t* tab;
	extern syntree_t* ast;


/* Line 2060 of yacc.c  */
#line 183 "minako-syntax.tab.h"

#endif /* !YY_YY_MINAKO_SYNTAX_TAB_H_INCLUDED  */
