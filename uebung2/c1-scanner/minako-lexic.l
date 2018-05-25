%x CCOMMENT COMMENTLINE
%{
#include "minako.h"
%}
WHITESPACE [ \t\n\r]
LETTER	[a-zA-Z]
INTEGER [[:digit:]]+
FLOAT {INTEGER}"."{INTEGER}|("."{INTEGER})
STRING \"(\\.|[^"\\])*\"

%option noyywrap
%%

{WHITESPACE}               {}
"&&"                        {return AND;}
"||"                        {return OR;}
"=="                        {return EQ;}
"!="                        {return NEQ;}
"<="                        {return LEQ;}
"<"                         {return LSS;}
">"                         {return GRT;}
"bool"                      {return KW_BOOLEAN;}
"do"                        {return KW_DO;}
"else"                      {return KW_ELSE;}
"float"                     {return KW_FLOAT;}
"for"                       {return KW_FOR;}
"if"                        {return KW_IF;}
"int"                       {return KW_INT;}
"printf"                    {return KW_PRINTF;}
"return"                    {return KW_RETURN;}
"void"                      {return KW_VOID;}
"while"                     {return KW_VOID;}
"+"|"-"|"*"|"/"|","|";"|"("|")"|"{"|"}" {return (int)yytext[0];}
"\\\\"                        {BEGIN(COMMENTLINE);}
<COMMENTLINE>.              {}
<COMMENTLINE>\n             {BEGIN(INITIAL);}
"\\*"                        {BEGIN(CCOMMENT);}
<CCOMMENT>.|\n              {}
<CCOMMENT>"*\\"              {BEGIN(INITIAL);}
{INTEGER}                   {yylval.intValue = atoi(yytext); return CONST_INT;}
{FLOAT}([eE]([-+])?{INTEGER})?|{INTEGER}[eE]([-+])?{INTEGER}  {yylval.floatValue = atof(yytext); return CONST_FLOAT;}
"true"|"false"              {yylval.string = yytext; return CONST_BOOLEAN;}
{STRING}                    {yylval.string = yytext; return CONST_STRING;}
<<EOF>>                     {return 0;}
[a-zA-Z][a-zA-Z0-9]*        {yylval.string = yytext; return ID;}
.                           {fprintf(stderr,"%s" ,"invalid character"); return 0;}
