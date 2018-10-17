%{ 
#include "tokens.h"

%}

%option noyywrap
%%
none		{return TOK_NONE;}
class		{return TOK_CLASS;}
inherits 	{return TOK_INHERITS;}
instance_of	{return TOK_INSTANCE_OF;}
discard		{return TOK_DISCARD;}
itself		{return TOK_ITSELF;}
hidden		{return TOK_HIDDEN;}
secret		{return TOK_SECRET;}
exposed		{return TOK_EXPOSED;}
unique		{return TOK_UNIQUE;}
function	{return TOK_FUNCTION;}
return		{return TOK_RETURN;}
main		{return TOK_MAIN;}
boolean		{return TOK_BOOLEAN;}
array		{return TOK_ARRAY;}
printf		{return TOK_PRINTF;}
int			{return TOK_INT;}
if			{return TOK_IF;}
else		{return TOK_ELSE;}
while		{return TOK_WHILE;}
scanf		{return TOK_SCANF;}
false		{return TOK_FALSE;}
true 		{return TOK_TRUE;}
";"			
"("			
")"			
"*" 		
"+"			
"<="		{return TOK_MENORIGUAL;}
%%
