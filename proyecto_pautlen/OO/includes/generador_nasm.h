#ifndef GENERADOR_NASM_H
#define GENERADOR_NASM_H


#define PREFIJO_TABLA_METODOS_SOBREESCRIBIBLES "_ms"


/******************* NUEVAS OO *********************************************/
char * claseATabla(char * nombre_fuente_clase);
void instance_of (FILE * fd_asm, char * nombre_fuente_clase, int numero_atributos_instancia); 
void discardPila (FILE * fd_asm);  
void llamarMetodoSobreescribibleCualificadoInstanciaPila(FILE * fd_asm, char * nombre_metodo); 
void limpiarPila(FILE * fd_asm, int num_argumentos); 
void accederAtributoInstanciaDePila(FILE * fd_asm, char * nombre_atributo);
// ESTA FUNCIÓN ES LA QUE SE USA DESPUÉS DE 
// - escribir_operando (para una variable global)
// - escribirParametro 
// - escribirVariableLocal
void asignarDestinoEnPila(FILE* fpasm, int es_variable);



#endif