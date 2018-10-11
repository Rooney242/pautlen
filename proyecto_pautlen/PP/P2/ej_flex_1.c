#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

extern FILE* yyin;
extern FILE* yyout;
extern int yyleng;
extern char* yytext;

int main(int argc, char **argv){
	
	int token;
	
	if (argc!= 2){
		printf("Especifica fichero de entrada");
		return 0;
	}
	
	if ((yyin = fopen(argv[1],"r")) == NULL){
		printf("Error al abrir el fichero de entrada");
	}
	yyout = fopen("salida.txt","w");
	
	while ((token = yylex())!= 0){
		
		switch (token){
			
			case TOK_MAIN:
				printf("RECONOCIDO TOK_MAIN: %s\n",yytext);
				break;
			case TOK_ARRAY:
				printf("RECONOCIDO TOK_ARRAY: %s\n",yytext);		
				break;
			case TOK_IF:
				printf("RECONOCIDO TOK_IF: %s\n",yytext);
				break;
			case TOK_ELSE:
				printf("RECONOCIDO TOK_ELSE: %s\n",yytext);		
				break;
			case TOK_WHILE:	
				printf("RECONOCIDO TOK_WHILE: %s\n",yytext);		
				break;
			case TOK_INT:
				printf("RECONOCIDO TOK_INT: %s\n",yytext);
				break;
		}
	}
	printf("Fin del archivo\n");
	fclose(yyin);
	fclose(yyout);
}
