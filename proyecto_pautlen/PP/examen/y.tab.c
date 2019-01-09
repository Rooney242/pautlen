/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "omicron.y" /* yacc.c:339  */
	
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



#line 98 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_NONE = 258,
    TOK_CLASS = 259,
    TOK_INHERITS = 260,
    TOK_INSTANCE_OF = 261,
    TOK_DISCARD = 262,
    TOK_ITSELF = 263,
    TOK_FLECHA = 264,
    TOK_HIDDEN = 265,
    TOK_SECRET = 266,
    TOK_EXPOSED = 267,
    TOK_UNIQUE = 268,
    TOK_FUNCTION = 269,
    TOK_RETURN = 270,
    TOK_MAIN = 271,
    TOK_INT = 272,
    TOK_BOOLEAN = 273,
    TOK_ARRAY = 274,
    TOK_IF = 275,
    TOK_ELSE = 276,
    TOK_WHILE = 277,
    TOK_SCANF = 278,
    TOK_PRINTF = 279,
    TOK_IDENTIFICADOR = 280,
    TOK_IGUAL = 281,
    TOK_DISTINTO = 282,
    TOK_MENORIGUAL = 283,
    TOK_MAYORIGUAL = 284,
    TOK_OR = 285,
    TOK_AND = 286,
    TOK_CONSTANTE_ENTERA = 287,
    TOK_FALSE = 288,
    TOK_TRUE = 289,
    TOK_ERROR = 290,
    MENOSU = 291
  };
#endif
/* Tokens.  */
#define TOK_NONE 258
#define TOK_CLASS 259
#define TOK_INHERITS 260
#define TOK_INSTANCE_OF 261
#define TOK_DISCARD 262
#define TOK_ITSELF 263
#define TOK_FLECHA 264
#define TOK_HIDDEN 265
#define TOK_SECRET 266
#define TOK_EXPOSED 267
#define TOK_UNIQUE 268
#define TOK_FUNCTION 269
#define TOK_RETURN 270
#define TOK_MAIN 271
#define TOK_INT 272
#define TOK_BOOLEAN 273
#define TOK_ARRAY 274
#define TOK_IF 275
#define TOK_ELSE 276
#define TOK_WHILE 277
#define TOK_SCANF 278
#define TOK_PRINTF 279
#define TOK_IDENTIFICADOR 280
#define TOK_IGUAL 281
#define TOK_DISTINTO 282
#define TOK_MENORIGUAL 283
#define TOK_MAYORIGUAL 284
#define TOK_OR 285
#define TOK_AND 286
#define TOK_CONSTANTE_ENTERA 287
#define TOK_FALSE 288
#define TOK_TRUE 289
#define TOK_ERROR 290
#define MENOSU 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 34 "omicron.y" /* yacc.c:355  */

	tipo_atributos atributos;

#line 214 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 231 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   287

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,     2,     2,     2,     2,     2,
      48,    49,    38,    36,    47,    37,    50,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      53,    51,    52,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   123,   129,   135,   143,   148,   154,   158,
     164,   168,   175,   178,   182,   186,   190,   194,   198,   202,
     208,   214,   220,   229,   234,   240,   257,   262,   268,   274,
     282,   288,   299,   324,   350,   353,   359,   367,   372,   395,
     400,   409,   413,   418,   425,   431,   437,   443,   449,   462,
     466,   472,   477,   482,   486,   492,   496,   502,   506,   510,
     514,   519,   523,   527,   533,   539,   543,   549,   573,   582,
     586,   590,   596,   616,   621,   628,   635,   647,   654,   667,
     687,   693,   707,   711,   716,   729,   742,   755,   768,   781,
     794,   807,   821,   841,   847,   853,   859,   865,   873,   881,
     887,   894,   900,   906,   912,   918,   924,   938,   952,   966,
     980,   994,  1010,  1016,  1024,  1030,  1038
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_NONE", "TOK_CLASS", "TOK_INHERITS",
  "TOK_INSTANCE_OF", "TOK_DISCARD", "TOK_ITSELF", "TOK_FLECHA",
  "TOK_HIDDEN", "TOK_SECRET", "TOK_EXPOSED", "TOK_UNIQUE", "TOK_FUNCTION",
  "TOK_RETURN", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN", "TOK_ARRAY",
  "TOK_IF", "TOK_ELSE", "TOK_WHILE", "TOK_SCANF", "TOK_PRINTF",
  "TOK_IDENTIFICADOR", "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL",
  "TOK_MAYORIGUAL", "TOK_OR", "TOK_AND", "TOK_CONSTANTE_ENTERA",
  "TOK_FALSE", "TOK_TRUE", "TOK_ERROR", "'+'", "'-'", "'*'", "'/'",
  "MENOSU", "'!'", "'{'", "'}'", "';'", "'['", "']'", "','", "'('", "')'",
  "'.'", "'='", "'>'", "'<'", "$accept", "programa", "inicio_tsc",
  "escritura1", "escritura2", "escritura_main", "declaraciones",
  "declaracion", "modificadores_acceso", "clase", "declaracion_clase",
  "abrirAmbitoClase", "modificadores_clase", "clase_escalar", "tipo",
  "clase_objeto", "clase_vector", "identificadores", "funciones",
  "funcion", "fn_declaration", "fn_complete_name", "param_init", "fn_name",
  "tipo_retorno", "parametros_funcion", "resto_parametros_funcion", "idpf",
  "parametro_funcion", "declaraciones_funcion", "sentencias", "sentencia",
  "sentencia_simple", "destruir_objeto", "bloque", "asignacion",
  "elemento_vector", "condicional", "if_exp_sentencias", "if_exp", "bucle",
  "while_exp", "lectura", "escritura", "retorno_funcion", "exp",
  "identificador_clase", "lista_expresiones", "resto_lista_expresiones",
  "comparacion", "constante", "constante_logica", "constante_entera", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    43,    45,    42,    47,
     291,    33,   123,   125,    59,    91,    93,    44,    40,    41,
      46,    61,    62,    60
};
# endif

#define YYPACT_NINF -111

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-111)))

