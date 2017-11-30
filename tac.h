#ifndef TAC_HEADER
#define TAC_HEADER

#include "semantic.h"

enum TAC_TYPE_ENUM{
	TAC_SYMBOL,
	TAC_MOVE,
	TAC_ADD,
	TAC_MUL,
	TAC_DIV,
	TAC_AND,
	TAC_OR,
	TAC_LABEL,
	TAC_BEGINFUN,
	TAC_ENDFUN,
	TAC_JZ,
	TAC_JN,
	TAC_JUMP,
	TAC_CALL,
	TAC_ARG,
	TAC_RET,
	TAC_PRINT,
	TAC_READ
}typedef TacType;

struct TAC_STRUCT{
	TacType type;
	HashEntry *res;
	HashEntry *op1;
	HashEntry *op2;
	struct TAC_STRUCT *next;
	struct TAC_STRUCT *prev;
}typedef TAC;

TAC *createTAC(AST *node);
void printTAC(TAC *tac);
TAC *joinTAC(TAC *instruction1, TAC *instruction2);
HashEntry *createTemp();
HashEntry *createLabel();
TAC *generateCode(AST *node);
TAC *reverseCode(AST *first);

#endif