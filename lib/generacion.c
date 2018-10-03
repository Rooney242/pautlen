
#include <stdio.h>

void escribir_cabecera_bss(FILE* fpasm){
	fprintf(fpasm,"segment.bss\n\t__esp resd 1\n");
}
void escribir_subseccion_data(FILE* fpasm){
	fprintf(fpasm,"segment .data\n");
}
void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano){
	fprintf(fpasm,"/t_%s resd %d\n",nombre,tamano);
}

void escribir_segmento_codigo(FILE* fpasm){
	fprintf(fpasm,"segment .text\n\tglobal main\n\textern scan_int, print_int, scan_float, print_float," 
	"scan_boolean, print_boolean\n\textern print_endofline, print_blank, print_string\n\textern alfa_malloc, alfa_free, ld_float");
}
void escribir_inicio_main(FILE* fpasm){
	fprintf(fpasm,"; -----------------------\n; PROCEDIMIENTO PRINCIPAL\n; -----------------------\nmain:\n\tmov dword [__esp] , esp");
}
void escribir_fin(FILE* fpasm){
	fprintf(fpasm,"fin:\n\tmov dword esp, [__esp]\n\tret");
}
void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
	fprintf(fpasm,"")
}