#define YYTABLE_NINF -101

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -111,     9,    -3,  -111,   -27,  -111,   186,     4,     6,     8,
    -111,    16,  -111,   186,    88,  -111,  -111,  -111,   214,  -111,
      16,   233,    -4,    -8,    16,  -111,  -111,  -111,    86,    35,
      41,    34,     7,    54,  -111,  -111,  -111,  -111,    33,   233,
    -111,    63,  -111,   116,    60,    62,    93,     0,   -22,    70,
     233,    83,  -111,  -111,  -111,    85,  -111,   113,    49,  -111,
      89,  -111,  -111,  -111,    94,   186,  -111,  -111,    98,    96,
     100,   101,  -111,    41,    72,   126,  -111,  -111,  -111,   127,
     111,  -111,  -111,    31,  -111,  -111,  -111,     0,     0,     0,
    -111,   184,   105,  -111,  -111,  -111,     0,     0,   118,  -111,
     184,     0,     0,   134,  -111,  -111,  -111,   154,   114,   119,
     115,   123,   144,  -111,  -111,    45,   233,   138,  -111,    41,
    -111,   130,    16,  -111,  -111,  -111,     0,  -111,  -111,   180,
     124,     0,     0,     0,     0,     0,     0,   149,   200,   184,
     241,   229,   129,   151,   184,   155,   184,   233,   233,  -111,
     233,    19,   156,   158,   135,   141,   146,   147,  -111,    72,
     157,   143,     0,     0,     0,     0,  -111,     0,     0,  -111,
      78,  -111,    78,    78,  -111,  -111,   153,   152,  -111,     0,
    -111,  -111,   164,   165,   191,   192,   199,     0,     0,  -111,
    -111,  -111,  -111,    45,  -111,  -111,  -111,    16,  -111,  -111,
     184,   184,   184,   184,   184,   184,     0,  -111,   229,     0,
       0,  -111,  -111,  -111,   194,   184,   141,   201,   196,  -111,
     197,   198,  -111,  -111,  -111,  -111,  -111,  -111
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,     5,     6,    16,    17,    18,
      19,    34,     6,     8,    26,    13,    14,    15,    12,     7,
      34,     0,     0,     0,    34,     9,    28,    29,     0,     0,
       0,     0,     0,     0,    20,    27,    22,    21,     0,     0,
      35,     0,   101,     0,     0,     0,     0,     0,   100,     0,
      53,     0,    63,    56,    57,     0,    65,     0,     0,    66,
       0,    58,    59,    60,     0,    52,    39,     7,     0,     0,
      32,     0,    11,     0,    12,     0,    41,    42,    43,     0,
       0,    64,    83,    92,   116,   115,   114,     0,     0,     0,
      96,    82,     0,    93,   112,   113,     0,     0,    79,    80,
      81,     0,   103,     0,    36,    54,    55,     0,     0,     0,
       0,     0,     0,    51,    37,    45,     0,     0,    30,     0,
      10,     0,    34,    25,    40,     3,   103,    88,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,   105,     0,     0,    67,     0,    68,     0,     0,    75,
       0,     0,     0,     0,     0,    47,     0,     0,    33,    12,
       0,     0,     0,     0,     0,     0,    94,     0,     0,    95,
      90,    89,    84,    85,    87,    86,    99,     0,    72,     0,
     102,    62,     0,     0,     0,     0,     0,   103,     0,    48,
      49,    50,    38,     0,    44,     2,    31,    34,    24,    97,
     106,   107,   109,   108,   110,   111,   103,    76,   105,   103,
     103,    74,    73,    77,     0,    71,    47,     0,     0,   104,
       0,     0,    61,    46,    23,    98,    70,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,  -111,   238,   185,     5,  -111,   236,  -111,
    -111,  -111,  -111,  -111,    14,    30,  -111,   -66,   -20,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,    46,  -111,    58,   -64,
     -36,  -111,  -111,  -111,  -111,  -111,   -19,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,   -42,   -15,  -110,    53,  -111,
    -111,  -111,  -111
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,    11,    39,   113,    13,    14,    30,
      31,    32,    33,    34,   152,   153,    37,    71,    19,    20,
      21,    22,   115,    23,    79,   154,   194,   190,   155,   114,
      49,    50,    51,    52,    53,    54,    90,    56,    57,    58,
      59,    60,    61,    62,    63,   141,    92,   142,   180,   130,
      93,    94,    95
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    91,    55,    80,    67,   100,    64,   121,    42,     3,
     122,    12,    73,     4,   105,     5,   161,    15,    25,    16,
      55,    17,   110,   101,    64,    83,   102,    99,    35,   103,
      18,    55,    84,    85,    86,    64,    76,    87,    65,    55,
      66,    88,    68,    64,    36,   127,   128,   129,    89,    74,
      26,    27,    77,   158,   138,   139,    41,    42,    75,   140,
      69,   144,    26,    27,    43,   146,    70,   187,    78,    44,
     188,    45,    46,    47,    48,    29,   101,   214,    72,   126,
     156,  -100,     7,     8,     9,    10,   -52,    29,    81,   170,
     171,   172,   173,   174,   175,   197,   218,    55,   109,   220,
     221,    64,   160,    26,    27,    26,    27,    28,    96,   132,
      97,   184,   185,   104,   186,   -52,   135,   136,    98,    82,
     200,   201,   202,   203,    42,   204,   205,   106,    55,    55,
      29,    55,    64,    64,   108,    64,   107,   208,   111,   118,
     143,    83,    42,   117,   112,   120,   215,   119,    84,    85,
      86,   123,   124,    87,   125,   137,   147,    88,   149,    83,
     145,   148,    42,   101,    89,   150,    84,    85,    86,   151,
     157,    87,   159,   169,   176,    88,   182,   217,   181,    83,
     183,   189,    89,   191,   192,   193,    84,    85,    86,   195,
     -12,    87,   199,   196,   207,    88,     7,     8,     9,    10,
     198,   206,    89,   -12,   -12,   -12,   162,   163,   164,   165,
     131,   132,   209,   210,   131,   132,   133,   134,   135,   136,
     133,   134,   135,   136,     7,     8,     9,    10,   -12,   166,
     131,   132,   167,   168,   211,   212,   133,   134,   135,   136,
      41,    42,   213,   222,   224,   225,   226,   227,    43,   177,
      24,   216,   116,    44,    38,    45,    46,    47,    48,   131,
     132,   219,   223,     0,     0,   133,   134,   135,   136,     0,
       0,   131,   132,     0,     0,     0,   179,   133,   134,   135,
     136,     0,     0,     0,     0,     0,     0,   178
};

