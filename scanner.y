%{
	int yylex(void);
	void yyerror(char *);
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
	fundec //program
	| vardec program
	|
	;

vardec:
	TK_IDENTIFIER ":" type "=" value ";"
	| TK_IDENTIFIER ":" type "[" LIT_INTEGER "]" valuelist ";" //valueList pode ser vazia, conflict
//	| TK_IDENTIFIER ":" type "[" LIT_INTEGER "]" ";"
	;

expr:
    LIT_INTEGER //{ $$ = con($1); }
    | TK_IDENTIFIER  //{ $$ = id($1); }
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

cmd:
	KW_READ
	| KW_PRINT
	| KW_RETURN
	| KW_IF "(" expr ")" KW_THEN cmd elseCmd
	| KW_WHILE "(" expr ")" cmd
    | cmdblock
	;

elseCmd:
    KW_ELSE cmd
    |
    ;


type:
	"byte"
	| "short"
	| "long"
	| "float"
	| "double"
	;

value:
	LIT_INTEGER
	| LIT_REAL
	| LIT_CHAR
	;

valuelist:
	value valuelist
	|
	;

fundec:
	funheader funbody
	;

funheader:
	"(" type ")" TK_IDENTIFIER "(" arglist ")"
	;

arglist:
	arg optarg
	|
	;

arg:
	TK_IDENTIFIER ":" type
	;

optarg:
	"," arg optarg
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
	|
	;

optcmd:
	";" cmd optcmd
	|
	;