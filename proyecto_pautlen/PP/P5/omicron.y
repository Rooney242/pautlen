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
	int etiqueta = 1;

	int tipo_actual;                                                                
	int clase_actual;
	int * tipo_parametros;
	int pos_parametro_actual;
   	int num_parametros_actual;
	int tamanio_vector_actual;
	int ambito;

	tsc * tabla_simbolos;
    tsa* tsa_aux;
    tsa_elem * elem_aux;

    char nombre_clase_desde[ID_MAX];
    char nombre_ambito_desde[ID_MAX];


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
%type <atributos> clase
%type <atributos> clase_escalar
%type <atributos> clase_vector
%type <atributos> clase_objeto
%type <atributos> condicional
%type <atributos> if_exp_sentencias
%type <atributos> if_exp
%type <atributos> exp
%type <atributos> asignacion
%type <atributos> identificador_clase
%type <atributos> elemento_vector
%type <atributos> constante_logica
%type <atributos> constante_entera
%type <atributos> parametros_funcion
%type <atributos> funcion
%type <atributos> resto_parametros_funcion
%type <atributos> lista_expresiones
%type <atributos> resto_lista_expresiones
%type <atributos> fn_name
%type <atributos> idpf
%type <atributos> fn_complete_name
%type <atributos> tipo_retorno
%type <atributos> sentencia_simple
%type <atributos> retorno_funcion
%type <atributos> fn_declaration


%start programa
%left '+' '-' TOK_OR
%left '*' '/' TOK_AND
%right MENOSU '!'
%%

programa: 	inicio_tsc TOK_MAIN '{' escritura1 declaraciones escritura2 funciones escritura_main sentencias '}' 
				{ 
					fprintf(fout, ";R:\tprograma: 	TOK_MAIN '{' declaraciones funciones sentencias '}'\n");
				}	
			| inicio_tsc TOK_MAIN '{' escritura1 escritura2 funciones escritura_main sentencias '}'
				{
					fprintf(fout, ";R:\tprograma: 	TOK_MAIN '{' funciones sentencias '}'\n");
				}	
			;

inicio_tsc:		{
  					tabla_simbolos = init_tsc("TSC_Omicron");
         	 	}
          		;


escritura1: 	{
					strcpy(nombre_clase_desde,TSA_MAIN); 
					ambito = 0;
  					escribir_subseccion_data(asmfile);
    				escribir_cabecera_bss(asmfile);
         	 	}
          		;

escritura2: 	{
          		    escribir_segmento_codigo(asmfile);
         	 	}
          		;

escritura_main: {
    				escribir_inicio_main(asmfile);
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
				//strcpy(nombre_clase_desde, $1.lexema);
				fprintf(fout, ";R:\tclase:	clase_escalar\n");
			}
		| clase_vector
			{
				clase_actual = VECTOR;
				//strcpy(nombre_clase_desde, $1.lexema);
				fprintf(fout, ";R:\tclase:	clase_vector\n");
			}
		| clase_objeto
			{

				clase_actual = OBJETO;
				//strcpy(nombre_clase_desde, $1.lexema);
				fprintf(fout, ";R:\tclase:	clase_objeto\n");
			}
		;

declaracion_clase:	abrirAmbitoClase TOK_INHERITS identificadores '{' declaraciones_funcion funciones '}'
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
						/* Abrimos el ambito de la clase 
						if(!abrirClase(tabla_simbolos, $3.lexema)) {
							fprintf(stdout,"ERROR AL ABRIR CLASE :%d:%d\n", line_count, col_count);
							return -1;
						}

						if(!abrirAmbitoClase(tabla_simbolos, $3.lexema, 0)){
					        fprintf(stdout, "ERROR AL ABRIR AMBITO CLASE :%d:%d\n", line_count, col_count);
					        return 0;
					    }
						*/
					}
					;

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
						tamanio_vector_actual = atoi($4.valor_entero);
						if (tamanio_vector_actual < 1 || tamanio_vector_actual > MAX_TAMANIO_VECTOR) {
							fprintf(stdout,"****Error semantico en lin %d:\n\tEl tamanyo del vector <%s> excede los limites permitidos (1,64).\n", line_count, nombre_clase_desde);
							return -1;
						}
						fprintf(fout, ";R:\tclase_vector: 	TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'\n");
					}
				;

