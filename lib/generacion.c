
#include <stdio.h>

void escribir_cabecera_bss(FILE* fpasm){
	fprintf(fpasm,"segment.bss\n\t__esp resd 1\n");
}
void escribir_subseccion_data(FILE* fpasm){
	//Con mensaje de error de division cero
	fprintf(fpasm,"segment .data\n\tmsg_div_cero\tdb \"ERROR: DIVISOR ES CERO\", 0");
}
void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano){
	fprintf(fpasm,"/t_%s resd %d\n",nombre,tamano);
}

void escribir_segmento_codigo(FILE* fpasm){
	fprintf(fpasm,"segment .text\n\tglobal main\n\textern scan_int, print_int, scan_float, print_float," 
	"scan_boolean, print_boolean\n\textern print_endofline, print_blank, print_string\n\textern alfa_malloc, alfa_free, ld_float\n");
}
void escribir_inicio_main(FILE* fpasm){
	fprintf(fpasm,"; -----------------------\n; PROCEDIMIENTO PRINCIPAL\n; -----------------------\nmain:\n\tmov dword [__esp] , esp\n");
}
void escribir_fin(FILE* fpasm){
	fprintf(fpasm,"fin:\n\tmov dword esp, [__esp]\n\tret");
}
void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
	//Si es una variable se escribe con los corchetes de direccion
	if (es_variable == 1)
		fprintf(fpasm,"\tpush dword [_%s]\n",nombre);
	//Si no, se escibe tal como esta
	if(es_variable == 0)
		fprintf(fpasm,"\tpush dword %s\n",nombre);
}

void asignar(FILE* fpasm, char* nombre, int es_variable){
	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable == 1){
		//Sacamos la variable de pila
		fprintf(fpasm, "\tpop dword eax\n");
		//La asignamos a la referencia
		fprintf(fpasm, "\tmov dword [_%s] , [eax]", nombre);
	}
	if (es_variable == 0){
		//Sacamos la variable de pila
		fprintf(fpasm, "\tpop dword eax\n");
		//La asignamos a la referencia
		fprintf(fpasm, "\tmov dword [_%s] , eax", nombre);
	}
	
}


void sumar(FILE* fpasm, int es_variable_1, int es_variable_2) {

	// Sacamos las variables de pila
	fprintf(fpasm, "pop dword eax\n\tpop dword edx\n\t");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (!es_variable_1) {
		fprintf(fpasm, "mov eax, [eax]\n\t");
	}
	if (!es_variable_2) {
		fprintf(fpasm, "mov edx, [edx]\n\t");
	}

	// Realizamos operacion y almacenamos en eax
	fprintf(fpasm, "add eax, edx\n\t");

	// Metemos eax en pila
	fprintf(fpasm, "push dword eax\n\t");
}

void restar(FILE* fpasm, int es_variable_1, int es_variable_2) {

	// Sacamos las variables de pila
	fprintf(fpasm, "pop dword eax\n\tpop dword edx\n\t");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (!es_variable_1) {
		fprintf(fpasm, "mov eax, [eax]\n\t");
	}
	if (!es_variable_2) {
		fprintf(fpasm, "mov edx, [edx]\n\t");
	}

	// Realizamos operacion y almacenamos en eax
	fprintf(fpasm, "sub eax, edx\n\t");

	// Metemos eax en pila
	fprintf(fpasm, "push dword eax\n\t");
}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2) {

	// Sacamos las variables de pila
	fprintf(fpasm, "pop dword eax\n\tpop dword ecx\n\t");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (!es_variable_1) {
		fprintf(fpasm, "mov eax, [eax]\n\t");
	}
	if (!es_variable_2) {
		fprintf(fpasm, "mov ecx, [ecx]\n\t");
	}

	// Realizamos operacion y almacenamos en eax
	fprintf(fpasm, "imul ecx\n\t");

	// Metemos eax en pila
	fprintf(fpasm, "push dword eax\n\t");
}

// TODO Comprobar si el divisor es 0, en cuyo caso:
// saltar a la rutina de error controlado (restaurando 
// el puntero de pila en ese caso y comprobando en el retorno 
// que no se produce “Segmentation Fault”)

void dividir(FILE* fpasm, int es_variable_1, int es_variable_2) {

	// Sacamos las variables de pila
	fprintf(fpasm, "pop dword eax\n\tpop dword ecx\n\t");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (!es_variable_1) {
		fprintf(fpasm, "mov eax, [eax]\n\t");
	}
	if (!es_variable_2) {
		fprintf(fpasm, "mov ecx, [ecx]\n\t");
	}

	// Realizamos operacion y almacenamos en eax
	fprintf(fpasm, "cdq\n\tidiv ecex\n\t")

	// Metemos eax en pila
	fprintf(fpasm, "push dword eax\n\t");
}


void o(FILE* fpasm, int es_variable_1, int es_variable_2) {

	// Sacamos las variables de pila
	fprintf(fpasm, "pop dword eax\n\tpop dword edx\n\t");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (!es_variable_1) {
		fprintf(fpasm, "mov eax, [eax]\n\t");
	}
	if (!es_variable_2) {
		fprintf(fpasm, "mov edx, [edx]\n\t");
	}

	// Realizamos operacion y almacenamos en eax
	fprintf(fpasm, "or eax, edx\n\t");

	// Metemos eax en pila
	fprintf(fpasm, "push dword eax\n\t");
}


void y(FILE* fpasm, int es_variable_1, int es_variable_2) {

	// Sacamos las variables de pila
	fprintf(fpasm, "pop dword eax\n\tpop dword edx\n\t");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (!es_variable_1) {
		fprintf(fpasm, "mov eax, [eax]\n\t");
	}
	if (!es_variable_2) {
		fprintf(fpasm, "mov edx, [edx]\n\t");
	}

	// Realizamos operacion y almacenamos en eax
	fprintf(fpasm, "and eax, edx\n\t");

	// Metemos eax en pila
	fprintf(fpasm, "push dword eax\n\t");
}

void cambiar_signo(FILE* fpasm, int es_variable) {

	// Sacamos las variables de pila
	fprintf(fpasm, "pop dword eax\n\t");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (!es_variable) {
		fprintf(fpasm, "mov eax, [eax]\n\t");
	}

	// Realizamos operacion y almacenamos en eax
	fprintf(fpasm, "neg eax\n\t");

	// Metemos eax en pila
	fprintf(fpasm, "push dword eax\n\t");
}


