#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tsc.h"
#include "generador_nasm.h"



int _get_metodos_sobreescribibles(tsc* t, tsa_elem *** ms_list){
	int i, j, index = 0, tsa_num_elem;
	tsa_elem ** elem_list;
	if(!t) return ERROR;

	/*Por linealizacion se que se meteran primero los primeros declarados*/
	for(i=0; i<t->grafo->vertex_count; i++){
		tsa_num_elem = t->grafo->nodes[i]->tsa->ppal->e_num;
		elem_list = (tsa_elem **) malloc(sizeof(tsa_elem*)*tsa_num_elem);
		if(!elem_list) return ERROR;
		ht_list_values(t->grafo->nodes[i]->tsa->ppal, (void*)elem_list, tsa_num_elem);
		for(j=0; j<tsa_num_elem; j++){
			if(elem_list[j]->categoria == METODO_SOBREESCRIBIBLE){
				if(index==0){
					*ms_list = (tsa_elem**) malloc(sizeof(tsa_elem*));
					if(!(*ms_list)) return ERROR;
					(*ms_list)[index] = elem_list[j];
					index++;
				}else{
					*ms_list = (tsa_elem**) realloc(*ms_list, sizeof(tsa_elem*)*(index+1));
					if(!(*ms_list)) return ERROR;
					(*ms_list)[index] = elem_list[j];
					index++;
				}
			}
		}
	}
	return index;
}

int _get_metodos_sobreescribibles_sin_repeticion(tsc* t, tsa_elem *** ms_list){
	tsa_elem ** aux_list;
	char* symbol_name1, *symbol_name2, *pref;
	int i, j, new_index = 0, flag = 0, index = _get_metodos_sobreescribibles(t, ms_list);

	for (i=0; i<index; i++, flag=0){
		_parse_symbol((*ms_list)[i]->id, &pref, &symbol_name1);
		for(j=new_index; j>=0; j--){
			_parse_symbol(aux_list[j]->id, &pref, &symbol_name2);
			if(!strcmp(symbol_name1, symbol_name2)){
				flag = 1;/*Se activa cuando ya estaba incluido*/
				break;
			}

		}
		if(!flag){/*Entonces lo añadimos, sabemos que es el primero declarado por linealizacion*/
			if(new_index = 0){
				aux_list = (tsa_elem**) malloc(sizeof(tsa_elem*));
				if(!(*ms_list)) return ERROR;
				(aux_list)[new_index] = (*ms_list)[j];
				new_index++;
			}else{
				aux_list = (tsa_elem**) realloc(aux_list, sizeof(tsa_elem*)*(new_index+1));
				if(!(aux_list)) return ERROR;
				aux_list[index] = (*ms_list)[j];
				new_index++;
			}
		}
	}
	free(*ms_list);
	*ms_list = aux_list;
	return new_index;


}


/******************* NUEVAS OO *********************************************/
char * claseATabla(char * nombre_fuente_clase){
	char* ret;
	if(!nombre_fuente_clase) return NULL;

	ret = (char*) malloc(sizeof(char)*(strlen(nombre_fuente_clase)+strlen(PREFIJO_TABLA_METODOS_SOBREESCRIBIBLES)+1));
	if(!ret) return NULL;

	spfintf(ret, "%s%s", PREFIJO_TABLA_METODOS_SOBREESCRIBIBLES, nombre_fuente_clase);

	return ret; 	
}

void instance_of (FILE * fd_asm, char * nombre_fuente_clase, int numero_atributos_instancia){
	/*TODO: para que se necesita el nombre de la clase?*/

	/*Meto el espacio que quiero reservar TODO: Hay que multiplicarlo por algo o algo asi?*/
	fprintf(fpasm, "\tpush %d\n", numero_atributos_instancia);

	fprintf(fpasm, "\tcall malloc\n");

	/*Restauro la pila*/
	fprintf(fpasm, "\tadd esp, 4\n");

	/*Meto la direccion que ha devuelto malloc en eax en la pila*/
	fprintf(fpasm, "\tpush eax\n");

	//TODO: no se si queda algo mas por hacer en cuanto a la pila
	return;

}
void discardPila (FILE * fd_asm); /*TODO*/
void llamarMetodoSobreescribibleCualificadoInstanciaPila(FILE * fd_asm, char * nombre_metodo){
	/*Cojo de la pila la direccion de lo que cualifica*/
	fprintf(fpasm, "\tpop dword eax\n");

	/*TODO: Ahora entiendo que hay que concatenar el offset de lo que cualifica con el offset del metodo*/



	//TODO: no se si queda algo mas por hacer en cuanto a la pila
	return;
} 
void limpiarPila(FILE * fd_asm, int num_argumentos); /*TODO*/
void accederAtributoInstanciaDePila(FILE * fd_asm, char * nombre_atributo);/*TODO*/
// ESTA FUNCIÓN ES LA QUE SE USA DESPUÉS DE 
// - escribir_operando (para una variable global)
// - escribirParametro 
// - escribirVariableLocal
void asignarDestinoEnPila(FILE* fpasm, int es_variable){
	/*Cargamos el valor a asignar*/
	fprintf(fpasm, "\tpop dword eax\n");
	if (es_variable) fprintf(fpasm, "\tmov dword eax, [eax]\n");

	/*Cargamos la direccion donde hay que dejarlo*/
	fprintf(fpasm, "\tpop dword edx\n");

	/*Asignamos el valor*/
	fprintf(fpasm, "\tmov [edx], eax\n");

	//TODO: no se si queda algo mas por hacer en cuanto a la pila
	return;
}
