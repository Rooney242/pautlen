#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "macros.h"
#include "tsa.h"
#include "hash_table.h"
#include "casos.h"


int	print_error(FILE* pf, int error, char* id, char* ambito_desde, tsa* ambito_encontrado, tsa_elem* elem){
	if(!pf) return ERROR;

	switch(error){
		case ERROR:
			fprintf(pf, "HA HABIDO UN ERROR.\n");
			break;
		case ERROR_20:
			fprintf(pf, "CASO 20 -- OK\n"
				"-->Elemento %s en buscarIdNoCualificado desde (%s) ENCONTRADO en main.\n", id, ambito_desde);
			break;
		case ERROR_21:
			fprintf(pf, "hola\n");
			break;
		default:
			fprintf(pf, "ME HA LLEGADO ALGO QUE NO SE LO QUE ES HULIO.\n");
			break;
	}
}