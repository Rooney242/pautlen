#ifndef CASOS_H
#define CASOS_H

#include "tsa.h"
#include "hash_table.h"

#define ERROR_20 -20
#define ERROR_21 -21


int	print_error(FILE* pf, int error, char* id, char* ambito_desde, tsa* ambito_encontrado, tsa_elem* elem);

#endif