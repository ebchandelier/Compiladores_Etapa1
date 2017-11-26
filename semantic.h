#include "hash.h"
#include "ast.h"

#define TRUE 1
#define FALSE 0

#define NATURE_SCALAR 2
#define NATURE_VECTOR 3
#define NATURE_FUNCTION 4

#define DATA_TYPE_REAL 5
#define DATA_TYPE_INTEGER 6
#define DATA_TYPE_FUNCTION 7

void firstPass(AST *node);
int secondPass(AST *node);