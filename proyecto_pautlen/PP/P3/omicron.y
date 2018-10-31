%{	
	#include <stdlib.h>
	#include <stdio.h>
	extern int line_count;
	extern int col_count;	
	extern FILE* fout;
%}


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
%token TOK_IDENTIFICADOR    

/* OPERADORES */
%token TOK_IGUAL    
%token TOK_DISTINTO    
%token TOK_MENORIGUAL   
%token TOK_MAYORIGUAL   
%token TOK_OR   
%token TOK_AND   

/* CONSTANTES */
%token TOK_CONSTANTE_ENTERA  
%token TOK_FALSE     
%token TOK_TRUE    


/* ERRORES */
%token TOK_ERROR

%start programa
%left '+' '-' TOK_OR
%left '*' '/' TOK_AND
%right MENOSU '!'
%%

programa: 	TOK_MAIN '{' declaraciones funciones sentencias '}'
			| TOK_MAIN '{' funciones sentencias '}'
			;
declaraciones:	declaracion
				| declaracion declaraciones
				;
declaracion:	modificador_acceso clase identificadores ';'
				| modificador_acceso declaracion_clase ';'
				;
modificador_acceso: /*vacio*/
					| TOK_HIDDEN TOK_UNIQUE
					| TOK_SECRET TOK_UNIQUE
					| TOK_EXPOSED TOK_UNIQUE
					| TOK_HIDDEN 
					| TOK_SECRET
					| TOK_EXPOSED
					| TOK_UNIQUE
					;
clase:	clase_escalar
		| clase_vector
		| clase_objeto
		;
declaracion_clase:	modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones funciones '}'
					| modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'
					;
modificadores_clase: /*vacio*/
					;
clase_escalar: tipo;
tipo: TOK_INT | TOK_BOOLEAN;
clase_objeto: '{' TOK_IDENTIFICADOR '}';
clase_vector: TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']';
identificadores: TOK_IDENTIFICADOR | TOK_IDENTIFICADOR ',' identificadores;
funciones: /*vacio*/ | funcion funciones;
funcion: TOK_FUNCTION modificador_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}';
tipo_retorno: TOK_NONE | tipo;
parametros_funcion: parametro_funcion resto_parametros_funcion | /*vacio*/;
resto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion | /*vacio*/;
parametro_funcion: tipo TOK_IDENTIFICADOR;
declaraciones_funcion: declaraciones | /*vacio*/;
sentencias: sentencia | sentencia sentencias;
sentencia: sentencia_simple ';' | bloque;
sentencia_simple: asignacion 	| lectura | escritura | retorno_funcion | identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
								|  TOK_IDENTIFICADOR '(' lista_expresiones ')' | destruir_objeto;
destruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR;
bloque: condicional | bucle;
asignacion: TOK_IDENTIFICADOR '=' exp | elemento_vector '=' exp | elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
			| TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
			| identificador_clase '.' TOK_IDENTIFICADOR '=' exp;

elemento_vector: TOK_IDENTIFICADOR '[' exp ']';
condicional: TOK_IF '(' exp ')' '{' sentencias '}' | TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '{' sentencias '}';
bucle: TOK_WHILE '(' exp ')' '{' sentencias '}';
lectura: TOK_SCANF TOK_IDENTIFICADOR | TOK_SCANF elemento_vector;
escritura: TOK_PRINTF exp;
retorno_funcion: TOK_RETURN exp | TOK_RETURN TOK_NONE;

exp:	exp '+' exp
		| exp '-' exp
		| exp '/' exp
		| exp '*' exp
		| '-' exp %prec MENOSU
		| exp TOK_AND exp
		| exp TOK_OR exp
		| '!' exp
		| TOK_IDENTIFICADOR
		| constante 
		| '(' exp ')'
		| '(' comparacion ')'
		| elemento_vector
		| TOK_IDENTIFICADOR '(' lista_expresiones ')'
		| identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
		| identificador_clase '.' TOK_IDENTIFICADOR
		;

identificador_clase: TOK_IDENTIFICADOR | TOK_ITSELF;
lista_expresiones: exp resto_lista_expresiones | /*vacio*/;
resto_lista_expresiones: ',' exp resto_lista_expresiones | /*vacio*/;
comparacion: exp TOK_IGUAL exp | exp TOK_DISTINTO exp | exp TOK_MAYORIGUAL exp | exp TOK_MENORIGUAL exp | exp '>' exp | exp '<' exp ;
constante: constante_logica | TOK_CONSTANTE_ENTERA;
constante_logica: TOK_TRUE | TOK_FALSE;


%%

void yyerror(char* s) {
	
}