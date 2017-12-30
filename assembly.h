#include "hash.h"
#include "tac.h"

void generateAssembly(TAC* tacs, const char* filename);
void generateAssemblyOf(TAC* tac);
void generateAssembly_move(HashEntry* res, HashEntry* source);
void generateAssembly_arrayMove(HashEntry* res, HashEntry* source);
void generateAssembly_begin_fun(HashEntry* node);
void generateAssembly_end_fun(HashEntry* node);
void generateAssembly_arrayAccess(HashEntry* res, HashEntry* source1, HashEntry* source2);
void generateAssembly_less(HashEntry* res, HashEntry* source1, HashEntry* source2);
void generateAssembly_less_equal(HashEntry* res, HashEntry* source1, HashEntry* source2);
void generateAssembly_greater(HashEntry* res, HashEntry* source1, HashEntry* source2);
void generateAssembly_greater_equal(HashEntry* res, HashEntry* source1, HashEntry* source2);
void generateAssembly_equal(HashEntry* res, HashEntry* source1, HashEntry* source2);
void generateAssembly_not_equal(HashEntry* res, HashEntry* source1, HashEntry* source2);
void generateAssembly_and(HashEntry* res, HashEntry* source1, HashEntry* source2);
void generateAssembly_arrayAccess(HashEntry* res, HashEntry* op1, HashEntry* op2);