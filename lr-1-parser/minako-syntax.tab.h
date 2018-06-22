/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 4 "minako-syntax.y" /* yacc.c:1916  */

	#include <stdio.h>
	#include <stdlib.h>
	extern void yyerror(const char*);
	extern FILE* yyin;

#line 51 "minako-syntax.tab.h" /* yacc.c:1916  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    UMINUS = 258,
    MOO = 259,
    FOO = 260,
    AND = 261,
    OR = 262,
    EQ = 263,
    NEQ = 264,
    LEQ = 265,
    GEQ = 266,
    LSS = 267,
    GRT = 268,
    KW_BOOLEAN = 269,
    KW_DO = 270,
    KW_ELSE = 271,
    KW_FLOAT = 272,
    KW_FOR = 273,
    KW_IF = 274,
    KW_INT = 275,
    KW_PRINTF = 276,
    KW_RETURN = 277,
    KW_VOID = 278,
    KW_WHILE = 279,
    CONST_INT = 280,
    CONST_FLOAT = 281,
    CONST_BOOLEAN = 282,
    CONST_STRING = 283,
    ID = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "minako-syntax.y" /* yacc.c:1916  */

	char* string;
	double floatValue;
	int intValue;

#line 99 "minako-syntax.tab.h" /* yacc.c:1916  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINAKO_SYNTAX_TAB_H_INCLUDED  */
