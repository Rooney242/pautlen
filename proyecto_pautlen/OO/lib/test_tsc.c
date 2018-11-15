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

    if(!insertarSimboloEnMain(p_omicron, "v1", VARIABLE, INT, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NINGUNO, 0, 0, 0, 0, 0, 0, 0, NULL)){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;

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

    // exposed unique int a1;
    if(!insertarSimboloEnClase(p_omicron, "AA", "a1", VARIABLE, INT, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, EXPOSED, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL)){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;

    //hidden int sa1;
    if(!insertarSimboloEnClase(p_omicron, "AA", "sa1", VARIABLE, INT, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, HIDDEN, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL)){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;

    //function exposed int mA1(int pmA1) {
    if(!abrirAmbitoEnClase(p_omicron, "AA", "mA1@1", METODO_SOBREESCRIBIBLE, EXPOSED, INT, 0, 0)){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;

    //int vlmA1;
    if(!insertarSimboloEnAmbitoEnClase(p_omicron, "AA", "mA1@1", "vlmA1", VARIABLE, INT, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NINGUNO, 0, 0, 0, 0, 0, 0, 0, NULL)){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;
    //printf v1;
    //CASO 20: SE BUSCA UN ID NO CUALIFICADO v1 QUE NO ESTÁ EN LA JERARQUÍA.. ESTÁ EN MAIN ==> OK
    ret = buscarIdNoCualificado(p_omicron, "v1", "mA1@1", &tsa_aux, &elem_aux);
    print_error(stdout, ret, "v1", "mA1@1", tsa_aux, elem_aux);

    //return x;        
    //CASO 21: SE BUSCA UN ID NO CUALIFICADO x QUE NO ESTÁ EN NINGÚN LADO ==> ERR
    ret = buscarIdNoCualificado(p_omicron, "x", "mA1@1", &tsa_aux, &elem_aux);
    //printf("simbolo encontrado en %s\n", tsa_aux->ambito);
    print_error(stdout, ret, "x", "mA1@1", tsa_aux, elem_aux);



    //}
    if(!cerrarAmbitoEnClase(p_omicron, "AA", "mA1@1")){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;

    //printf AA.sa1;
    if(buscarIdCualificadoClase(p_omicron, "AA", "sa1", "AA", &tsa_aux, &elem_aux)){
        printf("simbolo encontrado en %s\n", tsa_aux->ambito);
    }else{
        printf("simbolo NO encontrado\n");
    }

    //};

    if(!cerrarClase(p_omicron, "AA", 3, 0, 1, 0)){
        printf("Error: %d\n", error);
        return 0;
    }
    error++;


    //printf AA.sa1;
    if(buscarIdCualificadoClase(p_omicron, "AA", "sa1", "AA", &tsa_aux, &elem_aux)){
        printf("simbolo encontrado en %s\n", tsa_aux->ambito);
    }else{
        printf("simbolo NO encontrado\n");
    }


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




/*
main
{

    int v1;

    class AA {
        exposed unique int a1;
        hidden int sa1;

        function exposed int mA1(int pmA1) {
            int vlmA1;
            printf v1;       //CASO 20: SE BUSCA UN ID NO CUALIFICADO v1 QUE NO ESTÁ EN LA JERARQUÍA.. ESTÁ EN MAIN ==> OK
            return x;        //CASO 21: SE BUSCA UN ID NO CUALIFICADO x QUE NO ESTÁ EN NINGÚN LADO ==> ERR

        }

        printf AA.sa1;
    };

    printf AA.sa1;

    function int f1 (boolean pf1)
    {
        int vlf11;

        if ((pf1 == true))
                        //CASO 24: SE BUSCA UN ID NO CUALIFICADO DEFINIDO EN UNA FUNCIÓN GLOBAL DESDE LA MISMA FUNCIÓN 
                    // Y SÍ QUE ESTÁ ==> OK
    {
            vlf11=v1+a1;        //CASO 25: SE BUSCA DESDE UNA FUNCIÓN GLOBAL UN IDENTIFICADOR NO CUALIFICADO QUE ESTÁ EN EL 
                    // ÁMBITO main (v1) ==> OK
                    //CASO 26: SE BUSCA UN ID NO CUALIFICADO DESDE UNA FUNCIÓN GLOBAL Y NO ESTÁ NI EN LA FUNCIÓN NI 
                    // EN EL MAIN (a1) ==> ERR

    }
        return vlf11;
    }

    printf v1;      //CASO 22: SE BUSCA UN ID NO CUALIFICADO DESDE MAIN EL ID NO ESTÁ EN LA JERARQUÍA PERO SÍ EN EL MAIN
            // (v1) ==> OK

    printf x;           //CASO 23: SE BUSCA UN ID NO CUALIFICADO DESDE UNA FUNCIÓN GLOBAL CUADO EL ID NO ESTÁ EN LA JERARQUÍA NI EN EL MAIN (x)
            // ==> ERR
}
*/
