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
    6,    6,    6,    6,    6,    6,    6,    6,    6,    7,
    7,    7,    7,    7,    7,    8,    8,    3,    3,    3,
    3,    3,    4,    4,    4,    5,    5,    1,   10,   12,
   12,   13,   14,   14,   11,    9,   15,   15,   16,   16,
};
static const YYINT yylen[] = {                            2,
    2,    2,    0,    6,    8,    1,    1,    2,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    1,
    1,    1,    7,    5,    1,    2,    0,    1,    1,    1,
    1,    1,    1,    1,    1,    2,    0,    2,    7,    2,
    0,    3,    3,    0,    1,    3,    2,    0,    3,    0,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,   28,   29,   30,
   31,   32,    0,    1,    2,    0,   45,   38,    0,    0,
    0,    0,   20,   22,   21,    0,   25,    0,    0,    0,
    0,    0,    0,    0,   47,   46,   33,   34,   35,    0,
    0,    0,    7,    6,    0,    0,    0,    0,    0,    4,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   49,    0,
    0,    0,   39,    0,   40,   19,    0,    0,    0,    0,
    0,    0,    0,    0,   11,   12,    0,   24,   36,    5,
   42,    0,    0,   43,    0,   23,   26,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,   13,   70,   71,   47,   26,   96,   27,    6,
   18,   53,   54,   75,   28,   35,
};
static const YYINT yysindex[] = {                       -38,
  -49, -155,    0,  -38,  -38, -101, -155,    0,    0,    0,
    0,    0,  -14,    0,    0, -122,    0,    0,  -57, -244,
    1,    7,    0,    0,    0,  -20,    0,  -76, -271, -224,
   26,  -40,  -40, -122,    0,    0,    0,    0,    0,    3,
  -30, -205,    0,    0,  -40,  -40,  -31,  -24,  -20,    0,
 -271,   17,   36,   38,  -27,  -17,  -40,  -40,  -40,  -40,
  -40,  -40,  -40,  -40,  -40,  -40, -183, -122,    0, -271,
   25, -155,    0, -205,    0,    0,   54,   54,   54,   54,
   54,   54,  -27,  -27,    0,    0, -122,    0,    0,    0,
    0,   38, -178,    0, -122,    0,    0,
};
static const YYINT yyrindex[] = {                        88,
    0,    0,    0,   88,   88,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -34,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -32,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   57,    0,    0,    0,    0,    0,    0,  -32,    0,
   41,    0,    0,   69,   -8,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   41,
    0,    0,    0,    0,    0,    0,   10,   14,   19,   23,
   27,   32,   -1,    5,    0,    0,    0,    0,    0,    0,
    0,   69,  -56,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                        53,
    0,    0,    6,   82,   42,   62,   22,    0,  107,    0,
    0,    0,   40,   24,    0,   66,
};
#define YYTABLESIZE 305
static const YYINT yytable[] = {                         46,
   16,    2,   27,   29,   45,   37,   38,   39,    7,   67,
   65,   63,   19,   64,   65,   66,   68,   65,   63,   66,
   64,   16,   66,   76,   65,   63,   20,   64,   61,   66,
   62,   31,    8,   30,    8,   61,    8,   62,   34,    9,
   32,    9,   61,    9,   62,   10,   33,   10,   36,   10,
   16,    8,   41,    8,   15,   49,   14,   15,    9,   18,
    9,   50,   51,   17,   10,   42,   10,   13,   27,   16,
   52,   16,   14,   15,   72,   15,   73,   91,   18,   87,
   18,   74,   17,   90,   17,   95,   13,    3,   13,   88,
   48,   14,   50,   14,   48,   65,   63,   41,   64,   37,
   66,    8,    9,   10,   11,   12,   55,   56,   93,   44,
   40,   89,   17,   92,   69,   94,   97,    0,   77,   78,
   79,   80,   81,   82,   83,   84,   85,   86,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   21,
    0,    0,   22,    0,   23,   24,   25,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   43,   44,    1,   57,   58,
   59,   60,    0,    0,    0,   57,   58,   59,   60,    0,
    0,    0,   57,   58,   59,   60,    0,    0,    0,    0,
    0,    8,    8,    8,    8,    0,    0,    0,    9,    9,
    9,    9,    0,    0,   10,   10,   10,   10,    0,   16,
   16,   16,   16,   15,   15,   15,   15,    0,   18,   18,
   18,   18,   17,   17,   17,   17,   13,   13,   13,   13,
    0,   14,   14,   14,   14,
};
static const YYINT yycheck[] = {                         40,
  123,   40,   59,   61,   45,  277,  278,  279,   58,   41,
   42,   43,    7,   45,   42,   47,   41,   42,   43,   47,
   45,  123,   47,   41,   42,   43,   41,   45,   60,   47,
   62,  276,   41,   91,   43,   60,   45,   62,   59,   41,
   40,   43,   60,   45,   62,   41,   40,   43,  125,   45,
   41,   60,  277,   62,   41,   34,    4,    5,   60,   41,
   62,   59,   93,   41,   60,   40,   62,   41,  125,   60,
  276,   62,   41,   60,   58,   62,   41,   72,   60,  263,
   62,   44,   60,   59,   62,  264,   60,    0,   62,   68,
  125,   60,  125,   62,   33,   42,   43,   41,   45,   59,
   47,  257,  258,  259,  260,  261,   45,   46,   87,   41,
   29,   70,    6,   74,   49,   92,   95,   -1,   57,   58,
   59,   60,   61,   62,   63,   64,   65,   66,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,
   -1,   -1,  265,   -1,  267,  268,  269,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  276,  277,  276,  270,  271,
  272,  273,   -1,   -1,   -1,  270,  271,  272,  273,   -1,
   -1,   -1,  270,  271,  272,  273,   -1,   -1,   -1,   -1,
   -1,  270,  271,  272,  273,   -1,   -1,   -1,  270,  271,
  272,  273,   -1,   -1,  270,  271,  272,  273,   -1,  270,
  271,  272,  273,  270,  271,  272,  273,   -1,  270,  271,
  272,  273,  270,  271,  272,  273,  270,  271,  272,  273,
   -1,  270,  271,  272,  273,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 281
#define YYUNDFTOKEN 300
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
"LIT_CHAR","LIT_STRING","TOKEN_ERROR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : fundec program",
"program : vardec program",
"program :",
"vardec : TK_IDENTIFIER ':' type '=' value ';'",
"vardec : TK_IDENTIFIER ':' type '[' LIT_INTEGER ']' valuelist ';'",
"expr : LIT_INTEGER",
"expr : TK_IDENTIFIER",
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
"cmd : KW_READ",
"cmd : KW_PRINT",
"cmd : KW_RETURN",
"cmd : KW_IF '(' expr ')' KW_THEN cmd elseCmd",
"cmd : KW_WHILE '(' expr ')' cmd",
"cmd : cmdblock",
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
"funbody : cmdblock",
"cmdblock : '{' cmdlist '}'",
"cmdlist : cmd optcmd",
"cmdlist :",
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
#line 153 "scanner.y"

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
    return;
}

#include"main.c"
#line 343 "y.tab.c"

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
#line 553 "y.tab.c"
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
