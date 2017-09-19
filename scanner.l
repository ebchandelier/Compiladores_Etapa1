/*Eduardo Bassani Chandelier 261591
Bruno Loureiro*/

digit [0-9]
letter [A-Za-z] 
identifier ({letter}|_)({letter}|{digit}|\ |_)*({letter}|{digit}|_) 
int ({digit})+


%{
	#include"tokens.h"
	#include <string.h> 
	char *yylval;
	int getLineNumber(void);
	int lineCount = 0;

	int isRunning(void);
	int running = 0;
	
	void initMe(void);

	#include"hash.c"

	hashtable_t *hashtable;
%}

%%

\n	lineCount++;
<<EOF>> {/*printf("EOF\n");*/ running=0;}

byte	return KW_BYTE;
short	return KW_SHORT;
long	return KW_LONG;
float	return KW_FLOAT;
double	return KW_DOUBLE;
if	return KW_IF;
then	return KW_THEN;
else	return KW_ELSE;
while	return KW_WHILE;
for	return KW_FOR;
read	return KW_READ;
print	return KW_PRINT;
return	return KW_RETURN;

{identifier}	{	ht_set( hashtable, yytext, TK_IDENTIFIER );return TK_IDENTIFIER;}		

({digit})+	{ht_set( hashtable, yytext, LIT_INTEGER); return LIT_INTEGER;}
({digit})+(.)({digit})+	{ht_set( hashtable, yytext, LIT_REAL); return LIT_REAL;}
(\')(.)(\')	{ht_set( hashtable, yytext, LIT_CHAR);return LIT_CHAR;}
(\")(.)*(\")	{ht_set( hashtable, yytext, LIT_STRING);return LIT_STRING;}


[\,\;\:\(\)\[\]\{\}\+\-\*\/\<\>\=\!\&\$\#]	return *yytext;

\<=	return OPERATOR_LE;
\>=	return OPERATOR_GE;
\==	return OPERATOR_EQ;
\!=	return OPERATOR_NE;
\&&	return OPERATOR_AND;
\|\|	return OPERATOR_OR;

(\/\/)(.)*(\n)	{/*printf("simple comment"); */lineCount++; break;}
(\/\*)(.)*(\*\/)	{/*printf("mult comment");*/ break;}

.	return TOKEN_ERROR;


%%

int isRunning(void) {

	return running;
}

int getLineNumber(void) {

	return lineCount;
}

int yywrap(void) {

	return 1;
} 

void initMe(void) {
	
	hashtable = ht_create( 65536 );
	running=1;
}

#include "main.c"

