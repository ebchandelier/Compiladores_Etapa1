#include "tac.h"

HashTable *hash;

/*
enum TAC_TYPE_ENUM{
	TAC_SYMBOL,
	TAC_MOVE,
	TAC_ARRAYMOVE,
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
*/

TAC *createTAC(TACType type, HashEntry *res, HashEntry *op1, HashEntry *op2){
	TAC *newTAC;
	newTAC = malloc(sizeof(TAC));
	newTAC->type = type;
	newTAC->res = res;
	newTAC->op1 = op1;
	newTAC->op2 = op2;
	newTAC->next = NULL;
	newTAC->prev = NULL;

	return newTAC;
}

TAC *joinTAC(TAC *instruction1, TAC *instruction2){
	if (!instruction1)
		return instruction2;

	if (!instruction2)
		return instruction1;

	TAC *aux = instruction2;

	while (aux->prev != NULL){
		aux = aux->prev;
	}

	aux->prev = instruction1;
	instruction1->next = aux;

	return instruction2;
}

TAC *copyTAC(TAC *tac){
	//TO-DO
}

void printTAC(TAC *tac){
	TAC *aux;

	const char* tacNames[] = {
	"TAC_PARAM",
	"TAC_SYMBOL",
	"TAC_MOVE",
	"TAC_ARRAYMOVE",
	"TAC_ARRAY_ACCESS",
	"TAC_ADD",
	"TAC_SUB",
	"TAC_MUL",
	"TAC_DIV",
	"TAC_INV",
	"TAC_AND",
	"TAC_OR",
	"TAC_GT",
	"TAC_LT",
	"TAC_EQ",
	"TAC_GE",
	"TAC_LE",
	"TAC_NE",
	"TAC_LABEL",
	"TAC_BEGINFUN",
	"TAC_ENDFUN",
	"TAC_IFZ",
	"TAC_JUMP",
	"TAC_CALL",
	"TAC_ARG",
	"TAC_RET",
	"TAC_PRINT",
	"TAC_READ"
	};

	for (aux = tac; aux != NULL; aux = aux->next){
		fprintf(stderr, "%s\n", tacNames[aux->type]);
	}
}

void initTAC(HashTable *ht){
	hash = ht;
}


HashEntry *createTemp(){
	static int tempCounter = 0;

	char name[MAX_NAME];
	bzero(name, MAX_NAME);

	sprintf(name, "__temp_%d", tempCounter);
	tempCounter++;
	//FIX
	HashEntry *newEntry = setHashValue(hash, name, AST_SYMBOL);

	return newEntry;
}

HashEntry *createLabel(){
	static int labelCounter = 0;

	char name[MAX_NAME];
	bzero(name, MAX_NAME);

	sprintf(name, "__label_%d", labelCounter);
	labelCounter++;
	//FIX
	HashEntry *newEntry = setHashValue(hash, name, AST_SYMBOL);
	
	return newEntry;
}

HashEntry *createStartLabel(HashEntry *fun){
	int len = strlen(fun->key)+100;
	char *label = malloc(len);
	bzero(label, len);

	sprintf(label, "___%s__begin__", fun->key);

	HashEntry *newEntry = setHashValue(hash, label, AST_SYMBOL);

	return newEntry;
}

HashEntry *createEndLabel(HashEntry *fun){
	int len = strlen(fun->key)+100;
	char *label = malloc(len);
	bzero(label, len);

	sprintf(label, "___%s__end__", fun->key);

	HashEntry *newEntry = setHashValue(hash, label, AST_SYMBOL);

	return newEntry;
}

TAC *createArithmeticTAC(TACType type, TAC **newTAC){
	HashEntry *temp1 = newTAC[0]->res;
	HashEntry *temp2 = newTAC[1]->res;

	return joinTAC(joinTAC(newTAC[0], newTAC[1]), createTAC(type, createLabel(), temp1, temp2));
}

TAC *createCallTAC(TAC *id, TAC *arg){

	return joinTAC(joinTAC(arg, id), createTAC(TAC_CALL, createLabel(), id->res, NULL));
}

