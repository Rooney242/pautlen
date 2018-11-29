#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"
#include "output.h"
#include "tsc.h"
#include "generador_tsc.h"

int main(int argc, char* argv[])
{
    FILE* in,*out;

    out = stdout;
    if (argc!= 3){
        printf("Especifica fichero de entrada y de salida\n");
        return 0;
    }

    if (( in = fopen(argv[1],"r")) == NULL){
        printf("Error al abrir el fichero de entrada\n");
    }
    
    /*if (( out = fopen(argv[2],"w")) == NULL){
        printf("Error al abrir el fichero de salida\n");
    }*/

    if(parse_file(in, out)==ERROR){
        printf("Ha ocurrido un error al parsear el archivo de entrada.\n");
    }


    fclose(in);
    //fclose(out);
}