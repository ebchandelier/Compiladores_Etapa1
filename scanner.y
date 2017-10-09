%{
	int yylex(void);
	void yyerror(char *);

	#include <string.h>

	#include<stdio.h>
	#include<stdlib.h>

    int lineCount = 0;
	void initMe();
%}

%token KW_BYTE
%token KW_SHORT
%token KW_LONG
%token KW_FLOAT
%token KW_DOUBLE
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_FOR
%token KW_READ
%token KW_RETURN
%token KW_PRINT

%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_NE
%token OPERATOR_AND
%token OPERATOR_OR

%token TK_IDENTIFIER
%token LIT_INTEGER
%token LIT_REAL
%token LIT_CHAR
%token LIT_STRING

%token TOKEN_ERROR

%left '<' '>' OPERATOR_GE OPERATOR_LE OPERATOR_NE OPERATOR_EQ
%left '+' '-'
%left '*' '/'

%%

program:
	fundec program {printf("program fundec\n");}
	| vardec program {printf("program vardec\n");}
	|
	;

vardec:
	TK_IDENTIFIER ":" type "=" value ";" //{} setHashValue
	| TK_IDENTIFIER ":" type "[" LIT_INTEGER "]" valuelist ";" //setHashValue
	;

expr:
    LIT_INTEGER //setHashValue { $$ = con($1); }
    | funcall
    | TK_IDENTIFIER at_array //{ $$ = id($1); }
    | '-' expr //%prec UMINUS { $$ = opr(UMINUS, 1, $2); }
    | expr '+' expr //{ $$ = opr('+', 2, $1, $3); }
    | expr '-' expr //{ $$ = opr('-', 2, $1, $3); }
    | expr '*' expr //{ $$ = opr('*', 2, $1, $3); }
    | expr '/' expr //{ $$ = opr('/', 2, $1, $3); }
    | expr '<' expr //{ $$ = opr('<', 2, $1, $3); }
    | expr '>' expr //{ $$ = opr('>', 2, $1, $3); }
    | expr OPERATOR_GE expr  //{ $$ = opr(GE, 2, $1, $3); }
    | expr OPERATOR_LE expr  //{ $$ = opr(LE, 2, $1, $3); }
    | expr OPERATOR_NE expr  //{ $$ = opr(NE, 2, $1, $3); }
    | expr OPERATOR_EQ expr  //{ $$ = opr(EQ, 2, $1, $3); }
    | '(' expr ')'  //{ $$ = $2; }
    ;

at_array:
	"[" expr "]"
	|
	;

funcall:
	TK_IDENTIFIER "(" paramlist ")"
	;

cmd:
	TK_IDENTIFIER "=" expr
	| TK_IDENTIFIER "[" expr "]" "=" expr
	| KW_READ ">" TK_IDENTIFIER
	| KW_PRINT printableList
	| KW_RETURN expr
	| KW_IF "(" expr ")" KW_THEN cmd elseCmd
	| KW_WHILE "(" expr ")" cmd
    | cmdblock
    |
	;

printableList:
	printable optPrintable
	|
	;

printable:
	LIT_STRING //setHashValue ?
	| expr
	;

optPrintable:
	"," printable optPrintable
	|
	;

elseCmd:
    KW_ELSE cmd
    |
    ;


type:
	KW_BYTE
	| KW_SHORT
	| KW_LONG
	| KW_FLOAT
	| KW_DOUBLE
	;

value:
	LIT_INTEGER //setHashValue
	| LIT_REAL //setHashValue
	| LIT_CHAR //setHashValue
	;

valuelist:
	value valuelist
	|
	;

fundec:
	funheader funbody
	;

funheader:
	"(" type ")" TK_IDENTIFIER "(" arglist ")" //setHashValue
	;

arglist:
	arg optarg
	|
	;

arg:
	TK_IDENTIFIER ":" type //setHashValue?
	;

optarg:
	"," arg optarg
	|
	;

paramlist:
	param optparam
	|
	;

param:
	expr
	;

optparam:
	"," param optparam
	|
	;

funbody:
	cmdblock
	;

cmdblock:
	"{" cmdlist "}"
	;

cmdlist:
	cmd optcmd
	;

optcmd:
	";" cmd optcmd
	|
	;


%%

void yyerror(char *s) {
    fprintf(stderr, "%s at line: %d\n", s, lineCount);
	exit(3);
}

#include"main.c"
