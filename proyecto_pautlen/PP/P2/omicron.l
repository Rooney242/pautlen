%{ 
#include "tokens.h"

int line_count = 1;
int col_count = 0;

%}

%option noyywrap

DIGITO			[0-9]
LETRA			[a-zA-Z]
ENTERO			{DIGITO}*
COMENTARIO		"//".*\n
IDENTIFICADOR 	{LETRA}({LETRA}|{DIGITO})*

%%
none				{col_count+=yyleng; return TOK_NONE;}
class				{col_count+=yyleng; return TOK_CLASS;}
inherits			{col_count+=yyleng; return TOK_INHERITS;}
instance_of			{col_count+=yyleng; return TOK_INSTANCE_OF;}
discard				{col_count+=yyleng; return TOK_DISCARD;}
itself				{col_count+=yyleng; return TOK_ITSELF;}
hidden				{col_count+=yyleng; return TOK_HIDDEN;}
secret				{col_count+=yyleng; return TOK_SECRET;}
exposed				{col_count+=yyleng; return TOK_EXPOSED;}
unique				{col_count+=yyleng; return TOK_UNIQUE;}
function			{col_count+=yyleng; return TOK_FUNCTION;}
return				{col_count+=yyleng; return TOK_RETURN;}
main				{col_count+=yyleng; return TOK_MAIN;}
boolean				{col_count+=yyleng; return TOK_BOOLEAN;}
array				{col_count+=yyleng; return TOK_ARRAY;}
printf				{col_count+=yyleng; return TOK_PRINTF;}
int					{col_count+=yyleng; return TOK_INT;}
if					{col_count+=yyleng; return TOK_IF;}
else				{col_count+=yyleng; return TOK_ELSE;}
while				{col_count+=yyleng; return TOK_WHILE;}
scanf				{col_count+=yyleng; return TOK_SCANF;}
false				{col_count+=yyleng; return TOK_FALSE;}
true				{col_count+=yyleng; return TOK_TRUE;}
"->"				{col_count+=yyleng; return TOK_FLECHA;}
==					{col_count+=yyleng; return TOK_IGUAL;}
"!="				{col_count+=yyleng; return TOK_DISTINTO;}
"<="				{col_count+=yyleng; return TOK_MENORIGUAL;}
">="				{col_count+=yyleng; return TOK_MAYORIGUAL;}
"&&"				{col_count+=yyleng; return TOK_AND;}
"||"				{col_count+=yyleng; return TOK_OR;}
";"					{col_count+=yyleng; return yytext[0];}
"#"					{col_count+=yyleng; return yytext[0];}
","					{col_count+=yyleng; return yytext[0];}
"="					{col_count+=yyleng; return yytext[0];}
"("					{col_count+=yyleng; return yytext[0];}
")"					{col_count+=yyleng; return yytext[0];}
"{"					{col_count+=yyleng; return yytext[0];}
"}"					{col_count+=yyleng; return yytext[0];}
"["					{col_count+=yyleng; return yytext[0];}
"]"					{col_count+=yyleng; return yytext[0];}
":"					{col_count+=yyleng; return yytext[0];}
"+"					{col_count+=yyleng; return yytext[0];}
"-"					{col_count+=yyleng; return yytext[0];}
"/"					{col_count+=yyleng; return yytext[0];}
"*"					{col_count+=yyleng; return yytext[0];}
">"					{col_count+=yyleng; return yytext[0];}
"<"					{col_count+=yyleng; return yytext[0];}
"&"					{col_count+=yyleng; return yytext[0];}
"!"					{col_count+=yyleng; return yytext[0];}
"."					{col_count+=yyleng; return yytext[0];}
[ \t\r]				{col_count += yyleng;}
{ENTERO}			{col_count+=yyleng; return TOK_CONSTANTE_ENTERA;}
{COMENTARIO}|"\n"	{col_count = 0; line_count++;}
{IDENTIFICADOR}		{
						if (yyleng > MAX_LONG_ID) {
							return TOK_ERROR;
						} else {
							col_count += yyleng;
							return TOK_IDENTIFICADOR;
						}
					}
.					{col_count+=yyleng; return TOK_ERROR;}


%%
