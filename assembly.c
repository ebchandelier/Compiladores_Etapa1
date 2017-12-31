#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash.h"
#include "y.tab.h"
#include "assembly.h"

#define sMOVE "MOVE"
#define sARRAYMOVE "ARRAY MOVE"
#define sBEGINFUN "BEGINFUN"
#define sENDFUN "ENDFUN"
#define sLABEL "LABEL"
#define sARG "ARG"
#define sARRAYACCESS "ARRAY ACCESS"
#define sLT "LESS THAN"
#define sLE "LESSER OR EQUAL"
#define sGT "GREATER THAN"
#define sGE "GREATER OR EQUAL"
#define sEQ "EQUAL"
#define sNE "NOT EQUAL"
#define sAND "AND"
#define sOR "OR"
#define sSYMBOL "SYMBOL"
#define sINVALID "NOT VALID"
#define sPARAM "PARAM"
#define sADD "ADD"
#define sSUB "SUB"
#define sMUL "MUL"
#define sDIV "DIV"
#define sINV "INV"
#define sIFZ "IFZ"
#define sJUMP "JUMP"
#define sCALL "CALL"
#define sRET "RETURN"
#define sPRINT "PRINT"
#define sREAD "READ"

FILE* file;

int functions_count = 0;

char* type_to_string(int type){
	switch(type){
		case TAC_SYMBOL: 		return sSYMBOL;
		case TAC_MOVE: 			return sMOVE;
		case TAC_ARRAYMOVE: 	return sARRAYMOVE;
		case TAC_BEGINFUN:		return sBEGINFUN;
		case TAC_LABEL:			return sLABEL;
		case TAC_ARG:			return sARG;
		case TAC_ENDFUN:		return sENDFUN;
		case TAC_ARRAY_ACCESS: 	return sARRAYACCESS;
		case TAC_LT:			return sLT;
		case TAC_LE: 			return sLE;
		case TAC_GT: 			return sGT;
		case TAC_GE: 			return sGE;
		case TAC_EQ: 			return sEQ;
		case TAC_NE: 			return sNE;
		case TAC_AND: 			return sAND;
		case TAC_OR: 			return sOR;
		case TAC_PARAM: 		return sPARAM;
		case TAC_ADD: 			return sADD;
		case TAC_SUB: 			return sSUB;
		case TAC_MUL: 			return sMUL;
		case TAC_DIV: 			return sDIV;
		case TAC_INV:			return sINV;
		case TAC_IFZ:			return sIFZ;
		case TAC_JUMP:			return sJUMP;
		case TAC_CALL:			return sCALL;
		case TAC_RET:			return sRET;
		case TAC_PRINT:			return sPRINT;
		case TAC_READ:			return sREAD;
		default:				return sINVALID;
	}
		
}

void generateAssembly_less(HashEntry* res, HashEntry* source1, HashEntry* source2)
{
	char* resString = res->key;//lvalue(res);
	char* source1String = source1->key;//rvalue(source1);
	char* source2String = source2->key;//rvalue(source2);

	fprintf(file,"\t\t# STARTING LESS\n");
	fprintf(file,"\t\t\tmovl %s, %%edx\n", source1String);
	fprintf(file,"\t\t\tmovl %s, %%eax\n", source2String);
	fprintf(file,"\t\t\tcmpl %%eax, %%edx\n");
	fprintf(file,"\t\t\tsetl %%al\n");
	fprintf(file,"\t\t\tmovzbl %%al, %%eax\n");
	fprintf(file,"\t\t\tmovl %%eax, %s\n", resString);
	fprintf(file,"\t\t# ENDING LESS\n\n");

	// free(resString);
	// free(source1String);
	// free(source2String);
}

