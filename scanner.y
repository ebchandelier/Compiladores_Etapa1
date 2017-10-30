%{
	int yylex(void);
	void yyerror(char *);

	#include <string.h>

	#include "hash.h"
	#include "ast.h"

	#include<stdio.h>
	#include<stdlib.h>

    int lineCount = 0;

	AST* astRoot;

	void initMe();
%}

%union {
	AST* ast;
	HashEntry* symbol;
}

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

%token<symbol> TK_IDENTIFIER
%token<symbol> LIT_INTEGER
%token<symbol> LIT_REAL
%token<symbol> LIT_CHAR
%token<symbol> LIT_STRING

%token TOKEN_ERROR

%type<ast> expr
%type<ast> at_array
%type<ast> program
%type<ast> vardec
%type<ast> type
%type<ast> value
%type<ast> valuelist
%type<ast> fundec
%type<ast> funheader 
%type<ast> funbody
%type<ast> arglist
%type<ast> arg
%type<ast> optarg
%type<ast> cmdblock
%type<ast> cmdlist
%type<ast> cmd
%type<ast> printableList
%type<ast> printable
%type<ast> optPrintable
%type<ast> elseCmd
%type<ast> optcmd
%type<ast> funcall
%type<ast> paramlist
%type<ast> param
%type<ast> optparam

%left '<' '>' OPERATOR_GE OPERATOR_LE OPERATOR_NE OPERATOR_EQ
%left '+' '-'
%left '*' '/'

%%

begin:
	program {astRoot = $1;}

program:
	fundec program	{ $$ = astCreate(AST_LIST, 0, $1, $2, 0, 0); }
	| vardec program	{ $$ = astCreate(AST_LIST, 0, $1, $2, 0, 0); }
	|	{ $$ = 0;}
	;

vardec:
	TK_IDENTIFIER ':' type '=' value ';'	{$$ = astCreate(ASSIGNMENT, 0, astCreate(AST_SYMBOL, $1, 0, 0, 0, 0), $3, $5, 0);}
	| TK_IDENTIFIER ':' type '[' LIT_INTEGER ']' valuelist ';' {$$ = astCreate(ASSIGNMENT_LIST, 
																0, 
																astCreate(AST_SYMBOL, $1, 0, 0, 0, 0), 
																$3, 
																astCreate(AST_SYMBOL, $5, 0, 0, 0, 0), 
																$7);}
	;

expr:
    LIT_INTEGER { $$ = astCreate(LITERAL, $1, 0, 0, 0, 0);}
    | funcall	{ $$ = $1; }	
    | TK_IDENTIFIER at_array	{ $$ = astCreate(AST_SYMBOL_ARRAY, $1, $2, 0, 0, 0);}
    | '-' expr { $$ = astCreate(AST_CHANGE_SIGN, 0, $2, 0, 0, 0); }//%prec UMINUS { $$ = opr(UMINUS, 1, $2); }
    | expr '+' expr	{ $$ = astCreate(AST_ADD, 0, $1, $3, 0, 0);}
    | expr '-' expr { $$ = astCreate(AST_SUB, 0, $1, $3, 0, 0);}
    | expr '*' expr { $$ = astCreate(AST_MUL, 0, $1, $3, 0, 0);}
    | expr '/' expr { $$ = astCreate(AST_DIV, 0, $1, $3, 0, 0);}
    | expr '<' expr { $$ = astCreate(AST_LESS, 0, $1, $3, 0, 0);}
    | expr '>' expr { $$ = astCreate(AST_GREA, 0, $1, $3, 0, 0);}
    | expr OPERATOR_GE expr  { $$ = astCreate(GE, 0, $1, $3, 0, 0); }
    | expr OPERATOR_LE expr  { $$ = astCreate(LE, 0, $1, $3, 0, 0); }
    | expr OPERATOR_NE expr  { $$ = astCreate(NOT_EQUAL, 0, $1, $3, 0, 0); }
    | expr OPERATOR_EQ expr  { $$ = astCreate(EQUAL, 0, $1, $3, 0, 0); }
    | '(' expr ')'  { $$ = astCreate(PARENTESES, 0, $2, 0, 0, 0); }
    | expr OPERATOR_OR expr { $$ = astCreate(OR, 0, $1, $3, 0, 0); }
    | expr OPERATOR_AND expr { $$ = astCreate(AND, 0, $1, $3, 0, 0); }
    ;

at_array:
	'[' expr ']'	{ $$ = astCreate(AST_AT_ARRAY, 0, $2, 0, 0, 0); }
	|	{ $$ = 0; }
	;

funcall:
	TK_IDENTIFIER '(' paramlist ')'	{ $$ = astCreate(AST_FUN_CAL, $1, $3, 0, 0, 0); }
	;

