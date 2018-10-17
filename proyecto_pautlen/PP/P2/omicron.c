#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

extern FILE* yyin;
extern FILE* yyout;
extern int yyleng;
extern char* yytext;
extern int line_count;
extern int col_count;

FILE* fout;

int main(int argc, char **argv){
	
	int token;
	
	if (argc!= 3){
		printf("Especifica fichero de entrada y de salida");
		return 0;
	}
	
	if ((yyin = fopen(argv[1],"r")) == NULL){
		printf("Error al abrir el fichero de entrada");
	}

	if ((fout = fopen(argv[2],"w")) == NULL){
		printf("Error al abrir el fichero de salida");
	}

	yyout = fopen("residuo.txt","w");
	
	while ((token = yylex())!= 0){
		
		switch (token){

			case TOK_MAIN:
				fprintf(fout,"TOK_MAIN\t%d\t%s\n",TOK_MAIN,yytext);
				break;
			case TOK_ARRAY:
				fprintf(fout,"TOK_ARRAY\t%d\t%s\n",TOK_ARRAY,yytext);				
				break;
			case TOK_IF:
				fprintf(fout,"TOK_IF\t%d\t%s\n",TOK_IF,yytext);
				break;
			case TOK_ELSE:
				fprintf(fout,"TOK_ELSE\t%d\t%s\n",TOK_ELSE,yytext);	
				break;
			case TOK_WHILE:	
				fprintf(fout,"TOK_WHILE\t%d\t%s\n",TOK_WHILE,yytext);		
				break;
			case TOK_INT:
				fprintf(fout,"TOK_INT\t%d\t%s\n",TOK_INT,yytext);
				break;
			case TOK_NONE:
				fprintf(fout,"TOK_NONE\t%d\t%s\n",TOK_NONE,yytext);
				break;
			case TOK_CLASS:
				fprintf(fout,"TOK_CLASS\t%d\t%s\n",TOK_CLASS,yytext);				
				break;
			case TOK_INHERITS:
				fprintf(fout,"TOK_INHERITS\t%d\t%s\n",TOK_INHERITS,yytext);
				break;
			case TOK_INSTANCE_OF:
				fprintf(fout,"TOK_INSTANCE_OF\t%d\t%s\n",TOK_INSTANCE_OF,yytext);	
				break;
			case TOK_DISCARD:	
				fprintf(fout,"TOK_DISCARD\t%d\t%s\n",TOK_DISCARD,yytext);		
				break;
			case TOK_ITSELF:
				fprintf(fout,"TOK_ITSELF\t%d\t%s\n",TOK_ITSELF,yytext);
				break;
			case TOK_HIDDEN:
				fprintf(fout,"TOK_HIDDEN\t%d\t%s\n",TOK_HIDDEN,yytext);
				break;
			case TOK_SECRET:
				fprintf(fout,"TOK_SECRET\t%d\t%s\n",TOK_SECRET,yytext);				
				break;
			case TOK_EXPOSED:
				fprintf(fout,"TOK_EXPOSED\t%d\t%s\n",TOK_EXPOSED,yytext);
				break;
			case TOK_UNIQUE:
				fprintf(fout,"TOK_UNIQUE\t%d\t%s\n",TOK_UNIQUE,yytext);	
				break;
			case TOK_FUNCTION:	
				fprintf(fout,"TOK_FUNCTION\t%d\t%s\n",TOK_FUNCTION,yytext);		
				break;
			case TOK_RETURN:
				fprintf(fout,"TOK_RETURN\t%d\t%s\n",TOK_RETURN,yytext);
				break;
			case TOK_BOOLEAN:
				fprintf(fout,"TOK_BOOLEAN\t%d\t%s\n",TOK_BOOLEAN,yytext);
				break;
			case TOK_PRINTF:
				fprintf(fout,"TOK_PRINTF\t%d\t%s\n",TOK_PRINTF,yytext);				
				break;
			case TOK_ELSE:
				fprintf(fout,"TOK_ELSE\t%d\t%s\n",TOK_ELSE,yytext);
				break;
			case TOK_SCANF:
				fprintf(fout,"TOK_SCANF\t%d\t%s\n",TOK_SCANF,yytext);	
				break;
			case TOK_FALSE:	
				fprintf(fout,"TOK_FALSE\t%d\t%s\n",TOK_FALSE,yytext);		
				break;
			case TOK_TRUE:
				fprintf(fout,"TOK_TRUE\t%d\t%s\n",TOK_TRUE,yytext);
				break;
			case TOK_IGUAL:
				fprintf(fout,"TOK_IGUAL\t%d\t%s\n",TOK_IGUAL,yytext);
				break;
			case TOK_DISTINTO:
				fprintf(fout,"TOK_DISTINTO\t%d\t%s\n",TOK_DISTINTO,yytext);
				break;
			case TOK_MAYORIGUAL:
				fprintf(fout,"TOK_MAYORIGUAL\t%d\t%s\n",TOK_MAYORIGUAL,yytext);
				break;
			case TOK_MENORIGUAL:
				fprintf(fout,"TOK_MENORIGUAL\t%d\t%s\n",TOK_MENORIGUAL,yytext);
				break;
			case TOK_AND:
				fprintf(fout,"TOK_AND\t%d\t%s\n",TOK_AND,yytext);
				break;
			case TOK_OR:
				fprintf(fout,"TOK_OR\t%d\t%s\n",TOK_OR,yytext);
				break;
			case TOK_FLECHA:
				fprintf(fout,"TOK_FLECHA\t%d\t%s\n",TOK_FLECHA,yytext);
				break;
			case TOK_IDENTIFICADOR:
				fprintf(fout,"TOK_IDENTIFICADOR\t%d\t%s\n",TOK_IDENTIFICADOR,yytext);
				break;
			case TOK_CONSTANTE_ENTERA:
				fprintf(fout,"TOK_CONSTANTE_ENTERA\t%d\t%s\n",TOK_CONSTANTE_ENTERA,yytext);
				break;
			case TOK_ERROR:
				fprintf(fout,"TOK_ERROR\t%d\t%s\n",TOK_ERROR,yytext);
				break;
			default:
				fprintf(fout,"SIMBOLO SIMPLE\t%d\t%s\n",token,yytext);
			}
	}
	printf("Fin del archivo\n");
	fclose(yyin);
	fclose(yyout);
	fclose(fout);
}
