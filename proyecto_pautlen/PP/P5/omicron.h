#ifndef OMICRON_H
#define OMICRON_H

#define MAX_LONG_ID 50

#define INT 1
#define BOOLEAN 3

typedef struct
{
   char lexema[MAX_LONG_ID+1];
   int tipo;
   int valor_entero;
   int es_direccion;
   int etiqueta;
}tipo_atributos;

#endif
