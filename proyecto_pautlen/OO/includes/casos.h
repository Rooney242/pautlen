#ifndef CASOS_H
#define CASOS_H

#include "tsa.h"
#include "hash_table.h"

#define CASO_20 -20/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_22 -22/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_23 -23/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_21 -21/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_24 -24/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_25 -25/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_26 -26/*v7 BUSCAR ID NO CUALIFICADO*///////////////////////////////////////////////
#define CASO_27 -27/*v8*/
#define CASO_28 -28/*v8*/
#define CASO_29 -29/*v8*/
#define CASO_30 -30/*v8*/
#define CASO_31 -31/*v8*/
#define CASO_32 -32/*v8*/
#define CASO_33 -33/*v8*/
#define CASO_34 -34/*v8*/
#define CASO_35 -35/*v8*/
#define CASO_36 -36/*v8*/
#define CASO_37 -37/*v8*/
#define CASO_38 -38/*v8*/
#define CASO_39 -39/*v8*/
#define CASO_40 -40/*v8*/

#define CASO_42 -42/*v8*/
#define CASO_43 -43/*v8*/

#define CASO_45 -45/*v8*/
#define CASO_46 -46/*v8*/
#define CASO_47 -47/*v8*/

#define CASO_49 -49/*v8 BUSCAR PARA DECLARAR MIEMBRO CLASE*/
#define CASO_50 -50/*v8 BUSCAR PARA DECLARAR MIEMBRO CLASE*/
#define CASO_51 -51/*v8 BUSCAR PARA DECLARAR MIEMBRO INSTANCIA*/
#define CASO_52 -52/*v8 BUSCAR PARA DECLARAR MIEMBRO INSTANCIA*/
#define CASO_53 -53/*v8 BUSCAR PARA DECLARAR MIEMBRO INSTANCIA*/



int	print_caso(FILE* pf, int caso, char* id, char* ambito_desde, tsa* ambito_encontrado, tsa_elem* elem);

#endif