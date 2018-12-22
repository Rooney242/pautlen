
#include <stdio.h>
#include "generacion.h"

void escribir_cabecera_bss(FILE* fpasm){
	fprintf(fpasm,"\nsegment .bss\n\t__esp resd 1\n");
}

void escribir_subseccion_data(FILE* fpasm){
	//Con mensaje de error de division cero
	fprintf(fpasm,"segment .data\n\tmsg_div_cero\tdb \"Error division por 0\", 0");
	fprintf(fpasm, "\n\tmsg_vector\tdb \"Indice de vector fuera de rango\", 0");
}

void declarar_variable(FILE* fpasm, char * nombre,  int tipo,  int tamano){
	fprintf(fpasm,"\t_%s resd %d\n",nombre,tamano);
}

void escribir_segmento_codigo(FILE* fpasm){
	fprintf(fpasm,"segment .text\n\tglobal main\n\textern scan_int, print_int, scan_float, print_float," 
	"scan_boolean, print_boolean\n\textern print_endofline, print_blank, print_string\n\textern malloc, free, ld_float\n");
}

void escribir_inicio_main(FILE* fpasm){
	fprintf(fpasm,"; -----------------------\n; PROCEDIMIENTO PRINCIPAL\n; -----------------------\nmain:\n\tmov dword [__esp] , esp\n");
}

void escribir_fin(FILE* fpasm){
	fprintf(fpasm,"fin:\n\tmov dword esp, [__esp]\n\tret\n");

	/* Gestion de las divisiones por 0 */
	fprintf(fpasm, "error_div_cero:\n");
	fprintf(fpasm, "\tpush dword msg_div_cero\n\tcall print_string\n\tadd esp, 4\n\tcall print_endofline\n\tret\n");
	fprintf(fpasm, "error_vector:\n");
	fprintf(fpasm, "\tpush dword msg_vector\n\tcall print_string\n\tadd esp, 4\n\tcall print_endofline\n\tret\n");
}

void escribir_operando(FILE* fpasm, char* nombre, int es_variable){
	//Si es una variable se escribe con los corchetes de direccion
	if (es_variable == 1)
		fprintf(fpasm,"\tpush dword _%s\n",nombre);
	//Si no, se escibe tal como esta
	if(es_variable == 0)
		fprintf(fpasm,"\tpush dword %s\n",nombre);
}

void asignar(FILE* fpasm, char* nombre, int es_variable){
	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable == 1){
		//Sacamos la variable de pila
		fprintf(fpasm, "\tpop dword eax\n"); 
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
		//La asignamos a la referencia
		fprintf(fpasm, "\tmov dword [_%s], eax\n", nombre);
	}
	if (es_variable == 0){
		//Sacamos la variable de pila
		fprintf(fpasm, "\tpop dword eax\n");
		//La asignamos a la referencia
		fprintf(fpasm, "\tmov dword [_%s], eax\n", nombre);
	}
	
}

/* FUNCIONES ARITMÉTICO-LÓGICAS BINARIAS */

void sumar(FILE* fpasm, int es_variable_1, int es_variable_2) {

	// Sacamos las variables de pila
	fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable_2) {
		fprintf(fpasm, "\tmov edx, dword [edx]\n");
	}
	if (es_variable_1) {
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	}

	// Realizamos operacion y almacenamos en eax
	fprintf(fpasm, "\tadd eax, edx\n");

	// Metemos eax en pila
	fprintf(fpasm, "\tpush dword eax\n");
}

void restar(FILE* fpasm, int es_variable_1, int es_variable_2) {

	// Sacamos las variables de pila
	fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable_2) {
		fprintf(fpasm, "\tmov edx, dword [edx]\n");
	}
	if (es_variable_1) {
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	}

	// Realizamos operacion y almacenamos en eax
	fprintf(fpasm, "\tsub eax, edx\n");

	// Metemos eax en pila
	fprintf(fpasm, "\tpush dword eax\n");
}

