#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include "hash_table.h"
#include "tsa.h"


tsa* init_tsa(char* name){
	tsa* tsam;
	tsam = (tsa*) malloc(sizeof(tsa));

	tsam->ambito = (char*)malloc(sizeof(char)*strlen(name));
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

/*En estos put manejaremos el hecho de que haya colisiones*/
void* ppal_put(tsa* tsa, char* key, void* data){
	return ht_put(tsa->ppal, key, data);
}

void* ppal_get(tsa* tsa, char* key){
	return ht_get(tsa->ppal, key);
}

void* ppal_remove(tsa* tsa, char* key){
	return ht_remove(tsa->ppal, key);
}

void* met_put(tsa* tsa, char* key, void* data){
	return ht_put(tsa->met, key, data);
}

void* met_get(tsa* tsa, char* key){
	return ht_get(tsa->met, key);
}

void* met_remove(tsa* tsa, char* key){
	return ht_remove(tsa->met, key);
}

int close_tsa(tsa* t){
	return OK;
}