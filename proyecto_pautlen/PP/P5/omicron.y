%{	
	#include <stdio.h>

	#include <string.h>
	#include "omicron.h"
	#include "output.h"
	#include "macros.h"
	#include "tsc.h"
	#include "generacion.h"
	extern int line_count;
	extern int col_count;	
	extern FILE* fout;
	extern FILE* asmfile;
	int tipo_actual;                                                                
	int clase_actual;

	tsc * tabla_simbolos;
=======
=======
	#include <stdlib.h>
	#include <string.h>
	#include "omicron.h"
	#include "macros.h"
	#include "casos.h"
	#include "tsc.h"


	extern int line_count;
	extern int col_count;	
	extern FILE* fout;

	tsc* p_omicron;
    tsa* tsa_aux;
    tsa_elem * elem_aux;
    char nombre_clase_desde[ID_MAX]


%}

%union	
{
	tipo_atributos atributos;
}

%token TOK_NONE    
%token TOK_CLASS    
%token TOK_INHERITS    
%token TOK_INSTANCE_OF    
%token TOK_DISCARD    
%token TOK_ITSELF   
%token TOK_FLECHA   
%token TOK_HIDDEN   
%token TOK_SECRET   
%token TOK_EXPOSED   
%token TOK_UNIQUE    
%token TOK_FUNCTION    
%token TOK_RETURN    
%token TOK_MAIN    
%token TOK_INT    
%token TOK_BOOLEAN   
%token TOK_ARRAY   	
%token TOK_IF   
%token TOK_ELSE   
%token TOK_WHILE   
%token TOK_SCANF    
%token TOK_PRINTF    

/* IDENTIFICADOR */
%token <atributos> TOK_IDENTIFICADOR    

/* OPERADORES */
%token TOK_IGUAL    
%token TOK_DISTINTO    
%token TOK_MENORIGUAL   
%token TOK_MAYORIGUAL   
%token TOK_OR   
%token TOK_AND   

/* CONSTANTES */
%token <atributos> TOK_CONSTANTE_ENTERA  
%token TOK_FALSE     
%token TOK_TRUE    


/* ERRORES */
%token TOK_ERROR

%type <atributos> tipo
%type <atributos> comparacion
%type <atributos> constante
%type <atributos> exp
%type <atributos> asignacion
%type <atributos> identificador_clase
%type <atributos> elemento_vector
%type <atributos> constante_logica
%type <atributos> constante_entera

%start programa
%left '+' '-' TOK_OR
%left '*' '/' TOK_AND
%right MENOSU '!'
%%

