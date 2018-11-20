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
/*Realiza las operaciones de cierre necesarias para que la tabla de simbolos de clases quede consistente.
	En nuestro caso de momento nada*/
int close_tsa(tsa* t);


void* ppal_put(tsa* tsa, char* key, tsa_elem* data);
tsa_elem* ppal_get(tsa* tsa, char* key);
void* ppal_remove(tsa* tsa, char* key);
void* met_put(tsa* tsa, char* key, tsa_elem* data);
tsa_elem* met_get(tsa* tsa, char* key);
void* met_remove(tsa* tsa, char* key);

/********************************************************************************************/

int open_scope_met(tsa* t, char* id_ambito, int categoria, int tipo_acceso, int tipo_miembro, int posicion_metodo_sobreescribible, int tamanio);

int close_scope_met(tsa* t, char* id_ambito);

int open_scope_class(tsa* t, char* id_clase, int tamanio, int tipo);

int close_scope_class(tsa* t, char*id_clase);

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
	int * tipo_args);
#endif
