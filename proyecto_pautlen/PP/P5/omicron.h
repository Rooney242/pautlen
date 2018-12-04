#ifndef OMICRON_H
#define OMICRON_H

#define MAX_LONG_ID 50

/*TIPOS*/
#define INT 1
#define BOOLEAN 3

/* CLASES */
#define ESCALAR 1
#define OBJETO 2
#define VECTOR 3


typedef struct tipo_atributos
{
   char lexema[MAX_LONG_ID+1];
   int tipo;
   int valor_entero;
   int es_direccion;
   int etiqueta;
   int clase;
}	tipo_atributos;

#endif
