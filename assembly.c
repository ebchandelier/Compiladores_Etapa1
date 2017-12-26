#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash.h"
#include "y.tab.h"
#include "assembly.h"

FILE* file;

void generateAssembly_begin_fun(HashEntry* node)
{
	fprintf(file,"\t.globl	%s\n", node->key);
	fprintf(file,"\t.type	%s, @function\n", node->key);

	fprintf(file,"\t%s:\n", node->key);
	//fprintf(file,"\t.LFB%d:\n", functions_count);
	fprintf(file,"\t\t.cfi_startproc\n");
	fprintf(file,"\t\tpushq	%%rbp\n");
	fprintf(file,"\t\t.cfi_def_cfa_offset 16\n");
	fprintf(file,"\t\t.cfi_offset 6, -16\n");
	fprintf(file,"\t\tmovq	%%rsp, %%rbp\n");
	fprintf(file,"\t\t.cfi_def_cfa_register 6\n\n");
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


void generateAssemblyOf(TAC* tac)
{

	//fprintf(stderr, "%d\n", tac->tac_type);
	switch(tac->type)
	{
		case TAC_SYMBOL: 		break;
		case TAC_MOVE: 			generateAssembly_move(tac->res, tac->op1); break;
		case TAC_ARRAYMOVE: 	generateAssembly_arrayMove(tac->res, tac->op1); break;
		case TAC_BEGINFUN:		generateAssembly_begin_fun(tac->res); break;
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