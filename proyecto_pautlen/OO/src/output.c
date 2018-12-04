#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "macros.h"
#include "tsa.h"
#include "tsc.h"
#include "hash_table.h"
#include "output.h"


int	print_caso(FILE* pf, int caso, char* ambito_desde, tsa* ambito_encontrado, tsa_elem* elem){
	if(!pf) return ERROR;

	switch(caso){
		/************************BUSCAR ID NO CUALIFICADO************************/
		case ERROR:
			fprintf(pf, "CASO 20 -- OK\n"
				"-->Elemento %s en buscarIdNoCualificado desde (%s) ENCONTRADO en main.\n", elem->id, ambito_desde);
			break;
		case CASO_21:
			fprintf(pf, "CASO 21 -- ERR\n"
				"-->FALLO en la busqueda en buscarIdNoCualificado desde %s \n", ambito_desde);
			break;
		case CASO_22:
			fprintf(pf, "CASO 22 -- OK\n"
				"-->Elemento %s en buscarIdNoCualificado desde %s ENCONTRADO en main\n", elem->id, ambito_desde);
			break;
		case CASO_23:
			fprintf(pf, "CASO 23 -- ERR\n"
				"-->FALLO en la busqueda en buscarIdNoCualificado desde %s\n", ambito_desde);
			break;
		case CASO_24:
			fprintf(pf, "CASO 24 -- OK\n"
				"-->Elemento %s en buscarIdNoCualificado desde %s ENCONTRADO en %s\n", elem->id, ambito_desde, ambito_encontrado->ambito);
			break;
		case CASO_25:
			fprintf(pf, "CASO 25 -- OK\n"
				"-->Elemento %s en buscarIdNoCualificado desde %s ENCONTRADO en main\n", elem->id, ambito_desde);
			break; 
		case CASO_26:
			fprintf(pf, "CASO 26 -- ERR\n"
				"-->FALLO en la busqueda en buscarIdNoCualificado desde %s\n", ambito_desde);
			break;

		/************************BUSCAR PARA DECLARAR MIEMBRO CLASE************************/
		case CASO_49:
			fprintf(pf, "CASO 49\n"
				"Buscar para declarar miembro clase: ERR-> %s YA ESTA",elem->id);
			break;
		case CASO_50:
			fprintf(pf, "CASO 50\n"
				"Buscar para declarar miembro clase: OK-> NO ESTA en %s", ambito_desde);
			break;

		/************************BUSCAR PARA DECLARAR MIEMBRO INSTANCIA************************/
		case CASO_51:
			fprintf(pf, "CASO 51\n"
				"Buscar para declarar miembro instancia: ERR -> %s YA ESTA Y NO SE PUEDE DECLARAR",elem->id);
			break; 
		case CASO_52:
			fprintf(pf, "CASO 52\n"
				"Buscar para declarar miembro instancia: NO EXISTE EN LA CLASE PERO PUEDE QUE SI EN LA JERARQUIA");
			break; 
		case CASO_53:
			fprintf(pf, "CASO 53\n"
				"Buscar para declarar miembro instancia: OK-> NO ESTA en la clase %s", ambito_desde);
			break;

		/************************BUSCAR ID CUALIFICADO CLASE************************/
		case CASO_35:
			fprintf(pf,"CASO 35\n"
				"Buscar id cualificado: OK-> %s ESTA EN LA JERARQUIA Y ES ACCESIBLE",elem->id);
			break;
		case CASO_36:
			(pf,"CASO 36\n"
				"Buscar id cualificado clase: ERR-> ESTA EN LA JERARQUIA Y NO ES ACCESIBLE DESDE %s", ambito_desde);
			break;
		case CASO_37:
			fprintf(pf,"CASO 37\n"
				"Buscar id cualificado clase: ERR-> SE ACCEDE A ALGO CUALIFICADO POR LA CLASE %s, EXISTE LA CLASE PERO NO LO BUSCADO", ambito_desde);
			break;
		case CASO_38:
			fprintf(pf,"CASO 38\n"
				"Buscar id cualificado clase: ERR-> SE ACCEDE A ALGO CUALIFICADO POR LA CLASE , NO EXISTE LA CLASE");
			break;

		/************************BUSCAR ID CUALIFICADO CLASE************************/
		case CASO_271:
			fprintf(pf,"CASO 27.1\n"
				"Buscar id cualificado clase desde main: OK-> %s EL ATRIBUTO EXISTE, ESTA EN LA JERARQUIA Y ES ACCESIBLE",elem->id);
			break;
		case CASO_28:
			fprintf(pf,"CASO 28\n"
				"Buscar id cualificado clase desde main: ERR-> EL ATRIBUTO EXISTE, ESTA EN LA JERARQUIA Y NO ES ACCESIBLE (HIDDEN)");
			break;
		case CASO_29:
			fprintf(pf,"CASO 29\n"
				"Buscar id cualificado clase desde main: ERR-> EL ID BUSCADO NO EXISTE");
			break;
		case CASO_30:
			fprintf(pf,"CASO 30\n"
				"Buscar id cualificado clase desde main: ERR-> NO EXISTE LA CLASE");
			break;
		case CASO_31:
			fprintf(pf,"CASO 31\n"
				"Buscar id cualificado clase desde funcion global: OK-> %s SE ACCEDE A ALGO CUALIFICADO POR UNA CLASE QUE EXISTE, Y ES ACCESIBLE",elem->id);
			break;
		case CASO_32:
			fprintf(pf,"CASO 32\n"
				"Buscar id cualificado clase desde funcion global: ERR-> SE ACCEDE A ALGO CUALIFICADO POR UNA CLASE QUE EXISTE PERO NO ES ACCESIBLE");
			break;
		case CASO_33:
			fprintf(pf,"CASO 33\n"
				"Buscar id cualificado clase desde funcion global: ERR-> SE ACCEDE A ALGO CUALIFICADO POR UNA CLASE QUE EXISTE PERO NO EXISTE LO BUSCADO");
			break;
		case CASO_34:
			fprintf(pf,"CASO 34\n"
				"Buscar id cualificado clase desde funcion global: ERR-> NO EXISTE LA CLASE");
			break;

		/************************BUSCAR ID CUALIFICADO INSTANCIA************************/
		case CASO_401:
			fprintf(pf,"CASO 40.1\n"
				"Buscar id cualificado instancia: ERR-> EL ATRIBUTO NO EXISTE CUALIFICADO AUNQUE LA INSTANCIA EXISTE Y ES GLOBAL");
			break;
		case CASO_403:
			fprintf(pf,"CASO 40.3\n"
				"Buscar id cualificado instancia desde main: OK-> %s EL ATRIBUTO CUALIFICADO POR UNA INSTANCIA QUE ES VARIABLE GLOBAL "
				"DECLARADA DE TIPO DE CLASE QUE EXISTE Y EL ID ES UN ATRIBUTO QUE EXISTE EN LA JERARQUIA Y ES ACCESIBLE",elem->id);
			break;
		case CASO_423:
			fprintf(pf,"CASO 42.3\n"
				"Buscar id cualificado instancia desde funcion global: OK-> %s SE ACCEDE A UN ID CUALIFICADO POR UNA INSTANCIA QUE ES "
				"UNA VARIABLE GLOBAL DECLARADA DE  TIPO DE CLASE QUE EXISTE Y EL ID ES UN ATRIBUTO QUE EXISTE EN LA JERARQUIA Y ES ACCESIBLE",elem->id);
			break;
		case CASO_431:
			fprintf(pf,"CASO 43.1\n"
				"Buscar id cualificado instancia desde funcion global: ERR-> BUSCA UN ID QUE EXISTE COMO VARIABLE GLOBAL DE UNA CLASE QUE NO TIENE ESE ATRIBUTO");
			break;
		case CASO_433:
			fprintf(pf,"CASO 43.3\n"
				"Buscar id cualificado instancia desde funcion global: OK-> %s BUSCA ID QUE EXISTE COMO VARIABLE GLOBAL DE UNA CLASE "
				"QUE NO TIENE ESOS ATRIBUTOS PERO QUE SÍ LOS TIENE SU JERARQUIA Y SON ACCESIBLES",elem->id);
			break;
		case CASO_453:
			fprintf(pf,"CASO 45.3\n"
				"Buscar id cualificado instancia desde un metodo: OK-> %s BUSCA ID QUE ES UNA VARIABLE LOCAL DEL MÉTODO  DE UNA CLASE QUE "
				"EXISTE Y LA COSA BUSCADA ES UNA ATRIBUTO QUE ESTA EN LA JERARQUÍA Y ES ACCESIBLE ",elem->id);
			break;
		case CASO_463:
			fprintf(pf,"CASO 46.3\n"
				"Buscar id cualificado instancia desde dentro de un metodo: OK-> %s  SE BUSCA ALGO CUALIFICADO POR UNA INSTANCIA DE "
				"UNA CLASE QUE ES UNA VARIABLE GLOBAL Y LO BUSCADO ES UN ATRIBUTO QUE ESTA EN LA JERARQUÍA Y ES ACCESIBLE",elem->id);
			break;
		case CASO_471:
			fprintf(pf,"CASO 47.1\n"
				"Buscar id cualificado instancia desde un metodo: ERR-> SE ACCEDE A ALGO CUALIFICADO POR UNA INSTANCIA QUE"
				 "ES UN ATRIBUTO ACCESIBLE EN ESTE CASO DE LA MISMA CLASE PERO EL ATRIBUTO BUSCADO NO EXISTE");
			break;
		case CASO_473:
			fprintf(pf,"CASO 47.3\n"
				"Buscar id cualificado instancia desde un metodo: OK-> %s SE ACCEDE A UN ATRIBUTO QUE EXISTE EN LA JERARQUÍA Y ESTA "
				"ACCESIBLE CUALIFICANDO POR UNA INSTANCIA ACCESIBLE",elem->id);
			break;
		case CASO_48:
			fprintf(pf,"CASO 48\n"
				"Buscar id cualificado instancia desde un metodo: ERR-> SE ACCEDE A UN ATRIBUTO QUE EXISTE EN LA JERARQUÍA Y NO "
				"ESTA ACCESIBLE A TRAVÉS DE UNA INSTANCIA QUE SÍ ESTA ACCESIBLE");
			break;

		/************************BUSCAR PARA DECLARAR ID TABLA SIMBOLOS AMBITO************************/
		case CASO_54:
			fprintf(pf,"CASO 54\n"
				"Buscar para declarar id tabla simbolos ambito: ERR-> LA VARIABLE NO ESTA, SE PUEDE DECLARAR");
			break;
		case CASO_55:
			fprintf(pf,"CASO 55\n"
				"Buscar para declarar id tabla simbolos ambito: ERR-> LA FUNCION NO ESTA, SE PUEDE DECLARAR");
			break;
		case CASO_56:
			fprintf(pf,"CASO 56\n"
				"Buscar para declarar id tabla simbolos ambito: ERR-> EL PARAMETRO NO ESTA, SE PUEDE DECLARAR");
			break;
		case CASO_57:
			fprintf(pf,"CASO 57\n"
				"Buscar para declarar id tabla simbolos ambito: OK-> %s VARIABLE YA DECLARADA, NO SE PUEDE DECLARAR",elem->id);
			break;
		case CASO_58:
			fprintf(pf,"CASO 58\n"
				"Buscar para declarar id tabla simbolos ambito: ERR-> FUNCION YA DECLARADA, SE PUEDE DECLARAR");
			break;
		case CASO_59:
			fprintf(pf,"CASO 59\n"
				"Buscar para declarar id tabla simbolos ambito: OK-> %s PARAMETRO YA DECLARADO, NO SE PUEDE DECLARAR",elem->id);
			break;

		/************************BUSCAR PARA DECLARAR ID TABLA SIMBOLOS AMBITO************************/
		case CASO_60:
			fprintf(pf,"CASO 60\n"
				"Buscar para declarar un parametro: ERR-> LA VARIABLE NO ESTA, SE PUEDE DECLARAR");
			break;
		case CASO_61:
			fprintf(pf,"CASO 61\n"
				"Buscar para declarar un parametro: ERR-> YA HA SIDO DECLARADO COMO FUNCION ");
			break;
		case CASO_62:
			fprintf(pf,"CASO 62\n"
				"Buscar para declarar un parametro: ERR-> HA SIDO DECLARADO COMO FUNCION. NO ESTA Y SE UEDE DECLARAR");
			break;
		case CASO_63:
			fprintf(pf,"CASO 63\n"
				"Buscar para declarar una variable local: OK-> %s VARIABLE NO DECLARADA, SE PUEDE DECLARAR",elem->id);
			break;
		case CASO_64:
			fprintf(pf,"CASO 64\n"
				"Buscar para declarar una variable local: OK-> %s DECLARADA PREVIAMENTE COMO ARGUMENTO, ESTA DECLARADO Y NO SE PUEDE DECLARAR",elem->id);
			break;
		case CASO_65:
			fprintf(pf,"CASO 65\n"
				"Buscar para declarar una variable local: OK-> %s HA SIDO DECLARADA COMO FUNCION. YA ESTA DECLARADA Y NO SE PUEDE DECLARAR",elem->id);
			break;
		case CASO_66:
			fprintf(pf,"CASO 66\n"
				"Buscar para declarar una variable local: ERR-> YA HA SIDO DECLARADA COMO FUNCION Y EL PREFIJO DE LA FUNCIÓN ES EL DE LA"
 				"CLASE Y EL DE LA VARIABLE ES EL DEL METODO. NO ESTA DECLARADA Y SE PUEDE DECLARAR");
			break;
		case CASO_67:
			fprintf(pf,"CASO 67\n"
				"Buscar para declarar una variable local: ERR-> LA FUNCION NO ESTA, SE PUEDE DECLARAR");
			break;

		default:
			/*Estos casos hacen referencia a como tomamos nosotros los casos, para una ampliacion de casos esto tiene que ser actualizado*/
			if(caso){
				fprintf(pf, "Simbolo %s encontrado en %s. ", elem->id, ambito_encontrado->ambito);
				if(caso >= 53 && caso < 271){//Es un buscar para declarar
					fprintf(pf, "No se puede declarar.\n");
				}else{
					fprintf(pf, "Se puede acceder al simbolo.\n");
				}
			}else{
				if(caso <= -53 && caso > -271){//Es un buscar para declarar
					fprintf(pf, "Se puede declarar.\n");
				}else{
					fprintf(pf, "No se puede acceder al simbolo.\n");
				}
			}
			break;
	}

}