TAC *createPrintTAC(TAC *newTAC){
	return joinTAC(newTAC, createTAC(TAC_PRINT, NULL, NULL, NULL));
}

TAC *createRetTAC(TAC *newTAC){
	return joinTAC(createTAC(TAC_RET, NULL, newTAC->res, NULL), newTAC);
}

TAC *createIfTAC(TAC *test, TAC *thenTAC, TAC *elseTAC){
	HashEntry *labelEnd = createLabel();
	HashEntry *labelThen = createLabel();

	return
	joinTAC
		(joinTAC
			(joinTAC
				(joinTAC
					(joinTAC
						(joinTAC

						(test, createTAC(TAC_IFZ, labelThen, test->res, NULL))
					,elseTAC)
				,createTAC(TAC_JUMP, labelEnd, NULL, NULL))
			,createTAC(TAC_LABEL, labelThen, NULL, NULL))
		,thenTAC)
	,createTAC(TAC_LABEL, labelEnd, NULL, NULL));

	return NULL;
}

/*
START:
TEST
IF Z GOTO DO
JMP END
DO:
//CMDS
JMP START
END:
*/

TAC *createWhileTAC(TAC *test, TAC *doWhile){
	HashEntry *labelEnd = createLabel();
	HashEntry *labelDo = createLabel();
	HashEntry *labelStart = createLabel();

	return
	joinTAC(
		joinTAC(
			joinTAC(
				joinTAC(
					joinTAC(
						joinTAC(
							joinTAC(

							createTAC(TAC_LABEL, labelStart, NULL, NULL), test)
						,createTAC(TAC_IFZ, labelDo, test->res, NULL))
					,createTAC(TAC_JUMP, labelEnd, NULL, NULL))
				,createTAC(TAC_LABEL, labelDo, NULL, NULL))
			,doWhile)
		,createTAC(TAC_JUMP, labelStart, NULL, NULL))
	,createTAC(TAC_LABEL, labelEnd, NULL, NULL));

}

TAC *createFunctionTAC(TAC **newTAC){
	return NULL;
	HashEntry *startLabel = createLabel();
	HashEntry *endLabel = createLabel();

	createTAC(TAC_BEGINFUN, startLabel, NULL, NULL);
	createTAC(TAC_LABEL, startLabel, NULL, NULL);
}

TAC *createArgTAC(TAC **newTAC){
	TAC *first = newTAC[0];
	TAC *rest = newTAC[1];

	if (!first)
		return NULL;

	return joinTAC(joinTAC(createTAC(TAC_ARG, first->res, NULL, NULL), first), rest);
}

TAC *createParamTAC(TAC *first, TAC *rest){
	if (!first)
		return NULL;

	return joinTAC(joinTAC(createTAC(TAC_PARAM, first->res, NULL, NULL), first), rest);
}

TAC *createArrayDecTAC(TAC *id, AST *values){
	if (!values)
		return NULL;

	if (values->son[0]){
		if (!values->son[0]->symbol)
			return NULL;

		return joinTAC(createArrayDecTAC(id, values->son[1]), createTAC(TAC_ARRAYMOVE, id->res, values->son[0]->symbol, NULL));
	}else{
		fprintf(stderr, "Valuelist did not have a value\n");
		return NULL;
	}
}

