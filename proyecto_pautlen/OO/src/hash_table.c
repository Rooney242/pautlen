#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "macros.h"
#include "hash_table.h"

char err_ptr;
void* HT_ERROR = &err_ptr; // Data pointing to HT_ERROR are returned in case of error

/* 	Internal funcion to calculate hash for keys.
	It's based on the DJB algorithm from Daniel J. Bernstein.
	The key must be ended by '\0' character.*/
static unsigned int ht_calc_hash(char* key)
{
	unsigned int h = 5381;
	while(*(key++))
		h = ((h << 5) + h) + (*key);
	return h;
}

/* 	Create a hashtable with capacity 'capacity'
	and return a pointer to it*/
hashtable_t* ht_create(unsigned int capacity)
{
	hashtable_t* hasht = malloc(sizeof(hashtable_t));
	if(!hasht)
		return NULL;
	if((hasht->table = malloc(capacity*sizeof(hash_elem_t*))) == NULL)
	{
		free(hasht->table);
		return NULL;
	}
	hasht->capacity = capacity;
	hasht->e_num = 0;
	unsigned int i;
	for(i = 0; i < capacity; i++)
		hasht->table[i] = NULL;
	return hasht;
}

/* 	Store data in the hashtable. If data with the same key are already stored,
	we return NULL. Else it return NULL.
	Return HT_ERROR if there are memory alloc error*/
void* ht_put(hashtable_t* hasht, char* key, tsa_elem* data)
{
	if(data == NULL)
		return NULL;
	unsigned int h = ht_calc_hash(key) % hasht->capacity;
	hash_elem_t* e = hasht->table[h];

	while(e != NULL)
	{
		if(!strcmp(e->key, key))
		{
			if(e->data->simbolo_cerrado) return NULL;
			e->data = data;
			return e;
		}
		e = e->next;
	}
	// Getting here means the key doesn't already exist

	if((e = malloc(sizeof(hash_elem_t)+strlen(key)+1)) == NULL)
		return HT_ERROR;
	strcpy(e->key, key);
	e->data = data;

	// Add the element at the beginning of the linked list
	e->next = hasht->table[h];
	hasht->table[h] = e;
	hasht->e_num ++;

	return e;
}

/* Retrieve data from the hashtable */
tsa_elem* ht_get(hashtable_t* hasht, char* key)
{
	unsigned int h = ht_calc_hash(key) % hasht->capacity;
	hash_elem_t* e = hasht->table[h];
	while(e != NULL)
	{
		if(!strcmp(e->key, key))
			return e->data;
		e = e->next;
	}
	return NULL;
}

/* 	Remove data from the hashtable. Return the data removed from the table
	so that we can free memory if needed */
tsa_elem* ht_remove(hashtable_t* hasht, char* key)
{
	unsigned int h = ht_calc_hash(key) % hasht->capacity;
	hash_elem_t* e = hasht->table[h];
	hash_elem_t* prev = NULL;
	while(e != NULL)
	{
		if(!strcmp(e->key, key))
		{
			void* ret = e->data;
			if(prev != NULL)
				prev->next = e->next;
			else
				hasht->table[h] = e->next;
			free(e);
			e = NULL;
			hasht->e_num --;
			return ret;
		}
		prev = e;
		e = e->next;
	}
	return NULL;
}

/* List keys. k should have length equals or greater than the number of keys */
void ht_list_keys(hashtable_t* hasht, char** k, size_t len)
{
	if(len < hasht->e_num)
		return;
	int ki = 0; //Index to the current string in **k
	int i = hasht->capacity;
	while(--i >= 0)
	{
		hash_elem_t* e = hasht->table[i];
		while(e)
		{
			k[ki++] = e->key;
			e = e->next;
		}
	}
}

/* 	List values. v should have length equals or greater 
	than the number of stored elements */
void ht_list_values(hashtable_t* hasht, void** v, size_t len)
{
	if(len < hasht->e_num)
		return;
	int vi = 0; //Index to the current string in **v
	int i = hasht->capacity;
	while(--i >= 0)
	{
		hash_elem_t* e = hasht->table[i];
		while(e)
		{
			v[vi++] = e->data;
			e = e->next;
		}
	}
}

/* Iterate through table's elements. */
hash_elem_t* ht_iterate(hash_elem_it* iterator)
{
	while(iterator->elem == NULL)
	{
		if(iterator->index < iterator->ht->capacity - 1)
		{
			iterator->index++;
			iterator->elem = iterator->ht->table[iterator->index];
		}
		else
			return NULL;
	}
	hash_elem_t* e = iterator->elem;
	if(e)
		iterator->elem = e->next;
	return e;
}

/* Iterate through keys. */
char* ht_iterate_keys(hash_elem_it* iterator)
{
	hash_elem_t* e = ht_iterate(iterator);
	return (e == NULL ? NULL : e->key);
}

