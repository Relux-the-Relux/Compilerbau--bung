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
    AND = 259,
    OR = 260,
    EQ = 261,
    NEQ = 262,
    LEQ = 263,
    GEQ = 264,
    LSS = 265,
    GRT = 266,
    KW_BOOLEAN = 267,
    KW_DO = 268,
    KW_ELSE = 269,
    KW_FLOAT = 270,
    KW_FOR = 271,
    KW_IF = 272,
    KW_INT = 273,
    KW_PRINTF = 274,
    KW_RETURN = 275,
    KW_VOID = 276,
    KW_WHILE = 277,
    CONST_INT = 278,
    CONST_FLOAT = 279,
    CONST_BOOLEAN = 280,
    CONST_STRING = 281,
    ID = 282
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

#line 97 "minako-syntax.tab.h" /* yacc.c:1916  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINAKO_SYNTAX_TAB_H_INCLUDED  */
