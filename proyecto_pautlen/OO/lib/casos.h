#ifndef CASOS_H
#define CASOS_H

#include "tsa.h"
#include "hash_table.h"

#define ERROR_20 -20/*v7 BUSCAR ID NO CUALIFICADO*/
#define ERROR_22 -22/*v7 BUSCAR ID NO CUALIFICADO*/
#define ERROR_23 -23/*v7 BUSCAR ID NO CUALIFICADO*/
#define ERROR_21 -21/*v7 BUSCAR ID NO CUALIFICADO*/
#define ERROR_24 -24/*v7 BUSCAR ID NO CUALIFICADO*/
#define ERROR_25 -25/*v7 BUSCAR ID NO CUALIFICADO*/
#define ERROR_26 -26/*v7 BUSCAR ID NO CUALIFICADO*///////////////////////////////////////////////
#define ERROR_27 -27/*v8*/
#define ERROR_28 -28/*v8*/
#define ERROR_29 -29/*v8*/
#define ERROR_30 -30/*v8*/
#define ERROR_31 -31/*v8*/
#define ERROR_32 -32/*v8*/
#define ERROR_33 -33/*v8*/
#define ERROR_34 -34/*v8*/
#define ERROR_35 -35/*v8*/
#define ERROR_36 -36/*v8*/
#define ERROR_37 -37/*v8*/
#define ERROR_38 -38/*v8*/
#define ERROR_39 -39/*v8*/
#define ERROR_40 -40/*v8*/

#define ERROR_42 -42/*v8*/
#define ERROR_43 -43/*v8*/

#define ERROR_45 -45/*v8*/
#define ERROR_46 -46/*v8*/
#define ERROR_47 -47/*v8*/

#define ERROR_49 -49/*v8 BUSCAR PARA DECLARAR MIEMBRO CLASE*/
#define ERROR_50 -50/*v8 BUSCAR PARA DECLARAR MIEMBRO CLASE*/
#define ERROR_51 -51/*v8 BUSCAR PARA DECLARAR MIEMBRO INSTANCIA*/
#define ERROR_52 -52/*v8 BUSCAR PARA DECLARAR MIEMBRO INSTANCIA*/
#define ERROR_53 -53/*v8 BUSCAR PARA DECLARAR MIEMBRO INSTANCIA*/



int	print_error(FILE* pf, int error, char* id, char* ambito_desde, tsa* ambito_encontrado, tsa_elem* elem);

#endif