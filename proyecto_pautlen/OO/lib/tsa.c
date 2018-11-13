#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include "hash_table.h"
#include "tsa.h"


tsa* init_tsa(char* name){
	tsa* tsam;
	tsam = (tsa*) malloc(sizeof(tsa));

	tsam->ambito = (char*)malloc(sizeof(char)*(strlen(name)+1));
	strcpy(tsam->ambito, name);

	tsam->ppal = ht_create(TSA_TAM);
	tsam->met = ht_create(TSA_TAM);

	return tsam;
}

void free_tsa(tsa* tsa){

	ht_destroy(tsa->ppal);
	ht_destroy(tsa->met);

	free(tsa->ambito);
	free(tsa);
}

int close_tsa(tsa* t){
	return OK;
}

/*En estos put manejaremos el hecho de que haya colisiones*/
void* ppal_put(tsa* tsa, char* key, tsa_elem* data){
	return ht_put(tsa->ppal, key, data);
}

tsa_elem* ppal_get(tsa* tsa, char* key){
	return get_tsa_elem(tsa->ppal, key);
}

void* ppal_remove(tsa* tsa, char* key){
	return ht_remove(tsa->ppal, key);
}

void* met_put(tsa* tsa, char* key, tsa_elem* data){
	return ht_put(tsa->met, key, data);
}

tsa_elem* met_get(tsa* tsa, char* key){
	return ht_get(tsa->met, key);
}

int met_restore(tsa* tsa){
	ht_clear(tsa->met, TRUE);
	return OK;
}

void* met_remove(tsa* tsa, char* key){
	return ht_remove(tsa->met, key);
}

/***************************************************************************************/

/*TODO: nombres de los ambitos y de los simbolos*/

/*Abre el ambito de un metodo dentro de una clase*/
int open_scope_met(tsa* t, char* id_ambito, int categoria, int tipo_acceso, int tipo_miembro, int posicion_metodo_sobreescribible, int tamanio){
	if(!t || !id_ambito) return ERROR;
	tsa_elem* elem;
	elem = init_tsa_elem();
	if(!elem) return ERROR;

	elem->categoria = categoria;
	elem->tipo_acceso = tipo_acceso;
	elem->tipo_miembro = tipo_miembro;
	elem->posicion_metodo_sobreescribible = posicion_metodo_sobreescribible;
	elem->tamanio = tamanio;

	if(!ppal_put(t, id_ambito, elem)) return ERROR;

	if(!met_put(t, id_ambito, elem)) return ERROR;

	return OK;


}

/*Se realizan los cambios necesarios para actualizar el ambito y se limpia la tabla hash auxiliar*/
int close_scope_met(tsa* t, char*id_ambito){
	if(!t || !id_ambito) return ERROR;

	met_remove(t, id_ambito);
	met_restore(t);

	tsa_elem* elem;
	elem = ppal_get(t, id_ambito);
	if(!elem) return ERROR;
	
	if(elem->simbolo_cerrado == TRUE) return ERROR;
	elem->simbolo_cerrado = TRUE;

	return OK;
}

/*Abre el ambito de una clase. En principio solo se usa en el main*/
int open_scope_class(tsa* t, char* id_clase, int tamanio, int tipo){
	if(!t || !id_clase) return ERROR;
	tsa_elem* elem;

	elem = init_tsa_elem();
	if(!elem) return ERROR;

	elem->tamanio = tamanio;
	elem->tipo = tipo;

	if(!ppal_put(t, id_clase, elem)) return ERROR;

	return OK;


}

/*Se realizan los cambios necesarios para actualizar el ambito*/
int close_scope_class(tsa* t, char* id_clase){
	if(!t || !id_clase) return ERROR;

	tsa_elem* elem;
	elem = ppal_get(t, id_clase);
	if(!elem) return ERROR;
	
	if(elem->simbolo_cerrado == TRUE) return ERROR;
	elem->simbolo_cerrado = TRUE;

	return OK;
}


/*Inserta un simbolo nuevo en la tabla principal*/
int insert_symbol(tsa* t, char* simbolo, int categoria, int tipo,						int estructura,
	int direcciones,					int numero_parametros,
	int numero_variables_locales,		int posicion_variable_local,
	int posicion_parametro,			int dimension,
	int tamanio,					int filas,
	int columnas,					int capacidad,
	int numero_atributos_clase,			int numero_atributos_instancia,
	int numero_metodos_sobreescribibles,	int numero_metodos_no_sobreescribibles,
	int tipo_acceso,  				int tipo_miembro, 
	int posicion_atributo_instancia,		int posicion_metodo_sobreescribible,
	int num_acumulado_atributos_instancia,	int num_acumulado_metodos_sobreescritura,
	int posicion_acumulada_atributos_instancia,
	int posicion_acumulada_metodos_sobreescritura,
	int * tipo_args){


	tsa_elem* elem;
	if(!t || !simbolo) return ERROR;

	elem = init_tsa_elem();
	if(!elem) return ERROR;
	set_tsa_elem(elem, categoria, tipo,	estructura,
	direcciones,					 numero_parametros,
	numero_variables_locales,		posicion_variable_local,
	posicion_parametro,			dimension,
	tamanio,					filas,
	columnas,					capacidad,
	numero_atributos_clase,		numero_atributos_instancia,
	numero_metodos_sobreescribibles,	numero_metodos_no_sobreescribibles,
	tipo_acceso,  				tipo_miembro, 
	posicion_atributo_instancia,		posicion_metodo_sobreescribible,
	num_acumulado_atributos_instancia,	num_acumulado_metodos_sobreescritura,
	posicion_acumulada_atributos_instancia,
	posicion_acumulada_metodos_sobreescritura,
	tipo_args, TRUE);
	if(!ppal_put(t, simbolo, elem)) return ERROR;
	return OK;

}