identificadores: 	TOK_IDENTIFICADOR 
						{
							tsa* ambito_encontrado = NULL;
							tsa_elem* elem = NULL;
							char * real_id;
							fprintf(fout, ";R:\tidentificadores: 	TOK_IDENTIFICADOR \n");

							if (buscarParaDeclararIdMain(tabla_simbolos, $1.lexema, &ambito_encontrado, &elem) > 0)
						    {
								fprintf(stdout,"****Error semantico en lin %d: Declaracion duplicada.\n", line_count);	
								return -1;
						    }
						    else 
						    {
						    	if (clase_actual != VECTOR)
						    		tamanio_vector_actual = 0;
						    	insertarSimboloEnMain(tabla_simbolos, $1.lexema, VARIABLE, tipo_actual, clase_actual,0, 
    								0, 0, 0, 0, 0, 0, tamanio_vector_actual, 0, 0, 0, 0, 0, 0, 0, EXPOSED, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
						    	real_id = _concat_prefix(nombre_clase_desde, $1.lexema);
						    	declarar_variable(asmfile, real_id, tipo_actual, clase_actual);
						    	tamanio_vector_actual = 0;
						    	free(real_id);
						    }

						}
					| TOK_IDENTIFICADOR ',' identificadores
						{
							tsa* ambito_encontrado = NULL;
							tsa_elem* elem = NULL;
							char * real_id;
							fprintf(fout, ";R:\tidentificadores:	TOK_IDENTIFICADOR ',' identificadores\n");
							if (buscarParaDeclararIdMain(tabla_simbolos, $1.lexema, &ambito_encontrado, &elem) > 0)
						    {							      	
								fprintf(stdout,"****Error semantico en lin %d: Declaracion duplicada.\n", line_count);
								return -1;
						    }
						    else 
						    {
						    	if (clase_actual != VECTOR)
						    		tamanio_vector_actual = 0;
						    	insertarSimboloEnMain(tabla_simbolos, $1.lexema, VARIABLE, tipo_actual, clase_actual,0, 
    								0, 0, 0, 0, 0, 0, tamanio_vector_actual, 0, 0, 0, 0, 0, 0, 0, EXPOSED, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
						    	real_id = _concat_prefix(nombre_clase_desde, $1.lexema);
						    	declarar_variable(asmfile, real_id, tipo_actual, tamanio_vector_actual);
						    	tamanio_vector_actual = 0;
						    	free(real_id);
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

funcion: 	fn_declaration sentencias '}'
				{
					ambito = 0;
					cerrarAmbitoEnClase(tabla_simbolos, nombre_clase_desde, $1.lexema);
					fprintf(fout, ";R:\tfuncion: 	TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");
				}
			

fn_declaration:	fn_complete_name '{' declaraciones_funcion
				{
					strcpy($$.lexema,$1.lexema);
				}

fn_complete_name:	fn_name '(' param_init parametros_funcion ')' 
				{
					int i;
					int tipo = INT;
					char * real_id;
					char funcion[MAX_LONG_ID+1];
					strcpy(funcion,$1.lexema);

					for(i=0;i<num_parametros_actual;i++){
						strcat(funcion,"@");
						strcat(funcion,tipo_parametros[0]);
					}
					if($1.tipo == BOOLEAN)
						tipo = BOOLEAN;
					abrirAmbitoEnClase(tabla_simbolos, nombre_clase_desde, funcion, METODO_SOBREESCRIBIBLE, EXPOSED, tipo, 0, 0);
					real_id = _concat_prefix(nombre_clase_desde, funcion);
					declararFuncion(asmfile, real_id, num_parametros_actual);
					strcpy(nombre_ambito_desde, real_id);
    				free(real_id);
					strcpy($$.lexema, funcion);
					ambito = 1;
				}

param_init:	{
				num_parametros_actual = 0;
				free(tipo_parametros);
			}

fn_name: 	TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR 
				{
					strcpy($$.lexema,$4.lexema);
					$$.tipo = $3.tipo;
				}

			


tipo_retorno:	TOK_NONE
					{
						fprintf(fout, ";R:\ttipo_retorno:	TOK_NONE\n");
					}
				| tipo
					{
						$$.tipo=$1.tipo;
						fprintf(fout, ";R:\ttipo_retorno:	tipo\n");
					}
				| clase_objeto
					{
						$$.tipo=$1.tipo;
						fprintf(fout, ";R:\ttipo_retorno:	clase_objeto\n");
					}
				;

parametros_funcion:	parametro_funcion resto_parametros_funcion
						{
							//$$.num_parametros = 1 + $2.num_parametros;
							fprintf(fout, ";R:\tparametros_funcion:	parametro_funcion resto_parametros_funcion\n");
						}
					| /*vacio*/
						{
							//$$.num_parametros = 0;
							fprintf(fout, ";R:\tparametros_funcion: \n");
						}
					;

resto_parametros_funcion:	';' parametro_funcion resto_parametros_funcion 
								{
									//$$.num_parametros = 1 + $2.num_parametros;
									fprintf(fout, ";R:\tresto_parametros_funcion:	';' parametro_funcion resto_parametros_funcion \n");
								}
							| /*vacio*/
								{
									//$$.num_parametros = 0;
									fprintf(fout, ";R:\tresto_parametros_funcion: \n");
								}
							;

idpf:	TOK_IDENTIFICADOR
			{	
				tsa* tsa_encontrada = NULL;
				tsa_elem* elem = NULL;
				if (buscarIdNoCualificado(tabla_simbolos, $1.lexema, nombre_clase_desde, &tsa_encontrada, &elem) < 0) {
					fprintf(stdout,"****Error semantico en lin %d: Acceso a variable no declarada (%s).", line_count, $1.lexema);
					return -1;
				}
				num_parametros_actual ++;	
				tipo_parametros = (int*)realloc(tipo_parametros, num_parametros_actual*sizeof(int));
				fprintf(fout, ";R:\tidpf: TOK_IDENTIFICADOR\n");
			}

parametro_funcion:	tipo idpf
						{
							fprintf(fout, ";R:\tparametro_funcion:	tipo idpf\n");
						}
					| clase_objeto TOK_IDENTIFICADOR
						{
							fprintf(fout, ";R:\tparametro_funcion:	clase_objeto TOK_IDENTIFICADOR\n");
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
							retornarFuncion(asmfile, $1.tipo);
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
					tsa* tsa_encontrada = NULL;
					tsa_elem* elem = NULL;
					if (buscarIdNoCualificado(tabla_simbolos, $1.lexema, nombre_clase_desde, &tsa_encontrada, &elem) < 0) {
						fprintf(stdout,"****Error semantico en lin %d: Acceso a variable no declarada (%s).", line_count, $1.lexema);
						return -1;
					}
					
					if (elem->categoria == FUNCION){
						fprintf(stdout,"****Error semantico en lin %d: Asignacion incompatible.\n", line_count);
						return -1;
					}
					if (elem->clase == VECTOR){
						fprintf(stdout,"****Error semantico en lin %d: Asignacion incompatible.\n", line_count);
						return -1;
					}
					if($3.tipo != elem->tipo){
						fprintf(stdout,"****Error semantico en lin %d: Asignacion incompatible.\n", line_count);
						return -1;
					}
					asignar(asmfile, elem->id, $3.es_direccion);
					fprintf(fout, ";R:\tasignacion:	TOK_IDENTIFICADOR '=' exp\n");
				}
			| elemento_vector '=' exp
				{
					if($1.tipo != $3.tipo){
						fprintf(stdout,"****Error semantico en lin %d: Asignacion incompatible.\n", line_count);
						return -1;
					}
					asignarDestinoEnPila(asmfile, $3.es_direccion);
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
							tsa* tsa_encontrada = NULL;
							tsa_elem* elem = NULL;

							if (buscarIdNoCualificado(tabla_simbolos, $1.lexema, nombre_clase_desde, &tsa_encontrada, &elem) < 0){
								fprintf(stdout,"****Error semantico en lin %d: Acceso a variable no declarada (%s).", line_count, $1.lexema);
								return -1;
							}

							if ($3.tipo != INT){
								fprintf(stdout,"****Error semantico en lin %d: El indice en una operacion de indexacion tien que ser de tipo entero.", line_count);
								return -1;
							}
							$$.tipo = elem->tipo;
							escribir_elemento_vector(asmfile, elem->id, elem->tamanio, $3.es_direccion);
							fprintf(fout, ";R:\telemento_vector:	TOK_IDENTIFICADOR '[' exp ']'\n");
						}
					;

condicional:	if_exp ')' '{' sentencias '}' 
					{
						ifthen_fin(asmfile, $1.etiqueta);
						fprintf(fout, ";R:\tcondicional:	if_exp ')' '{' sentencias '}' \n");
					}
				| if_exp_sentencias TOK_ELSE '{' sentencias '}'
					{
						ifthenelse_fin(asmfile, $1.etiqueta);
						fprintf(fout, ";R:\tcondicional:	if_exp_sentencias TOK_ELSE '{' sentencias '}'\n");
					}
				;

if_exp_sentencias:	if_exp sentencias '}'
					{
						$$.etiqueta = $1.etiqueta;
						ifthenelse_fin_then(asmfile, $1.etiqueta);
						fprintf(fout, ";R:\tif_exp_sentencias:	if_exp sentencias '}'\n");
					}

if_exp:	TOK_IF '(' exp ')' '{' 
			{
				if($3.tipo != BOOLEAN){
					fprintf(stdout,"****Error semantico en lin %d: Condicional con condicion de tipo int.\n", line_count);
					return -1;
				}
				$$.etiqueta = etiqueta ++;
				ifthenelse_inicio(asmfile, $3.es_direccion, $$.etiqueta);
				fprintf(fout, ";R:\tif_exp:	TOK_IF '(' exp ')' '{' \n");
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
						fprintf(stdout,"****Error semantico en lin %d: Bucle con condicion de tipo int.\n", line_count);
						return -1;
					}
					fprintf(fout, ";R:\twhile_exp:	TOK_WHILE '(' exp \n");
				}
				;

lectura:	TOK_SCANF TOK_IDENTIFICADOR 
				{
					tsa * tsa_encontrada = NULL;
					tsa_elem* elem = NULL;
					/* Si al buscar el identificdor en la tabla de símbolos, no está... salir con ERROR */
					if (buscarIdNoCualificado(tabla_simbolos, $2.lexema, nombre_clase_desde, &tsa_encontrada, &elem) < 0){
						fprintf(stdout,"****Error semantico en lin %d: Acceso a variable no declarada (%s).", line_count, $2.lexema);
						return -1;
					}
					if (elem->categoria == FUNCION){
						fprintf(stdout,"****Error semantico en lin %d: Asignacion incompatible.", line_count);
						return -1;
					}
					if (elem->clase == VECTOR){
						fprintf(stdout,"****Error semantico en lin %d: Asignacion incompatible.", line_count);
						return -1;
					}
					leer(asmfile, elem->id,  elem->tipo);
					fprintf(fout, ";R:\tlectura:	TOK_SCANF TOK_IDENTIFICADOR \n");
				}
			| TOK_SCANF elemento_vector
				{
					fprintf(fout, ";R:\tlectura:	TOK_SCANF elemento_vector \n");
				}
			;

escritura:	TOK_PRINTF exp
				{
					//Hacer para ambitos esto_concat_prefix(t->main->ambito, nombre_id)
					char * real_id;
					if ($2.es_direccion){
						real_id = _concat_prefix(nombre_clase_desde, $2.lexema);
						escribir_operando(asmfile, real_id, $2.es_direccion);
						free(real_id);
					}
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
					sumar(asmfile, $1.es_direccion, $3.es_direccion);
					$$.tipo = 1;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion aritmetica con operandos boolean.", line_count);	
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp '+' exp\n");
			}
		| exp '-' exp
			{
				if($1.tipo == INT && $3.tipo == INT){
					restar(asmfile, $1.es_direccion, $3.es_direccion);
					$$.tipo = 1;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion aritmetica con operandos boolean.", line_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp '-' exp\n");
			}
		| exp '/' exp
			{
				if($1.tipo == INT && $3.tipo == INT){
					dividir(asmfile, $1.es_direccion, $3.es_direccion);
					$$.tipo = 1;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion aritmetica con operandos boolean.", line_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp '/' exp\n");
			}
		| exp '*' exp
			{
				if($1.tipo == INT && $3.tipo == INT){
					multiplicar(asmfile, $1.es_direccion, $3.es_direccion);
					$$.tipo = 1;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion aritmetica con operandos boolean.", line_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp '*' exp\n");
			}
		| '-' exp %prec MENOSU
			{
				if($2.tipo == INT){
					cambiar_signo(asmfile,  $2.es_direccion);
					$$.tipo = 1;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion aritmetica con operandos boolean.", line_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	'-' exp\n");
			}
		| exp TOK_AND exp
			{
				if($1.tipo == BOOLEAN && $3.tipo == BOOLEAN){
					y(asmfile, $1.es_direccion, $3.es_direccion);
					$$.tipo = BOOLEAN;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion logica con operandos int.", line_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp TOK_AND exp\n");
			}
		| exp TOK_OR exp
			{
				if($1.tipo == BOOLEAN && $3.tipo == BOOLEAN){
					o(asmfile, $1.es_direccion, $3.es_direccion);
					$$.tipo = BOOLEAN;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion logica con operandos int.", line_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp TOK_OR exp\n");
			}
		| '!' exp
			{
				if($2.tipo == BOOLEAN){
					no(asmfile, $2.es_direccion, etiqueta);
					etiqueta ++;
					$$.tipo = BOOLEAN;
					$$.es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion logica con operandos int.", line_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	'!' exp\n");
			}
		| TOK_IDENTIFICADOR
			{
				tsa* tsa_encontrada = NULL;
				tsa_elem* elem = NULL;
				if (buscarIdNoCualificado(tabla_simbolos, $1.lexema, nombre_clase_desde, &tsa_encontrada, &elem) < 0){
							return -1;
					}
				if (elem->categoria == FUNCION){
					fprintf(stdout,"****Error semantico en lin %d: Asignacion incompatible.", line_count);
					return -1;
				}
				if (elem->clase == VECTOR){
					fprintf(stdout,"****Error semantico en lin %d: Asignacion incompatible.", line_count);
					return -1;
				}
				$$.tipo = elem->tipo;
				$$.es_direccion = 1;
				escribir_operando(asmfile, elem->id, $$.es_direccion);
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
				$$.es_direccion = 1;
				fprintf(fout, ";R:\texp:	elemento_vector\n");
			}
		| TOK_IDENTIFICADOR '(' lista_expresiones ')'
			{
				if ($3.num_expresiones != get_parameters_from_function(tabla_simbolos, $1.lexema)){
					fprintf(stdout,"****Error semantico en lin %d: Numero de argumentos en la funcion \"%s\" incorrecto", line_count, $1.lexema);
					return -1;
				}
				fprintf(fout, ";R:\texp:	TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
			}
		| identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
			{
				if ($5.num_expresiones != get_parameters_from_function(tabla_simbolos, $3.lexema)){
					fprintf(stdout,"****Error semantico en lin %d: Numero de argumentos en la funcion \"%s\" incorrecto", line_count, $1.lexema);
					return -1;
				}
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

								fprintf(fout, ";R:\tidentificador_clase:	TOK_IDENTIFICADOR\n");
							} 
						| TOK_ITSELF
							{
								fprintf(fout, ";R:\tidentificador_clase:	TOK_ITSELF\n");
							}
						;

lista_expresiones: 	exp resto_lista_expresiones 
						{
							$$.num_expresiones = 1 + $2.num_expresiones;
							fprintf(fout, ";R:\tlista_expresiones:	exp resto_lista_expresiones \n");
						}
					| /*vacio*/
						{
							$$.num_expresiones = 0;
							fprintf(fout, ";R:\tlista_expresiones:	\n");
						}
					;

resto_lista_expresiones:	',' exp resto_lista_expresiones 
								{
									$$.num_expresiones = 1 + $3.num_expresiones;
									fprintf(fout, ";R:\tresto_lista_expresiones:	',' exp resto_lista_expresiones \n");
								}
							| /*vacio*/
								{
									$$.num_expresiones = 0;
									fprintf(fout, ";R:\tresto_lista_expresiones:	\n");
								}
							;

comparacion:	exp TOK_IGUAL exp 
					{	
						if($1.tipo == INT && $3.tipo == INT){
							igual(asmfile, $1.es_direccion, $3.es_direccion, etiqueta);
							etiqueta ++;
							$$.tipo = BOOLEAN;
							$$.es_direccion = 0;
						}
						else {
							fprintf(stdout,"****Error semantico en lin %d: Comparacion con operandos boolean", line_count);
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
							fprintf(stdout,"****Error semantico en lin %d: Comparacion con operandos boolean", line_count);
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
							fprintf(stdout,"****Error semantico en lin %d: Comparacion con operandos boolean", line_count);
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
							fprintf(stdout,"****Error semantico en lin %d: Comparacion con operandos boolean", line_count);
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
							fprintf(stdout,"****Error semantico en lin %d: Comparacion con operandos boolean", line_count);
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
							fprintf(stdout,"****Error semantico en lin %d: Comparacion con operandos boolean", line_count);
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
					strcpy($$.valor_entero, $1.valor_entero);
					escribir_operando(asmfile, $1.valor_entero, 0);
					fprintf(fout, ";R:\tconstante_entera:	TOK_CONSTANTE_ENTERA \n");
				}
				;


%%

void yyerror(char* s) {
	fprintf(stdout,"ERROR SINTACTICO:%d:%d\n", line_count, col_count);
}

