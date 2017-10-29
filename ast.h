#ifndef ASTREE_HEADER
#define ASTREE_HEADER

#include "hash.h"

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

//problem....use enum?

typedef struct ast_node {

    int type;
    HashEntry *symbol;
    struct ast_node* son[4];
} AST;

AST* astCreate(int type, HashEntry* symbol, AST* son1, AST* son2, AST* son3, AST* son4);
void astPrint(AST* node, int level);

#endif