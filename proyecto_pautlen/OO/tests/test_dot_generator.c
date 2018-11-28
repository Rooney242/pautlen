#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include "output.h"
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
    FILE* out;

    out = stdout;
    /*if (argc!= 2){
        printf("Especifica fichero de salida\n");
        return 0;
    }
    
    if (( out = fopen(argv[1],"w")) == NULL){
        printf("Error al abrir el fichero de salida\n");
    }*/

    /* Inicializar la tabla de las clases */
    p_omicron = init_tsc("entrega");


/**********************************/
    abrirClase(p_omicron, "A");
    abrirAmbitoClase(p_omicron, "A", 0);

    insertarSimboloEnClase(p_omicron, "A", "aca", VARIABLE, BOOLEAN, ESCALAR, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, EXPOSED, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    tsa_aux = _get_tsa_from_scope(p_omicron, "A");
    print_hash_table_from_class(out, tsa_aux);

    insertarSimboloEnClase(p_omicron, "A", "aia", VARIABLE, BOOLEAN, ESCALAR, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, EXPOSED, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
    tsa_aux = _get_tsa_from_scope(p_omicron, "A");
    print_hash_table_from_class(out, tsa_aux);


    abrirAmbitoEnClase(p_omicron, "A", "msA", METODO_SOBREESCRIBIBLE, NINGUNO, INT, 0, 0);
    tsa_aux = _get_tsa_from_scope(p_omicron, "A");
    print_hash_table_from_met(out, tsa_aux, "msA");
    cerrarAmbitoEnClase(p_omicron, "A", "msA");

    abrirAmbitoEnClase(p_omicron, "A", "mcA", METODO_NO_SOBREESCRIBIBLE, NINGUNO, INT, 0, 0);
    cerrarAmbitoEnClase(p_omicron, "A", "mcA");


    cerrarClase(p_omicron, "A", 1, 1, 1, 1);

/****************************/
    abrirClaseHereda(p_omicron, "B", "A", NULL);
    abrirAmbitoClase(p_omicron, "B", 0);

    insertarSimboloEnClase(p_omicron, "B", "acb", VARIABLE, BOOLEAN, ESCALAR, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, EXPOSED, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    insertarSimboloEnClase(p_omicron, "B", "aib", VARIABLE, BOOLEAN, ESCALAR, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, EXPOSED, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    abrirAmbitoEnClase(p_omicron, "B", "msA", METODO_SOBREESCRIBIBLE, NINGUNO, INT, 0, 0);
    cerrarAmbitoEnClase(p_omicron, "B", "msA");

    abrirAmbitoEnClase(p_omicron, "B", "msB", METODO_SOBREESCRIBIBLE, NINGUNO, INT, 0, 0);
    cerrarAmbitoEnClase(p_omicron, "B", "msB");

    cerrarClase(p_omicron, "B", 1, 1, 1, 1);


/**********************/
    abrirClaseHereda(p_omicron, "C", "B", NULL);
    abrirAmbitoClase(p_omicron, "C", 0);

    insertarSimboloEnClase(p_omicron, "C", "acc", VARIABLE, BOOLEAN, ESCALAR, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, EXPOSED, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    insertarSimboloEnClase(p_omicron, "C", "aic", VARIABLE, BOOLEAN, ESCALAR, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, EXPOSED, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    abrirAmbitoEnClase(p_omicron, "C", "msA", METODO_SOBREESCRIBIBLE, NINGUNO, INT, 0, 0);
    cerrarAmbitoEnClase(p_omicron, "C", "msA");

    abrirAmbitoEnClase(p_omicron, "C", "msB", METODO_SOBREESCRIBIBLE, NINGUNO, INT, 0, 0);
    cerrarAmbitoEnClase(p_omicron, "C", "msB");

    abrirAmbitoEnClase(p_omicron, "C", "msC", METODO_SOBREESCRIBIBLE, NINGUNO, INT, 0, 0);
    cerrarAmbitoEnClase(p_omicron, "C", "msC");


    cerrarClase(p_omicron, "C", 1, 1, 1, 1);


    close_tsc(p_omicron);
    free_tsc(p_omicron);
    //fclose(out);

    return 0;
}