static const yytype_int16 yycheck[] =
{
      20,    43,    21,    39,    24,    47,    21,    73,     8,     0,
      74,     6,     5,    16,    50,    42,   126,    13,    13,    13,
      39,    13,    58,    45,    39,    25,    48,    46,    14,    51,
      14,    50,    32,    33,    34,    50,     3,    37,    42,    58,
      48,    41,    28,    58,    14,    87,    88,    89,    48,    42,
      17,    18,    38,   119,    96,    97,     7,     8,     4,   101,
      25,   103,    17,    18,    15,   107,    25,    48,    38,    20,
      51,    22,    23,    24,    25,    42,    45,   187,    44,    48,
     116,    50,    10,    11,    12,    13,    14,    42,    25,   131,
     132,   133,   134,   135,   136,   159,   206,   116,    49,   209,
     210,   116,   122,    17,    18,    17,    18,    19,    48,    31,
      48,   147,   148,    43,   150,    43,    38,    39,    25,     3,
     162,   163,   164,   165,     8,   167,   168,    44,   147,   148,
      42,   150,   147,   148,    21,   150,    51,   179,    49,    43,
       6,    25,     8,    45,    50,    44,   188,    47,    32,    33,
      34,    25,    25,    37,    43,    50,    42,    41,    43,    25,
       6,    42,     8,    45,    48,    42,    32,    33,    34,    25,
      32,    37,    42,    49,    25,    41,    25,   197,    49,    25,
      25,    25,    48,    25,    49,    44,    32,    33,    34,    43,
       4,    37,    49,    46,    42,    41,    10,    11,    12,    13,
      43,    48,    48,    17,    18,    19,    26,    27,    28,    29,
      30,    31,    48,    48,    30,    31,    36,    37,    38,    39,
      36,    37,    38,    39,    10,    11,    12,    13,    42,    49,
      30,    31,    52,    53,    43,    43,    36,    37,    38,    39,
       7,     8,    43,    49,    43,    49,    49,    49,    15,    49,
      12,   193,    67,    20,    18,    22,    23,    24,    25,    30,
      31,   208,   216,    -1,    -1,    36,    37,    38,    39,    -1,
      -1,    30,    31,    -1,    -1,    -1,    47,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    56,     0,    16,    42,    57,    10,    11,    12,
      13,    58,    60,    61,    62,    13,    13,    13,    14,    72,
      73,    74,    75,    77,    58,    60,    17,    18,    19,    42,
      63,    64,    65,    66,    67,    68,    69,    70,    62,    59,
      72,     7,     8,    15,    20,    22,    23,    24,    25,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   100,    42,    48,    72,    68,    25,
      25,    71,    44,     5,    42,     4,     3,    68,    69,    78,
      84,    25,     3,    25,    32,    33,    34,    37,    41,    48,
      90,    99,   100,   104,   105,   106,    48,    48,    25,    90,
      99,    45,    48,    51,    43,    84,    44,    51,    21,    49,
      84,    49,    50,    60,    83,    76,    59,    45,    43,    47,
      44,    71,    83,    25,    25,    43,    48,    99,    99,    99,
     103,    30,    31,    36,    37,    38,    39,    50,    99,    99,
      99,    99,   101,     6,    99,     6,    99,    42,    42,    43,
      42,    25,    68,    69,    79,    82,    84,    32,    71,    42,
      72,   101,    26,    27,    28,    29,    49,    52,    53,    49,
      99,    99,    99,    99,    99,    99,    25,    49,    46,    47,
     102,    49,    25,    25,    84,    84,    84,    48,    51,    25,
      81,    25,    49,    44,    80,    43,    46,    83,    43,    49,
      99,    99,    99,    99,    99,    99,    48,    42,    99,    48,
      48,    43,    43,    43,   101,    99,    82,    72,   101,   102,
     101,   101,    49,    80,    43,    49,    49,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    57,    58,    59,    60,    60,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      63,    63,    63,    64,    64,    65,    66,    67,    68,    68,
      69,    70,    71,    71,    72,    72,    73,    74,    75,    76,
      77,    78,    78,    78,    79,    79,    80,    80,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    86,
      86,    86,    86,    86,    87,    88,    88,    89,    89,    89,
      89,    89,    90,    91,    91,    92,    93,    94,    95,    96,
      96,    97,    98,    98,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   103,   103,
     103,   103,   104,   104,   105,   105,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     9,     0,     0,     0,     0,     1,     2,
       4,     3,     0,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     7,     5,     3,     0,     1,     1,     1,
       3,     5,     1,     3,     0,     2,     3,     3,     5,     0,
       4,     1,     1,     1,     2,     0,     3,     0,     1,     2,
       2,     1,     0,     1,     2,     2,     1,     1,     1,     1,
       1,     6,     4,     1,     2,     1,     1,     3,     3,     7,
       7,     5,     4,     5,     5,     3,     5,     5,     3,     2,
       2,     2,     2,     2,     3,     3,     3,     3,     2,     3,
       3,     2,     1,     1,     3,     3,     1,     4,     6,     3,
       1,     1,     2,     0,     3,     0,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 120 "omicron.y" /* yacc.c:1646  */
    { 
					fprintf(fout, ";R:\tprograma: 	TOK_MAIN '{' declaraciones funciones sentencias '}'\n");
				}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 124 "omicron.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R:\tprograma: 	TOK_MAIN '{' funciones sentencias '}'\n");
				}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 129 "omicron.y" /* yacc.c:1646  */
    {
  					tabla_simbolos = init_tsc("TSC_Omicron");
         	 	}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 135 "omicron.y" /* yacc.c:1646  */
    {
					strcpy(nombre_clase_desde,TSA_MAIN); 
					ambito = 0;
  					escribir_subseccion_data(asmfile);
    				escribir_cabecera_bss(asmfile);
         	 	}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 143 "omicron.y" /* yacc.c:1646  */
    {
          		    escribir_segmento_codigo(asmfile);
         	 	}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 148 "omicron.y" /* yacc.c:1646  */
    {
    				escribir_inicio_main(asmfile);
         	 	}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 155 "omicron.y" /* yacc.c:1646  */
    {
						fprintf(fout, ";R:\tdeclaraciones:	declaracion\n");
					}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 159 "omicron.y" /* yacc.c:1646  */
    {
						fprintf(fout, ";R:\tdeclaraciones:	declaracion declaraciones\n");
					}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 165 "omicron.y" /* yacc.c:1646  */
    {
						fprintf(fout, ";R:\tdeclaracion:	modificadores_acceso clase identificadores ';'\n");
					}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 169 "omicron.y" /* yacc.c:1646  */
    {
						fprintf(fout, ";R:\tdeclaracion:	modificadores_acceso declaracion_clase ';'\n");
					}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 175 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tmodificadores_acceso: \n");
						}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 179 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tmodificadores_acceso: TOK_HIDDEN TOK_UNIQUE\n");
						}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 183 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tmodificadores_acceso: TOK_SECRET TOK_UNIQUE\n");
						}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 187 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tmodificadores_acceso: TOK_EXPOSED TOK_UNIQUE\n");
						}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 191 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tmodificadores_acceso: TOK_HIDDEN\n");
						}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 195 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tmodificadores_acceso: TOK_SECRET\n");
						}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 199 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tmodificadores_acceso: TOK_EXPOSED\n");
						}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 203 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tmodificadores_acceso: TOK_UNIQUE\n");
						}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 209 "omicron.y" /* yacc.c:1646  */
    {
				clase_actual = ESCALAR;
				//strcpy(nombre_clase_desde, $1.lexema);
				fprintf(fout, ";R:\tclase:	clase_escalar\n");
			}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 215 "omicron.y" /* yacc.c:1646  */
    {
				clase_actual = VECTOR;
				//strcpy(nombre_clase_desde, $1.lexema);
				fprintf(fout, ";R:\tclase:	clase_vector\n");
			}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 221 "omicron.y" /* yacc.c:1646  */
    {

				clase_actual = OBJETO;
				//strcpy(nombre_clase_desde, $1.lexema);
				fprintf(fout, ";R:\tclase:	clase_objeto\n");
			}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 230 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tdeclaracion_clase:	modificadores_clase TOK_CLASS TOK_IDENTIFICADOR TOK_INHERITS identificadores '{' declaraciones_funcion funciones '}'\n");
							
						}
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 235 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tdeclaracion_clase:	modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones_funcion funciones '}'\n");
						}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 241 "omicron.y" /* yacc.c:1646  */
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
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 257 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tmodificadores_clase: \n");
						}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 263 "omicron.y" /* yacc.c:1646  */
    {
						fprintf(fout, ";R:\tclase_escalar: tipo\n");
					}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 269 "omicron.y" /* yacc.c:1646  */
    {
				tipo_actual = INT;
				(yyval.atributos).tipo = INT;
				fprintf(fout, ";R:\ttipo: 	TOK_INT \n");
			}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 275 "omicron.y" /* yacc.c:1646  */
    {	
				tipo_actual = BOOLEAN;
				(yyval.atributos).tipo = BOOLEAN;
				fprintf(fout, ";R:\ttipo: 	TOK_BOOLEAN  \n");
			}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 283 "omicron.y" /* yacc.c:1646  */
    {
						fprintf(fout, ";R:\tclase_objeto: 	'{' TOK_IDENTIFICADOR '}'\n");
					}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 289 "omicron.y" /* yacc.c:1646  */
    {	
						tamanio_vector_actual = atoi((yyvsp[-1].atributos).valor_entero);
						if (tamanio_vector_actual < 1 || tamanio_vector_actual > MAX_TAMANIO_VECTOR) {
							fprintf(stdout,"****Error semantico en lin %d:\n\tEl tamanyo del vector <%s> excede los limites permitidos (1,64).\n", line_count, nombre_clase_desde);
							return -1;
						}
						fprintf(fout, ";R:\tclase_vector: 	TOK_ARRAY tipo '[' TOK_CONSTANTE_ENTERA ']'\n");
					}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 300 "omicron.y" /* yacc.c:1646  */
    {
							tsa* ambito_encontrado = NULL;
							tsa_elem* elem = NULL;
							char * real_id;
							fprintf(fout, ";R:\tidentificadores: 	TOK_IDENTIFICADOR \n");

							if (buscarParaDeclararIdMain(tabla_simbolos, (yyvsp[0].atributos).lexema, &ambito_encontrado, &elem) > 0)
						    {
								fprintf(stdout,"****Error semantico en lin %d: Declaracion duplicada.\n", line_count);	
								return -1;
						    }
						    else 
						    {
						    	if (clase_actual != VECTOR)
						    		tamanio_vector_actual = 0;
						    	insertarSimboloEnMain(tabla_simbolos, (yyvsp[0].atributos).lexema, VARIABLE, tipo_actual, clase_actual,0, 
    								0, 0, 0, 0, 0, 0, tamanio_vector_actual, 0, 0, 0, 0, 0, 0, 0, EXPOSED, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
						    	real_id = _concat_prefix(nombre_clase_desde, (yyvsp[0].atributos).lexema);
						    	declarar_variable(asmfile, real_id, tipo_actual, clase_actual);
						    	tamanio_vector_actual = 0;
						    	free(real_id);
						    }

						}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 325 "omicron.y" /* yacc.c:1646  */
    {
							tsa* ambito_encontrado = NULL;
							tsa_elem* elem = NULL;
							char * real_id;
							fprintf(fout, ";R:\tidentificadores:	TOK_IDENTIFICADOR ',' identificadores\n");
							if (buscarParaDeclararIdMain(tabla_simbolos, (yyvsp[-2].atributos).lexema, &ambito_encontrado, &elem) > 0)
						    {							      	
								fprintf(stdout,"****Error semantico en lin %d: Declaracion duplicada.\n", line_count);
								return -1;
						    }
						    else 
						    {
						    	if (clase_actual != VECTOR)
						    		tamanio_vector_actual = 0;
						    	insertarSimboloEnMain(tabla_simbolos, (yyvsp[-2].atributos).lexema, VARIABLE, tipo_actual, clase_actual,0, 
    								0, 0, 0, 0, 0, 0, tamanio_vector_actual, 0, 0, 0, 0, 0, 0, 0, EXPOSED, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
						    	real_id = _concat_prefix(nombre_clase_desde, (yyvsp[-2].atributos).lexema);
						    	declarar_variable(asmfile, real_id, tipo_actual, tamanio_vector_actual);
						    	tamanio_vector_actual = 0;
						    	free(real_id);
						    }
						}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 350 "omicron.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R:\tfunciones: \n");
				}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 354 "omicron.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R:\tfunciones: funcion funciones\n");
				}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 360 "omicron.y" /* yacc.c:1646  */
    {
					ambito = 0;
					cerrarAmbitoEnClase(tabla_simbolos, nombre_clase_desde, (yyvsp[-2].atributos).lexema);
					fprintf(fout, ";R:\tfuncion: 	TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");
				}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 368 "omicron.y" /* yacc.c:1646  */
    {
					strcpy((yyval.atributos).lexema,(yyvsp[-2].atributos).lexema);
				}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 373 "omicron.y" /* yacc.c:1646  */
    {
					int i;
					int tipo = INT;
					char * real_id;
					char funcion[MAX_LONG_ID+1];
					strcpy(funcion,(yyvsp[-4].atributos).lexema);

					for(i=0;i<num_parametros_actual;i++){
						strcat(funcion,"@");
						strcat(funcion,tipo_parametros[0]);
					}
					if((yyvsp[-4].atributos).tipo == BOOLEAN)
						tipo = BOOLEAN;
					abrirAmbitoEnClase(tabla_simbolos, nombre_clase_desde, funcion, METODO_SOBREESCRIBIBLE, EXPOSED, tipo, 0, 0);
					real_id = _concat_prefix(nombre_clase_desde, funcion);
					declararFuncion(asmfile, real_id, num_parametros_actual);
					strcpy(nombre_ambito_desde, real_id);
    				free(real_id);
					strcpy((yyval.atributos).lexema, funcion);
					ambito = 1;
				}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 395 "omicron.y" /* yacc.c:1646  */
    {
				num_parametros_actual = 0;
				free(tipo_parametros);
			}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 401 "omicron.y" /* yacc.c:1646  */
    {
					strcpy((yyval.atributos).lexema,(yyvsp[0].atributos).lexema);
					(yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
				}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 410 "omicron.y" /* yacc.c:1646  */
    {
						fprintf(fout, ";R:\ttipo_retorno:	TOK_NONE\n");
					}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 414 "omicron.y" /* yacc.c:1646  */
    {
						(yyval.atributos).tipo=(yyvsp[0].atributos).tipo;
						fprintf(fout, ";R:\ttipo_retorno:	tipo\n");
					}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 419 "omicron.y" /* yacc.c:1646  */
    {
						(yyval.atributos).tipo=(yyvsp[0].atributos).tipo;
						fprintf(fout, ";R:\ttipo_retorno:	clase_objeto\n");
					}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 426 "omicron.y" /* yacc.c:1646  */
    {
							//$$.num_parametros = 1 + $2.num_parametros;
							fprintf(fout, ";R:\tparametros_funcion:	parametro_funcion resto_parametros_funcion\n");
						}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 431 "omicron.y" /* yacc.c:1646  */
    {
							//$$.num_parametros = 0;
							fprintf(fout, ";R:\tparametros_funcion: \n");
						}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 438 "omicron.y" /* yacc.c:1646  */
    {
									//$$.num_parametros = 1 + $2.num_parametros;
									fprintf(fout, ";R:\tresto_parametros_funcion:	';' parametro_funcion resto_parametros_funcion \n");
								}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 443 "omicron.y" /* yacc.c:1646  */
    {
									//$$.num_parametros = 0;
									fprintf(fout, ";R:\tresto_parametros_funcion: \n");
								}
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 450 "omicron.y" /* yacc.c:1646  */
    {	
				tsa* tsa_encontrada = NULL;
				tsa_elem* elem = NULL;
				if (buscarIdNoCualificado(tabla_simbolos, (yyvsp[0].atributos).lexema, nombre_clase_desde, &tsa_encontrada, &elem) < 0) {
					fprintf(stdout,"****Error semantico en lin %d: Acceso a variable no declarada (%s).", line_count, (yyvsp[0].atributos).lexema);
					return -1;
				}
				num_parametros_actual ++;	
				tipo_parametros = (int*)realloc(tipo_parametros, num_parametros_actual*sizeof(int));
				fprintf(fout, ";R:\tidpf: TOK_IDENTIFICADOR\n");
			}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 463 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tparametro_funcion:	tipo idpf\n");
						}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 467 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tparametro_funcion:	clase_objeto TOK_IDENTIFICADOR\n");
						}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 473 "omicron.y" /* yacc.c:1646  */
    {
								fprintf(fout, ";R:\tdeclaraciones_funcion:	 declaraciones \n");
							}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 477 "omicron.y" /* yacc.c:1646  */
    {
								fprintf(fout, ";R:\tdeclaraciones_funcion:	 \n");
							}
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 483 "omicron.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R:\tsentencias:	sentencia \n");
				}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 487 "omicron.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R:\tsentencias:	sentencia sentencias \n");
				}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 493 "omicron.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R:\tsentencia:	sentencia_simple ';' \n");
				}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 497 "omicron.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R:\tsentencia:	bloque\n");
				}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 503 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tsentencia_simple:	asignacion\n");
						}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 507 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tsentencia_simple:	lectura\n");
						}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 511 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tsentencia_simple:	escritura\n");
						}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 515 "omicron.y" /* yacc.c:1646  */
    {
							retornarFuncion(asmfile, (yyvsp[0].atributos).tipo);
							fprintf(fout, ";R:\tsentencia_simple:	retorno_funcion\n");
						}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 520 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tsentencia_simple:	identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
						}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 524 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tsentencia_simple:	TOK_IDENTIFICADOR '(' lista_expresiones ')' \n");
						}
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 528 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tsentencia_simple:	destruir_objeto\n");
						}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 534 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tdestruir_objeto: 	TOK_DISCARD TOK_IDENTIFICADOR\n");
						}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 540 "omicron.y" /* yacc.c:1646  */
    {
				fprintf(fout, ";R:\tbloque:	condicional\n");
			}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 544 "omicron.y" /* yacc.c:1646  */
    {
				fprintf(fout, ";R:\tbloque:	bucle\n");
			}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 550 "omicron.y" /* yacc.c:1646  */
    {
					tsa* tsa_encontrada = NULL;
					tsa_elem* elem = NULL;
					if (buscarIdNoCualificado(tabla_simbolos, (yyvsp[-2].atributos).lexema, nombre_clase_desde, &tsa_encontrada, &elem) < 0) {
						fprintf(stdout,"****Error semantico en lin %d: Acceso a variable no declarada (%s).", line_count, (yyvsp[-2].atributos).lexema);
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
					if((yyvsp[0].atributos).tipo != elem->tipo){
						fprintf(stdout,"****Error semantico en lin %d: Asignacion incompatible.\n", line_count);
						return -1;
					}
					asignar(asmfile, elem->id, (yyvsp[0].atributos).es_direccion);
					fprintf(fout, ";R:\tasignacion:	TOK_IDENTIFICADOR '=' exp\n");
				}
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 574 "omicron.y" /* yacc.c:1646  */
    {
					if((yyvsp[-2].atributos).tipo != (yyvsp[0].atributos).tipo){
						fprintf(stdout,"****Error semantico en lin %d: Asignacion incompatible.\n", line_count);
						return -1;
					}
					asignarDestinoEnPila(asmfile, (yyvsp[0].atributos).es_direccion);
					fprintf(fout, ";R:\tasignacion:	elemento_vector '=' exp\n");
				}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 583 "omicron.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
				}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 587 "omicron.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R:\tasignacion: TOK_IDENTIFICADOR '='TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
				}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 591 "omicron.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R:\tasignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");
				}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 597 "omicron.y" /* yacc.c:1646  */
    {
							tsa* tsa_encontrada = NULL;
							tsa_elem* elem = NULL;

							if (buscarIdNoCualificado(tabla_simbolos, (yyvsp[-3].atributos).lexema, nombre_clase_desde, &tsa_encontrada, &elem) < 0){
								fprintf(stdout,"****Error semantico en lin %d: Acceso a variable no declarada (%s).", line_count, (yyvsp[-3].atributos).lexema);
								return -1;
							}

							if ((yyvsp[-1].atributos).tipo != INT){
								fprintf(stdout,"****Error semantico en lin %d: El indice en una operacion de indexacion tien que ser de tipo entero.", line_count);
								return -1;
							}
							(yyval.atributos).tipo = elem->tipo;
							escribir_elemento_vector(asmfile, elem->id, elem->tamanio, (yyvsp[-1].atributos).es_direccion);
							fprintf(fout, ";R:\telemento_vector:	TOK_IDENTIFICADOR '[' exp ']'\n");
						}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 617 "omicron.y" /* yacc.c:1646  */
    {
						ifthen_fin(asmfile, (yyvsp[-4].atributos).etiqueta);
						fprintf(fout, ";R:\tcondicional:	if_exp ')' '{' sentencias '}' \n");
					}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 622 "omicron.y" /* yacc.c:1646  */
    {
						ifthenelse_fin(asmfile, (yyvsp[-4].atributos).etiqueta);
						fprintf(fout, ";R:\tcondicional:	if_exp_sentencias TOK_ELSE '{' sentencias '}'\n");
					}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 629 "omicron.y" /* yacc.c:1646  */
    {
						(yyval.atributos).etiqueta = (yyvsp[-2].atributos).etiqueta;
						ifthenelse_fin_then(asmfile, (yyvsp[-2].atributos).etiqueta);
						fprintf(fout, ";R:\tif_exp_sentencias:	if_exp sentencias '}'\n");
					}
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 636 "omicron.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].atributos).tipo != BOOLEAN){
					fprintf(stdout,"****Error semantico en lin %d: Condicional con condicion de tipo int.\n", line_count);
					return -1;
				}
				(yyval.atributos).etiqueta = etiqueta ++;
				ifthenelse_inicio(asmfile, (yyvsp[-2].atributos).es_direccion, (yyval.atributos).etiqueta);
				fprintf(fout, ";R:\tif_exp:	TOK_IF '(' exp ')' '{' \n");
			}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 648 "omicron.y" /* yacc.c:1646  */
    {
				fprintf(fout, ";R:\tbucle: 	while_exp ')' '{' sentencias '}'\n");
				while_fin(asmfile, (yyvsp[-4].atributos).etiqueta);
			}
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 655 "omicron.y" /* yacc.c:1646  */
    {
					if((yyvsp[0].atributos).tipo != BOOLEAN) {
						fprintf(stdout,"****Error semantico en lin %d: Bucle con condicion de tipo int.\n", line_count);
						return -1;
					}
					(yyval.atributos).etiqueta = etiqueta ++;
					while_inicio(asmfile, etiqueta);
					while_exp_pila(asmfile, (yyvsp[0].atributos).es_direccion, etiqueta);
					fprintf(fout, ";R:\twhile_exp:	TOK_WHILE '(' exp \n");
				}
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 668 "omicron.y" /* yacc.c:1646  */
    {
					tsa * tsa_encontrada = NULL;
					tsa_elem* elem = NULL;
					/* Si al buscar el identificdor en la tabla de símbolos, no está... salir con ERROR */
					if (buscarIdNoCualificado(tabla_simbolos, (yyvsp[0].atributos).lexema, nombre_clase_desde, &tsa_encontrada, &elem) < 0){
						fprintf(stdout,"****Error semantico en lin %d: Acceso a variable no declarada (%s).", line_count, (yyvsp[0].atributos).lexema);
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
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 688 "omicron.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R:\tlectura:	TOK_SCANF elemento_vector \n");
				}
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 694 "omicron.y" /* yacc.c:1646  */
    {
					//Hacer para ambitos esto_concat_prefix(t->main->ambito, nombre_id)
					char * real_id;
					if ((yyvsp[0].atributos).es_direccion){
						real_id = _concat_prefix(nombre_clase_desde, (yyvsp[0].atributos).lexema);
						escribir_operando(asmfile, real_id, (yyvsp[0].atributos).es_direccion);
						free(real_id);
					}
					escribir(asmfile, (yyvsp[0].atributos).es_direccion, (yyvsp[0].atributos).tipo);
					fprintf(fout, ";R:\tescritura:	TOK_PRINTF exp\n");
				}
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 708 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tretorno_funcion:	TOK_RETURN exp\n");
						}
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 712 "omicron.y" /* yacc.c:1646  */
    {
							fprintf(fout, ";R:\tretorno_funcion:	TOK_RETURN TOK_NONE\n");
						}
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 717 "omicron.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
					sumar(asmfile, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
					(yyval.atributos).tipo = 1;
					(yyval.atributos).es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion aritmetica con operandos boolean.", line_count);	
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp '+' exp\n");
			}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 730 "omicron.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
					restar(asmfile, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
					(yyval.atributos).tipo = 1;
					(yyval.atributos).es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion aritmetica con operandos boolean.", line_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp '-' exp\n");
			}
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 743 "omicron.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
					dividir(asmfile, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
					(yyval.atributos).tipo = 1;
					(yyval.atributos).es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion aritmetica con operandos boolean.", line_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp '/' exp\n");
			}
