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

void eat(){
    currentToken = nextToken;
    nextToken = yylex();
}

void isTokenAndEat(int token){
    if(token == currentToken) {
        eat();
    }else{
        
    }
}

void error(){
    fprintf(stderr,"ERROR: Syntaxfehler in Zeile %i", yylineno);
    exit(-1);
}

int isToken(int token){
    if(token == currentToken){
        return 1;
    }else{
        return 0;
    }
}

//rules

void program() {
    while(isToken(KW_BOOLEAN)||isToken(KW_FLOAT)||isToken(KW_INT)||isToken(KW_VOID)){
        functiondefinition();
    }
    isTokenAndEat(0);
}

void functiondefinition() {
    if(isToken(KW_BOOLEAN)||isToken(KW_FLOAT)||isToken(KW_INT)||isToken(KW_VOID)){
        type();
        isTokenAndEat(ID);
        isTokenAndEat('(');
        isTokenAndEat(')');
        isTokenAndEat('{');
    }
}
        
void functioncall() {
    isTokenAndEat('(');
    isTokenAndEat(ID);
    isTokenAndEat(')');
}
        
void statementlist() {
    while(isToken('(')){
        eat();
        block();
        isTokenAndEat(')');
    }
}
        
void block() {
    if(isToken('{')){
        statementlist();
        isTokenAndEat('}');
    }else if(isToken(KW_IF)||isToken(KW_RETURN)||isToken(KW_PRINTF)||(isToken(ID) && nextToken == '=')||(isToken(ID) && nextToken == '(')) {
        statement();
    }else {
        error();
    }
}

void statement() {
    if (isToken(KW_IF)){
        ifstatement();
    }else if(isToken(KW_RETURN)) {
        returnstatement();
    }else if(isToken(KW_PRINTF)) {
        printF();
    }else if(isToken(ID) && nextToken == '=') {
        statassignment();
    }else if(isToken(ID) && nextToken == '(') {
        functioncall();
    }else {
        error();
    }
}
        
void ifstatement() {
    isTokenAndEat(KW_IF);
    isTokenAndEat('(');
    if(isToken(ID)||isToken('-')){
        assignment();
    } else {
        error();
    }
    isTokenAndEat(')');
    if(isToken('{')){
        block();
    } else {
        error();
    }
    isTokenAndEat('{');
}
       
void returnstatement() {
    isTokenAndEat(KW_RETURN);
    if(isToken(ID)||isToken('-')){
        assignment();
    }
    
}

void printF() {
    isTokenAndEat(KW_PRINTF);
    isTokenAndEat('(');
    if(isToken(ID)||isToken('-')){
        assignment();
    } else {
        error();
    }
    isTokenAndEat(')');
}
        
void type() {
    if(isToken(KW_BOOLEAN)||isToken(KW_FLOAT)||isToken(KW_INT)||isToken(KW_VOID)){
        eat();
    } else {
        error();
    }
}
        
void statassignment() {
    isTokenAndEat(ID);
    isTokenAndEat('=');
    if(isToken(ID)||isToken('-')){
        assignment();
    } else {
        error();
    }
}
        
void assignment() {
    if(isToken(ID)){
        eat();
        isTokenAndEat('=');
        if(isToken(ID)||isToken('-')){
            assignment();
        } else {
            error();
        }
    }else if(isToken('-')||isToken(CONST_INT)||isToken(CONST_FLOAT)||isToken(CONST_BOOLEAN)||isToken(ID)||isToken('(')){
        expr();
    } else{
        error();
    }
}
        
void expr() {
    if(isToken('-')||isToken(CONST_INT)||isToken(CONST_FLOAT)||isToken(CONST_BOOLEAN)||isToken(ID)||isToken('(')) {
        simpexpr();
    }
    if(isToken(EQ)||isToken(NEQ)||isToken(LEQ)||isToken(GEQ)||isToken('<')||isToken('>')){
        eat();
        if(isToken('-')||isToken(CONST_INT)||isToken(CONST_FLOAT)||isToken(CONST_BOOLEAN)||isToken(ID)||isToken('(')) {
            simpexpr();
        }else {
            error();
        }
    }
}
        
void simpexpr() {
    if(isToken('-')){
        eat();
    }
    if(isToken(CONST_INT)||isToken(CONST_FLOAT)||isToken(CONST_BOOLEAN)||isToken(ID)||isToken('(')) {
        term();
    }else{
        error();
    }
    while(isToken('+')||isToken('.')||isToken(OR)) {
        eat();
        if(isToken('-')||isToken(CONST_INT)||isToken(CONST_FLOAT)||isToken(CONST_BOOLEAN)||isToken(ID)||isToken('(')) {
            simpexpr();
        }else {
            error();
        }
    }
}
        
void term() {
    if(isToken(CONST_INT)||isToken(CONST_FLOAT)||isToken(CONST_BOOLEAN)||isToken(ID)||isToken('(')){
        factor();
    } else {
        error();
    }
    if(isToken('*')||isToken('/')||isToken(AND)){
        eat();
        if(isToken(CONST_INT)||isToken(CONST_FLOAT)||isToken(CONST_BOOLEAN)||isToken(ID)||isToken('(')){
            factor();
        } else {
           error(); 
        }
    }
}
        
void factor() {
    if(isToken(CONST_INT)||isToken(CONST_FLOAT)||isToken(CONST_BOOLEAN)||isToken(ID)) {
        eat();
    } else if(isToken('(')) {
        eat();
        if(isToken(ID)||isToken('-')){
        assignment();
        } else {
        
        }
        isTokenAndEat(')');
    }else {
        error();
    }
}

int main(int argc, char** argv){
    
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
    
    exit(0);
}