void generateAssembly_less_equal(HashEntry* res, HashEntry* source1, HashEntry* source2)
{
	char* resString = res->key;//lvalue(res);
	char* source1String = source1->key;//rvalue(source1);
	char* source2String = source2->key;//rvalue(source2);

	fprintf(file,"\t\t# STARTING LESS EQUAL\n");
	fprintf(file,"\t\t\tmovl %s, %%edx\n", source1String);
	fprintf(file,"\t\t\tmovl %s, %%eax\n", source2String);
	fprintf(file,"\t\t\tcmpl %%eax, %%edx\n");
	fprintf(file,"\t\t\tsetle %%al\n");
	fprintf(file,"\t\t\tmovzbl %%al, %%eax\n");
	fprintf(file,"\t\t\tmovl %%eax, %s\n", resString);
	fprintf(file,"\t\t# ENDING LESS EQUAL\n\n");

	// free(resString);
	// free(source1String);
	// free(source2String);
}

void generateAssembly_greater(HashEntry* res, HashEntry* source1, HashEntry* source2)
{
	char* resString = res->key;//lvalue(res);
	char* source1String = source1->key;//rvalue(source1);
	char* source2String = source2->key;//rvalue(source2);

	fprintf(file,"\t\t# STARTING GREATER\n");
	fprintf(file,"\t\t\tmovl %s, %%edx\n", source1String);
	fprintf(file,"\t\t\tmovl %s, %%eax\n", source2String);
	fprintf(file,"\t\t\tcmpl %%eax, %%edx\n");
	fprintf(file,"\t\t\tsetg %%al\n");
	fprintf(file,"\t\t\tmovzbl %%al, %%eax\n");
	fprintf(file,"\t\t\tmovl %%eax, %s\n", resString);
	fprintf(file,"\t\t# ENDING GREATER\n\n");

	// free(resString);
	// free(source1String);
	// free(source2String);
}

void generateAssembly_greater_equal(HashEntry* res, HashEntry* source1, HashEntry* source2)
{
	char* resString = res->key;//lvalue(res);
	char* source1String = source1->key;//rvalue(source1);
	char* source2String = source2->key;//rvalue(source2);

	fprintf(file,"\t\t# STARTING GREATER EQUAL\n");
	fprintf(file,"\t\t\tmovl %s, %%edx\n", source1String);
	fprintf(file,"\t\t\tmovl %s, %%eax\n", source2String);
	fprintf(file,"\t\t\tcmpl %%eax, %%edx\n");
	fprintf(file,"\t\t\tsetge %%al\n");
	fprintf(file,"\t\t\tmovzbl %%al, %%eax\n");
	fprintf(file,"\t\t\tmovl %%eax, %s\n", resString);
	fprintf(file,"\t\t# ENDING GREATER EQUAL\n\n");

	// free(resString);
	// free(source1String);
	// free(source2String);
}

void generateAssembly_equal(HashEntry* res, HashEntry* source1, HashEntry* source2)
{
	char* resString = res->key;//lvalue(res);
	char* source1String = source1->key;//rvalue(source1);
	char* source2String = source2->key;//rvalue(source2);

	fprintf(file,"\t\t# STARTING EQUAL\n");
	fprintf(file,"\t\t\tmovl %s, %%edx\n", source1String);
	fprintf(file,"\t\t\tmovl %s, %%eax\n", source2String);
	fprintf(file,"\t\t\tcmpl %%eax, %%edx\n");
	fprintf(file,"\t\t\tsete %%al\n");
	fprintf(file,"\t\t\tmovzbl %%al, %%eax\n");
	fprintf(file,"\t\t\tmovl %%eax, %s\n", resString);
	fprintf(file,"\t\t# ENDING EQUAL\n\n");

	// free(resString);
	// free(source1String);
	// free(source2String);
}

void generateAssembly_not_equal(HashEntry* res, HashEntry* source1, HashEntry* source2)
{
	char* resString = res->key;//lvalue(res);
	char* source1String = source1->key;//rvalue(source1);
	char* source2String = source2->key;//rvalue(source2);

	fprintf(file,"\t\t# STARTING NOT EQUAL\n");
	fprintf(file,"\t\t\tmovl %s, %%edx\n", source1String);
	fprintf(file,"\t\t\tmovl %s, %%eax\n", source2String);
	fprintf(file,"\t\t\tcmpl %%eax, %%edx\n");
	fprintf(file,"\t\t\tsetne %%al\n");
	fprintf(file,"\t\t\tmovzbl %%al, %%eax\n");
	fprintf(file,"\t\t\tmovl %%eax, %s\n", resString);
	fprintf(file,"\t\t# ENDING NOT EQUAL\n\n");

	// free(resString);
	// free(source1String);
	// free(source2String);
}

