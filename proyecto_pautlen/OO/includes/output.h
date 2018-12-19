#ifndef OUTPUT_H
#define OUTPUT_H

#include "tsa.h"
#include "tsc.h"
#include "hash_table.h"


#define CASO_1 1/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_2 2/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_3 3/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_4 4/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_5 5/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_6 6/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_7 7/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_8 8/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_9 9/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_10 10/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_11 11/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_12 -12/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_13 13/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_14 14/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_15 -15/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_16 16/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_17 17/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_18 -18/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
#define CASO_19 -19/*v10 BUSCAR ID EN JERARQUIA DESDE CLASE*/
/*
BUSCAR ID EN JERARQUIA DESDE CLASE

1: SE BUSCA SIN CUALIFICADOR UNA VARIABLE LOCAL DEFINIDA (vlmA1) EN EL PROPIO MÉTODO  ==> OK
2: SE BUSCA UN PARÁMETRO SIN CUALIFICAR DE UN MÉTODO (pmA1) QUE ESTÁ EN EL MÉTODO DESDE EL MÉTODO ==> OK
3: SE BUSCA DESDE UN MÉTODO, UN MÉTODO SIN CUALIFICAR QUE ES HIDDEN (mc1) Y QUE EXISTE EN EL MÉTODO ==> OK
4: SE BUSCA DESDE UN METODO, OTRO SIN CUALIFICAR QUE ES SECRET Y QUE ESTA DEFINIDO EN EL METODO (mD2) ==> OK
6: SE BUSCA DESDE UN MÉTODO OTRO SIN CUALIFICAR QUE ES HIDDEN Y QUE NO ESTÁ DEFINIDO EN EL MÉTODO PERO SI EN LA CLASE DEL METODO (mc0) ==> OK
7: SE BUSCA DESDE UN METODO, OTRO SIN CUALIFICAR QUE ES SECRET Y QUE NO ESTA EN EL METODO PERO SI EN SU CLASE (mD1)  ==> OK
8: SE BUSCA UN MÉTODO EXPOSED SIN CUALIFICAR (mA0) QUE EXISTE EN LA CLASE DEL MÉTODO, PERO NO EN EL MÉTODO ==> OK
9: SE BUSCA UN ATRIBUTO SIN CUALIFICAR QUE ES HIDDEN (sa2) Y QUE EXISTE EN LA CLASE DEL MÉTODO, PERO NO EN EL METODO ==> OK
10: SE BUSCA DESDE UN MÉTODO UN ATRIBUTO SIN CUALIFICAR QUE ES SECRET (sa1)  QUE EXISTE EN LA CLASE DEL MÉTODO, PERO NO EN EL MÉTODO  ==> OK
11: SE BUSCA DESDE UN MÉTODO UN ATRIBUTO SIN CUALIFICAR QUE ES EXPOSED (a1)  Y QUE EXISTE EN LA CLASE DEL MÉTODO PERO NO EN EL MÉTODO ==> OK
12: SE BUSCA DESDE UN MÉTODO, OTRO HIDDEN QUE NO ESTÁ EN EL MÉTODO, NI EN LA CLASE, PERO SÍ  EN LA JERARQUIA (mC1()) ==> ERR
13: SE BUSCA DESDE UN MÉTODO, OTRO SECRET QUE NO ESTÁ EN EL MÉTODO, NI EN LA CLASE, PERO SÍ  EN LA JERARQUIA (mD1()) ==> OK
14: SE BUSCA DESDE UN MÉTODO, OTRO EXPOSED QUE NO ESTÁ EN EL MÉTODO, NI EN LA CLASE, PERO SÍ  EN LA JERARQUIA (mA1()) ==> OK
15: SE BUSA DESDE UN METODO UN ATRIBUTO SIN CUALIFICAR QUE ES HIDDEN Y QUE NO ESTA EN EL METODO NI EN SU CLASE PERO SI EN LA JERARQUIA (sa2) ==> ERR
16: SE BUSCA DESDE UN METODO, UN ATRIBUTO QUE NO ESTÁ EN EL MÉTODO, NI EN LA CLASE PERO SÍ EN LA JERARQUÍA Y ES SECRET (sa1) ==> OK
17: SE BUSCA DESDE UN METODO, UN ATRIBUTO SIN CUALIFICAR QUE ES EXPOSED Y QUE NO ESTA EN  EL METODO, NI EN SU CLASE PERO SI EN LA JERARQUIA (a1) ==> OK
18: DESDE UN MÉTODO SE BUSCA UN MÉTODO SIN CUALIFICAR QUE NO EXISTE EN NINGÚN LUGAR NI DEL MÉTODO, NI DE LA CLASE DONDE ESTÁ NI DE LA JERARQUÍA (mA1)   ==> ERR
19: DESDE UN MÉTODO SE BUSCA UN ATRIBUTO SIN CUALIFICAR QUE NO EXISTE EN NINGÚN LUGAR NI DEL MÉTODO, NI DE LA CLASE DONDE ESTÁ NI DE LA JERARQUÍA (a1) ==> ERR
*/