/* Iterate through values. */
void* ht_iterate_values(hash_elem_it* iterator)
{
	hash_elem_t* e = ht_iterate(iterator);
	return (e == NULL ? NULL : e->data);
}

/* 	Removes all elements stored in the hashtable.
	if free_data, all stored datas are also freed.*/
void ht_clear(hashtable_t* hasht, int free_data)
{
	hash_elem_it it = HT_ITERATOR(hasht);
	char* k = ht_iterate_keys(&it);
	while(k != NULL)
	{
		if(free_data){
			free_tsa_elem(ht_remove(hasht, k));
		}else{
			ht_remove(hasht, k);
		}
		//free_data ? free_tsa_elem(ht_remove(hasht, k)) : ht_remove(hasht, k);
		k = ht_iterate_keys(&it);
	}
}

/* 	Destroy the hash table, and free memory.
	Data still stored are freed*/
void ht_destroy(hashtable_t* hasht)
{
	ht_clear(hasht, 1); // Delete and free all.
	free(hasht->table);
	free(hasht);
}


/*Funciones de los elementos de la TSA. De momento sin control de errorres*/

tsa_elem* init_tsa_elem(){
	tsa_elem* elem;
	elem = (tsa_elem*) malloc(sizeof(tsa_elem));
	if(!elem) return NULL;
	elem->categoria = 0;
	elem->tipo = 0;
	elem->clase = 0;
	elem->estructura = 0;
	elem->direcciones = 0;
	elem->numero_parametros = 0;
	elem->numero_variables_locales = 0;
	elem->posicion_variable_local = 0;
	elem->posicion_parametro = 0;
	elem->dimension = 0;
	elem->tamanio = 0;
	elem->filas = 0;
	elem->columnas = 0;
	elem->capacidad = 0;
	elem->numero_atributos_clase = 0;
	elem->numero_atributos_instancia = 0;
	elem->numero_metodos_sobreescribibles = 0;
	elem->numero_metodos_no_sobreescribibles = 0;
	elem->tipo_acceso = 0;
	elem->tipo_miembro = 0;
	elem->posicion_atributo_instancia = 0;
	elem->posicion_metodo_sobreescribible = 0;
	elem->num_acumulado_atributos_instancia = 0;
	elem->num_acumulado_metodos_sobreescritura = 0;
	elem->posicion_acumulada_atributos_instancia = 0;
	elem->posicion_acumulada_metodos_sobreescritura = 0;
	elem->tipo_args = NULL;
	elem->simbolo_cerrado = FALSE;

	return elem;
}

void free_tsa_elem(tsa_elem* elem){
	if(elem) free(elem);
}


tsa_elem* set_tsa_elem(tsa_elem* elem, char* id, int categoria, int tipo, int clase,		int estructura,
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
	int * tipo_args, int simbolo_cerrado){
		if(!elem) return NULL;

		strcpy(elem->id, id);
		elem->categoria = categoria;
		elem->tipo = tipo;
		elem->clase = clase;
		elem->estructura = estructura;
		elem->direcciones = direcciones;
		elem->numero_parametros = numero_parametros;
		elem->numero_variables_locales = numero_variables_locales;
		elem->posicion_variable_local = posicion_variable_local;
		elem->posicion_parametro = posicion_parametro;
		elem->dimension = dimension;
		elem->tamanio = tamanio;
		elem->filas = filas;
		elem->columnas = columnas;
		elem->capacidad = capacidad;
		elem->numero_atributos_clase = numero_atributos_clase;
		elem->numero_atributos_instancia = numero_atributos_instancia;
		elem->numero_metodos_sobreescribibles = numero_metodos_sobreescribibles;
		elem->numero_metodos_no_sobreescribibles = numero_metodos_no_sobreescribibles;
		elem->tipo_acceso = tipo_acceso;
		elem->tipo_miembro = tipo_miembro;
		elem->posicion_atributo_instancia = posicion_atributo_instancia;
		elem->posicion_metodo_sobreescribible = posicion_metodo_sobreescribible;
		elem->num_acumulado_atributos_instancia = num_acumulado_atributos_instancia;
		elem->num_acumulado_metodos_sobreescritura = num_acumulado_metodos_sobreescritura;
		elem->posicion_acumulada_atributos_instancia = posicion_acumulada_atributos_instancia;
		elem->posicion_acumulada_metodos_sobreescritura = posicion_acumulada_metodos_sobreescritura;
		elem->tipo_args = tipo_args;
		elem->simbolo_cerrado = simbolo_cerrado;

		return elem;
}

tsa_elem* get_tsa_elem(hashtable_t* table, char* clave){
	return ht_get(table, clave); 
}

int put_tsa_elem(hashtable_t* table, char* clave, tsa_elem* elem){
	if(!ht_put(table, clave, elem)) return ERROR;
}

