#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include "tsc.h"


/*******************************************************************************************/
int main(int argc, char* argv[])
{
    int error = 0;
    int num_funciones = 11;
    tsc* p_omicron;

    /* Inicializar la tabla de las clases */
    p_omicron = init_tsc("ejemplo_omicron");

    //int v1;
    error+=insertarSimboloEnMain(p_omicron, "v1", VARIABLE, INT, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NINGUNO, 0, 0, 0, 0, 0, 0, 0, NULL);

    //class AA{
    error+=abrirClase(p_omicron, "AA");
    error+=abrirAmbitoClase(p_omicron, "AA", 0);

    // exposed unique int a1;
    error+=insertarSimboloEnClase(p_omicron, "AA", "a1", VARIABLE, INT, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    //hidden int sa1;
    error+=insertarSimboloEnClase(p_omicron, "AA", "sa1", VARIABLE, INT, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ACCESO_CLASE, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

    //function exposed int mA1(int pmA1) {
    error+=abrirAmbitoEnClase(p_omicron, "AA", "mA1@1", METODO_SOBREESCRIBIBLE, ACCESO_TODOS, INT, 0, 0);

    //int vlmA1;
    error+=insertarSimboloEnAmbitoEnClase(p_omicron, "AA", "mA1@1", "vlmA1", VARIABLE, INT, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NINGUNO, 0, 0, 0, 0, 0, 0, 0, NULL);
    //printf v1;       //CASO 20: SE BUSCA UN ID NO CUALIFICADO v1 QUE NO ESTÁ EN LA JERARQUÍA.. ESTÁ EN MAIN ==> OK
    //return x;        //CASO 21: SE BUSCA UN ID NO CUALIFICADO x QUE NO ESTÁ EN NINGÚN LADO ==> ERR


    //}
    error+=cerrarAmbitoEnClase(p_omicron, "AA", "mA1@1");

    //};

    error+=cerrarClase(p_omicron, "AA", 3, 0, 1, 0);

    printf("%d\n", buscarTablaSimbolosAmbitosConPrefijos(p_omicron, "a1", "AA"));


    error+=close_tsc(p_omicron);
    error+=free_tsc(p_omicron);
    //fclose(fsalida);
    if(error == num_funciones){
        printf("No ha habido ningun error\n");
    }else{
        printf("Ha habido ERRORES\n");
    }
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
    };

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