#define CASO_20 20/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_21 -21/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_22 22/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_23 -23/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_24 24/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_25 25/*v7 BUSCAR ID NO CUALIFICADO*/
#define CASO_26 -26/*v7 BUSCAR ID NO CUALIFICADO*/
/*
BUSCAR ID NO CUALIFICADO

20: SE BUSCA UN ID NO CUALIFICADO v1 QUE NO ESTÁ EN LA JERARQUÍA.. ESTÁ EN MAIN ==> OK
21: SE BUSCA UN ID NO CUALIFICADO x QUE NO ESTÁ EN NINGÚN LADO ==> ERR
22: SE BUSCA UN ID NO CUALIFICADO DESDE MAIN EL ID NO ESTÁ EN LA JERARQUÍA PERO SÍ EN EL MAIN (v1) ==> OK
23: SE BUSCA UN ID NO CUALIFICADO DESDE UNA FUNCIÓN GLOBAL CUADO EL ID NO ESTÁ EN LA JERARQUÍA NI EN EL MAIN (x) ==> ERR
24: SE BUSCA UN ID NO CUALIFICADO (pf1) DEFINIDO EN UNA FUNCIÓN GLOBAL DESDE LA MISMA FUNCIÓN Y SÍ QUE ESTÁ ==> OK
25: SE BUSCA DESDE UNA FUNCIÓN GLOBAL UN IDENTIFICADOR NO CUALIFICADO QUE ESTÁ EN EL  ÁMBITO main (v1) ==> OK
26: SE BUSCA UN ID NO CUALIFICADO DESDE UNA FUNCIÓN GLOBAL Y NO ESTÁ NI EN LA FUNCIÓN NI  EN EL MAIN (a1) ==> ERR
*/


