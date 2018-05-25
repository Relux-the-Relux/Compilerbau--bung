%x PRELINKTEXT LINKTEXT POSTLINKTEXT URL

%{
#include "urlscanner.h"
%}
WHITESPACE [ \t\n\r]

%option noyywrap
%option yylineno
%%

{WHITESPACE}                        {}
<<EOF>>                             {return MYEOF;}
"\<a ".*"href=\""                    {BEGIN(URL);}
<URL>[^\"]*                         {BEGIN(PRELINKTEXT); yylval = yytext; return TOKEN_URL;}
<PRELINKTEXT>\"[^\>]*\>             {BEGIN(LINKTEXT);}
<LINKTEXT>[^\<]*                    {BEGIN(POSTLINKTEXT); yylval = yytext; return TOKEN_TEXT;}
<POSTLINKTEXT>[\</a]                {BEGIN(INITIAL);}
.                                   {}
