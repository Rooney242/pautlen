#ifndef HASH_H
#define HASH_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inititalize hashtable iterator on hashtable 'ht'
#define HT_ITERATOR(ht) {ht, 0, ht->table[0]}

typedef struct { //TODO: añadir clase
	int categoria; /* VARIABLE PARAMETRO FUNCION CLASE 
	METODO_SOBREESCRIBIBLE METODO_NO_SOBREESCRIBIBLE 
	ATRIBUTO_CLASE ATRIBUTO_INSTANCIA */
	int tipo;/* INT FLOAT (no este curso) BOOLEAN Y PARA LAS 
	CLASES, ALGÚN MECANISMO (-índice en el vector del 
	grafo??)  */	    
	int estructura; 
	int direcciones;        /* >=1  SI ES VARIABLE 1*/
	int numero_parametros;  /* >=0 */
	int numero_variables_locales;	/* >=0 */
	int posicion_variable_local;	/* >=1 */
	int posicion_parametro;			/* >=0 */
	int dimension;		/* 1,2 (no este curso) */
	int tamanio;		/* 1-64 */
	int filas;			/* 1-64 (no este curso) */
	int columnas;		/* 1-64 (no este curso)*/
	int capacidad;		/* 1-64 (no este curso) */
	/* INFORMACION PARA CLASES */
	int numero_atributos_clase;
	int numero_atributos_instancia;
	int numero_metodos_sobreescribibles;
	int numero_metodos_no_sobreescribibles;
	int tipo_acceso;/*NINGUNO (exposed) ACCESO_CLASE (hidden) 
	ACCESO_HERENCIA	(secret) ACCESO_TODOS (exposed) */
	int tipo_miembro;/*MIEMBRO_UNICO (unique) MIEMBRO_NO_UNICO*/
	int posicion_atributo_instancia;
	int posicion_metodo_sobreescribible;
	int num_acumulado_atributos_instancia;
	int num_acumulado_metodos_sobreescritura;
	int posicion_acumulada_atributos_instancia;
	int posicion_acumulada_metodos_sobreescritura;
	int * tipo_args;
	int simbolo_cerrado;
   
}tsa_elem;


//Hashtable element structure
typedef struct hash_elem_t {
	struct hash_elem_t* next; // Next element in case of a collision
	tsa_elem* data;	// Pointer to the stored element
	char key[]; 	// Key of the stored element
}hash_elem_t;

//Hashtable structure
typedef struct  hashtable_t{
	unsigned int capacity;	// Hashtable capacity (in terms of hashed keys)
	unsigned int e_num;	// Number of element currently stored in the hashtable
	hash_elem_t** table;	// The table containaing elements
}hashtable_t;

//Structure used for iterations
typedef struct  hash_elem_it{
	hashtable_t* ht; 	// The hashtable on which we iterate
	unsigned int index;	// Current index in the table
	hash_elem_t* elem; 	// Curent element in the list
}hash_elem_it;



/* 	Internal funcion to calculate hash for keys.
	It's based on the DJB algorithm from Daniel J. Bernstein.
	The key must be ended by '\0' character.*/
static unsigned int ht_calc_hash(char* key);

/* 	Create a hashtable with capacity 'capacity'
	and return a pointer to it*/
hashtable_t* ht_create(unsigned int capacity);

/* 	Store data in the hashtable. If data with the same key are already stored,
	they are overwritten, and return by the function. Else it return NULL.
	Return HT_ERROR if there are memory alloc error*/
void* ht_put(hashtable_t* hasht, char* key, tsa_elem* data);

/* Retrieve data from the hashtable */
tsa_elem* ht_get(hashtable_t* hasht, char* key);

/* 	Remove data from the hashtable. Return the data removed from the table
	so that we can free memory if needed */
tsa_elem* ht_remove(hashtable_t* hasht, char* key);

/* List keys. k should have length equals or greater than the number of keys */
void ht_list_keys(hashtable_t* hasht, char** k, size_t len);

/* 	List values. v should have length equals or greater 
	than the number of stored elements */
void ht_list_values(hashtable_t* hasht, void** v, size_t len);

/* Iterate through table's elements. */
hash_elem_t* ht_iterate(hash_elem_it* iterator);

/* Iterate through keys. */
char* ht_iterate_keys(hash_elem_it* iterator);

/* Iterate through values. */
void* ht_iterate_values(hash_elem_it* iterator);

/* 	Removes all elements stored in the hashtable.
	if free_data, all stored datas are also freed.*/
void ht_clear(hashtable_t* hasht, int free_data);

/* 	Destroy the hash table, and free memory.
	Data still stored are freed*/
void ht_destroy(hashtable_t* hasht);

/************************************************************************************************************/

/*Funciones de los elementos de la TSA. De momento sin control de errorres*/
tsa_elem* init_tsa_elem();
void free_tsa_elem(tsa_elem* elem);
tsa_elem* set_tsa_elem(tsa_elem* elem, int categoria, int tipo,						int estructura,
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
	int * tipo_args, int simbolo_cerrado);

tsa_elem* get_tsa_elem(hashtable_t* table, char* clave);



#endif