#define CASO_27 27/*v8 BUSCAR ID CUALIFICADO*/
#define CASO_28 -28/*v8 BUSCAR ID CUALIFICADO*/
#define CASO_29 -29/*v8 BUSCAR ID CUALIFICADO*/
#define CASO_30 -30/*v8 BUSCAR ID CUALIFICADO*/
#define CASO_31 31/*v8 BUSCAR ID CUALIFICADO*/
#define CASO_32 -32/*v8 BUSCAR ID CUALIFICADO*/
#define CASO_33 -33/*v8 BUSCAR ID CUALIFICADO*/
#define CASO_34 -34/*v8 BUSCAR ID CUALIFICADO*/
/*
BUSCAR ID CUALIFICADO CLASE/INSTANCIA

27: DESDE EL CÓDIGO DE MAIN SE BUSCA ALGO CUALIFICADO POR UNA CLASE QUE EXISTE (AA) Y EL ID BUSCADO (clasepub) ES UN ATRIBUTO
      QUE EXISTE EN LA CLASE, ACCESIBLE Y ATRIBUTO DE CLASE ==> DEBE DEVOLVER OK

28: DESDE EL CÓDIGO DE MAIN SE BUSCA ALGO CUALIFICADO POR UNA CLASE QUE EXISTE (AA) Y EL ID BUSCADO (clasepub) ES UN ATRIBUTO 
    QUE EXISTE EN LA CLASE, NO ACCESIBLE (HIDDEN) ==> DEBE DEVOLVER ERR

29: DESDE EL CÓDIGO DE MAIN SE BUSCA ALGO CUALIFICADO POR UNA CLASE QUE EXISTE (AA) Y EL ID BUSCADO (noExiste) NO EXISTE ==> DEBE DEVOLVER ERR

30: DESDE EL CÓDIGO DE MAIN SE BUSCA ALGO CUALIFICADO POR UNA CLASE QUE NO EXISTE (JJ) ==> DEBE DEVOLVER ERR


31: ACCESOS DESDE UNA FUNCIÓN GLOBAL (prueba) A ALGO CUALIFICADO POR UNACLASE (A) QUE EXISTE Y LO BUSCADO (clasepub ) 
    SON ATRIBUTOS DE ESA CLASE SON DE CLASE Y ES ACCESIBLE  ==> DEBE DEVOLVER  OK 

32: ACCESOS DESDE UNA FUNCIÓN GLOBAL (prueba) A ALGO CUALIFICADO POR UNACLASE (A) QUE EXISTE Y LO BUSCADO (clasepriv) 
    SON ATRIBUTOS DE ESA CLASE SON DE CLASE Y NO ES ACCESIBLE  ==> DEBE DEVOLVER  ERR 

33: ACCESO DESDE UNA FUNCIÓN GLOBAL (prueba) A ALGO CUALIFICADO POR UNA CLASE (A) QUE EXISTE Y LO BUSCADO (claseNoExiste) NO ==> DEBE DEVOLVER ERR

34: ACCESO DESDE FUNCIÓN GLOBAL DE ALGO CUALIFICADO POR UNA CLASE QUE NO EXISTE ==> DEBE DEVOLVER ERR
*/


#define CASO_35 35 /*v8 BUSCAR ID CUALIFICADO CLASE*/
#define CASO_36 -36/*v8 BUSCAR ID CUALIFICADO CLASE*/
#define CASO_37 -37/*v8 BUSCAR ID CUALIFICADO CLASE*/
#define CASO_38 -38/*v8 BUSCAR ID CUALIFICADO CLASE*/
/*
BUSCAR ID CUALIFICADO CLASE

35: ACCESO A ATRIBUTOS DE CLASES DESDE CLASE, EXISTEN ==> DEVUELVE OK
36: Acceso desde método a atributo de clase, que existe pero no está accesible en la jerarquía (clasepriv) ==> DEVUELVE ERR
37: Acceso desde método a atributo de clase que no existe (claseNoExiste) ==> DEVUELVE ERR
38: Acceso desde método de atributo de clase para una clase que no existe ==> DEVUELVE ERR
*/


