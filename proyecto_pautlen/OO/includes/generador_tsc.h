#ifndef GENERADOR_TSC_H
#define GENERADOR_TSC_H

#define DELIMITADOR "\t"
#define COMENTARIO '#'

#define INICIA_TSC "inicia_tsc" //---Iniciar la tabla de símbolos de clases
#define CERRAR_TSC "cerrar_tsc" //---Dar por terminada la gestión de la tabla de clases
#define INICIA_TSA_MAIN "inicia_tsa_main" //---Inicia la tabla de ámbitos de main
#define CERRAR_TSA_MAIN "cerrar_tsa_main" //---Dar por terminada la gestión de la tabla de ámbitos del main
#define ABRIR_AMBITO_PPAL_MAIN "abrir_ambito_ppal_main" //---Abre el ámbito ppal de main
#define BUSCAR "buscar" //Buscar en general
#define DECLARAR_MAIN "declarar_main" //Busca un símbolo para ser declarado en la tabla de ámbitos de main
#define DECLARAR_MIEMBRO_CLASE "declarar_miembro_clase" //Busca para declarar como miembro de clase un símbolo en la tabla de clases a partir de una clase
#define DECLARAR_MIEMBRO_INSTANCIA "declarar_miembro_instancia" //Busca para declarar como miembro de instancia un símbolo en la tabla de clases a partir de una clase
#define DECLARAR_ID_LOCAL_METODO "declarar_id_local_metodo" //Busca para declarar como variable local o parámetro un símbolo, en el método actual de la clase indicada
#define JERARQUIA "jerarquia" //Función interna que busca en la jerarquía un id a partir de una clase
#define ID_NO_CUALIFICADO "id_no_cualificado" //Búsqueda para ser usado en alguna sentencia de un id no cualificado desde cualquier lugar del programa
#define ID_CUALIFICADO_INSTANCIA "id_cualificado_instancia" //Búsqueda para ser usado en alguna sentencia de un id cualificado a través de una instancia desde cualquier lugar del programa
#define ID_CUALIFICADO_CLASE "id_cualificado_clase" //Búsqueda para ser usado en alguna sentencia de un id cualificado a través de una clase desde cualquier lugar del programa
#define INSERTAR_TSA_MAIN "insertar_tsa_main" //---Insertar un símbolo cuando se está en los ámbitos de main
#define INSERTAR_TSC "insertar_tsc" //Insertar un símbolo desde cualquier lugar de las clases del programa
#define ABRIR_AMBITO_TSA_MAIN "abrir_ambito_tsa_main" //Apertura del ámbito asociado con una nueva función global en el ámbito principal de main
#define CERRAR_AMBITO_TSA_MAIN "cerrar_ambito_tsa_main" //Cerrar el ámbito asociado con una función global en el ámbito principal de main
#define ABRIR_CLASE "abrir_clase" //---Abrir una nueva clase que no hereda de ninguna
#define ABRIR_CLASE_HEREDA "abrir_clase_hereda" //---Abrir una nueva clase que hereda de una lista
#define CERRAR_CLASE "cerrar_clase" //---Cerrar una clase
#define ABRIR_AMBITO_TSC "abrir_ambito_tsc" //Abrir el ámbito de un nuevo método de una clase
#define CERRAR_AMBITO_TSC "cerrar_ambito_tsc" //Cerrar el ámbito de un método de una clase

typedef struct {
	int num_atributos_clase;
	int num_atributos_instancia;
	int num_metodos_sobreescribibles;
	int num_metodos_no_sobreescribibles;
}class_info;

int parse_file(FILE* in, FILE* out);


#endif