#include <stdio.h>
#include <stdlib.h>
#include "omicron.h"
#include "y.tab.h"

extern FILE* yyin;
extern FILE* yyout;
extern int yyleng;
extern char* yytext;
extern int line_count;
extern int col_count;

FILE* fout;
FILE* asmfile;

int main(int argc, char **argv){

	if (argc!= 3){
		printf("Especifica fichero de entrada, de salida");
		return 0;
	}
	
	if ((yyin = fopen(argv[1],"r")) == NULL){
		printf("Error al abrir el fichero de entrada");
	}

	if ((fout = fopen(argv[2],"w")) == NULL){
		printf("Error al abrir el fichero de salida");
	}

	asmfile = fopen("omicron.asm","w");
	yyout = fopen("residuo.txt","w");

	yyparse();
	
	fclose(yyin);
	fclose(yyout);
	fclose(fout);

	return 1;
}


