#ifndef MACROS_H
#define MACROS_H

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR -1

#define ID_MAX 64


#define SEPARA_SIMBOLO "_"

/*Categoria*/
#define VARIABLE 1
#define PARAMETRO 2
#define FUNCION 3
#define CLASE 4
#define METODO_SOBREESCRIBIBLE 5
#define METODO_NO_SOBREESCRIBIBLE 6
#define ATRIBUTO_CLASE 7
#define ATRIBUTO_INSTANCIA 8

/*Tipo (basico)*/
#define TIPO_MAIN -999
#define INT 1
#define FLOAT 2
#define BOOLEAN 3

/*Clase*/
#define ESCALAR 1
#define PUNTERO 2
#define VECTOR 3
#define CONJUNTO 4

/*Tipo acceso*/
#define NINGUNO 1 //(exposed)
#define HIDDEN 2 //(hidden) 
#define SECRET 3 //(secret)
#define EXPOSED 4 //(exposed)

/*Tipo miembro*/
#define MIEMBRO_UNICO 1
#define MIEMBRO_NO_UNICO 2

#endif