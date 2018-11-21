#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include "casos.h"
#include "tsc.h"


/*******************************************************************************************/
int main(int argc, char* argv[])
{
    int error = 1;
    int ret;
    int num_funciones = 11;
    tsc* p_omicron;
    tsa* tsa_aux;
    tsa_elem * elem_aux;

    /* Inicializar la tabla de las clases */
    p_omicron = init_tsc("ejemplo_omicron");

    //class AA{
    if(!abrirClase(p_omicron, "AA")){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;
    if(!abrirAmbitoClase(p_omicron, "AA", 0)){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;

    if(!insertarSimboloEnClase(p_omicron, "AA", "sa1", VARIABLE, INT, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, HIDDEN, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL)){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;
    
    if(!cerrarClase(p_omicron, "AA", 3, 0, 1, 0)){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;

    //class BB
    if(!abrirClaseHereda(p_omicron, "BB", "AA", NULL)){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;
    if(!abrirAmbitoClase(p_omicron, "AA", 0)){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;
    if(!cerrarClase(p_omicron, "BB", 3, 0, 1, 0)){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;


    if(!close_tsc(p_omicron)){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;
    if(!free_tsc(p_omicron)){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;

    printf("El programa ha terminado perfectamente y sin errores\n");
	return 0;
}