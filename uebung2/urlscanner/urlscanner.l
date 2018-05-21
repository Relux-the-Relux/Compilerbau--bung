%x PRELINKTEXT LINKTEXT POSTLINKTEXT URL

%{
#include "urlscanner.h"
%}
WHITESPACE [ \t\n\r]

%option noyywrap 
%%

{WHITESPACE}                    {}
<<EOF>>                         {return MYEOF;}
"<a ".*"href=\""                {begin(URL);}
<URL>^\"*                       {begin(PRELINKTEXT);return TOKEN_URL;}
<PRELINKTEXT>\".*">"              {begin(LINKTEXT);}                                
<LINKTEXT>^<*                   {begin(POSTLINKTEXT); return TOKEN_TEXT;}
<POSTLINKTEXT>"<a"{WHITESPACE}+">" {begin(INITIAL);}                  
