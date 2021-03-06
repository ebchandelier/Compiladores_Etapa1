/*Eduardo Bassani Chandelier 261591
Bruno Loureiro*/

digit [0-9]
letter [A-Za-z]
identifier ({letter}|_)({letter}|{digit}|((\ )*({letter}|{digit}|_))|_)*
int ({digit})+


%{
	#include <string.h> 
	int getLineNumber(void);

	extern int lineCount;

	int isRunning(void);
	int running = 0;
	
	#include"hash.h"
	#include"ast.h"
	#include"hash.c"

	#include"y.tab.h"

	void initMe(void);
    void yyparse();

	HashTable *hashtable;
%}

%%

\n	lineCount++;
<<EOF>> { printHash(hashtable); running=0; return 0;}

byte		return KW_BYTE;
short		return KW_SHORT;
long		return KW_LONG;
float		return KW_FLOAT;
double		return KW_DOUBLE;
if			return KW_IF;
then		return KW_THEN;
else		return KW_ELSE;
while		return KW_WHILE;
for			return KW_FOR;
read		return KW_READ;
print		return KW_PRINT;
return		return KW_RETURN;

{identifier}					{yylval.symbol = setHashValue( hashtable, yytext, TK_IDENTIFIER );return TK_IDENTIFIER;}

({digit})+						{yylval.symbol = setHashValue( hashtable, yytext, LIT_INTEGER); return LIT_INTEGER;}
({digit})+(".")({digit})+		{yylval.symbol = setHashValue( hashtable, yytext, LIT_REAL); return LIT_REAL;}
(\')(.)(\')						{yylval.symbol = setHashValue( hashtable, yytext, LIT_CHAR);return LIT_CHAR;}
((\")([^\"]|(\\\"))*(\"))		{yylval.symbol = setHashValue( hashtable, yytext, LIT_STRING);return LIT_STRING;}

[ \t]   // Ignore whitespace, tab
[\,\;\:\(\)\[\]\{\}\+\-\*\/\<\>\=\!\&\$\#]	return *yytext;

\<=		return OPERATOR_LE;
\>=		return OPERATOR_GE;
\==		return OPERATOR_EQ;
\!=		return OPERATOR_NE;
\&&		return OPERATOR_AND;
\|\|	return OPERATOR_OR;

(\/\/)(.)*(\n)		{lineCount++; break;}
(\/\*)(.|\n)*(\*\/)	{break;}

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
	lineCount = 1;
	hashtable = createHashTable( 65536 );
	running=1;
}

//#include "main.c"