#define CASO_401 -401/*v8 BUSCAR ID CUALIFICADO INSTANCIA*/
#define CASO_403 403/*v8 BUSCAR ID CUALIFICADO INSTANCIA*/
#define CASO_423 423/*v8 BUSCAR ID CUALIFICADO INSTANCIA*/
#define CASO_431 -431/*v8 BUSCAR ID CUALIFICADO INSTANCIA*/
#define CASO_433 433/*v8 BUSCAR ID CUALIFICADO INSTANCIA*/
#define CASO_453 453/*v8 BUSCAR ID CUALIFICADO INSTANCIA*/
#define CASO_463 463/*v8 BUSCAR ID CUALIFICADO INSTANCIA*/
#define CASO_471 -471/*v8 BUSCAR ID CUALIFICADO INSTANCIA*/
#define CASO_473 473/*v8 BUSCAR ID CUALIFICADO INSTANCIA*/
#define CASO_48 -48  /*v8 BUSCAR ID CUALIFICADO INSTANCIA*/
/*
BUSCAR IDCUALIFICADO CLASE/INSTANCIA

40.1 SE BUSCA ALGO QUE NO EXISTE CUALIFICADO POR UNA INSTANCIA QUE EXISTE Y ES GLOBAL ==> DEBE DEVOLVER ERR

40.3: DESDE EL CÓDIGO DE MAIN SE BUSCA ALGO CUALIFICADO POR UNA INSTANCIA QUE ES UNA VARIABLE GLOBAL (MainMiBB2) 
      DECLARAD DE TIPO DE CLASE QUE EXISTE (B) Y EL ID (inspub) ES UN ATRIBUTO QUE EXISTE EN LA JERARQUIA (A) Y ES ACCESIBLE ==> DEBE DEVOLVER OK

42.3 DESDE UNA FUNCIÓN GLOBAL (f2) SE ACCEDE A UN ID CUALIFICADO POR UNA INSTANCIA QUE ES UNA VARIABLE GLOBAL (MainMiBB2)
     DECLARAD DE TIPO DE CLASE QUE EXISTE (B) Y EL ID (inspub) ES UN ATRIBUTO QUE EXISTE EN LA JERARQUIA (A) Y ES ACCESIBLE ==> DEBE DEVOLVER OK

43.1. ACCESO DESDE UNA FUNCIÓN GLOBAL (prueba) DE UN ID (insNoExiste) CUALIFICADO POR UNA INSTANCIA (MainMiBB2) QUE EXISTE COMO 
      VARIABLE GLOBAL DE UNA CLASE (B) QUE NO TIENE ESE ATRIBUTO DE NINGUNA MANERA ==> DEBE DEVOLVER ERR

43.3: ACCESO DESDE UNA FUNCIÓN GLOBAL (f2) DE UN ID (inspub y inspriv) CUALIFICADO POR UNA INSTANCIA (MainMiBB2) QUE
      EXISTE COMO VARIABLE GLOBAL DE UNA CLASE (B) QUE NO TIENE ESOS ATRIBUTOS PERO QUE SÍ LOS TIENE SU JERARQUIA  (A) Y ADEMÁS
      DESDE ELLA (B) SON ACCESIBLES (RESPECTIVAMENTE SON EXPOSED Y SECRET Y B HEREDA DE A) ==> DEBE DEVOLVER OK

45.3: DESDE UN METODO SE ACCEDE A ALGO CUALIFICADO POR UNA INSTANCIA (varLoc) QUE ES UNA VARIABLE LOCAL DEL MÉTODO  DE UN CLASE 
      QUE EXISTE (E) Y LA COSA BUSCADA (inspub) ES UNA ATRIBUTO QUE AUNQUE NO ESTÁ EN LA CLASE SÍ ESTÁ EN LA JERARQUÍA (A) Y ES ACCESIBLE 
      (exposed) ==> DEBE DEVOLVER OK

46.3: DESDE DENTRO DE UN MÉTODO, SE BUSCA ALGO CUALIFICADO POR UNA INSTANCIA DE UNA CLASE (B) QUE ES UNA VARIABLE GLOBAL Y 
      LO BUSCADO ES UN ATRIBUTO (inspub) QUE NO ESTÁ EN LA CLASE PERO SÍ EN LA JERARQUÍA (en A) Y ES ACCESIBLE (exposed) ==> DEBERÍA DEVOLVER OK

47.1: DESDE UN MÉTODO SE ACCEDE A ALGO CUALIFICADO POR UNA INSTANCIA (miee) QUE ES UN ATRIBUTO ACCESIBLE EN ESTE CASO DE LA
      MISMA CLASE PERO EL ATRIBUTO BUSCADO (insNoExiste) NO EXISTE ==> DEBE DEVOLVER ERR

47.3 SE ACCEDE DESDE UN MÉTODO A UN ATRIBUTO QUE EXISTE EN LA JERARQUÍA Y ESTÁ ACCESIBLE (inspub es exposed e insprot es secret)
     CUALIFICANDO POR UNA INSTANCIA ACCESIBLE (miaa) ==> DEBE DEVOLVER OK

48. SE ACCEDE DESDE UN MÉTODO A UN ATRIBUTO (inspriv) QUE EXISTE EN LA JERARQUÍA (AA) Y NO ESTÁ ACCESIBLE (inspriv es hidden)
    A TRAVÉS DE UNA INSTANCIA QUE SÍ ESTÁ ACCESIBLE (miaa) ==> DEBE DEVOLVER ERR
*/


