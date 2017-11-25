#include "hash.h"
#include "ast.h"

#define TRUE 1
#define FALSE 0

#define NATURE_SCALAR 0
#define NATURE_VECTOR 1
#define NATURE_FUNCTION 2

#define DATA_TYPE_REAL 0
#define DATA_TYPE_INTEGER 1

void firstPass(AST *node);