void generateAssembly_and(HashEntry* res, HashEntry* source1, HashEntry* source2)
{
	char* resString = res->key;//lvalue(res);
	char* source1String = source1->key;// rvalue(source1);
	char* source2String = source2->key;//rvalue(source2);

	fprintf(file,"\t\t# STARTING AND\n");
	fprintf(file,"\t\t\tmovl %s, %%edx\n", source1String);
	fprintf(file,"\t\t\tmovl %s, %%eax\n", source2String);
	fprintf(file,"\t\t\tandl %%edx, %%eax\n");
	fprintf(file,"\t\t\tmovl %%eax, %s\n", resString);
	fprintf(file,"\t\t# ENDING AND\n\n");

	// free(resString);
	// free(source1String);
	// free(source2String);
}

void generateAssembly_or(HashEntry* res, HashEntry* source1, HashEntry* source2)
{
	char* resString = res->key;// lvalue(res);
	char* source1String = source1->key; // rvalue(source1);
	char* source2String = source2->key; //  rvalue(source2);

	fprintf(file,"\t\t# STARTING OR\n");
	fprintf(file,"\t\t\tmovl %s, %%edx\n", source1String);
	fprintf(file,"\t\t\tmovl %s, %%eax\n", source2String);
	fprintf(file,"\t\t\torl %%edx, %%eax\n");
	fprintf(file,"\t\t\tmovl %%eax, %s\n", resString);
	fprintf(file,"\t\t# ENDING OR\n\n");

	// free(resString);
	// free(source1String);
	// free(source2String);
}


void generateAssembly_arrayAccess(HashEntry* res, HashEntry* op1, HashEntry* op2)
{
	char* resString = res->key;//lvalue(res);
	char* source1String = op1->key;// rvalue(op1);

	fprintf(file,"\t\t# STARTING ARRAYACCESS\n");
	fprintf(file,"\t\t\tmovl %s, %%eax\n", source1String);
	fprintf(file,"\t\t\tcltq\n");
	fprintf(file,"\t\t\tmovl %s(,%%rax,4), %%eax\n", op2->key);
	fprintf(file,"\t\t\tmovl %%eax, %s\n", resString);
	fprintf(file,"\t\t# ENDING ARRAYACCESS\n\n");

//	free(resString);
//	free(source1String);
}


void generateAssembly_begin_fun(HashEntry* node)
{
	fprintf(file,"\t.globl	%s\n", node->key);
	fprintf(file,"\t.type	%s, @function\n", node->key);

	fprintf(file,"\t%s:\n", node->key);
	fprintf(file,"\t.LFB%d:\n", functions_count);
	fprintf(file,"\t\t.cfi_startproc\n");
	fprintf(file,"\t\tpushq	%%rbp\n");
	fprintf(file,"\t\t.cfi_def_cfa_offset 16\n");
	fprintf(file,"\t\t.cfi_offset 6, -16\n");
	fprintf(file,"\t\tmovq	%%rsp, %%rbp\n");
	fprintf(file,"\t\t.cfi_def_cfa_register 6\n\n");
}

void generateAssembly_end_fun(HashEntry* node)
{
	fprintf(stderr, "Ending fun\n");
	fprintf(file,"\t.LFE%d:\n", functions_count);
	fprintf(file,"\t\t.size	%s, .-%s\n\n", node->key, node->key);

	functions_count++;
}