void multiplicar(FILE* fpasm, int es_variable_1, int es_variable_2) {

	// Sacamos las variables de pila
	fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable_2) {
		fprintf(fpasm, "\tmov edx, dword [edx]\n");
	}
	if (es_variable_1) {
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	}

	// Realizamos operacion y almacenamos en eax
	fprintf(fpasm, "\timul edx\n");

	// Metemos eax en pila
	fprintf(fpasm, "\tpush dword eax\n");
}

// TODO Comprobar si el divisor es 0, en cuyo caso:
// saltar a la rutina de error controlado (restaurando 
// el puntero de pila en ese caso y comprobando en el retorno 
// que no se produce “Segmentation Fault”)
void dividir(FILE* fpasm, int es_variable_1, int es_variable_2) {

	// Sacamos las variables de pila
	fprintf(fpasm, "\tpop dword ebx\n\tpop dword eax\n");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable_2) {
		fprintf(fpasm, "\tmov ebx, dword [ebx]\n");
	}
	if (es_variable_1) {
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	}

	fprintf(fpasm, "\tcmp ebx, 0\n");
	fprintf(fpasm, "\tje error_div_cero\n");

	// Realizamos operacion y almacenamos en eax
	fprintf(fpasm, "\tcdq\n\tidiv ebx\n");

	// Metemos eax en pila
	fprintf(fpasm, "\tpush dword eax\n");
}


void o(FILE* fpasm, int es_variable_1, int es_variable_2) {
	
	// Sacamos las variables de pila
	fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable_2) {
		fprintf(fpasm, "\tmov edx, dword [edx]\n");
	}
	if (es_variable_1) {
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	}

	// Realizamos operacion y almacenamos en eax
	fprintf(fpasm, "\tor eax, edx\n");

	// Metemos eax en pila
	fprintf(fpasm, "\tpush dword eax\n");
}


void y(FILE* fpasm, int es_variable_1, int es_variable_2) {

	// Sacamos las variables de pila
	fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable_2) {
		fprintf(fpasm, "\tmov edx, dword [edx]\n");
	}
	if (es_variable_1) {
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	}

	// Realizamos operacion y almacenamos en eax
	fprintf(fpasm, "\tand eax, edx\n");

	// Metemos eax en pila
	fprintf(fpasm, "\tpush dword eax\n");
}

void cambiar_signo(FILE* fpasm, int es_variable) {

	// Sacamos las variables de pila
	fprintf(fpasm, "\tpop dword eax\n");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable) {
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	}

	// Realizamos operacion y almacenamos en eax
	fprintf(fpasm, "\tneg eax\n");

	// Metemos eax en pila
	fprintf(fpasm, "\tpush dword eax\n");
}

void no(FILE* fpasm, int es_variable, int cuantos_no) {

	// Sacamos la variable de pila
	fprintf(fpasm, "\tpop dword eax\n");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable) {
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	}
	
	/*Implementado como en las diapositivas, no estoy seguro del todo de si he nombrado bien las 
		etiquetas ni si he puesto bien la sintaxis de los jump*/
		
	fprintf(fpasm, "\tcmp eax, 0\n");
	fprintf(fpasm, "\tje near _uno_%d\n", cuantos_no);
	fprintf(fpasm, "\tpush 0\n");
	fprintf(fpasm, "\tjmp near _fin_not_%d\n", cuantos_no);
	fprintf(fpasm, "_uno_%d:\n", cuantos_no);
	fprintf(fpasm, "\tpush 1\n");
	fprintf(fpasm, "_fin_not_%d:\n", cuantos_no);
}

/* FUNCIONES COMPARATIVAS */

void igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
	
	// Sacamos las variables de pila
	fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable2) {
		fprintf(fpasm, "\tmov edx, dword [edx]\n");
	}
	if (es_variable1) {
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	}
	
	/*Implementado como en las diapositivas, no estoy seguro del todo de si he nombrado bien las 
		etiquetas ni si he puesto bien la sintaxis de los jump*/
		
	fprintf(fpasm, "\tcmp eax, edx\n");
	fprintf(fpasm, "\tje near _igual_%d\n", etiqueta);
	fprintf(fpasm, "\tpush 0\n");
	fprintf(fpasm, "\tjmp near _fin_igual_%d\n", etiqueta);
	fprintf(fpasm, "_igual_%d:\n", etiqueta);
	fprintf(fpasm, "\tpush 1\n");
	fprintf(fpasm, "_fin_igual_%d:\n", etiqueta);
	
}

void distinto(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
	
	// Sacamos las variables de pila
	fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable2) {
		fprintf(fpasm, "\tmov edx, dword [edx]\n");
	}
	if (es_variable1) {
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	}
	
	/*Implementado como en las diapositivas, no estoy seguro del todo de si he nombrado bien las 
		etiquetas ni si he puesto bien la sintaxis de los jump*/
		
	fprintf(fpasm, "\tcmp eax, edx\n");
	fprintf(fpasm, "\tjne near _distinto_%d\n", etiqueta);
	fprintf(fpasm, "\tpush 0\n");
	fprintf(fpasm, "\tjmp near _fin_distinto_%d\n", etiqueta);
	fprintf(fpasm, "_distinto_%d:\n", etiqueta);
	fprintf(fpasm, "\tpush 1\n");
	fprintf(fpasm, "_fin_distinto_%d:\n", etiqueta);
	
}

void menor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
	
	// Sacamos las variables de pila
	fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable2) {
		fprintf(fpasm, "\tmov edx, dword [edx]\n");
	}
	if (es_variable1) {
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	}

	/*Implementado como en las diapositivas, no estoy seguro del todo de si he nombrado bien las 
		etiquetas ni si he puesto bien la sintaxis de los jump*/
		
	fprintf(fpasm, "\tcmp eax, edx\n");
	fprintf(fpasm, "\tjle near _menor_igual_%d\n", etiqueta);
	fprintf(fpasm, "\tpush 0\n");
	fprintf(fpasm, "\tjmp near _fin_menor_igual_%d\n", etiqueta);
	fprintf(fpasm, "_menor_igual_%d:\n", etiqueta);
	fprintf(fpasm, "\tpush 1\n");
	fprintf(fpasm, "_fin_menor_igual_%d:\n", etiqueta);
	
}

void mayor_igual(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
	
	// Sacamos las variables de pila
	fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable2) {
		fprintf(fpasm, "\tmov edx, dword [edx]\n");
	}
	if (es_variable1) {
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	}
	
	/*Implementado como en las diapositivas, no estoy seguro del todo de si he nombrado bien las 
		etiquetas ni si he puesto bien la sintaxis de los jump*/
		
	fprintf(fpasm, "\tcmp eax, edx\n");
	fprintf(fpasm, "\tjge near _mayor_igual_%d\n", etiqueta);
	fprintf(fpasm, "\tpush 0\n");
	fprintf(fpasm, "\tjmp near _fin_mayor_igual_%d\n", etiqueta);
	fprintf(fpasm, "_mayor_igual_%d:\n", etiqueta);
	fprintf(fpasm, "\tpush 1\n");
	fprintf(fpasm, "_fin_mayor_igual_%d:\n", etiqueta);
	
}

void menor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta){
	
	// Sacamos las variables de pila
	fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable2) {
		fprintf(fpasm, "\tmov edx, dword [edx]\n");
	}
	if (es_variable1) {
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	}
	
	/*Implementado como en las diapositivas, no estoy seguro del todo de si he nombrado bien las 
		etiquetas ni si he puesto bien la sintaxis de los jump*/
		
	fprintf(fpasm, "\tcmp eax, edx\n");
	fprintf(fpasm, "\tjl near _menor_%d\n", etiqueta);
	fprintf(fpasm, "\tpush 0\n");
	fprintf(fpasm, "\tjmp near _fin_menor_%d\n", etiqueta);
	fprintf(fpasm, "_menor_%d:\n", etiqueta);
	fprintf(fpasm, "\tpush 1\n");
	fprintf(fpasm, "_fin_menor_%d:\n", etiqueta);
	
}

