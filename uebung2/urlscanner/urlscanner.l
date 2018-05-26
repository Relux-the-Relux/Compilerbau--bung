%x BEFORELINKTEXT LINKTEXT AFTERLINKTEXT URL
%option noyywrap
%option yylineno
%option nounput
%option noinput

%{
extern int fileno(FILE *stream);
#include "urlscanner.h"
%}

WHITESPACE [ \t\n\r]
%%

{WHITESPACE}                        {}
<<EOF>>                             {return MYEOF;}
"\<a ".*"href=\""                   {BEGIN(URL);}
<URL>[^\"]*                         {BEGIN(BEFORELINKTEXT); yylval = yytext; return TOKEN_URL;}
<BEFORELINKTEXT>\"[^\>]*\>          {BEGIN(LINKTEXT);}
<LINKTEXT>[^\<]*                    {BEGIN(AFTERLINKTEXT); yylval = yytext; return TOKEN_TEXT;}
<AFTERLINKTEXT>[\</a]               {BEGIN(INITIAL);}
.                                   {}
