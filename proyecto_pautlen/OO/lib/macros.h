#ifndef MACROS_H
#define MACROS_H

#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR -1

/*Categoria*/
#define VARIABLE 10
#define PARAMETRO 11
#define FUNCION 12
#define CLASE 13
#define METODO_SOBREESCRIBIBLE 14
#define METODO_NO_SOBREESCRIBIBLE 15
#define ATRIBUTO_CLASE 16
#define ATRIBUTO_INSTANCIA 17

/*Tipo*/
#define INT 20
#define FLOAT 21

/*Clase*/
#define ESCALAR 30
#define PUNTERO 31
#define VECTOR 32
#define CONJUNTO 33

/*Tipo acceso*/
#define NINGUNO 40 //(exposed)
#define HIDDEN 41 //(hidden) 
#define SECRET 42 //(secret)
#define EXPOSED 43 //(exposed)

/*Tipo miembro*/
#define MIEMBRO_UNICO 50
#define MIEMBRO_NO_UNICO 51

#endif