void mayor(FILE* fpasm, int es_variable1, int es_variable2, int etiqueta) {
	
	// Sacamos las variables de pila
	fprintf(fpasm, "\tpop dword edx\n\tpop dword eax\n");

	// Comprobamos si los operandos son referencias o valores explicitos
	if (es_variable2) {
		fprintf(fpasm, "\tmov edx, dword [edx]\n");
	}
	if (es_variable1) {
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	}
	
	/*Implementado como en las diapositivas, no estoy seguro del todo de si he nombrado bien las 
		etiquetas ni si he puesto bien la sintaxis de los jump*/
		
	fprintf(fpasm, "\tcmp eax, edx\n");
	fprintf(fpasm, "\tjle near _mayor_%d\n", etiqueta);
	fprintf(fpasm, "\tpush 0\n");
	fprintf(fpasm, "\tjmp near _fin_mayor_%d\n", etiqueta);
	fprintf(fpasm, "_mayor_%d:\n", etiqueta);
	fprintf(fpasm, "\tpush 1\n");
	fprintf(fpasm, "_fin_mayor_%d:\n", etiqueta);
	
}

/* FUNCIONES DE ESCRITURA Y LECTURA */

void leer(FILE* fpasm, char* nombre, int tipo) {

    fprintf(fpasm, "\tpush _%s\n", nombre);

    if(tipo == BOOLEANO){ 
    	fprintf(fpasm, "\tcall scan_boolean\n");
    } else { 
    	fprintf(fpasm, "\tcall scan_int\n");
    }

    /* Restauramos pila */
    fprintf(fpasm, "\tadd esp, 4\n");

}

void escribir(FILE* fpasm, int es_variable, int tipo) {

    if(es_variable)
        fprintf(fpasm, "\tpop eax\n\tpush dword [eax]\n");

    if (tipo == BOOLEANO){
    	fprintf(fpasm, "\tcall print_boolean\n");
    } else {
    	fprintf(fpasm, "\tcall print_int\n");
    }

    fprintf(fpasm, "\tadd esp, 4\n");
    fprintf(fpasm, "\tcall print_endofline\n");

}
 
void ifthenelse_inicio(FILE * fpasm, int exp_es_variable, int etiqueta) {
	
	fprintf(fpasm, "\tpop eax\n");
	
	if(exp_es_variable)
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	
	fprintf(fpasm, "\tcmp eax, 0\n");
	fprintf(fpasm, "\tje near _fin_si_%d\n", etiqueta);
}

void ifthen_inicio(FILE * fpasm, int exp_es_variable, int etiqueta){

	fprintf(fpasm, "\tpop eax\n");
	
	if(exp_es_variable)
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	
	fprintf(fpasm, "\tcmp eax, 0\n");
	fprintf(fpasm, "\tje near _fin_si_%d\n", etiqueta);
}

void ifthen_fin(FILE * fpasm, int etiqueta){

	fprintf(fpasm, "_fin_si_%d:\n", etiqueta);
}

void ifthenelse_fin_then(FILE * fpasm, int etiqueta){

	fprintf(fpasm, "\tjmp near _fin_sino_%d\n", etiqueta);
	fprintf(fpasm, "_fin_si_%d:\n", etiqueta);
}

void ifthenelse_fin(FILE * fpasm, int etiqueta){

	fprintf(fpasm, "_fin_sino_%d:\n", etiqueta);
}

void if_exp_pila (FILE * fpasm, int exp_es_variable, int etiqueta){

	fprintf(fpasm, "\tpop eax\n");
	
	if(exp_es_variable)
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	
	fprintf(fpasm, "\tcmp eax, 0\n");
	fprintf(fpasm, "\tje near _fin_si_%d\n", etiqueta);
}

