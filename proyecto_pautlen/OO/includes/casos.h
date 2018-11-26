#ifndef CASOS_H
#define CASOS_H

#include "tsa.h"
#include "hash_table.h"

#define CASO_20 20/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_21 -21/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_22 22/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_23 -23/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_24 24/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_25 25/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_26 -26/*v7 BUSCAR ID NO CUALIFICADO*///////////////////////////////////////////////


#define CASO_49 -49/*v8 BUSCAR PARA DECLARAR MIEMBRO CLASE*/
#define CASO_50 50/*v8 BUSCAR PARA DECLARAR MIEMBRO CLASE*/
#define CASO_51 51/*v8 BUSCAR PARA DECLARAR MIEMBRO INSTANCIA*/
#define CASO_52 -52/*v8 BUSCAR PARA DECLARAR MIEMBRO INSTANCIA*/
#define CASO_53 -53/*v8 BUSCAR PARA DECLARAR MIEMBRO INSTANCIA*/



int	print_caso(FILE* pf, int caso, char* id, char* ambito_desde, tsa* ambito_encontrado, tsa_elem* elem);

#endif