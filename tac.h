#ifndef TAC_HEADER
#define TAC_HEADER

#include "semantic.h"

#define MAX_NAME 17

enum TAC_TYPE_ENUM{
	TAC_SYMBOL,
	TAC_MOVE,
	TAC_ARRAYMOVE,
	TAC_ARRAY_ACCESS,
	TAC_ADD,
	TAC_SUB,
	TAC_MUL,
	TAC_DIV,
	TAC_INV,
	TAC_AND,
	TAC_OR,
	TAC_GT,
	TAC_LT,
	TAC_EQ,
	TAC_GE,
	TAC_LE,
	TAC_NE,
	TAC_LABEL,
	TAC_BEGINFUN,
	TAC_ENDFUN,
	TAC_IFZ,
	TAC_JUMP,
	TAC_CALL,
	TAC_ARG,
	TAC_RET,
	TAC_PRINT,
	TAC_READ

}typedef TACType;

struct TAC_STRUCT{
	TACType type;
	HashEntry *res;
	HashEntry *op1;
	HashEntry *op2;
	struct TAC_STRUCT *next;
	struct TAC_STRUCT *prev;
}typedef TAC;

TAC *createTAC(TACType type, HashEntry *res, HashEntry *op1, HashEntry *op2);
TAC *joinTAC(TAC *instruction1, TAC *instruction2);
TAC *copyTAC(TAC *tac);
void printTAC(TAC *tac);
HashEntry *createTemp();
HashEntry *createLabel();
TAC *generateCode(AST *node);
TAC *reverseCode(TAC *tac);

#endif