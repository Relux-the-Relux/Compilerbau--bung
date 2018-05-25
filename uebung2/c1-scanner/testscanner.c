#include <stdio.h>
#include <stdlib.h>
#include "minako.h"
#include <string.h>

yystype yylval;

int main(int argc, char* argv[])
{

	FILE *datei;
	datei = fopen("ausgabe.txt","w");

	int token;

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

	while ((token = yylex()))
	{
		fprintf(datei,"Line: %3d\t", yylineno);
		switch (token)
		{
		case ID:
			fprintf(datei,"ID:     %s\n", yylval.string);
			break;
			
		case CONST_BOOLEAN:
			fprintf(datei,"BOOL:   %s\n", yylval.intValue ? "true" : "false");
			break;
			
		case CONST_INT:
			fprintf(datei,"INT:    %d\n", yylval.intValue);
			break;
			
		case CONST_FLOAT:
			fprintf(datei,"FLOAT:  %g\n", yylval.floatValue);
			break;
			
		case CONST_STRING:
			fprintf(datei,"STRING: %s\n", yylval.string);
			break;
			
		default:
			if (token <= 255)
				fprintf(datei,"Token: '%c'\n", token);
			else
				fprintf(datei,"Token: %d\n", token);
		}
	}
	fclose(datei);
	datei = fopen("ausgabe.txt","r");
	FILE *datei2;
	datei2 = fopen("demorgan.sol","r");
	char temp1[260], temp2[260];
	int i =0;
	while(fgets(temp1, 50, datei)){
		fgets(temp2, 50, datei2);
		printf("t1: %s\n",temp1);
		printf("t2: %s\n",temp2);
		i++;
		if(strcmp(temp1,temp2)!=0){
			printf("error in line %d\n",i);
			exit(-1);
		}
	}
	fclose(datei);
	fclose(datei2);
	return 0;
}
