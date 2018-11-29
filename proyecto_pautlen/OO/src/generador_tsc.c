#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generador_tsc.h"
#include "macros.h"


int parser_line(char* line){
	char* token;

	token = strtok(line, DELIMITADOR);

	if(strcmp(token, INICIA_TSC)){

	}else if(strcmp(token, CERRAR_TSC)){

	}else if(strcmp(token, INICIA_TSA_MAIN)){

	}else if(strcmp(token, CERRAR_TSA_MAIN)){

	}else if(strcmp(token, ABRIR_AMBITO_PPAL_MAIN)){

	}else if(strcmp(token, BUSCAR)){
		token = strtok(NULL, line);
		if(strcmp(token, DECLARAR_MAIN)){

		}else if(strcmp(token, DECLARAR_MIEMBRO_CLASE)){

		}else if(strcmp(token, DECLARAR_MIEMBRO_INSTANCIA)){

		}else if(strcmp(token, DECLARAR_ID_LOCAL_METODO)){

		}else if(strcmp(token, JERARQUIA)){

		}else if(strcmp(token, ID_NO_CUALIFICADO)){

		}else if(strcmp(token, ID_CUALIFICADO_INSTANCIA)){

		}else if(strcmp(token, ID_CUALIFICADO_CLASE)){

		}else{
			return ERROR;
		}

	}else if(strcmp(token, INSERTAR_TSA_MAIN)){

	}else if(strcmp(token, INSERTAR_TSC)){

	}else if(strcmp(token, ABRIR_AMBITO_TSA_MAIN)){

	}else if(strcmp(token, CERRAR_AMBITO_TSA_MAIN)){

	}else if(strcmp(token, ABRIR_CLASE)){

	}else if(strcmp(token, ABRIR_CLASE_HEREDA)){

	}else if(strcmp(token, CERRAR_CLASE)){

	}else if(strcmp(token, ABRIR_AMBITO_TSC)){

	}else if(strcmp(token, CERRAR_AMBITO_TSC)){

	}else{
		return ERROR;
	}

}

int parse_file(FILE* pf){
	char line[1000];
	if(!pf) return ERROR;

	do{
		fscanf(pf,"%[^\n]", line);
		if(parser_line(line) == ERROR) return ERROR;
	while(line != NULL);

	return OK;
}