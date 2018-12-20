#ifndef OUTPUT_H
#define OUTPUT_H

#include "tsa.h"
#include "tsc.h"
#include "hash_table.h"


int	print_caso(FILE* pf, int caso, int es_declarar, char* ambito_desde, tsa* ambito_encontrado, tsa_elem* elem);
int print_hash_table_from_class(FILE* pf, tsc* p_tsc, char* id_clase);
int print_hash_table_from_met(FILE* pf, tsc* p_tsc, char* id_clase, char* metodo);
int print_command(FILE* pf, char* command, int salto_de_linea);



#endif