void generateAssembly_move(HashEntry* res, HashEntry* source)
{
    char* resString = res->key;//  lvalue(res);
	char* sourceString = source->key; //rvalue(source);

	fprintf(file,"\t\t# STARTING MOVE\n");
	fprintf(file,"\t\t\tmovl %s, %%edx\n", sourceString);
	fprintf(file,"\t\t\tmovl %%edx, %s\n", resString);
	fprintf(file,"\t\t# ENDING MOVE\n\n");

	//free(resString);
	//free(sourceString);
}

void generateAssembly_arrayMove(HashEntry* res, HashEntry* source)
{
	char* resString = res->key;// lvalue(res);
	char* sourceString = source->key;// rvalue(source);

	fprintf(file,"\t\t# STARTING MOVE TO ARRAY\n");
	fprintf(file,"\t\t\tmovl %s, %%edx\n", sourceString);
	fprintf(file,"\t\t\tmovl %%edx, %s\n", resString);
	fprintf(file,"\t\t# ENDING MOVE TO ARRAY\n\n");

	//free(resString);
	//free(sourceString);
}

void generateAssembly_label(HashEntry* res)
{

	fprintf(file,"\t\t\t%s:\n", res->key);
}

void generateAssembly_arg(HashEntry* source)
{
	char* sourceString = source->key;// rvalue(source);

	fprintf(file,"\t\t# STARTING ARG\n");
	fprintf(file,"\t\t\tsubq	$8, %%rsp\n");
	fprintf(file,"\t\t\tmovl %s, %%edx\n", sourceString);
	fprintf(file,"\t\t\tmovl %%edx, (%%rsp)\n"/*, argCount * 8*/);
	fprintf(file,"\t\t# ENDING ARG\n\n");

	//free(sourceString);
}

void generateAssemblyOf(TAC* tac)
{
	int done = 1;
	//fprintf(stderr, "%d\n", tac->tac_type);
	switch(tac->type)
	{
		case TAC_SYMBOL: 		break;
		case TAC_MOVE: 			generateAssembly_move(tac->res, tac->op1); break;
		case TAC_ARRAYMOVE: 	generateAssembly_arrayMove(tac->res, tac->op1); break;
		case TAC_BEGINFUN:		generateAssembly_begin_fun(tac->res); break;
		case TAC_LABEL:			generateAssembly_label(tac->res); break;
		case TAC_ARG:			generateAssembly_arg(tac->res); break;
		case TAC_ENDFUN:		generateAssembly_end_fun(tac->res); break;	
		case TAC_ARRAY_ACCESS: 	generateAssembly_arrayAccess(tac->res, tac->op1, tac->op2); break;
		case TAC_LT:			generateAssembly_less(tac->res, tac->op1, tac->op2); break;
		case TAC_LE: 			generateAssembly_less_equal(tac->res, tac->op1, tac->op2); break;
		case TAC_GT: 			generateAssembly_greater(tac->res, tac->op1, tac->op2); break;
		case TAC_GE: 			generateAssembly_greater_equal(tac->res, tac->op1, tac->op2); break;
		case TAC_EQ: 			generateAssembly_equal(tac->res, tac->op1, tac->op2); break;
		case TAC_NE: 			generateAssembly_not_equal(tac->res, tac->op1, tac->op2); break;
		case TAC_AND: 			generateAssembly_and(tac->res, tac->op1, tac->op2); break;
		case TAC_OR: 			generateAssembly_or(tac->res, tac->op1, tac->op2); break;
		default:
			done = 0;
			fprintf(stderr, "->FAZER O %s\n", type_to_string(tac->type));
			break;
    }
    if (done){
    	fprintf(stderr, "DONE: %s\n", type_to_string(tac->type));
    }
}

void generateAssembly(TAC* tacs, const char* filename)
{

	TAC* aux;
    
    file = fopen(filename, "w");

	//fprintf(file,"# DATA SECTION\n\n");

	//generate_data_section(hashTable);

	fprintf(file,"# CODE SECTION:\n\n");

	for(aux = tacs; aux != NULL; aux = aux->next)
	{
		fprintf(stderr, "fazendo %s\n", type_to_string(aux->type));
		generateAssemblyOf(aux);
	}

	close(file);
}