#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generador_tsc.h"
#include "macros.h"
#include "output.h"
#include "tsa.h"
#include "tsc.h"
#include "hash_table.h"


int parser_line(char* line, FILE* out){
	char* token;

	token = strtok(line, DELIMITADOR);
	print_command(out, token);

	if(!strcmp(token, INICIA_TSC)){

	}else if(!strcmp(token, CERRAR_TSC)){

	}else if(!strcmp(token, INICIA_TSA_MAIN)){

	}else if(!strcmp(token, CERRAR_TSA_MAIN)){

	}else if(!strcmp(token, ABRIR_AMBITO_PPAL_MAIN)){

	}else if(!strcmp(token, BUSCAR)){
		token = strtok(NULL, line);
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
			return OK;//TEMPORAL
		}

	}else if(!strcmp(token, INSERTAR_TSA_MAIN)){

	}else if(!strcmp(token, INSERTAR_TSC)){

	}else if(!strcmp(token, ABRIR_AMBITO_TSA_MAIN)){

	}else if(!strcmp(token, CERRAR_AMBITO_TSA_MAIN)){

	}else if(!strcmp(token, ABRIR_CLASE)){

	}else if(!strcmp(token, ABRIR_CLASE_HEREDA)){

	}else if(!strcmp(token, CERRAR_CLASE)){

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
	if(!in || !out) return ERROR;

	while((read = getline(&line, &len, in)) != -1){
		line[strlen(line)-1] = 0;
		//printf("Linea: %s con caracteres %ld\n", line, read);
		if(parser_line(line, out) == ERROR) return ERROR;
		//if(line) free(line);
	}

	return OK;
}