/* Guion 12 Parte PROC */
void declararFuncion(FILE * fpasm, char * nombre_funcion, int num_var_loc) {
	fprintf(fpasm, "_%s:\n", nombre_funcion);
	fprintf(fpasm, "\tpush ebp\n");
	fprintf(fpasm, "\tmov ebp, esp\n");
	fprintf(fpasm, "\tsub esp, %d\n", 4*num_var_loc);
}

void retornarFuncion(FILE * fpasm, int es_variable) {
	fprintf(fpasm, "\tpop dword eax\n");

	if (es_variable)
		fprintf(fpasm, "\tmov eax, dword [eax]\n");

	fprintf(fpasm, "\tmov dword esp, ebp\n");
	fprintf(fpasm, "\tpop dword ebp\n");
	fprintf(fpasm, "\tret\n");
}


void escribirParametro(FILE* fpasm, int pos_parametro, int num_total_parametros) {
	fprintf(fpasm, "\tlea eax, [ebp+%d]\n", 4 + 4 * (num_total_parametros - pos_parametro));
}

void escribirVariableLocal(FILE* fpasm, int posicion_variable_local) {
	fprintf(fpasm, "\tlea eax, [ebp-%d]\n", 4 * posicion_variable_local);
}

// TODO Creo que no hace falta comprobar el caso de que no sea variable porque se
// supone que ya está escrito en pila
void operandoEnPilaAArgumento(FILE * fd_asm, int es_variable) {
	if (es_variable) {
		fprintf(fd_asm, "\tpop eax\n");
		fprintf(fd_asm, "\tpush dword [eax]\n");
	} 
}

void llamarFuncion(FILE * fpasm, char * nombre_funcion, int num_argumentos) {
	fprintf(fpasm, "call _%s\n", nombre_funcion);
	fprintf(fpasm, "add esp, 4*%d\n", num_argumentos);
	fprintf(fpasm, "push dword eax\n");
}

void limpiarPila(FILE * fd_asm, int num_argumentos) {
	fprintf(fd_asm, "add esp, %d\n", 4 * num_argumentos);
}

void while_inicio(FILE * fpasm, int etiqueta){

	fprintf(fpasm, "_inicio_while_%d:\n", etiqueta);
}

void while_exp_pila (FILE * fpasm, int exp_es_variable, int etiqueta){
	fprintf(fpasm, "\tpop eax\n");
	
	if(exp_es_variable)
		fprintf(fpasm, "\tmov eax, dword [eax]\n");
	
	fprintf(fpasm, "\tcmp eax, 0\n");
	fprintf(fpasm, "\tje near _fin_while_%d\n", etiqueta);
}

void while_fin( FILE * fpasm, int etiqueta){
	fprintf(fpasm, "\tjmp near _inicio_while_%d\n", etiqueta);
	fprintf(fpasm, "_fin_while_%d:\n", etiqueta);
}

void escribir_elemento_vector(FILE * fpasm, char * nombre_vector, 
                   int tam_max, int exp_es_direccion){
	
	fprintf(fpasm, "\tpop dword eax\n");
	
	if (exp_es_direccion)
   		fprintf(fpasm, "\tmov dword eax , [eax]\n");

	fprintf(fpasm, "\tcmp eax,0\n");
	fprintf(fpasm, "\tjl near error_vector\n");
	fprintf(fpasm, "\tcmp eax, %d\n", tam_max -1);
	fprintf(fpasm, "\tjg near error_vector\n");
	fprintf(fpasm, "\tmov dword edx, _%s\n", nombre_vector);
	fprintf(fpasm, "\tlea eax, [edx + eax*4]\n");
	fprintf(fpasm, "\tpush dword eax\n");
}


/******************* NUEVAS OO *********************************************/
char * claseATabla(char * nombre_fuente_clase){
	char* ret;
	if(!nombre_fuente_clase) return NULL;

	ret = (char*) malloc(sizeof(char)*(strlen(nombre_fuente_clase)+strlen(PREFIJO_TABLA_METODOS_SOBREESCRIBIBLES)+1));
	if(!ret) return NULL;

	sprintf(ret, "%s%s", PREFIJO_TABLA_METODOS_SOBREESCRIBIBLES, nombre_fuente_clase);

	return ret; 	
}

