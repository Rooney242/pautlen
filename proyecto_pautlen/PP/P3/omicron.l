%{ 
#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"

int line_count = 1;
int col_count = 0;
extern FILE* fout;

%}

%option noyywrap

DIGITO			[0-9]
LETRA			[a-zA-Z]
ENTERO			{DIGITO}*
COMENTARIO		"//".*\n
IDENTIFICADOR 	{LETRA}({LETRA}|{DIGITO})*

%%
none				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_NONE\n"); return TOK_NONE;}
class				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_CLASS\n"); return TOK_CLASS;}
inherits			{col_count+=yyleng; fprintf(fout, ";D:\tTOK_INHERITS\n"); return TOK_INHERITS;}
instance_of			{col_count+=yyleng; fprintf(fout, ";D:\tTOK_INSTANCE_OF\n"); return TOK_INSTANCE_OF;}
discard				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_DISCARD\n"); return TOK_DISCARD;}
itself				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_ITSELF\n"); return TOK_ITSELF;}
hidden				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_HIDDEN\n"); return TOK_HIDDEN;}
secret				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_SECRET\n"); return TOK_SECRET;}
exposed				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_EXPOSED\n"); return TOK_EXPOSED;}
unique				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_UNIQUE\n"); return TOK_UNIQUE;}
function			{col_count+=yyleng; fprintf(fout, ";D:\tTOK_FUNCTION\n"); return TOK_FUNCTION;}
return				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_RETURN\n"); return TOK_RETURN;}
main				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_MAIN\n"); return TOK_MAIN;}
boolean				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_BOOLEAN\n"); return TOK_BOOLEAN;}
array				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_ARRAY\n"); return TOK_ARRAY;}
printf				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_PRINTF\n"); return TOK_PRINTF;}
int					{col_count+=yyleng; fprintf(fout, ";D:\tTOK_INT\n"); return TOK_INT;}
if					{col_count+=yyleng; fprintf(fout, ";D:\tTOK_IF\n"); return TOK_IF;}
else				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_ELSE\n"); return TOK_ELSE;}
while				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_WHILE\n"); return TOK_WHILE;}
scanf				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_SCANF\n"); return TOK_SCANF;}
false				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_FALSE\n"); return TOK_FALSE;}
true				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_TRUE\n"); return TOK_TRUE;}
"->"				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_FLECHA\n"); return TOK_FLECHA;}
==					{col_count+=yyleng; fprintf(fout, ";D:\tTOK_IGUAL\n"); return TOK_IGUAL;}
"!="				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_DISTINTO\n"); return TOK_DISTINTO;}
"<="				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_MENORIGUAL\n"); return TOK_MENORIGUAL;}
">="				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_MAYORIGUAL\n"); return TOK_MAYORIGUAL;}
"&&"				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_AND\n"); return TOK_AND;}
"||"				{col_count+=yyleng; fprintf(fout, ";D:\tTOK_OR\n"); return TOK_OR;}
";"					{col_count+=yyleng; fprintf(fout, ";D:\t;"); return yytext[0];}
"#"					{col_count+=yyleng; fprintf(fout, ";D:\t#"); return yytext[0];}
","					{col_count+=yyleng; fprintf(fout, ";D:\t,"); return yytext[0];}
"="					{col_count+=yyleng; fprintf(fout, ";D:\t="); return yytext[0];}
"("					{col_count+=yyleng; fprintf(fout, ";D:\t("); return yytext[0];}
")"					{col_count+=yyleng; fprintf(fout, ";D:\t)"); return yytext[0];}
"{"					{col_count+=yyleng; fprintf(fout, ";D:\t{"); return yytext[0];}
"}"					{col_count+=yyleng; fprintf(fout, ";D:\t}"); return yytext[0];}
"["					{col_count+=yyleng; fprintf(fout, ";D:\t["); return yytext[0];}
"]"					{col_count+=yyleng; fprintf(fout, ";D:\t]"); return yytext[0];}
":"					{col_count+=yyleng; fprintf(fout, ";D:\t:"); return yytext[0];}
"+"					{col_count+=yyleng; fprintf(fout, ";D:\t+"); return yytext[0];}
"-"					{col_count+=yyleng; fprintf(fout, ";D:\t-"); return yytext[0];}
"/"					{col_count+=yyleng; fprintf(fout, ";D:\t/"); return yytext[0];}
"*"					{col_count+=yyleng; fprintf(fout, ";D:\t*"); return yytext[0];}
">"					{col_count+=yyleng; fprintf(fout, ";D:\t>"); return yytext[0];}
"<"					{col_count+=yyleng; fprintf(fout, ";D:\t<"); return yytext[0];}
"&"					{col_count+=yyleng; fprintf(fout, ";D:\t&"); return yytext[0];}
"!"					{col_count+=yyleng; fprintf(fout, ";D:\t!"); return yytext[0];}
"."					{col_count+=yyleng; fprintf(fout, ";D:\t."); return yytext[0];}
[ \t\r]				{col_count += yyleng;}
{ENTERO}			{col_count+=yyleng; fprintf(fout, ";D:\tTOK_CONSTANTE_ENTERA\n"); return TOK_CONSTANTE_ENTERA;}
{COMENTARIO}|"\n"	{col_count = 0; line_count++;}
{IDENTIFICADOR}		{
						if (yyleng > 50) {
							fprintf(stderr, "ERROR MORFOLOGICO:%d:%d:IDENTIFICADOR DEMASIADO LARGO (%s)\n", line_count, col_count, yytext);
							return TOK_ERROR;
						} else {
							col_count += yyleng;
							fprintf(fout, ";D:\tTOK_IDENTIFICADOR\n");
							return TOK_IDENTIFICADOR;
						}
					}
.					{col_count+=yyleng;
						fprintf(stderr, "ERROR MORFOLOGICO:%d:%d:CARACTER INVALIDO (%s)\n", line_count, col_count, yytext);
						return TOK_ERROR;}


%%
