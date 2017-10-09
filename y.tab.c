/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "scanner.y"
	int yylex(void);
	void yyerror(char *);

	#include <string.h>

	#include<stdio.h>
	#include<stdlib.h>

	void initMe();
#line 31 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define KW_BYTE 257
#define KW_SHORT 258
#define KW_LONG 259
#define KW_FLOAT 260
#define KW_DOUBLE 261
#define KW_IF 262
#define KW_THEN 263
#define KW_ELSE 264
#define KW_WHILE 265
#define KW_FOR 266
#define KW_READ 267
#define KW_RETURN 268
#define KW_PRINT 269
#define OPERATOR_LE 270
#define OPERATOR_GE 271
#define OPERATOR_EQ 272
#define OPERATOR_NE 273
#define OPERATOR_AND 274
#define OPERATOR_OR 275
#define TK_IDENTIFIER 276
#define LIT_INTEGER 277
#define LIT_REAL 278
#define LIT_CHAR 279
#define LIT_STRING 280
#define TOKEN_ERROR 281
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    2,    2,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    8,    8,    7,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   11,   11,   14,   14,   15,   15,   12,   12,
    3,    3,    3,    3,    3,    4,    4,    4,    5,    5,
    1,   16,   18,   18,   19,   20,   20,    9,    9,   21,
   22,   22,   17,   13,   23,   24,   24,
};
static const YYINT yylen[] = {                            2,
    2,    2,    0,    6,    8,    1,    1,    2,    2,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    0,    4,    3,    6,    3,    2,    2,    7,    5,
    1,    0,    2,    0,    1,    1,    3,    0,    2,    0,
    1,    1,    1,    1,    1,    1,    1,    1,    2,    0,
    2,    7,    2,    0,    3,    3,    0,    2,    0,    1,
    3,    0,    1,    3,    2,    3,    0,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,   41,   42,   43,
   44,   45,    0,    1,    2,    0,   63,   51,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   31,    0,    0,
    0,    0,    0,    0,    0,    0,    6,    0,    0,    0,
    7,   35,    0,   27,    0,    0,    0,    0,   65,   64,
   46,   47,   48,    0,    0,    0,    0,    0,   26,    0,
    0,    8,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   33,    0,    0,    0,    4,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   20,    0,    0,    0,    0,    0,    0,    0,    0,   12,
   13,    0,    0,   66,    0,    0,    0,   52,    0,   53,
    0,   30,   21,   23,    0,   58,   37,    0,   49,    5,
   55,    0,    0,    0,    0,   56,    0,   29,   61,   39,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,   13,  105,  106,   43,   41,   62,   89,   27,
   44,  128,   28,   45,   76,    6,   18,   83,   84,  110,
   90,  116,   29,   49,
};
static const YYINT yysindex[] = {                       -34,
  -50,  -32,    0,  -34,  -34, -122,  -32,    0,    0,    0,
    0,    0,  -28,    0,    0,  -59,    0,    0,  -57, -267,
  -11,   -7,  -45,  -38,  -40,  -51,  -24,    0,  -82, -118,
 -218,   33,  -38,  -38, -191,  -37,    0,  -38,  -38,  152,
    0,    0,  152,    0,   49,  -38,  -38,  -59,    0,    0,
    0,    0,    0,   30,   15, -165,   41,  103,    0,  -38,
  -38,    0,   45,  110,  -38,  -38,  -38,  -38,  -38,  -38,
  -38,  -38,  -38,  -38,  -40,    0,  152,  131,  -24,    0,
 -118,   64,   92,   96, -120,  -59,  138,  152,  100,  105,
    0,  -31,  -31,  -31,  -31,  -31,  -31,   45,   45,    0,
    0,   49,   93,    0, -118,  107,  -32,    0, -165,    0,
  -59,    0,    0,    0,  -38,    0,    0,  -38,    0,    0,
    0,   96, -100,  105,  152,    0,  -59,    0,    0,    0,
};
static const YYINT yyrindex[] = {                       167,
    0,    0,    0,  167,  167,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   -4,    0,    0,    0,    0,
    0,    0,    0,    0,  -21,    0,   43,    0,    0,    0,
    0,    0,    0,    0,    0,  -23,    0,    0,    0,   -2,
    0,    0,    1,    0,    3,    0,    0,   -4,    0,    0,
    0,    0,    0,    0,    0,  130,    0,    0,    0,    0,
  134,    0,  -18,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    4,    0,   43,    0,
  123,    0,    0,  143,    0,    6,    0,   50,    0,  145,
    0,   12,   17,   37,   54,   65,   76,  -13,    7,    0,
    0,    3,    0,    0,  123,    0,    0,    0,    0,    0,
    6,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  143,   31,  145,    9,    0,    6,    0,    0,    0,
};
static const YYINT yygindex[] = {                       114,
    0,    0,    8,  157,   83,  381,    0,    0,    0,   91,
    0,    0,  183,  117,   94,    0,    0,    0,   95,   85,
   90,   87,    0,  136,
};
#define YYTABLESIZE 499
static const YYINT yytable[] = {                         39,
   16,   39,   61,   30,   38,    2,   38,    7,   32,   46,
   73,   71,   20,   72,   19,   74,   35,   22,   22,   22,
   22,   22,    9,   22,    9,    9,    9,   10,   33,   10,
   10,   10,   34,   31,   48,   22,   22,   34,   22,   47,
    9,    9,   50,    9,   36,   10,   10,   11,   10,   11,
   11,   11,   17,   60,   32,   17,   28,   16,   55,   36,
   16,   38,   24,   16,   32,   11,   11,   25,   11,   22,
   17,   17,   56,   17,    9,   16,   16,   19,   16,   10,
   19,   85,   73,   71,   59,   72,   73,   74,   80,   40,
   60,   74,   75,   60,   18,   19,   19,   18,   19,   11,
   69,   22,   70,   34,   17,   14,    9,   81,   14,   16,
   82,   10,   18,   18,  121,   18,   15,   14,   15,   15,
   32,  107,   28,   14,   14,   36,   14,   38,   24,   19,
   32,   11,  108,   25,   15,   15,   17,   15,   79,  109,
  114,   16,  111,   86,   73,   71,   18,   72,  115,   74,
   91,   73,   71,  118,   72,   40,   74,   14,   51,   52,
   53,   19,   69,  127,   70,  120,    3,   67,   15,   69,
   54,   70,   73,   71,   59,   72,  112,   74,   18,   73,
   71,   50,   72,   57,   74,   62,   54,  119,   17,   14,
   69,  102,   70,   73,   71,  117,   72,   69,   74,   70,
   15,  123,   21,  122,  124,   22,  126,   23,   24,   25,
  129,   69,    0,   70,  104,    0,   26,  130,    0,    0,
    0,    0,    0,  103,    8,    9,   10,   11,   12,    0,
  113,    0,    0,    0,    0,   36,   37,   36,   37,   42,
   22,    1,   34,    0,    0,    9,   22,   22,   22,   22,
   10,    9,    9,    9,    9,    0,   10,   10,   10,   10,
    0,   28,    0,    0,   36,    0,   38,   24,    0,   32,
   11,    0,   25,    0,    0,   17,   11,   11,   11,   11,
   16,   17,   17,   17,   17,    0,   16,   16,   16,   16,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   19,    0,    0,    0,    0,    0,   19,   19,   19,   19,
   65,   66,   67,   68,    0,    0,    0,   18,    0,    0,
    0,    0,    0,   18,   18,   18,   18,    0,   14,    0,
    0,    0,    0,    0,   14,   14,   14,   14,    0,   15,
    0,    0,    0,    0,    0,   15,   15,   15,   15,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   65,   66,   67,   68,    0,    0,    0,   65,
   66,   67,   68,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   65,   66,   67,   68,   40,    0,    0,   65,   66,   67,
   68,    0,    0,   57,   58,    0,    0,    0,   63,   64,
    0,   65,   66,   67,   68,    0,   77,   78,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   87,   88,    0,    0,    0,   92,   93,   94,   95,   96,
   97,   98,   99,  100,  101,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   88,    0,    0,  125,
};
static const YYINT yycheck[] = {                         40,
  123,   40,   40,   61,   45,   40,   45,   58,  276,   61,
   42,   43,   41,   45,    7,   47,   62,   41,   42,   43,
   44,   45,   41,   47,   43,   44,   45,   41,   40,   43,
   44,   45,   40,   91,   59,   59,   60,   59,   62,   91,
   59,   60,  125,   62,   44,   59,   60,   41,   62,   43,
   44,   45,   41,   91,   59,   44,   59,   41,  277,   59,
   44,   59,   59,  123,   59,   59,   60,   59,   62,   93,
   59,   60,   40,   62,   93,   59,   60,   41,   62,   93,
   44,   41,   42,   43,  276,   45,   42,   47,   59,   59,
   41,   47,   44,   44,   41,   59,   60,   44,   62,   93,
   60,  125,   62,  125,   93,   41,  125,   93,   44,   93,
  276,  125,   59,   60,  107,   62,   41,    4,    5,   44,
  125,   58,  125,   59,   60,  125,   62,  125,  125,   93,
  125,  125,   41,  125,   59,   60,  125,   62,   48,   44,
   41,  125,  263,   41,   42,   43,   93,   45,   44,   47,
   41,   42,   43,   61,   45,  125,   47,   93,  277,  278,
  279,  125,   60,  264,   62,   59,    0,  125,   93,   60,
   41,   62,   42,   43,   41,   45,   86,   47,  125,   42,
   43,   59,   45,   41,   47,   41,   30,  105,    6,  125,
   60,   75,   62,   42,   43,  102,   45,   60,   47,   62,
  125,  111,  262,  109,  115,  265,  122,  267,  268,  269,
  124,   60,   -1,   62,   79,   -1,  276,  127,   -1,   -1,
   -1,   -1,   -1,   93,  257,  258,  259,  260,  261,   -1,
   93,   -1,   -1,   -1,   -1,  276,  277,  276,  277,  280,
  264,  276,  264,   -1,   -1,  264,  270,  271,  272,  273,
  264,  270,  271,  272,  273,   -1,  270,  271,  272,  273,
   -1,  264,   -1,   -1,  264,   -1,  264,  264,   -1,  264,
  264,   -1,  264,   -1,   -1,  264,  270,  271,  272,  273,
  264,  270,  271,  272,  273,   -1,  270,  271,  272,  273,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  264,   -1,   -1,   -1,   -1,   -1,  270,  271,  272,  273,
  270,  271,  272,  273,   -1,   -1,   -1,  264,   -1,   -1,
   -1,   -1,   -1,  270,  271,  272,  273,   -1,  264,   -1,
   -1,   -1,   -1,   -1,  270,  271,  272,  273,   -1,  264,
   -1,   -1,   -1,   -1,   -1,  270,  271,  272,  273,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  270,  271,  272,  273,   -1,   -1,   -1,  270,
  271,  272,  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  270,  271,  272,  273,   24,   -1,   -1,  270,  271,  272,
  273,   -1,   -1,   33,   34,   -1,   -1,   -1,   38,   39,
   -1,  270,  271,  272,  273,   -1,   46,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   60,   61,   -1,   -1,   -1,   65,   66,   67,   68,   69,
   70,   71,   72,   73,   74,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  115,   -1,   -1,  118,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 281
#define YYUNDFTOKEN 308
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_BYTE","KW_SHORT","KW_LONG","KW_FLOAT",
"KW_DOUBLE","KW_IF","KW_THEN","KW_ELSE","KW_WHILE","KW_FOR","KW_READ",
"KW_RETURN","KW_PRINT","OPERATOR_LE","OPERATOR_GE","OPERATOR_EQ","OPERATOR_NE",
"OPERATOR_AND","OPERATOR_OR","TK_IDENTIFIER","LIT_INTEGER","LIT_REAL",
"LIT_CHAR","LIT_STRING","TOKEN_ERROR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : fundec program",
"program : vardec program",
"program :",
"vardec : TK_IDENTIFIER ':' type '=' value ';'",
"vardec : TK_IDENTIFIER ':' type '[' LIT_INTEGER ']' valuelist ';'",
"expr : LIT_INTEGER",
"expr : funcall",
"expr : TK_IDENTIFIER at_array",
"expr : '-' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr OPERATOR_GE expr",
"expr : expr OPERATOR_LE expr",
"expr : expr OPERATOR_NE expr",
"expr : expr OPERATOR_EQ expr",
"expr : '(' expr ')'",
"at_array : '[' expr ']'",
"at_array :",
"funcall : TK_IDENTIFIER '(' paramlist ')'",
"cmd : TK_IDENTIFIER '=' expr",
"cmd : TK_IDENTIFIER '[' expr ']' '=' expr",
"cmd : KW_READ '>' TK_IDENTIFIER",
"cmd : KW_PRINT printableList",
"cmd : KW_RETURN expr",
"cmd : KW_IF '(' expr ')' KW_THEN cmd elseCmd",
"cmd : KW_WHILE '(' expr ')' cmd",
"cmd : cmdblock",
"cmd :",
"printableList : printable optPrintable",
"printableList :",
"printable : LIT_STRING",
"printable : expr",
"optPrintable : ',' printable optPrintable",
"optPrintable :",
"elseCmd : KW_ELSE cmd",
"elseCmd :",
"type : KW_BYTE",
"type : KW_SHORT",
"type : KW_LONG",
"type : KW_FLOAT",
"type : KW_DOUBLE",
"value : LIT_INTEGER",
"value : LIT_REAL",
"value : LIT_CHAR",
"valuelist : value valuelist",
"valuelist :",
"fundec : funheader funbody",
"funheader : '(' type ')' TK_IDENTIFIER '(' arglist ')'",
"arglist : arg optarg",
"arglist :",
"arg : TK_IDENTIFIER ':' type",
"optarg : ',' arg optarg",
"optarg :",
"paramlist : param optparam",
"paramlist :",
"param : expr",
"optparam : ',' param optparam",
"optparam :",
"funbody : cmdblock",
"cmdblock : '{' cmdlist '}'",
"cmdlist : cmd optcmd",
"optcmd : ';' cmd optcmd",
"optcmd :",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 194 "scanner.y"

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
    return;
}

#include"main.c"
#line 413 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 49 "scanner.y"
	{printf("program fundec\n");}
break;
case 2:
#line 50 "scanner.y"
	{printf("program vardec\n");}
break;
#line 623 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