void instance_of (FILE * fd_asm, char * nombre_fuente_clase, int numero_atributos_instancia){
	char* nombre_final;
	/*Meto el espacio que quiero reservar*/
	fprintf(fd_asm, "\tpush %d\n", numero_atributos_instancia*4);

	fprintf(fd_asm, "\tcall malloc\n");

	/*Restauro la pila*/
	fprintf(fd_asm, "\tadd esp, 4\n");

	/*Meto la direccion que ha devuelto malloc en eax en la pila*/
	fprintf(fd_asm, "\tpush eax\n");

	nombre_final = claseATabla(nombre_fuente_clase);
	/*Hacemos que esa direccion apunte a la tabla de metodos sobreescribibles de la clase*/
	fprintf(fd_asm, "\tmov dword [eax], %s\n", nombre_final);

	free(nombre_final);
	return;

}
void discardPila (FILE * fd_asm){
	/*Como la direccion de la instancia esta ya en la cima de la pila llamo directamente a free*/
	fprintf(fd_asm, "\tpop dword eax\n");
	fprintf(fd_asm, "\tmov dword ebx, [eax]\n");
	fprintf(fd_asm, "\tpush dword [eax]\n");
	fprintf(fd_asm, "\tcall free\n");
	fprintf(fd_asm, "\tadd esp, 4\n");
	return;
}

void llamarMetodoSobreescribibleCualificadoInstanciaPila(FILE * fd_asm, char * nombre_metodo){
	/*Sacamos de pila la direccion de lo que cualifica*/
	fprintf(fd_asm, "\tpop dword ebx\n");

	/*Hacemos ebx apuntar al comienzo de la tabla de metodos sobreescribibles*/
	fprintf(fd_asm, "\tmov dword ebx, [ebx]\n");
	fprintf(fd_asm, "\tmov dword ebx, [ebx]\n");

	/*Sumamos el offset de la tabla de simbolos y el del metodo*/
	printf("--------------->_offset_%s\n", nombre_metodo);
	fprintf(fd_asm, "\tmov dword ecx, [_offset_%s]\n", nombre_metodo);
	fprintf(fd_asm, "\tlea ecx, [ebx+ecx]\n");

	/*Accedemos a la direccion real del metodo*/
	fprintf(fd_asm, "\tmov ecx, [ecx]\n");

	/*Lo llamamos*/
	fprintf(fd_asm, "\tcall ecx\n");

	return;
} 

void accederAtributoInstanciaDePila(FILE * fd_asm, char * nombre_atributo){
	/*Sacamos de pila la direccion de lo que cualifica*/
	fprintf(fd_asm, "\tpop dword ebx\n");

	/*Apuntamos al offset del atributo de la isntancia sumando el de la instancia con el del atributo*/
	fprintf(fd_asm, "\tmov dword ecx, [_offset_%s]\n", nombre_atributo);
	fprintf(fd_asm, "\tlea ecx, [ebx+ecx]\n");

	/*Dejo la direccion en la pila*/
	fprintf(fd_asm, "\tpush ecx\n");

}

// ESTA FUNCIÓN ES LA QUE SE USA DESPUÉS DE 
// - escribir_operando (para una variable global)
// - escribirParametro 
// - escribirVariableLocal
void asignarDestinoEnPila(FILE* fd_asm, int es_variable){

	/*Cargamos la direccion donde hay que dejarlo*/
	fprintf(fd_asm, "\tpop dword eax\n");

	/*Cargamos el valor a asignar*/
	fprintf(fd_asm, "\tpop dword ebx\n");
	if (es_variable) fprintf(fd_asm, "\tmov dword ebx, [ebx]\n");

	/*Asignamos el valor*/
	fprintf(fd_asm, "\tmov [eax], ebx\n");

	return;
}