%x CCOMMENT COMMENTLINE
%{
#include "minako.h"
#include "string.h"
%}
WHITESPACE [ \t\n\r]
LETTER	[a-zA-Z]
INTEGER [[:digit:]]+
FLOAT {INTEGER}"."{INTEGER}|("."{INTEGER})
STRING \"(\\.|[^"\\])*\"

%option noyywrap
%option yylineno
%%

{WHITESPACE}+               {}
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
"while"                     {return KW_WHILE;}
"="|"+"|"-"|"*"|"/"|","|";"|"("|")"|"{"|"}" {return (int)yytext[0];}
"//"                        {BEGIN(COMMENTLINE);}
<COMMENTLINE>.              {}
<COMMENTLINE>\n             {BEGIN(INITIAL);}
"/*"                        {BEGIN(CCOMMENT);}
<CCOMMENT>.|\n              {}
<CCOMMENT>"*/"              {BEGIN(INITIAL);}
{INTEGER}                   {yylval.intValue = atoi(yytext); return CONST_INT;}
{FLOAT}([eE]([-+])?{INTEGER})?|{INTEGER}[eE]([-+])?{INTEGER}  {yylval.floatValue = atof(yytext); return CONST_FLOAT;}
"true"                      {yylval.intValue = 1; return CONST_BOOLEAN;}
"false"                     {yylval.intValue = 0; return CONST_BOOLEAN;}
{STRING}                    {

                            int size = strlen(yytext);
                            char* temp =(char*) malloc((size-2)*sizeof(char));
                            for(int i=0;i<(size-2);i++){
                            temp[i]=yytext[i+1];
                            }
                            yylval.string = temp;
                            free(temp);
                            return CONST_STRING;}

[a-zA-Z][a-zA-Z0-9]*        {yylval.string = yytext; return ID;}
