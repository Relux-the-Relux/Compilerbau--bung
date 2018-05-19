%x CCOMMENT COMMENTLINE
WHITESPACE [ \t\n\r]
LETTER	[a-zA-Z]
INTEGER [[:digit:]]+
FLOAT {INTEGER}"."{INTEGER}| "." {INTEGER}
%%

{WHITESPACE}+               {}
"&&"                        {return(AND);}
"||"                        {return(OR);}
"=="                        {return(EQ);}
"!="                        {return(NEQ);}
"<="                        {return(LEQ);}
"<"                         {return(LSS);}
">"                         {return(GRT);}
"bool"                      {return(KW_BOOLEAN);}
"do"                        {return(KW_DO);}
"else"                      {return(KW_ELSE);}
"float"                     {return(KW_FLOAT);}
"for"                       {return(KW_FOR);}
"if"                        {return(KW_IF);}
"int"                       {return(KW_INT);}
"printf"                    {return(KW_PRINTF);}
"return"                    {return(KW_RETURN);}
"void"                      {return(KW_VOID);}
"while"                     {return(KW_VOID);}
"\\"                        {BEGIN(COMMENTLINE);}
<COMMENTLINE>.              {}
<COMMENTLINE>\n             {BEGIN(INITIAL);}
"\*"                        {BEGIN(CCOMMENT);}
<CCOMMENT>.|\n              {}
<CCOMMENT>"*\""             {BEGIN(INITIAL);}
INTEGER                     {yylval.intValue(atoi(yytext)); return(CONST_INT);}
FLOAT                       {yylval.floatValue(atof(yytext)); return(CONST_FLOAT);}
"true"|"false"              {yyval.string = YYText(); return(CONST_BOOLEAN);}
"\"" [^\n\"]* "\""          {yyval.string = YYText(); return(CONST_STRING);}
({LETTER})+ ({DIGIT} | {LETTER})*     {yyval.string = YYText(); return(ID);}