programa: 	TOK_MAIN '{' declaraciones escritura1 funciones escritura2 sentencias '}' 
				{ 


programa: 	inicioTabla TOK_MAIN '{' declaraciones funciones sentencias '}' 
				{
					fprintf(fout, ";R:\tprograma: 	TOK_MAIN '{' declaraciones funciones sentencias '}'\n");
				}	
			| TOK_MAIN '{' funciones escritura1 escritura2 sentencias '}'
				{
					fprintf(fout, ";R:\tprograma: 	TOK_MAIN '{' funciones sentencias '}'\n");
					escribir_fin(asmfile);
				}	
			;

escritura1: 	{
  					tabla_simbolos = init_tsc(TSA_MAIN);
  					escribir_subseccion_data(asmfile);
    				escribir_cabecera_bss(asmfile);
    				escribir_segmento_codigo(asmfile);
         	 	}
          		;

escritura2: 	{
    				escribir_inicio_main(asmfile);
         	 	}
          		;

inicioTabla:	{
					/* Inicializar la tabla de las clases */
    				p_omicron = init_tsc("TSC_Omicron");
				}
				;

declaraciones:	declaracion
					{
						fprintf(fout, ";R:\tdeclaraciones:	declaracion\n");
					}	
				| declaracion declaraciones
					{
						fprintf(fout, ";R:\tdeclaraciones:	declaracion declaraciones\n");
					}
				;

declaracion:	modificadores_acceso clase identificadores ';'
					{
						fprintf(fout, ";R:\tdeclaracion:	modificadores_acceso clase identificadores ';'\n");
					}
				| modificadores_acceso declaracion_clase ';'
					{
						fprintf(fout, ";R:\tdeclaracion:	modificadores_acceso declaracion_clase ';'\n");
					}
				;

modificadores_acceso: /*vacio*/
						{
							fprintf(fout, ";R:\tmodificadores_acceso: \n");
						}
					| TOK_HIDDEN TOK_UNIQUE
						{
							fprintf(fout, ";R:\tmodificadores_acceso: TOK_HIDDEN TOK_UNIQUE\n");
						}
					| TOK_SECRET TOK_UNIQUE
						{
							fprintf(fout, ";R:\tmodificadores_acceso: TOK_SECRET TOK_UNIQUE\n");
						}
					| TOK_EXPOSED TOK_UNIQUE
						{
							fprintf(fout, ";R:\tmodificadores_acceso: TOK_EXPOSED TOK_UNIQUE\n");
						}
					| TOK_HIDDEN 
						{
							fprintf(fout, ";R:\tmodificadores_acceso: TOK_HIDDEN\n");
						}
					| TOK_SECRET
						{
							fprintf(fout, ";R:\tmodificadores_acceso: TOK_SECRET\n");
						}
					| TOK_EXPOSED
						{
							fprintf(fout, ";R:\tmodificadores_acceso: TOK_EXPOSED\n");
						}
					| TOK_UNIQUE
						{
							fprintf(fout, ";R:\tmodificadores_acceso: TOK_UNIQUE\n");
						}
					;

clase:	clase_escalar
			{
				clase_actual = ESCALAR;
				strcpy(nombre_clase_desde, $1.atributos.lexema);
				fprintf(fout, ";R:\tclase:	clase_escalar\n");
			}
		| clase_vector
			{
				clase_actual = VECTOR;
				strcpy(nombre_clase_desde, $1.atributos.lexema);
				fprintf(fout, ";R:\tclase:	clase_vector\n");
			}
		| clase_objeto
			{

				clase_actual = OBJETO;
				strcpy(nombre_clase_desde, $1.atributos.lexema);
				fprintf(fout, ";R:\tclase:	clase_objeto\n");
			}
		;

declaracion_clase:	abrirAmbitoClase TOK_INHERITS identificadores '{' declaraciones_funcion funciones '}' cerrarAmbitoClase
						{
							fprintf(fout, ";R:\tdeclaracion_clase:	modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones_funcion funciones '}'\n");
						}
					| abrirAmbitoClase '{' declaraciones_funcion funciones '}'
						{
							fprintf(fout, ";R:\tdeclaracion_clase:	modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones_funcion funciones '}'\n");
						}
					;

abrirAmbitoClase: 	modificadores_clase TOK_CLASS TOK_IDENTIFICADOR
					{
						/* Abrimos el ambito de la clase */
						if(!abrirClase(p_omicron, $3.lexema)) {
							fprintf(stdout,"ERROR AL ABRIR CLASE :%d:%d\n", line_count, col_count);
							return -1;
						}

						if(!abrirAmbitoClase(p_omicron, $3.lexema, 0)){
					        fprintf(stdout, "ERROR AL ABRIR AMBITO CLASE :%d:%d\n", error);
					        return 0;
					    }

					}

modificadores_clase: /*vacio*/
						{
							fprintf(fout, ";R:\tmodificadores_clase: \n");
						}
					;

clase_escalar: 	tipo 
					{
						fprintf(fout, ";R:\tclase_escalar: tipo\n");
					}
				;

tipo: 	TOK_INT 
			{
				tipo_actual = INT;
				$$.tipo = INT;
				fprintf(fout, ";R:\ttipo: 	TOK_INT \n");
			} 
		| TOK_BOOLEAN 
			{	
				tipo_actual = BOOLEAN;
				$$.tipo = BOOLEAN;
				fprintf(fout, ";R:\ttipo: 	TOK_BOOLEAN  \n");
			}
		;

clase_objeto: 	'{' TOK_IDENTIFICADOR '}'
					{
						fprintf(fout, ";R:\tclase_objeto: 	'{' TOK_IDENTIFICADOR '}'\n");
					}
				;

clase_vector: 	TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'
					{
						fprintf(fout, ";R:\tclase_vector: 	TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'\n");
					}
				;

identificadores: 	TOK_IDENTIFICADOR 
						{
							tsa** ambito_encontrado = NULL;
							tsa_elem** elem = NULL;
							fprintf(fout, ";R:\tidentificadores: 	TOK_IDENTIFICADOR \n");

							if (buscarParaDeclararIdMain(tabla_simbolos, strcat("_", $1.lexema), ambito_encontrado, elem) == OK)
							    {
							      	print_caso(fout, CASO_51, TSA_MAIN, ambito_encontrado[0], elem[0]);
									return -1;
							    }
							    else 
							    {
							    	insertarSimboloEnMain(tabla_simbolos, strcat("_", $1.lexema), VARIABLE, tipo_actual, clase_actual,0, 
        								0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, EXPOSED, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
							    }
							buscarIdNoCualificado(p_omicron, $1.atributos.lexema, nombre_clase_desde, tsa_aux, elem_aux);

						}
					| TOK_IDENTIFICADOR ',' identificadores
						{
							fprintf(fout, ";R:\tidentificadores:	TOK_IDENTIFICADOR ',' identificadores\n");
							if (buscarIdNoCualificado(p_omicron, $1.atributos.lexema, nombre_clase_desde, tsa_aux, elem_aux) == TRUE) {
								/* EL identificador ya existe en la tabla de simbolos */

							}
						}
					;

funciones: 	/*vacio*/
				{
					fprintf(fout, ";R:\tfunciones: \n");
				}
			| funcion funciones
				{
					fprintf(fout, ";R:\tfunciones: funcion funciones\n");
				}
			;

funcion: 	TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR 
			'(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'
				{
					fprintf(fout, ";R:\tfuncion: 	TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");
				}
			;

tipo_retorno:	TOK_NONE
					{
						fprintf(fout, ";R:\ttipo_retorno:	TOK_NONE\n");
					}
				| tipo
					{
						fprintf(fout, ";R:\ttipo_retorno:	tipo\n");
					}
				;

parametros_funcion:	parametro_funcion resto_parametros_funcion
						{
							fprintf(fout, ";R:\tparametros_funcion:	parametro_funcion resto_parametros_funcion\n");
						}
					| /*vacio*/
						{
							fprintf(fout, ";R:\tparametros_funcion: \n");
						}
					;

resto_parametros_funcion:	';' parametro_funcion resto_parametros_funcion 
								{
									fprintf(fout, ";R:\tresto_parametros_funcion:	';' parametro_funcion resto_parametros_funcion \n");
								}
							| /*vacio*/
								{
									fprintf(fout, ";R:\tresto_parametros_funcion: \n");
								}
							;

idpf:	TOK_IDENTIFICADOR
			{
				fprintf(fout, ";R:\tidpf: TOK_IDENTIFICADOR\n");
			}

parametro_funcion:	tipo idpf
						{
							fprintf(fout, ";R:\tparametro_funcion:	tipo idpf\n");
						}
					;

declaraciones_funcion:	 declaraciones 
							{
								fprintf(fout, ";R:\tdeclaraciones_funcion:	 declaraciones \n");
							}
						| /*vacio*/
							{
								fprintf(fout, ";R:\tdeclaraciones_funcion:	 \n");
							}
						;

sentencias:	sentencia 
				{
					fprintf(fout, ";R:\tsentencias:	sentencia \n");
				}
			| sentencia sentencias
				{
					fprintf(fout, ";R:\tsentencias:	sentencia sentencias \n");
				}
			;

sentencia:	sentencia_simple ';' 
				{
					fprintf(fout, ";R:\tsentencia:	sentencia_simple ';' \n");
				}
			| bloque
				{
					fprintf(fout, ";R:\tsentencia:	bloque\n");
				}
			;

sentencia_simple:	asignacion
						{
							fprintf(fout, ";R:\tsentencia_simple:	asignacion\n");
						}
					| lectura 
						{
							fprintf(fout, ";R:\tsentencia_simple:	lectura\n");
						}
					| escritura 
						{
							fprintf(fout, ";R:\tsentencia_simple:	escritura\n");
						}
					| retorno_funcion 
						{
							fprintf(fout, ";R:\tsentencia_simple:	retorno_funcion\n");
						}
					| identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
						{
							fprintf(fout, ";R:\tsentencia_simple:	identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
						}
					|  TOK_IDENTIFICADOR '(' lista_expresiones ')' 
						{
							fprintf(fout, ";R:\tsentencia_simple:	TOK_IDENTIFICADOR '(' lista_expresiones ')' \n");
						}
					| destruir_objeto
						{
							fprintf(fout, ";R:\tsentencia_simple:	destruir_objeto\n");
						}
					;

destruir_objeto: 	TOK_DISCARD TOK_IDENTIFICADOR
						{
							fprintf(fout, ";R:\tdestruir_objeto: 	TOK_DISCARD TOK_IDENTIFICADOR\n");
						}
					;

bloque:	condicional
			{
				fprintf(fout, ";R:\tbloque:	condicional\n");
			}
		| bucle
			{
				fprintf(fout, ";R:\tbloque:	bucle\n");
			}
		;

asignacion:	TOK_IDENTIFICADOR '=' exp
				{
					tsa** tsa_encontrada = NULL;
					tsa_elem** elem = NULL;
					if (buscarIdNoCualificado(tabla_simbolos, strcat("_", $1.lexema), TSA_MAIN, tsa_encontrada, elem) == FALSE){
						      	print_caso(fout, CASO_23, TSA_MAIN, tsa_encontrada[0], elem[0]);
								return -1;
						}
					if (elem[0]->categoria == FUNCION){
						fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
						return -1;
					}
					if (elem[0]->clase == VECTOR){
						fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
						return -1;
					}
					$$.tipo = elem[0]->tipo;
					$$.es_direccion = 1;
					escribir_operando(asmfile, strcat("_", $1.lexema), $$.es_direccion);
					fprintf(fout, ";R:\tasignacion:	TOK_IDENTIFICADOR '=' exp\n");
				}
			| elemento_vector '=' exp
				{
					fprintf(fout, ";R:\tasignacion:	elemento_vector '=' exp\n");
				}
			| elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
				{
					fprintf(fout, ";R:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
				}
			| TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
				{
					fprintf(fout, ";R:\tasignacion: TOK_IDENTIFICADOR '='TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
				}
			| identificador_clase '.' TOK_IDENTIFICADOR '=' exp
				{
					fprintf(fout, ";R:\tasignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");
				}
			;

elemento_vector:	TOK_IDENTIFICADOR '[' exp ']'
						{
							fprintf(fout, ";R:\telemento_vector:	TOK_IDENTIFICADOR '[' exp ']'\n");
						}
					;

condicional:	if_exp ')' '{' sentencias '}' 
					{
						fprintf(fout, ";R:\tcondicional:	if_exp ')' '{' sentencias '}' \n");
					}
				| if_exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'
					{
						fprintf(fout, ";R:\tcondicional:	if_exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}'\n");
					}
				;

if_exp:	TOK_IF '(' exp
			{
				if($3.tipo != BOOLEAN){
					fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
					return -1;
				}
				fprintf(fout, ";R:\tif_exp:	TOK_IF '(' exp \n");
			}
			;

bucle:	while_exp ')' '{' sentencias '}'
			{
				fprintf(fout, ";R:\tbucle: 	while_exp ')' '{' sentencias '}'\n");
			}
		;

while_exp:	TOK_WHILE '(' exp
				{
					if($3.tipo != BOOLEAN) {
						fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
						return -1;
					}
					fprintf(fout, ";R:\twhile_exp:	TOK_WHILE '(' exp \n");
				}
				;

lectura:	TOK_SCANF TOK_IDENTIFICADOR 
				{
					fprintf(fout, ";R:\tlectura:	TOK_SCANF TOK_IDENTIFICADOR \n");
				}
			| TOK_SCANF elemento_vector
				{
					fprintf(fout, ";R:\tlectura:	TOK_SCANF elemento_vector \n");
				}
			;

escritura:	TOK_PRINTF exp
				{
					if ($2.es_direccion)
						asignar(asmfile, strcat("_", $2.lexema), $2.es_direccion);
					escribir(asmfile, $2.es_direccion, $2.tipo);
					fprintf(fout, ";R:\tescritura:	TOK_PRINTF exp\n");
				}
			;

retorno_funcion:	TOK_RETURN exp
						{
							fprintf(fout, ";R:\tretorno_funcion:	TOK_RETURN exp\n");
						}
					| TOK_RETURN TOK_NONE
						{
							fprintf(fout, ";R:\tretorno_funcion:	TOK_RETURN TOK_NONE\n");
						}
					;
exp:	exp '+' exp
			{
				if($1.tipo == INT && $3.tipo == INT){
					$$.tipo = 1;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp '+' exp\n");
			}
		| exp '-' exp
			{
				if($1.tipo == INT && $3.tipo == INT){
					$$.tipo = 1;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp '-' exp\n");
			}
		| exp '/' exp
			{
				if($1.tipo == INT && $3.tipo == INT){
					$$.tipo = 1;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp '/' exp\n");
			}
		| exp '*' exp
			{
				if($1.tipo == INT && $3.tipo == INT){
					$$.tipo = 1;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp '*' exp\n");
			}
		| '-' exp %prec MENOSU
			{
				if($2.tipo == INT){
					$$.tipo = 1;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	'-' exp\n");
			}
		| exp TOK_AND exp
			{
				if($1.tipo == BOOLEAN && $3.tipo == BOOLEAN){
					$$.tipo = BOOLEAN;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp TOK_AND exp\n");
			}
		| exp TOK_OR exp
			{
				if($1.tipo == BOOLEAN && $3.tipo == BOOLEAN){
					$$.tipo = BOOLEAN;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp TOK_OR exp\n");
			}
		| '!' exp
			{
				if($2.tipo == BOOLEAN){
					$$.tipo = BOOLEAN;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	'!' exp\n");
			}
		| TOK_IDENTIFICADOR
			{
				fprintf(fout, ";R:\texp:	TOK_IDENTIFICADOR\n");
			}
		| constante 
			{
				$$.tipo = $1.tipo;
				$$.es_direccion = $1.es_direccion;
				fprintf(fout, ";R:\texp:	constante \n");
			}
		| '(' exp ')'
			{
				$$.tipo = $2.tipo;
				$$.es_direccion = $2.es_direccion;
				fprintf(fout, ";R:\texp:	'(' exp ')'\n");
			}
		| '(' comparacion ')'
			{
				$$.tipo = $2.tipo;
				$$.es_direccion = $2.es_direccion;
				fprintf(fout, ";R:\texp:	'(' comparacion ')'\n");
			}
		| elemento_vector
			{
				$$.tipo = $1.tipo;
				$$.es_direccion = $1.es_direccion;
				fprintf(fout, ";R:\texp:	elemento_vector\n");
			}
		| TOK_IDENTIFICADOR '(' lista_expresiones ')'
			{
				fprintf(fout, ";R:\texp:	TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
			}
		| identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
			{
				fprintf(fout, ";R:\texp:	identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
			}
		| identificador_clase '.' TOK_IDENTIFICADOR
			{
				fprintf(fout, ";R:\texp:	identificador_clase '.' TOK_IDENTIFICADOR\n");
			}
		;

identificador_clase:	TOK_IDENTIFICADOR
							{

								strcpy($$.lexema,$1.lexema);
								strcpy($$.atributos.lexema, $1.atributos.lexema);

								fprintf(fout, ";R:\tidentificador_clase:	TOK_IDENTIFICADOR\n");
							} 
						| TOK_ITSELF
							{
								fprintf(fout, ";R:\tidentificador_clase:	TOK_ITSELF\n");
							}
						;

lista_expresiones: 	exp resto_lista_expresiones 
						{
							fprintf(fout, ";R:\tlista_expresiones:	exp resto_lista_expresiones \n");
						}
					| /*vacio*/
						{
							fprintf(fout, ";R:\tlista_expresiones:	\n");
						}
					;

resto_lista_expresiones:	',' exp resto_lista_expresiones 
								{
									fprintf(fout, ";R:\tresto_lista_expresiones:	',' exp resto_lista_expresiones \n");
								}
							| /*vacio*/
								{
									fprintf(fout, ";R:\tresto_lista_expresiones:	\n");
								}
							;

comparacion:	exp TOK_IGUAL exp 
					{	
						if($1.tipo == INT && $3.tipo == INT){
							$$.tipo = BOOLEAN;
							$$.es_direccion = 0;
						}
						else {
							fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
							return -1;
						}
						fprintf(fout, ";R:\tcomparacion:	exp TOK_IGUAL exp \n");
					}
				| exp TOK_DISTINTO exp
					{
						if($1.tipo == INT && $3.tipo == INT){
							$$.tipo = BOOLEAN;
							$$.es_direccion = 0;
						}
						else {
							fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
							return -1;
						}
						fprintf(fout, ";R:\tcomparacion:	exp TOK_DISTINTO exp\n");
					}
				| exp TOK_MAYORIGUAL exp
					{
						if($1.tipo == INT && $3.tipo == INT){
							$$.tipo = BOOLEAN;
							$$.es_direccion = 0;
						}
						else {
							fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
							return -1;
						}
						fprintf(fout, ";R:\tcomparacion:	exp TOK_MAYORIGUAL exp\n");
					}
				| exp TOK_MENORIGUAL exp
					{
						if($1.tipo == INT && $3.tipo == INT){
							$$.tipo = BOOLEAN;
							$$.es_direccion = 0;
						}
						else {
							fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
							return -1;
						}
						fprintf(fout, ";R:\tcomparacion:	exp TOK_MENORIGUAL exp\n");
					}
				| exp '>' exp
					{
						if($1.tipo == INT && $3.tipo == INT){
							$$.tipo = BOOLEAN;
							$$.es_direccion = 0;
						}
						else {
							fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
							return -1;
						}
						fprintf(fout, ";R:\tcomparacion:	exp '>' exp\n");
					}
				| exp '<' exp
					{
						if($1.tipo == INT && $3.tipo == INT){
							$$.tipo = BOOLEAN;
							$$.es_direccion = 0;
						}
						else {
							fprintf(stdout,"ERROR SEMÁNTICO:%d:%d\n", line_count, col_count);
							return -1;
						}
						fprintf(fout, ";R:\tcomparacion:	exp '<' exp\n");
					}
				;

constante:	constante_logica 
				{
					$$.tipo = $1.tipo;
					$$.es_direccion = $1.es_direccion;
					fprintf(fout, ";R:\tconstante:	constante_logica \n");
				}
			| constante_entera
				{	
					$$.tipo = $1.tipo;
					$$.es_direccion = $1.es_direccion;
					fprintf(fout, ";R:\tconstante:	constante_entera \n");
				}
			;

constante_logica:	TOK_TRUE 
						{
							$$.tipo = BOOLEAN;
							$$.es_direccion = 0;
							fprintf(fout, ";R:\tconstante_logica:	TOK_TRUE \n");
						}
					| TOK_FALSE
						{
							$$.tipo = BOOLEAN;
							$$.es_direccion = 0;
							fprintf(fout, ";R:\tconstante_logica:	TOK_FALSE \n");
						}
					;

constante_entera: TOK_CONSTANTE_ENTERA
				{	
					$$.tipo = INT;
					$$.es_direccion = 0;
					fprintf(fout, ";R:\tconstante_entera:	TOK_CONSTANTE_ENTERA \n");
				}
				;


%%

void yyerror(char* s) {
	fprintf(stdout,"ERROR SINTACTICO:%d:%d\n", line_count, col_count);
}