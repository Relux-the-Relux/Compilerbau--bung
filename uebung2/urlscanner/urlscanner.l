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
"<a ".*"href=\""                    {BEGIN(URL);}
<URL>^\"*                           {BEGIN(PRELINKTEXT); return TOKEN_URL;}
<PRELINKTEXT>\".*">"                {BEGIN(LINKTEXT);}                                
<LINKTEXT>^<*                       {BEGIN(POSTLINKTEXT); return TOKEN_TEXT;}
<POSTLINKTEXT>"<a"{WHITESPACE}+">"  {BEGIN(INITIAL);}                  