cmd:
	TK_IDENTIFIER '=' expr { $$ = astCreate(AST_SYMBOL_ASSIGNMENT, $1, $3, 0, 0, 0);}
	| TK_IDENTIFIER '[' expr ']' '=' expr { $$ = astCreate(ASSIGNMENT_LIST_INDEX, $1, $3, $6, 0, 0); }
	| KW_READ '>' TK_IDENTIFIER { $$ = astCreate(READ_CMD, 0, astCreate(AST_SYMBOL, $3, 0, 0, 0, 0), 0, 0, 0); }
	| KW_PRINT printableList { $$ = astCreate(PRINT_CMD, 0, $2, 0, 0, 0); }
	| KW_RETURN expr { $$ = astCreate(RETURN_CMD, 0, $2, 0, 0, 0); }
	| KW_IF '(' expr ')' KW_THEN cmd elseCmd { $$ = astCreate(IF_THEN_ELSE_CMD, 0, $3, $6, $7, 0);}
	| KW_WHILE '(' expr ')' cmd { $$ = astCreate(WHILE_CMD, 0, $3, $5, 0, 0); }
    | cmdblock	{ $$ = $1; }
    |	{ fprintf(stderr, "VAZIU CMD\n"); $$ = 0; }
	;

printableList:
	printable optPrintable { $$ = astCreate(PRINT_CONTENT, 0, $1, $2, 0, 0); }
	|	{ $$ = 0; }
	;

printable:
	LIT_STRING { $$ = astCreate(LITERAL, $1, 0, 0, 0, 0); }
	| expr	{ $$ = $1; }
	;

optPrintable:
	',' printable optPrintable { $$ = astCreate(PRINT_CONTENT, 0, $2, $3, 0, 0); }
	|	{ $$ = 0; } 
	;

elseCmd:
    KW_ELSE cmd { $$ = astCreate(ELSE_CMD, 0, $2, 0, 0, 0); }
    |	{ $$ = 0; }
    ;


type:
	KW_BYTE { $$ = astCreate(AST_BYTE, 0, 0, 0, 0, 0);}
	| KW_SHORT	{ $$ = astCreate(AST_SHORT, 0, 0, 0, 0, 0);}
	| KW_LONG	{ $$ = astCreate(AST_LONG, 0, 0, 0, 0, 0);}
	| KW_FLOAT	{ $$ = astCreate(AST_FLOAT, 0, 0, 0, 0, 0);}
	| KW_DOUBLE	{ $$ = astCreate(AST_DOUBLE, 0, 0, 0, 0, 0);}
	;

value:
	LIT_INTEGER { $$ = astCreate(LITERAL, $1, 0, 0, 0, 0);}
	| LIT_REAL { $$ = astCreate(LITERAL, $1, 0, 0, 0, 0);}
	| LIT_CHAR { $$ = astCreate(LITERAL, $1, 0, 0, 0, 0);}
	;

valuelist:
	value valuelist { $$ = astCreate(VALUE_LIST, 0, $1, $2, 0, 0);}
	|	{$$ = 0;}
	;

fundec:
	funheader funbody { $$ = astCreate(FUNCTION, 0, $1, $2, 0, 0);}
	;

funheader:
	'(' type ')' TK_IDENTIFIER '(' arglist ')' { $$ = astCreate(FUNCTION_HEADER, 0,
												$2,
												astCreate(AST_SYMBOL, $4, 0, 0, 0, 0),
												$6,
												0);}
	;

arglist:
	arg optarg { $$ = astCreate(ARG_LIST, 0, $1, $2, 0, 0); }
	|	{ $$ = 0; }
	;

arg:
	TK_IDENTIFIER ':' type { $$ = astCreate(ARGUMENT, 0, 
							astCreate(AST_SYMBOL, $1, 0, 0, 0, 0), 
							$3, 0, 0); }
	;

optarg:
	',' arg optarg { $$ = astCreate(ARG_LIST, 0, $2, $3, 0, 0); }
	|	{ $$ = 0; }
	;

paramlist:
	param optparam { $$ = astCreate(AST_PARAM_LIST, 0, $1, $2, 0, 0); }
	|	{ $$ = 0; }
	;

param:
	expr { $$ = $1; }
	;

optparam:
	',' param optparam  { $$ = astCreate(AST_PARAM_LIST, 0, $2, $3, 0, 0); }
	|	{ $$ = 0; }
	;

funbody:
	cmdblock { $$ = astCreate(FUNCTION_BODY, 0, $1, 0, 0, 0); }
	;

cmdblock:
	'{' cmdlist '}' { $$ = astCreate(AST_CMD_BLOCK, 0, $2, 0, 0, 0); }
	;

cmdlist:
	cmd optcmd { $$ = astCreate(AST_CMD_LIST, 0, $1, $2, 0, 0); }
	;

optcmd:
	';' cmd optcmd	{ $$ = astCreate(AST_CMD_LIST, 0, $2, $3, 0, 0); }
	|	{ fprintf(stderr, "VAZIU OPTCMD\n"); $$ = 0; }
	;


%%

void yyerror(char *s) {
    fprintf(stderr, "%s at line: %d\n", s, lineCount);
	exit(3);
}

#include"main.c"
