#ifndef ASTREE_HEADER
#define ASTREE_HEADER

#define AST_SYMBOL 1
#define AST_ADD 2
#define AST_MUL 3
#define AST_CHANGE_SIGN 4
#define AST_LIST 5
#define ASSIGNMENT 6
#define AST_BYTE 7
#define AST_SHORT 8
#define AST_LONG 9
#define AST_FLOAT 10
#define AST_DOUBLE 11
#define LITERAL 12
#define TOKEN 13
#define ASSIGNMENT_LIST 14
#define VALUE_LIST 15
#define FUNCTION 16
#define FUNCTION_HEADER 17
#define ARG_LIST 18
#define ARGUMENT 19
#define FUNCTION_BODY 20
#define ASSIGNMENT_LIST_INDEX 21
#define READ_CMD 22
#define PRINT_CMD 23
#define RETURN_CMD 24
#define IF_THEN_ELSE_CMD 25
#define WHILE_CMD 26
#define PRINT_CONTENT 27
#define AST_CMD_BLOCK 28
#define AST_CMD_LIST 29
#define AST_FUN_CAL 30
#define AST_AT_ARRAY 31
#define AST_SYMBOL_ASSIGNMENT 32
#define AST_SUB 33
#define AST_DIV 34
#define AST_LESS 35
#define AST_GREA 36
#define AST_PARAM_LIST 37
#define GE 38
#define LE 39
#define EQUAL 40
#define NOT_EQUAL 41
#define OR 42
#define AND 43
#define PARENTESES 44
#define AST_SYMBOL_ARRAY 45
#define ELSE_CMD 46

//problem....use enum?


typedef struct ast_node {
    
    int type;
    struct hash_table_entry* symbol;
    struct ast_node* son[4];
} AST;

#include "hash.h"

AST* astCreate(int type, struct hash_table_entry* symbol, AST* son1, AST* son2, AST* son3, AST* son4);
void astPrint(AST* node, int level);
char* toOutput(AST* ast);

#endif