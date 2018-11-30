#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generador_tsc.h"
#include "macros.h"
#include "output.h"
#include "tsa.h"
#include "tsc.h"
#include "hash_table.h"

/*Cosas de la estructura de informacion de las clases*/
class_info* init_class_info(){
	class_info * p_class_info;
	p_class_info = (class_info*) malloc(sizeof(class_info));
	if(!p_class_info) return NULL;

	p_class_info->num_atributos_clase  = 0;
	p_class_info->num_atributos_instancia  = 0;
	p_class_info->num_metodos_sobreescribibles  = 0;
	p_class_info->num_metodos_no_sobreescribibles  = 0;

	return p_class_info;
}

void free_class_info(class_info* p_class_info){
	if(p_class_info) free(p_class_info);
	return;
}

/**********************************************************************************/
/*TODO: quitar los prefijos, ya nos los dan*/

int parser_line(char* line, FILE* out, tsc** p_omicron, class_info ** p_class_info, class_info ** p_main_info){
	int i;
	char* token;
    tsa* tsa_aux = NULL;
    tsa_elem * elem_aux = NULL;
    char* nombre_clase = NULL, *nombre_simbolo = NULL;
    char** nombres_padres;
    int categoria, tipo_basico, estructura, tipo_acceso, tipo_miembro;


	token = strtok(line, DELIMITADOR);

	/*Caso de que sea un comentario, se ignora*/
	if(token[0] == COMENTARIO) return OK;

	print_command(out, token);

	if(!strcmp(token, INICIA_TSC)){
		token = strtok(NULL, DELIMITADOR);
		*p_omicron = init_tsc(token);
	}else if(!strcmp(token, CERRAR_TSC)){
		close_tsc(*p_omicron);
		free_tsc(*p_omicron);
	}else if(!strcmp(token, INICIA_TSA_MAIN)){
		/*no realiza nada, lo lleva la estructura tsc por dentro*/
	}else if(!strcmp(token, CERRAR_TSA_MAIN)){
		cerrarMain(*p_omicron, 
			(*p_main_info)->num_atributos_clase, 
			(*p_main_info)->num_atributos_instancia, 
			(*p_main_info)->num_metodos_sobreescribibles, 
			(*p_main_info)->num_metodos_no_sobreescribibles);
	}else if(!strcmp(token, ABRIR_AMBITO_PPAL_MAIN)){
		/*no realiza nada, lo lleva la estructura tsc por dentro*/
	}else if(!strcmp(token, BUSCAR)){
		token = strtok(NULL, DELIMITADOR);
		print_command(out, token);

		if(!strcmp(token, DECLARAR_MAIN)){

		}else if(!strcmp(token, DECLARAR_MIEMBRO_CLASE)){

		}else if(!strcmp(token, DECLARAR_MIEMBRO_INSTANCIA)){

		}else if(!strcmp(token, DECLARAR_ID_LOCAL_METODO)){

		}else if(!strcmp(token, JERARQUIA)){

		}else if(!strcmp(token, ID_NO_CUALIFICADO)){

		}else if(!strcmp(token, ID_CUALIFICADO_INSTANCIA)){

		}else if(!strcmp(token, ID_CUALIFICADO_CLASE)){

		}else{
			return ERROR;
		}

	}else if(!strcmp(token, INSERTAR_TSA_MAIN)){
		nombre_simbolo = strtok(NULL, DELIMITADOR);
		categoria = atoi(strtok(NULL, DELIMITADOR));
		tipo_basico = atoi(strtok(NULL, DELIMITADOR));
		estructura = atoi(strtok(NULL, DELIMITADOR));
		tipo_acceso = atoi(strtok(NULL, DELIMITADOR));
		tipo_miembro = atoi(strtok(NULL, DELIMITADOR));

		/*Actualizamos los datos del main*/
		if(categoria == ATRIBUTO_CLASE){
			(*p_main_info)->num_atributos_clase++;
		}else if(categoria == ATRIBUTO_INSTANCIA){
			(*p_main_info)->num_atributos_instancia++;
		}else if(categoria == METODO_SOBREESCRIBIBLE){
			(*p_main_info)->num_metodos_sobreescribibles++;
		}else if(categoria == METODO_NO_SOBREESCRIBIBLE){
			(*p_main_info)->num_metodos_no_sobreescribibles++;
		}

		insertarSimboloEnMain(*p_omicron, nombre_simbolo, categoria, tipo_basico, estructura,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, tipo_acceso, tipo_miembro, 0, 0, 0, 0, 0, 0, NULL);
		print_hash_table_from_class(out, *p_omicron, TSA_MAIN);

	}else if(!strcmp(token, INSERTAR_TSC)){
		nombre_clase = strtok(NULL, DELIMITADOR);
		nombre_simbolo = strtok(NULL, DELIMITADOR);
		categoria = atoi(strtok(NULL, DELIMITADOR));
		tipo_basico = atoi(strtok(NULL, DELIMITADOR));
		estructura = atoi(strtok(NULL, DELIMITADOR));
		tipo_acceso = atoi(strtok(NULL, DELIMITADOR));
		tipo_miembro = atoi(strtok(NULL, DELIMITADOR));
		
		/*Actualizamos los datos de la clase*/
		if(categoria == ATRIBUTO_CLASE){
			(*p_class_info)->num_atributos_clase++;
		}else if(categoria == ATRIBUTO_INSTANCIA){
			(*p_class_info)->num_atributos_instancia++;
		}else if(categoria == METODO_SOBREESCRIBIBLE){
			(*p_class_info)->num_metodos_sobreescribibles++;
		}else if(categoria == METODO_NO_SOBREESCRIBIBLE){
			(*p_class_info)->num_metodos_no_sobreescribibles++;
		}

	}else if(!strcmp(token, ABRIR_AMBITO_TSA_MAIN)){

	}else if(!strcmp(token, CERRAR_AMBITO_TSA_MAIN)){

	}else if(!strcmp(token, ABRIR_CLASE)){
		nombre_clase = strtok(NULL, DELIMITADOR);
		abrirClase(*p_omicron, nombre_clase);
		abrirAmbitoClase(*p_omicron, nombre_clase, 0);

		/*Al abrir una clase se resetea la informacion de la clase*/
		(*p_class_info)->num_atributos_clase  = 0;
		(*p_class_info)->num_atributos_instancia  = 0;
		(*p_class_info)->num_metodos_sobreescribibles  = 0;
		(*p_class_info)->num_metodos_no_sobreescribibles  = 0;

	}else if(!strcmp(token, ABRIR_CLASE_HEREDA)){
		nombre_clase = strtok(NULL, DELIMITADOR);
		token = strtok(NULL, DELIMITADOR);
		for(i=0; token != NULL; i++){
			if(i==0){
				nombres_padres = (char**)malloc(sizeof(char*));
			}else{
				nombres_padres = (char**)realloc(nombres_padres, sizeof(char*)*(i+1));
			}
			nombres_padres[i] = token;
			token = strtok(NULL, DELIMITADOR);
		}

		abrirClaseHereda(*p_omicron, nombre_clase, nombres_padres, i);
		abrirAmbitoClase(*p_omicron, nombre_clase, 0);
		free(nombres_padres);

	}else if(!strcmp(token, CERRAR_CLASE)){
		nombre_clase = strtok(NULL, DELIMITADOR);
		//printf("%d %d %d %d\n", (*p_class_info)->num_atributos_clase, (*p_class_info)->num_atributos_instancia, (*p_class_info)->num_metodos_sobreescribibles, (*p_class_info)->num_metodos_no_sobreescribibles);
		cerrarClase(*p_omicron, nombre_clase, 
			(*p_class_info)->num_atributos_clase, 
			(*p_class_info)->num_atributos_instancia, 
			(*p_class_info)->num_metodos_sobreescribibles, 
			(*p_class_info)->num_metodos_no_sobreescribibles);
	}else if(!strcmp(token, ABRIR_AMBITO_TSC)){

	}else if(!strcmp(token, CERRAR_AMBITO_TSC)){

	}else{
		return ERROR;
	}

	return OK;

}

int parse_file(FILE* in, FILE* out){
	char *line = NULL;
	size_t len = 0;
    ssize_t read;
    tsc* p_omicron = NULL;
    class_info * p_class_info = init_class_info();
    class_info * p_main_info = init_class_info();

	if(!in || !out) return ERROR;

	while((read = getline(&line, &len, in)) != -1){
		/*Esto es para quitar el \n del final de la linea, si no hay problemas con los strcmp*/
		if(line[strlen(line)-1] == '\n') line[strlen(line)-1] = 0;

		//printf("Linea: %s con caracteres %ld\n", line, read);
		if(parser_line(line, out, &p_omicron, &p_class_info, &p_main_info) == ERROR) return ERROR;
	}

	if(line) free(line);
	if(p_class_info) free_class_info(p_class_info);
	if(p_main_info) free_class_info(p_main_info);

	return OK;
}