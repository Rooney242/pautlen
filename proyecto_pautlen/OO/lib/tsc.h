#ifndef TSC_H
#define TSC_H

#include "tsa.h"
#include "graph.h"

#define TSA_MAIN "main"

typedef struct {
	char* nombre;
	tsa* main;
	Adjacency_Matrix* grafo;
}tsc;

/*Reserva todos los recursos para crear una tabla de símbolos basada en un grafo e 
	identificada con el nombre proporcionado como argumento.
	La tabla se deja en el primer argumento*/
tsc* init_tsc(char * nombre);

/*Libera todos los recursos para la tabla de símbolos de clases*/
int free_tsc(tsc* t);

/*Realiza las tareas de añadir al grafo una nueva raíz*/
int abrirClase(tsc* t, char* id_clase);

/*Realiza las tareas de añadir al grafo un nuevo nodo que debe conectarse a 
	los nombres identificados mediante los últimos argumentos
	Tiene un número variable de ellos y el últim es NULL*/
int abrirClaseHereda(tsc* t, char* id_clase, ...);

/*Realiza tareas asociadas con el final de la clase identificada mediante el segundo argumento
Los datos numéricos son necesarios para actualizar la información que se habrá calculado a lo largo del proceso de la clase.*/
int cerrarClase(tsc* t, char* id_clase, int num_atributos_clase, int num_atributos_instancia,
				int num_metodos_sobreescribibles, int num_metodos_no_sobreescribibles);

/*Dada la situación de la tabla de símbolos (grafo)
Modifica la información de los padres para recoger que se ha añadido una nueva clase*/
void graph_enrouteParentsLastNode(tsc * g);

/*Realiza las operaciones de cierre necesarias para que la tabla de simbolos de clases quede consistente.
	En nuestro caso de momento nada*/
int close_tsc(tsc* t);




#endif