#line 2379 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 756 "omicron.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
					multiplicar(asmfile, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
					(yyval.atributos).tipo = 1;
					(yyval.atributos).es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion aritmetica con operandos boolean.", line_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp '*' exp\n");
			}
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 769 "omicron.y" /* yacc.c:1646  */
    {
				if((yyvsp[0].atributos).tipo == INT){
					cambiar_signo(asmfile,  (yyvsp[0].atributos).es_direccion);
					(yyval.atributos).tipo = 1;
					(yyval.atributos).es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion aritmetica con operandos boolean.", line_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	'-' exp\n");
			}
#line 2413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 782 "omicron.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].atributos).tipo == BOOLEAN && (yyvsp[0].atributos).tipo == BOOLEAN){
					y(asmfile, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
					(yyval.atributos).tipo = BOOLEAN;
					(yyval.atributos).es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion logica con operandos int.", line_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp TOK_AND exp\n");
			}
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 795 "omicron.y" /* yacc.c:1646  */
    {
				if((yyvsp[-2].atributos).tipo == BOOLEAN && (yyvsp[0].atributos).tipo == BOOLEAN){
					o(asmfile, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
					(yyval.atributos).tipo = BOOLEAN;
					(yyval.atributos).es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion logica con operandos int.", line_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	exp TOK_OR exp\n");
			}
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 808 "omicron.y" /* yacc.c:1646  */
    {
				if((yyvsp[0].atributos).tipo == BOOLEAN){
					no(asmfile, (yyvsp[0].atributos).es_direccion, etiqueta);
					etiqueta ++;
					(yyval.atributos).tipo = BOOLEAN;
					(yyval.atributos).es_direccion = 0;
				}
				else {
					fprintf(stdout,"****Error semantico en lin %d: Operacion logica con operandos int.", line_count);
					return -1;
				}
				fprintf(fout, ";R:\texp:	'!' exp\n");
			}
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 822 "omicron.y" /* yacc.c:1646  */
    {
				tsa* tsa_encontrada = NULL;
				tsa_elem* elem = NULL;
				if (buscarIdNoCualificado(tabla_simbolos, (yyvsp[0].atributos).lexema, nombre_clase_desde, &tsa_encontrada, &elem) < 0){
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
				(yyval.atributos).tipo = elem->tipo;
				(yyval.atributos).es_direccion = 1;
				escribir_operando(asmfile, elem->id, (yyval.atributos).es_direccion);
				fprintf(fout, ";R:\texp:	TOK_IDENTIFICADOR\n");
			}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 842 "omicron.y" /* yacc.c:1646  */
    {
				(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
				(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
				fprintf(fout, ";R:\texp:	constante \n");
			}
#line 2499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 848 "omicron.y" /* yacc.c:1646  */
    {
				(yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
				(yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
				fprintf(fout, ";R:\texp:	'(' exp ')'\n");
			}
#line 2509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 854 "omicron.y" /* yacc.c:1646  */
    {
				(yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
				(yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
				fprintf(fout, ";R:\texp:	'(' comparacion ')'\n");
			}
#line 2519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 860 "omicron.y" /* yacc.c:1646  */
    {
				(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
				(yyval.atributos).es_direccion = 1;
				fprintf(fout, ";R:\texp:	elemento_vector\n");
			}
#line 2529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 866 "omicron.y" /* yacc.c:1646  */
    {
				if ((yyvsp[-1].atributos).num_expresiones != get_parameters_from_function(tabla_simbolos, (yyvsp[-3].atributos).lexema)){
					fprintf(stdout,"****Error semantico en lin %d: Numero de argumentos en la funcion \"%s\" incorrecto", line_count, (yyvsp[-3].atributos).lexema);
					return -1;
				}
				fprintf(fout, ";R:\texp:	TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
			}
#line 2541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 874 "omicron.y" /* yacc.c:1646  */
    {
				if ((yyvsp[-1].atributos).num_expresiones != get_parameters_from_function(tabla_simbolos, (yyvsp[-3].atributos).lexema)){
					fprintf(stdout,"****Error semantico en lin %d: Numero de argumentos en la funcion \"%s\" incorrecto", line_count, (yyvsp[-5].atributos).lexema);
					return -1;
				}
				fprintf(fout, ";R:\texp:	identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
			}
#line 2553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 882 "omicron.y" /* yacc.c:1646  */
    {
				fprintf(fout, ";R:\texp:	identificador_clase '.' TOK_IDENTIFICADOR\n");
			}
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 888 "omicron.y" /* yacc.c:1646  */
    {

								strcpy((yyval.atributos).lexema,(yyvsp[0].atributos).lexema);

								fprintf(fout, ";R:\tidentificador_clase:	TOK_IDENTIFICADOR\n");
							}
#line 2572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 895 "omicron.y" /* yacc.c:1646  */
    {
								fprintf(fout, ";R:\tidentificador_clase:	TOK_ITSELF\n");
							}
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 901 "omicron.y" /* yacc.c:1646  */
    {
							(yyval.atributos).num_expresiones = 1 + (yyvsp[0].atributos).num_expresiones;
							fprintf(fout, ";R:\tlista_expresiones:	exp resto_lista_expresiones \n");
						}
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 906 "omicron.y" /* yacc.c:1646  */
    {
							(yyval.atributos).num_expresiones = 0;
							fprintf(fout, ";R:\tlista_expresiones:	\n");
						}
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 913 "omicron.y" /* yacc.c:1646  */
    {
									(yyval.atributos).num_expresiones = 1 + (yyvsp[0].atributos).num_expresiones;
									fprintf(fout, ";R:\tresto_lista_expresiones:	',' exp resto_lista_expresiones \n");
								}
#line 2607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 918 "omicron.y" /* yacc.c:1646  */
    {
									(yyval.atributos).num_expresiones = 0;
									fprintf(fout, ";R:\tresto_lista_expresiones:	\n");
								}
#line 2616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 925 "omicron.y" /* yacc.c:1646  */
    {	
						if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
							igual(asmfile, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
							etiqueta ++;
							(yyval.atributos).tipo = BOOLEAN;
							(yyval.atributos).es_direccion = 0;
						}
						else {
							fprintf(stdout,"****Error semantico en lin %d: Comparacion con operandos boolean", line_count);
							return -1;
						}
						fprintf(fout, ";R:\tcomparacion:	exp TOK_IGUAL exp \n");
					}
#line 2634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 939 "omicron.y" /* yacc.c:1646  */
    {
						if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
							distinto(asmfile, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
							etiqueta ++;
							(yyval.atributos).tipo = BOOLEAN;
							(yyval.atributos).es_direccion = 0;
						}
						else {
							fprintf(stdout,"****Error semantico en lin %d: Comparacion con operandos boolean", line_count);
							return -1;
						}
						fprintf(fout, ";R:\tcomparacion:	exp TOK_DISTINTO exp\n");
					}
#line 2652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 953 "omicron.y" /* yacc.c:1646  */
    {
						if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
							mayor_igual(asmfile, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
							etiqueta ++;
							(yyval.atributos).tipo = BOOLEAN;
							(yyval.atributos).es_direccion = 0;
						}
						else {
							fprintf(stdout,"****Error semantico en lin %d: Comparacion con operandos boolean", line_count);
							return -1;
						}
						fprintf(fout, ";R:\tcomparacion:	exp TOK_MAYORIGUAL exp\n");
					}
#line 2670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 967 "omicron.y" /* yacc.c:1646  */
    {
						if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
							menor_igual(asmfile, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
							etiqueta ++;
							(yyval.atributos).tipo = BOOLEAN;
							(yyval.atributos).es_direccion = 0;
						}
						else {
							fprintf(stdout,"****Error semantico en lin %d: Comparacion con operandos boolean", line_count);
							return -1;
						}
						fprintf(fout, ";R:\tcomparacion:	exp TOK_MENORIGUAL exp\n");
					}
#line 2688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 981 "omicron.y" /* yacc.c:1646  */
    {
						if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
							mayor(asmfile, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
							etiqueta ++;
							(yyval.atributos).tipo = BOOLEAN;
							(yyval.atributos).es_direccion = 0;
						}
						else {
							fprintf(stdout,"****Error semantico en lin %d: Comparacion con operandos boolean", line_count);
							return -1;
						}
						fprintf(fout, ";R:\tcomparacion:	exp '>' exp\n");
					}
#line 2706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 995 "omicron.y" /* yacc.c:1646  */
    {
						if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){
							menor(asmfile, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
							etiqueta ++;
							(yyval.atributos).tipo = BOOLEAN;
							(yyval.atributos).es_direccion = 0;
						}
						else {
							fprintf(stdout,"****Error semantico en lin %d: Comparacion con operandos boolean", line_count);
							return -1;
						}
						fprintf(fout, ";R:\tcomparacion:	exp '<' exp\n");
					}
#line 2724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1011 "omicron.y" /* yacc.c:1646  */
    {
					(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
					(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
					fprintf(fout, ";R:\tconstante:	constante_logica \n");
				}
#line 2734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1017 "omicron.y" /* yacc.c:1646  */
    {	
					(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
					(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
					fprintf(fout, ";R:\tconstante:	constante_entera \n");
				}
#line 2744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1025 "omicron.y" /* yacc.c:1646  */
    {
							(yyval.atributos).tipo = BOOLEAN;
							(yyval.atributos).es_direccion = 0;
							fprintf(fout, ";R:\tconstante_logica:	TOK_TRUE \n");
						}
#line 2754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1031 "omicron.y" /* yacc.c:1646  */
    {
							(yyval.atributos).tipo = BOOLEAN;
							(yyval.atributos).es_direccion = 0;
							fprintf(fout, ";R:\tconstante_logica:	TOK_FALSE \n");
						}
#line 2764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1039 "omicron.y" /* yacc.c:1646  */
    {	
					(yyval.atributos).tipo = INT;
					(yyval.atributos).es_direccion = 0;
					strcpy((yyval.atributos).valor_entero, (yyvsp[0].atributos).valor_entero);
					escribir_operando(asmfile, (yyvsp[0].atributos).valor_entero, 0);
					fprintf(fout, ";R:\tconstante_entera:	TOK_CONSTANTE_ENTERA \n");
				}
#line 2776 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2780 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1049 "omicron.y" /* yacc.c:1906  */


void yyerror(char* s) {
	fprintf(stdout,"ERROR SINTACTICO:%d:%d\n", line_count, col_count);
}

