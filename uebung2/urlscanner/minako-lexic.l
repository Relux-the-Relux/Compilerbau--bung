%x COMMENTBLOCK COMMENTLINE
%option noyywrap
%option yylineno
%option nounput
%option noinput

%{
#include "minako.h"
extern int fileno(FILE *stream);
void getStringContent();
%}

WHITESPACE      [ \t\n\r]
INTEGER         [[:digit:]]+
EXPONENT        [eE]([-+])?{INTEGER}
FLOAT           [{INTEGER}"."{INTEGER}|("."{INTEGER})]{EXPONENT}?
STRING          \"[^\"\n]*\"
ID              [[:alpha:]][[:alnum:]]*

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
"//"                        {BEGIN(COMMENTLINE);}
<COMMENTLINE>.              {}
<COMMENTLINE>\n             {BEGIN(INITIAL);}
"/*"                        {BEGIN(COMMENTBLOCK);}
<COMMENTBLOCK>.|\n          {}
<COMMENTBLOCK>"*/"          {BEGIN(INITIAL);}
{INTEGER}                   {yylval.intValue = atoi(yytext); return CONST_INT;}
{FLOAT}|{INTEGER}{EXPONENT} {yylval.floatValue = atof(yytext); return CONST_FLOAT;}
"true"                      {yylval.intValue = 1; return CONST_BOOLEAN;}
"false"                     {yylval.intValue = 0; return CONST_BOOLEAN;}
{STRING}                    {getStringContent();return CONST_STRING;}
{ID}                        {yylval.string = yytext; return ID;}
"="|"+"|"-"|"*"|"/"|","|";"|"("|")"|"{"|"}" {return (int)yytext[0];}

%%

void getStringContent() {
    int size = strlen(yytext);
    char* temp =(char*) malloc((size-2)*sizeof(char));
    for(int i=0;i<(size-2);i++){
        temp[i]=yytext[i+1];
    }
    yylval.string = temp;
    free(temp);
}