TAC *generateCode(AST *node){
	if (!node)
		return NULL;

	TAC *newTAC[4];

	newTAC[3] = generateCode(node->son[3]);
	newTAC[2] = generateCode(node->son[2]);
	newTAC[1] = generateCode(node->son[1]);
	newTAC[0] = generateCode(node->son[0]);

	TAC *result = NULL;

	switch(node->type){

		case LITERAL:
		case AST_SYMBOL:
			result = createTAC(TAC_SYMBOL, node->symbol, NULL, NULL);
			break;

		case AST_ADD:
			result = createArithmeticTAC(TAC_ADD, newTAC);
			break;

		case AST_MUL:
			result = createArithmeticTAC(TAC_MUL, newTAC);
			break;

		case AST_SUB:
			result = createArithmeticTAC(TAC_SUB, newTAC);
			break;

		case AST_DIV:
			result = createArithmeticTAC(TAC_DIV, newTAC);
			break;

		case AST_CHANGE_SIGN:
			result = createArithmeticTAC(TAC_INV, newTAC);
			break;

		case AND:
			result = createArithmeticTAC(TAC_AND, newTAC);
			break;

		case OR:
			result = createArithmeticTAC(TAC_OR, newTAC);
			break;

		case AST_GREA:
			result = createArithmeticTAC(TAC_GT, newTAC);
			break;

		case AST_LESS:
			result = createArithmeticTAC(TAC_LT, newTAC);
			break;

		case EQUAL:
			result = createArithmeticTAC(TAC_EQ, newTAC);
			break;

		case GE:
			result = createArithmeticTAC(TAC_GE, newTAC);
			break;

		case LE:
			result = createArithmeticTAC(TAC_LE, newTAC);
			break;
		
		case NOT_EQUAL:
			result = createArithmeticTAC(TAC_NE, newTAC);
			break;

		case ASSIGNMENT_LIST:
			result = createArrayDecTAC(newTAC[0], node->son[3]);
			break;

		case ASSIGNMENT:
			result = createTAC(TAC_MOVE, newTAC[0]->res, newTAC[2]->res, NULL);

		case AST_SYMBOL_ASSIGNMENT:
			result = joinTAC(newTAC[0], createTAC(TAC_MOVE, node->symbol, newTAC[0]->res, NULL));
			break;

		case ASSIGNMENT_LIST_INDEX:
			//DOING
			//ASSIGN TO ARRAY
			result = joinTAC(newTAC[1], joinTAC(newTAC[0], createTAC(TAC_ARRAYMOVE, node->symbol, newTAC[0]->res, newTAC[1]->res)));
			break;

		case AST_SYMBOL_ARRAY:
			//ACCESS ARRAY
			result = createTAC(TAC_ARRAY_ACCESS, NULL, node->symbol, newTAC[0]->res);
			fprintf(stderr, "worked\n");
			break;

		case READ_CMD:
			result = createTAC(TAC_READ, newTAC[0]->res, NULL, NULL);
			break;

		case PRINT_CMD:
			result = createPrintTAC(newTAC[0]); 
			break;

		case AST_FUN_CAL:
			result = createCallTAC(newTAC[0], newTAC[1]);
			break;

		case RETURN_CMD:
			result = createRetTAC(newTAC[0]);
			break;

		case AST_PARAM_LIST:
			result = createParamTAC(newTAC[0], newTAC[1]);
			break;

		case IF_THEN_ELSE_CMD:
			result = createIfTAC(newTAC[0], newTAC[1], newTAC[2]);
			break;

		case WHILE_CMD:
			result = createWhileTAC(newTAC[0], newTAC[1]);
			break;

		case FUNCTION_HEADER:
			result = createFunctionTAC(newTAC);
			break;

		case ARGUMENT:
			result = createArgTAC(newTAC);
			break;

		case TOKEN:
		//?????????
//-----------------------------
		case VALUE_LIST:
		case ELSE_CMD:
		case ARG_LIST:
		case AST_AT_ARRAY:
		case PRINT_CONTENT:
		case FUNCTION_BODY:
		case PARENTESES:
		case AST_CMD_LIST:
		case AST_CMD_BLOCK:
		case FUNCTION:
		case AST_LIST:
		case AST_BYTE:
		case AST_SHORT:
		case AST_DOUBLE:
		case AST_LONG:
		case AST_FLOAT:
		default:
			result = joinTAC(joinTAC(joinTAC(newTAC[0], newTAC[1]), newTAC[2]), newTAC[3]);
			break;
	}

	return result;
}

TAC *reverseCode(TAC *tac){
	if (!tac)
		return NULL;

	TAC *aux = tac;

	while (aux->prev)
		aux = aux->prev;


	return aux;
}