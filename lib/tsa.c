#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tsa.h"


tsa* init_tsa(char* name){
	tsa* tsa;
	tsa = (tsa*) malloc(sizeof(tsa));

	tsa->ambito = (char*)malloc(sizeof(char)*strlen(name))
	strcpy(tsa->ambito, name)

	tsa->ppal = ht_create(TSA_TAM);
	tsa->met = ht_create(TSA_TAM);

	return tsa;
}

void free_tsa(tsa* tsa){

	ht_destroy(tsa->ppal);
	ht_destroy(tsa->met);

	free(tsa->ambito);
	free(tsa);
}

void* ppal_put(tsa* tsa, char* key, void* data){
	return ht_put(tsa->ppal, key, data);
}

void* ppal_get(tsa* tsa, char* key){
	return ht_put(tsa->ppal, key);
}

void* ppal_remove(tsa* tsa, char* key){
	return ht_remove(tsa->ppal, key);
}

void* met_put(tsa* tsa, char* key, void* data){
	return ht_put(tsa->met, key, data);
}

void* met_get(tsa* tsa, char* key){
	return ht_put(tsa->met, key);
}

void* met_remove(tsa* tsa, char* key){
	return ht_remove(tsa->met, key);
}