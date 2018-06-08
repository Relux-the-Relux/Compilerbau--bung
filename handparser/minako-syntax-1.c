#include <stdio.h>
#include <stdlib.h>
#include "minako.h"

const char* fileName;
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

/**
* @brief Die Eingang des Lexikalischer Scanner.
* @return int Die Zeichen falls das richtig ist.
*/
int lexicalScanner()
{
    int token;
    switch (token = yylex()) {
        case AND:
        case OR:
        case EQ:
        case NEQ:
        case LEQ:
        case GEQ:
        case LSS:
        case GRT:
        case KW_BOOLEAN:
        case KW_DO:
        case KW_IF:
        case KW_ELSE:
        case KW_FLOAT:
        case KW_INT:
        case KW_PRINTF:
        case KW_RETURN:
        case KW_VOID:
        case KW_WHILE:
        case CONST_INT:
        case CONST_FLOAT:
        case CONST_BOOLEAN:
        case ID:
        case '=':
        case '+':
        case '-':
        case '*':
        case '/':
        case ',':
        case ';':
        case '(':
        case ')':
        case '{':
        case '}': return token;
        case EOF: exit(0);      // End of file
        default:
            fprintf(stderr, "Lexikalischer Fehler: [%s line %d] %s\n", fileName, yylineno, (char*)&token);
            exit(EXIT_FAILURE);
    }
}

void eat()
{
    currentToken = nextToken;
    nextToken = lexicalScanner();
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
    if (isToken('{')\
    ||isToken(KW_IF)||isToken(KW_DO)||isToken(KW_FOR)||isToken(KW_WHILE)||isToken(KW_PRINTF)\
    ||isToken(KW_INT)||isToken(KW_FLOAT)||isToken(KW_BOOLEAN)||isToken(ID)\
    ||isToken(KW_RETURN))
    {
        block();
    }
}

void block()
{
    if(isToken('{'))
    {
        statementlist();
        isTokenAndEat('}');
    }
    else if(isToken(KW_IF)||isToken(KW_DO)||isToken(KW_FOR)||isToken(KW_WHILE)||isToken(KW_PRINTF)\
    ||isToken(KW_INT)||isToken(KW_FLOAT)||isToken(KW_BOOLEAN)||isToken(ID)\
    ||isToken(KW_RETURN))
    {
        statement();
    }
    else
    {
        error();
    }
}

void statement()
{
    if (isToken(KW_IF))
    {
        ifstatement();
    }
    else if(isToken(KW_PRINTF))
    {
        printF();
        isTokenAndEat(';');
    }
    else if(isToken(KW_RETURN))
    {
        returnstatement();
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
    else {
        error();
    }
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
    if (isToken(KW_BOOLEAN)||isToken(KW_FLOAT)||isToken(KW_INT)||isToken(KW_VOID)){
        eat();
    } else {
        error();
    }
}

void statassignment()
{
    isTokenAndEat(ID);
    isTokenAndEat('=');
    assignment();
}

void assignment()
{
    if(isToken(ID))
    {
        eat();
        isTokenAndEat('=');
        assignment();
    }
    else if(isToken('-')\
    ||isToken(CONST_INT)||isToken(CONST_FLOAT)||isToken(CONST_BOOLEAN)||isToken(ID)||isToken('('))
    {
        expr();
    }
    else
    {
        error();
    }
}

void expr()
{
    simpexpr();
    if(isToken(EQ)||isToken(NEQ)||isToken(LEQ)||isToken(GEQ)||isToken('<')||isToken('>'))
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
    {
        eat();
    }
    term();
    while(isToken('+')||isToken('.')||isToken(OR)) {
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
    if(isToken(CONST_INT)||isToken(CONST_FLOAT)||isToken(CONST_BOOLEAN))
        eat();
    else if (isToken(ID) && nextToken == '(')
        functioncall();
    else if (isToken(ID))
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

int main(int argc, char const *argv[])
{
    if (argc >= 2)
    {
        int fileIndex = 1;
        for (;fileIndex<argc;fileIndex++)
        {
            yyin = fopen(argv[fileIndex], "r");
            if (yyin == NULL)
            {
                fprintf(stderr, "Fehler: Konnte Datei %s nicht zum lesen oeffnen.\n", argv[fileIndex]);
                exit(EXIT_FAILURE);
            }
            else
            {
                fileName = argv[fileIndex];
                currentToken = lexicalScanner();
                nextToken = lexicalScanner();
                program();
            }
        }
    }
    else
    {
        yyin = stdin;
        printf("Liest aus stdin>>\n");
        currentToken = lexicalScanner();
        nextToken = lexicalScanner();
        program();
    }
    return 0;
}
