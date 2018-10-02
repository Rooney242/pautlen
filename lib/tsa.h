#ifndef TSA_H
#define TSA_H

#include "hash_table.h"

#define TSA_TAM 1024

typedef struct {
	char * ambito;
	hashtable_t *ppal;
	hashtable_t *met;
}tsa;

tsa* init_tsa(char* name);
void free_tsa(tsa* tsa);

void* ppal_put(tsa* tsa, char* key, void* data);
void* ppal_get(tsa* tsa, char* key);
void* ppal_remove(tsa* tsa, char* key);
void* met_put(tsa* tsa, char* key, void* data);
void* met_get(tsa* tsa, char* key);
void* met_remove(tsa* tsa, char* key);

#endif