#define CASO_49 49/*v8 BUSCAR PARA DECLARAR MIEMBRO CLASE*/
#define CASO_50 -50/*v8 BUSCAR PARA DECLARAR MIEMBRO CLASE*/
/*
BUSCAR PARA DECLARAR MIEMBRO CLASE

49: BUSCAR: OK (AA_sA1) YA ESTÁ EN AA (SOLO SE BUSCA EN AA) NO SE PUEDE DECLARAR
50: Buscar: ERROR (AA_sA1) NO ESTÁ EN AA (SOLO SE BUSCA EN AA) SE PUEDE DECLARAR
*/


#define CASO_51 51/*v8 BUSCAR PARA DECLARAR MIEMBRO INSTANCIA*/
#define CASO_521 -521/*v8 BUSCAR PARA DECLARAR MIEMBRO INSTANCIA*/
#define CASO_522 522/*v8 BUSCAR PARA DECLARAR MIEMBRO INSTANCIA*/
#define CASO_53 -53/*v8 BUSCAR PARA DECLARAR MIEMBRO INSTANCIA*/
/*
BUSCAR PARA DECLARAR MIEMBRO CLASE

51 Buscar: OK	(AA_sa1) NO SE PUEDE DECLARAR
521: Buscar: ERROR (BB_ha1) EXISTE AA_ha1 (EN AA) PERO NO ES ACCESIBLE PORQUE ES HIDDEN  SE PUEDE DECLARAR
522: Buscar: OK (AA_sa1) DECLARADO EN AA ES ATRIBUTO DE INSTANCIA ACCESIBLE CON ACCESO secret NO  SE PUEDE DECLARAR
53 Buscar: ERROR (AA_ha1) SE PUEDE DECLARAR
*/


#define CASO_54 -54/*v9 BUSCAR PARA DECLARAR ID MAIN*/
#define CASO_55 -55/*v9 BUSCAR PARA DECLARAR ID MAIN*/
#define CASO_56 -56/*v9 BUSCAR PARA DECLARAR ID MAIN*/
#define CASO_57 57/*v9 BUSCAR PARA DECLARAR ID MAIN*/
#define CASO_58 -58/*v9 BUSCAR PARA DECLARAR ID MAIN*/
#define CASO_59 59/*v9 BUSCAR PARA DECLARAR ID MAIN*/
/*
BUSCAR PARA DECLARAR ID MAIN

54: Declarar variable no declarada ==> Debe devolver ERR, es decir, se puede declarar
55: Declarar funcion no declarada ==> Debe devolver ERR, es decir, se puede declarar
56: Declarar parametro no declarado ==> Debe devolver ERR, es decir, se puede declarar
57: Declarar variable ya declarada ==> Debe devolver OK, es decir, no se puede declarar
58: Declarar funcion ya declarada ==> Debe devolver ERR, es decir, se puede declarar
59: Declarar parametro ya declarado ==> Debe devolver OK, es decir, no se puede declarar
*/


