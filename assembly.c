#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash.h"
#include "y.tab.h"
#include "assembly.h"

FILE* file;

int functions_count = 0;

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
		case TAC_ARRAY_ACCESS: 	generateAssembly_arrayAccess(tac->res, tac->op2, NULL); break;
		case TAC_LT:			generateAssembly_less(tac->res, tac->op1, tac->op2); break;
		case TAC_LE: 			generateAssembly_less_equal(tac->res, tac->op1, tac->op2); break;
		case TAC_GT: 			generateAssembly_greater(tac->res, tac->op1, tac->op2); break;
		case TAC_GE: 			generateAssembly_greater_equal(tac->res, tac->op1, tac->op2); break;
		case TAC_EQ: 			generateAssembly_equal(tac->res, tac->op1, tac->op2); break;
		case TAC_NE: 			generateAssembly_not_equal(tac->res, tac->op1, tac->op2); break;
		//case TAC_AND: 			generateAssembly_and(tac->res, tac->op1, tac->op2); break;
		//case TAC_OR: 			generateAssembly_or(tac->res, tac->op1, tac->op2); break;
		default:
			fprintf(stderr, "FAZER O %d\n", tac->type);
			break;
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
		generateAssemblyOf(aux);
	}
}