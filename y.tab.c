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
#line 24 "y.tab.c"

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
#define byte 282
#define short 283
#define long 284
#define float 285
#define double 286
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    2,    2,    2,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    7,    7,    7,    7,    7,    7,    8,    8,    3,    3,
    3,    3,    3,    4,    4,    4,    5,    5,    1,   10,
   12,   12,   13,   14,   14,   11,    9,   15,   15,   16,
   16,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    6,    8,    7,    1,    1,    2,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    1,    1,    1,    7,    5,    1,    2,    0,    1,    1,
    1,    1,    1,    1,    1,    1,    2,    0,    2,    7,
    2,    0,    3,    3,    0,    1,    3,    2,    0,    3,
    0,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    0,    0,    0,   29,   30,   31,
   32,   33,    0,    2,    0,   46,   39,    0,    0,    0,
    0,   21,   23,   22,    0,   26,    0,    0,    0,    0,
    0,    0,    0,   48,   47,   34,   35,   36,    0,    0,
    0,    8,    7,    0,    0,    0,    0,    0,    4,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   50,    6,    0,
    0,    0,   40,    0,   41,   20,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   25,   37,    5,
   43,    0,    0,   44,    0,   24,   27,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,   13,   70,   71,   46,   25,   96,   26,    6,
   17,   52,   53,   75,   27,   34,
};
static const YYINT yysindex[] = {                       -38,
  -36, -166,    0,    0,  -38, -103, -166,    0,    0,    0,
    0,    0,    7,    0, -116,    0,    0,  -34, -225,   28,
   33,    0,    0,    0,   37,    0,  -26, -237, -175,   64,
  -40,  -40, -116,    0,    0,    0,    0,    0,   51,   12,
 -165,    0,    0,  -40,  -40,  -31,  -24,   37,    0,  -58,
   63,   81,   79,   -3,  -17,  -40,  -40,  -40,  -40,  -40,
  -40,  -40,  -40,  -40,  -40, -139, -116,    0,    0, -237,
   66, -166,    0, -165,    0,    0,  -10,  -10,  -10,  -10,
  -39,  -39,   -3,   -3, -217, -217, -116,    0,    0,    0,
    0,   79, -138,    0, -116,    0,    0,
};
static const YYINT yyrindex[] = {                       127,
    0,    0,    0,    0,  127,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    3,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    4,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   89,    0,    0,    0,    0,    0,    0,    4,    0,    0,
    0,    0,   90,   41,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   73,
    0,    0,    0,    0,    0,    0,   92,   93,    7,   94,
   46,   53,   47,   52,   29,   38,    0,    0,    0,    0,
    0,   90,  -50,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                       131,
    0,    0,    6,  109,   68,    2,  -18,    0,  133,    0,
    0,    0,   67,   48,    0,   95,
};
#define YYTABLESIZE 270
static const YYINT yytable[] = {                         45,
   69,    2,   64,   62,   44,   63,   15,   65,   28,   66,
   64,   62,   18,   63,   48,   65,   67,   64,   62,   15,
   63,    7,   65,   76,   64,   62,   28,   63,   60,   65,
   61,   64,   62,   47,   63,   60,   65,   61,   64,   36,
   37,   38,   60,   65,   61,   54,   55,   19,   88,   60,
   30,   61,   56,   57,   58,   59,   29,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   31,   93,   12,
   12,   12,   32,   12,   28,   12,   97,   91,   13,   13,
   13,    9,   13,    9,   13,    9,   14,   10,   12,   10,
   12,   10,   11,   15,   11,   33,   11,   13,   35,   13,
    9,   40,    9,   41,   50,   14,   10,   14,   10,   49,
   51,   11,   15,   11,   15,    8,    9,   10,   11,   12,
   72,   73,   74,   87,   90,   95,    3,   49,   51,   42,
   45,   38,   17,   16,   18,   14,   39,   89,   16,   94,
   92,    0,   68,    0,    0,   20,    0,    0,   21,    0,
   22,   23,   24,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   36,   37,
   38,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   56,   57,   58,   59,    0,   42,   43,    1,   56,   57,
   58,   59,    0,    0,    0,   56,   57,   58,   59,    0,
    0,    0,   56,   57,   58,   59,    0,    0,    0,   56,
   57,   58,   59,    0,    0,    0,   56,   57,   58,   59,
};
static const YYINT yycheck[] = {                         40,
   59,   40,   42,   43,   45,   45,  123,   47,   59,   41,
   42,   43,    7,   45,   33,   47,   41,   42,   43,  123,
   45,   58,   47,   41,   42,   43,   61,   45,   60,   47,
   62,   42,   43,   32,   45,   60,   47,   62,   42,  277,
  278,  279,   60,   47,   62,   44,   45,   41,   67,   60,
  276,   62,  270,  271,  272,  273,   91,   56,   57,   58,
   59,   60,   61,   62,   63,   64,   65,   40,   87,   41,
   42,   43,   40,   45,  125,   47,   95,   72,   41,   42,
   43,   41,   45,   43,   47,   45,   41,   41,   60,   43,
   62,   45,   41,   41,   43,   59,   45,   60,  125,   62,
   60,  277,   62,   40,   93,   60,   60,   62,   62,   59,
  276,   60,   60,   62,   62,  282,  283,  284,  285,  286,
   58,   41,   44,  263,   59,  264,    0,  125,  125,   41,
   41,   59,   41,   41,   41,    5,   28,   70,    6,   92,
   74,   -1,   48,   -1,   -1,  262,   -1,   -1,  265,   -1,
  267,  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  277,  278,
  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  270,  271,  272,  273,   -1,  276,  277,  276,  270,  271,
  272,  273,   -1,   -1,   -1,  270,  271,  272,  273,   -1,
   -1,   -1,  270,  271,  272,  273,   -1,   -1,   -1,  270,
  271,  272,  273,   -1,   -1,   -1,  270,  271,  272,  273,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 286
#define YYUNDFTOKEN 305
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
"LIT_CHAR","LIT_STRING","TOKEN_ERROR","\"byte\"","\"short\"","\"long\"",
"\"float\"","\"double\"",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : fundec",
"program : vardec program",
"program :",
"vardec : TK_IDENTIFIER ':' type '=' value ';'",
"vardec : TK_IDENTIFIER ':' type '[' LIT_INTEGER ']' valuelist ';'",
"vardec : TK_IDENTIFIER ':' type '[' LIT_INTEGER ']' ';'",
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
"type : \"byte\"",
"type : \"short\"",
"type : \"long\"",
"type : \"float\"",
"type : \"double\"",
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
