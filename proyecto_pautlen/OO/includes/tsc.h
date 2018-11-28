#ifndef TSC_H
#define TSC_H

#include "tsa.h"
#include "graph.h"

#define TSA_MAIN "main"
#define OUTPUT_FILE "grafo.dot"

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

/*Realiza las operaciones de cierre necesarias para que la tabla de simbolos de clases quede consistente.
	En nuestro caso de momento nada*/
int close_tsc(tsc* t);

/*Realiza las tareas de añadir al grafo una nueva raíz*/
int abrirClase(tsc* t, char* id_clase);

/*Realiza las tareas de añadir al grafo un nuevo nodo que debe conectarse a 
	los nombres identificados mediante los últimos argumentos
	Tiene un número variable de ellos y el últim es NULL*/
int abrirClaseHereda(tsc* t, char* id_clase, ...);

/*Realiza las tareas de meter en la tabla hash del main los datos de la clase*/
int abrirAmbitoClase(tsc* t, char* id_clase, int tamanio);

/*Realiza tareas asociadas con el final de la clase identificada mediante el segundo argumento
Los datos numéricos son necesarios para actualizar la información que se habrá calculado a lo largo del proceso de la clase.*/
int cerrarClase(tsc* t, char* id_clase, int num_atributos_clase, int num_atributos_instancia,
				int num_metodos_sobreescribibles, int num_metodos_no_sobreescribibles);

/*Dada la situación de la tabla de símbolos (grafo)
Modifica la información de los padres para recoger que se ha añadido una nueva clase*/
void graph_enrouteParentsLastNode(tsc * g);

int abrirAmbitoEnClase(tsc * t, char * id_clase, char* id_ambito, int categoria, int acceso_metodo, int tipo_metodo, int posicion_metodo_sobreescribible, 	int tamanio);

int cerrarAmbitoEnClase(tsc* t, char* id_clase, char* id_ambito);

int insertarSimboloEnClase(tsc* t, char* id_clase, char* simbolo, int categoria, int tipo, int clase, int estructura,
	int direcciones,					int numero_parametros,
	int numero_variables_locales,		int posicion_variable_local,
	int posicion_parametro,			int dimension,
	int tamanio,					int filas,
	int columnas,					int capacidad,
	int numero_atributos_clase,			int numero_atributos_instancia,
	int numero_metodos_sobreescribibles,	int numero_metodos_no_sobreescribibles,
	int tipo_acceso,  				int tipo_miembro, 
	int posicion_atributo_instancia,		int posicion_metodo_sobreescribible,
	int num_acumulado_atributos_instancia,	int num_acumulado_metodos_sobreescritura,
	int posicion_acumulada_atributos_instancia,
	int posicion_acumulada_metodos_sobreescritura,
	int * tipo_args);

int insertarSimboloEnMain(tsc* t, char* simbolo, int categoria, int tipo, int clase, int estructura,
	int direcciones,					int numero_parametros,
	int numero_variables_locales,		int posicion_variable_local,
	int posicion_parametro,			int dimension,
	int tamanio,					int filas,
	int columnas,					int capacidad,
	int numero_atributos_clase,			int numero_atributos_instancia,
	int numero_metodos_sobreescribibles,	int numero_metodos_no_sobreescribibles,
	int tipo_acceso,  				int tipo_miembro, 
	int posicion_atributo_instancia,		int posicion_metodo_sobreescribible,
	int num_acumulado_atributos_instancia,	int num_acumulado_metodos_sobreescritura,
	int posicion_acumulada_atributos_instancia,
	int posicion_acumulada_metodos_sobreescritura,
	int * tipo_args);

int insertarSimboloEnAmbitoEnClase(tsc* t, char* id_clase, char* id_ambito, char* simbolo, int categoria, int tipo,	int clase,				int estructura,
	int direcciones,					int numero_parametros,
	int numero_variables_locales,		int posicion_variable_local,
	int posicion_parametro,			int dimension,
	int tamanio,					int filas,
	int columnas,					int capacidad,
	int numero_atributos_clase,			int numero_atributos_instancia,
	int numero_metodos_sobreescribibles,	int numero_metodos_no_sobreescribibles,
	int tipo_acceso,  				int tipo_miembro, 
	int posicion_atributo_instancia,		int posicion_metodo_sobreescribible,
	int num_acumulado_atributos_instancia,	int num_acumulado_metodos_sobreescritura,
	int posicion_acumulada_atributos_instancia,
	int posicion_acumulada_metodos_sobreescritura,
	int * tipo_args);

/***************FUNCIONES DE BUSQUEDA*******************/

tsa* _get_tsa_from_scope(tsc* t, char* scope);

int aplicarAccesos(tsc* t, char* id, char* ambito_id, char* ambito_actual, tsa_elem** elem);

int buscarIdEnJerarquiaDesdeAmbito (tsc* t, char* id, char* id_ambito, tsa** table, tsa_elem** elem);

int buscarIdNoCualificado(tsc* t, char* nombre_id, char* nombre_clase_desde, tsa** tsa_encontrada, tsa_elem** elem);

int buscarIdCualificadoClase(	tsc *t, char * nombre_clase_cualifica,
						char * nombre_id, char * nombre_ambito_desde,
						tsa ** ambito_encontrado,
						tsa_elem ** elem);

int buscarIdCualificadoInstancia(tsc *t, char * nombre_instancia_cualifica,
						char * nombre_id, char * nombre_clase_desde,
						tsa ** ambito_encontrado, tsa_elem ** elem);

int buscarParaDeclararMiembroClase(tsc *t, char * nombre_ambito_desde, char * nombre_miembro,
							tsa ** ambito_encontrado, tsa_elem ** elem);

int buscarParaDeclararMiembroInstancia(tsc *t, char * nombre_ambito_desde,
						char * nombre_miembro, tsa ** ambito_encontrado,
						tsa_elem ** elem);

int buscarParaDeclararIdMain(tsc *t, char* id, tsa** ambito_encontrado, tsa_elem** elem);

int buscarParaDeclararIdLocalEnMetodo(tsc *t, char * nombre_clase, char * id,
							tsa** ambito_encontrado, tsa_elem** elem);


/********Generacion del dot******************/
int generar_dot(tsc* tabla, char* file_name);






#endif