char * _print_info(tsa_elem* elem){
	char tipo[16], clase[16], acceso[16], miembro[32];
	char *ret;
	switch(elem->tipo){
		case INT:
			strcpy(tipo, "ENTERO");
			break;
		case FLOAT: 
			strcpy(tipo, "FLOAT");
			break;
		default:
			strcpy(tipo, "DESCONOCIDO");
			break;
	}
	switch(elem->clase){
		case ESCALAR:
			strcpy(clase,"ESCALAR");
			break;
		case PUNTERO:
			strcpy(clase,"PUNTERO");
			break;
		case VECTOR:
			strcpy(clase,"VECTOR");
			break;
		case CONJUNTO:
			strcpy(clase,"CONJUNTO");
			break;
		default:
			strcpy(clase, "DESCONOCIDO");
			break;
	}
	switch(elem->tipo_acceso){
		case NINGUNO:
			strcpy(acceso, "NINGUNO");
			break;
		case HIDDEN: 
			strcpy(acceso, "HIDDEN");
			break;
		case EXPOSED: 
			strcpy(acceso, "EXPOSED");
			break;
		case SECRET: 
			strcpy(acceso, "SECRET");
			break;
		default:
			strcpy(acceso, "DESCONOCIDO");
			break;
	}
	switch(elem->tipo_miembro){
		case MIEMBRO_UNICO:
			strcpy(miembro, "MIEMBRO_UNICO");
			break;
		case MIEMBRO_NO_UNICO: 
			strcpy(miembro, "MIEMBRO_NO_UNICO");
			break;
		default:
			strcpy(miembro, "DESCONOCIDO");
			break;
	}
	ret = (char*) malloc(sizeof(char)*(strlen(tipo)+strlen(clase)+strlen(acceso)+strlen(miembro)+100));//41

	sprintf(ret, "CLASE: %s\tTIPO: %s\tDIR: %d\tACCESO: %s\tMIEMBRO: %s\t",
		clase, tipo, elem->direcciones, acceso, miembro);
	return ret;

}

int print_tsa_elem(hashtable_t* table, char* clave, FILE* pf){
	tsa_elem* elem;
	char* elem_info;
	if(!table || !clave || !pf) return ERROR;
	elem = get_tsa_elem(table, clave);
	if (!elem) return ERROR;
	fprintf(pf, "****************Posicion %u ******************\n", ht_calc_hash(clave) % table->capacity);
	elem_info = _print_info(elem);
	switch(elem->categoria){
		case VARIABLE:
			fprintf(pf,"%s\tVARIABLE\tPOS LOCAL: %d\tPOS ATR INSTANCIA %d Y ACUMULADA %d\t%s\n",
				elem->id, elem->posicion_variable_local, elem->posicion_atributo_instancia,
				elem->posicion_acumulada_atributos_instancia, elem_info);
			break;
		case PARAMETRO:
			fprintf(pf,"%s\tPARAMETRO\tPOS PARAMETRO: %d\tPOS LOCAL %d\t%s\n",
				elem->id, elem->posicion_parametro, elem->posicion_variable_local, elem_info);
			break;
		case FUNCION:
			fprintf(pf,"%s\tFUNCION\t%s\n", elem->id, elem_info);
			break;
		case CLASE:
			fprintf(pf,"%s\tCLASE\tES CLASE CON %d ATR CLASE, %d ATR INSTANCIA, %d MET. SOBR. %d MET. NO SOBR. %d ACUM ATR INS Y %d ACUM MET SOBR.\t%s\n",
				elem->id, elem->numero_atributos_clase, elem->numero_atributos_instancia,
				elem->numero_metodos_sobreescribibles, elem->numero_metodos_no_sobreescribibles, 
				elem->num_acumulado_atributos_instancia , elem->num_acumulado_metodos_sobreescritura , elem_info);
			break;
		case METODO_SOBREESCRIBIBLE:
			fprintf(pf,"%s\tMETODO_SOBREESCRIBIBLE\tPOS METODO: %d\tY ACUMULADA %d\t%s\n",
				 elem->id, elem->posicion_metodo_sobreescribible, elem->posicion_acumulada_metodos_sobreescritura,
				 elem_info);
			break;
		case METODO_NO_SOBREESCRIBIBLE:
			fprintf(pf,"%s\tMETODO_SOBREESCRIBIBLE\t%s\n", elem->id, elem_info);
			break;
			break;
		case ATRIBUTO_CLASE:
			fprintf(pf,"%s\tATRIBUTO_CLASE\t%s\n", elem->id, elem_info);
			break;
		case ATRIBUTO_INSTANCIA:
			fprintf(pf,"%s\tATRIBUTO_INSTANCIA\tPOS ATR INSTANCIA %d Y ACUMULADA %d\t%s\n",
				 elem->id, elem->posicion_atributo_instancia,
				 elem->posicion_acumulada_atributos_instancia, elem_info);
			break;

	}
	free(elem_info);
	return OK;
}