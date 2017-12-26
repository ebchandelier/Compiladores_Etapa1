#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash.h"
#include "y.tab.h"
#include "assembly.h"

FILE* file;

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

void generateAssemblyOf(TAC* tac)
{

    fprintf(stderr, "GENERATE ASSEMBL OF\n");
	//fprintf(stderr, "%d\n", tac->tac_type);
	switch(tac->type)
	{
		case TAC_SYMBOL: break;
        //case TAC_MOVE: 			generateAssembly_move(tac->res, tac->op1); break;
    }
}

void generateAssembly(TAC* tacs, const char* filename)
{

    fprintf(stderr, "GENERATE ASSEM\n");
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