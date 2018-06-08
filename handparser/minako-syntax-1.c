#include <stdio.h>
#include <stdlib.h>
#include "minako.h"

int currentToken;
int nextToken;

void eat();
void isTokenAndEat(int token);
void error();
int isToken(int token);

void program();
void functiondefinition();
void functioncall();
void statementlist();
void block();
void statement();
void ifstatement();
void returnstatement();
void printF();
void type();
void statassignment();
void assignment();
void expr();
void simpexpr();
void term();
void factor();

void eat()
{
    currentToken = nextToken;
    if (nextToken) {
        nextToken = yylex();
    }
}

void isTokenAndEat(int token)
{
    if(token == currentToken)
        eat();
    else
        error();
}

void error()
{
    fprintf(stderr,"ERROR: Syntaxfehler in Zeile %i", yylineno);
    exit(-1);
}

int isToken(int token)
{
    if(token == currentToken){
        return 1;
    }else{
        return 0;
    }
}

//rules

void program()
{
    while(isToken(KW_BOOLEAN)||isToken(KW_FLOAT)||isToken(KW_INT)||isToken(KW_VOID)){
        functiondefinition();
    }
}

void functiondefinition()
{
    if(isToken(KW_BOOLEAN)||isToken(KW_FLOAT)||isToken(KW_INT)||isToken(KW_VOID)){
        type();
        isTokenAndEat(ID);
        isTokenAndEat('(');
        isTokenAndEat(')');
        isTokenAndEat('{');
        statementlist();
        isTokenAndEat('}');
    }
}

void functioncall()
{
    isTokenAndEat(ID);
    isTokenAndEat('(');
    isTokenAndEat(')');
}

void statementlist()
{
    while(isToken('{')||isToken(ID)\
    ||isToken(KW_IF)||isToken(KW_RETURN)||isToken(KW_PRINTF))
    {
        block();
    }
}

void block()
{
    if(isToken('{'))
    {
        eat();
        statementlist();
        isTokenAndEat('}');
    }
    else if(isToken(KW_IF)||isToken(KW_RETURN)||isToken(KW_PRINTF)||isToken(ID))
        statement();
    else
        error();
}

void statement()
{
    if (isToken(KW_IF))
        ifstatement();
    else if(isToken(KW_RETURN))
    {
        returnstatement();
        isTokenAndEat(';');
    }
    else if(isToken(KW_PRINTF))
    {
        printF();
        isTokenAndEat(';');
    }
    else if(isToken(ID) && nextToken == '=')
    {
        statassignment();
        isTokenAndEat(';');
    }
    else if(isToken(ID) && nextToken == '(')
    {
        functioncall();
        isTokenAndEat(';');
    }
    else
        error();
}

void ifstatement()
{
    isTokenAndEat(KW_IF);
    isTokenAndEat('(');
    assignment();
    isTokenAndEat(')');
    block();
}

void returnstatement()
{
    isTokenAndEat(KW_RETURN);
    if (isToken(';'))
        return;
    else
        assignment();
}

void printF()
{
    isTokenAndEat(KW_PRINTF);
    isTokenAndEat('(');
    assignment();
    isTokenAndEat(')');
}

void type()
{
    if (isToken(KW_BOOLEAN)||isToken(KW_FLOAT)||isToken(KW_INT)||isToken(KW_VOID))
        eat();
    else
        error();
}

void statassignment()
{
    isTokenAndEat(ID);
    isTokenAndEat('=');
    assignment();
}

void assignment()
{
    if(isToken(ID) && nextToken == '=')
    {
        eat();
        isTokenAndEat('=');
        assignment();
    }
    else if(isToken('-')||isToken(CONST_INT)||isToken(CONST_FLOAT)||isToken(CONST_BOOLEAN)||isToken(ID)||isToken('('))
        expr();
    else
        error();
}

void expr()
{
    simpexpr();
    if (isToken(EQ)||isToken(NEQ)||isToken(LEQ)||isToken(GEQ)||isToken(LSS)||isToken(GRT))
    {
        eat();
        simpexpr();
    }
    else
    {
        error();
    }
}

void simpexpr()
{
    if(isToken('-'))
        eat();
    term();
    while(isToken('+')||isToken('-')||isToken(OR)) {
        eat();
        term();
    }
}

void term()
{
    factor();
    while(isToken('*')||isToken('/')||isToken(AND))
    {
        eat();
        factor();
    }
}

void factor() {
    if (isToken(ID) && nextToken == '(')
        functioncall();
    else if(isToken(CONST_INT)||isToken(CONST_FLOAT)||isToken(CONST_BOOLEAN)||isToken(ID))
        eat();
    else if (isToken('('))
    {
        eat();
        assignment();
        isTokenAndEat(')');
    }
    else
        error();
}

int main(int argc, char** argv)
{
    if (argc != 2)
        yyin = stdin;
    else
    {
        yyin = fopen(argv[1], "r");
        if (yyin == 0)
        {
            fprintf(stderr, "Fehler: Konnte Datei %s nicht zum lesen oeffnen.\n", argv[1]);
            exit(-1);
        }
    }

    currentToken = yylex();
    nextToken = yylex();

    program();

    fclose(yyin);

    exit(0);
}