int print_hash_table_from_class(FILE* pf, tsc* p_tsc, char* id_clase){
	int i;
	char ** simbolos;
	tsa* t;
	if(!pf || !id_clase) return ERROR;

	t = _get_tsa_from_scope(p_tsc, id_clase);

	simbolos = (char**) malloc(sizeof(char*)*t->ppal->e_num);
	ht_list_keys(t->ppal, simbolos, t->ppal->e_num);


	fprintf(pf, "=================== %s =================\n", t->ambito);
	for(i=0; i<t->ppal->e_num; i++){
		if(print_tsa_elem(t->ppal, simbolos[i], pf) == ERROR){
			free(simbolos);
			return ERROR;
		}
	}
	free(simbolos);
	return OK;
}

int print_hash_table_from_met(FILE* pf, tsc* p_tsc, char* id_clase, char* metodo){
	int i;
	char ** simbolos;
	tsa* t;
	if(!pf || !id_clase || !metodo) return ERROR;

	t = _get_tsa_from_scope(p_tsc, metodo);

	simbolos = (char**) malloc(sizeof(char*)*t->met->e_num);
	ht_list_keys(t->met, simbolos, t->met->e_num);

	fprintf(pf, "=================== %s =================\n", metodo);
	for(i=0; i<t->met->e_num; i++){
		if(print_tsa_elem(t->met, simbolos[i], pf) == ERROR){
			free(simbolos);
			return ERROR;
		}
	}
	free(simbolos);
	return print_hash_table_from_class(pf, p_tsc, id_clase);
}

int print_command(FILE* pf, char* command){
	if(!pf || !command) return ERROR;
	fprintf(pf, "%s\n", command);
}
