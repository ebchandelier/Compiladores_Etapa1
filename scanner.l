/*Eduardo Bassani Chandelier 261591
Bruno Loureiro*/

digit [0-9]
letter [A-Za-z] 
identifier ([A-Za-z]|_)([A-Za-z]|[0-9]|((\ )*([A-Za-z]|_))|_)*
int ({digit})+


%{
	//#include"tokens.h"
	#include <string.h> 
	//char *yylval;
	int getLineNumber(void);

	extern int lineCount;

	int isRunning(void);
	int running = 0;

	#include"y.tab.h"

	void initMe(void);
    void yyparse();
	#include"hash.c"
	#include"hash_table_test.c"

	HashTable *hashtable;
	HASH_TABLE table;
%}

%%

\n	lineCount++;
<<EOF>> {print(&table); printf("EOF\n"); running=0; exit(0);/*yyterminate();*/}

byte	return KW_BYTE;
short	{return KW_SHORT;}
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

{identifier}    {printf("found a identifier\n");insert(&table, yytext, TK_IDENTIFIER);setHashValue( hashtable, yytext, TK_IDENTIFIER );return TK_IDENTIFIER;}

({digit})+	{setHashValue( hashtable, yytext, LIT_INTEGER); return LIT_INTEGER;}
({digit})+(".")({digit})+	{setHashValue( hashtable, yytext, LIT_REAL); return LIT_REAL;}
(\')(.)(\')	{setHashValue( hashtable, yytext, LIT_CHAR);return LIT_CHAR;}
(\")([^\"]|(\\\"))*(\")	{setHashValue( hashtable, yytext, LIT_STRING);return LIT_STRING;}

[ \t]   // Ignore whitespace, tab
[\,\;\:\(\)\[\]\{\}\+\-\*\/\<\>\=\!\&\$\#]	return *yytext;

\<=	return OPERATOR_LE;
\>=	return OPERATOR_GE;
\==	return OPERATOR_EQ;
\!=	return OPERATOR_NE;
\&&	return OPERATOR_AND;
\|\|	return OPERATOR_OR;

(\/\/)(.)*(\n)	{/*printf("simple comment"); */lineCount++; break;}
(\/\*)(.|\n)*(\*\/)	{/*printf("mult comment");*/ break;}

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
	
	hashtable = createHashTable( 65536 );
	running=1;
}

//#include "main.c"