#define CASO_60 -60/*v9 BUSCAR PARA DECLARAR ID LOCAL EN METODO*/
#define CASO_61 61/*v9 BUSCAR PARA DECLARAR ID LOCAL EN METODO*/
#define CASO_62 -62/*v9 BUSCAR PARA DECLARAR ID LOCAL EN METODO*/
#define CASO_63 63/*v9 BUSCAR PARA DECLARAR ID LOCAL EN METODO*/
#define CASO_64 64/*v9 BUSCAR PARA DECLARAR ID LOCAL EN METODO*/
#define CASO_65 65/*v9 BUSCAR PARA DECLARAR ID LOCAL EN METODO*/
#define CASO_66 -66/*v9 BUSCAR PARA DECLARAR ID LOCAL EN METODO*/
#define CASO_67 -67/*v9 BUSCAR PARA DECLARAR ID LOCAL EN METODO*/
/*
BUSCAR PARA DECLARAR ID LOCAL EN METODO

60: SE BUSCA PARA DECLARAR UN PARÁMETRO (p1) NO DECLARADO DEBE DEVOLVER ERR, NO ESTÁ Y SE PUEDE DECLARAR
61: SE BUSCA PARA DECLARAR UN PARÁMETRO (p1) YA DECLARADO DEBE DEVOLVER OK, YA ESTÁ Y NO SE PUEDE DECLARAR
62: SE BUSCA PARA DECLARAR UN PARAMETRO (mA3) YA DECLARADO COMO FUNCIÓN, DEBE DEVOLVER ERROR, NO ESTÁ PORQUE 
    AL TENER ARGUMENTOS EL NOMBRE DEL MÉTODO IRÁ SEGUIDO DE @S Y NO COINCIDIRÁ CON EL DE LA VARIABLE
63: SE BUSCA PARA DECLARAR UNA VARIABLE LOCAL(v2) NO DECLARADA DEBE DEVOLVER ERR, NO ESTÁ DECLARADA Y SE PUEDE DECLARAR
64: SE BUSCA PARA DECLARAR UNA VARIABLE LOCAL(v1) DECLARADA PREVIAMENTE COMO ARGUMENTO, DEBE DEVOLVER OK, ESTÁ YA DECLARADO
    Y NO SE PUEDE DECLARAR
65: SE BUSCA PARA DECLARAR UNA VARIABLE LOCAL(v1) DECLARADAPREVIAMENTE COMO LOCAL, DEBE DEVOLVER OK, ESTÁ YA DECLARADO Y NO SE PUEDE DECLARAR
66: SE BUSCA PARA DECLARAR UNA VARIABLE LOCAL(mA7) DECLARADA PREVIAMENTE COMO FUNCIÓN, Y ADEMÁS EL MÉTODO TIENE ARGUMENTOS,
    EN ESTE CASO COMO TIENE ARGUMENTOS EL NOMBRE DE LA FUNCIÓN TENDRA @s Y NO COLISIONARÁ CON EL DELA VARIABLE, DEBE DEVOLVER ERR, NO ESTÁ DECLARADA Y SE PUEDE DECLARAR
67: SE BUSCA PARA DECLARAR UNA VARIABLE LOCAL(mA8) DECLARADA PREVIAMENTE COMO FUNCION, AUNQUE EL MÉTODO NO TIENE ARGUMENTOS,
    NO COLISIONARÁ CON EL DE LA VARIABLE, YA QUE EL PREFIJO DE LA FUNCIÓN ES EL DE LA CLASE Y EL DE LA VARIABLE ES EL DEL METODO. 
    DEBE DEVOLVER ERROR, NO ESTÁ DECLARADA Y SE PUEDE DECLARAR
*/



int	print_caso(FILE* pf, int caso, char* ambito_desde, tsa* ambito_encontrado, tsa_elem* elem);
int print_hash_table_from_class(FILE* pf, tsc* p_tsc, char* id_clase);
int print_hash_table_from_met(FILE* pf, tsc* p_tsc, char* id_clase, char* metodo);
int print_command(FILE* pf, char* command);



#endif