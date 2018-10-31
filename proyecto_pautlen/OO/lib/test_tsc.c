#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tsa.h"
#include "tsc.h"


tsa *tabla_main; /* Tabla de simbolos de main*/
tsc *tabla_clases; /* Lista de tablas de simbolos de clases */

/*******************************************************************************************/
int main(int argc, char* argv[])
{
	tsc * ej_tabla_clases=NULL;
	//elementoTablaSimbolos * pelem;//no sabemos que es esto

	char id_ambito[100];

    FILE* fsalida=fopen(argv[1], "w");
    /* Inicializar la tabla de simbolos del main (ambito por defecto) */
	tabla_main = init_tsa("main");

    /* Inicializar la tabla de las clases */
    ej_tabla_clases = init_tsc("ej_clases");

    /* Clase AA: tiene 1 atributo de instancia y uno de clase, tambien un metodo */
    abrirClase(ej_tabla_clases,"AA");
	graph_enrouteParentsLastNode(ej_tabla_clases);

    cerrarClase(ej_tabla_clases,"AA",0,0,0,0);


	abrirClaseHereda(ej_tabla_clases, "BB", "AA", NULL);
	graph_enrouteParentsLastNode(ej_tabla_clases);

    cerrarClase(ej_tabla_clases,"AA",0,0,0,0);



    /* Cerrar las tablas de simbolos */
    close_tsc(ej_tabla_clases);

    close_tsa(tabla_main);

 	free_tsa(tabla_main);
    free_tsc(ej_tabla_clases);
    fclose(fsalida);

	return 0;
}
