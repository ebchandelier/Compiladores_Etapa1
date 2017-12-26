#include "tac.h"
#include "assembly.h"

extern FILE *yyin;

int WriteToFile(char* path, char* content)
{
	FILE* file;

	file = fopen(path,"w");

	if(file == NULL) {

		fprintf(stderr,"ERROR: Couldn't open %s\n",path);
		exit(1);
	}

	fprintf(file,"%s",content);

	return 1;
}


int main(int argc, char** argv) {
	
	initMe();
	
	if(!argv[1]) {
		exit(1);
	}

	yyin = fopen(argv[1], "r");
	//yyin = fopen("a.txt", "r");
	
	if(!yyin) {
		exit(2);
	}

	yyparse();
	
	fclose(yyin);

	astPrint(astRoot,0);

	//char* outputFile = toOutput(astRoot);
	//WriteToFile(argv[2],outputFile);

	//ETAPA 4: test semantic
	firstPass(astRoot);
	
	secondPass(astRoot);

	fprintf(stderr, "Finished both passes\n");

	//ETAPA 5
	initTAC(hashtable);
	TAC *last = generateCode(astRoot);
	
	TAC *first = reverseCode(last);

	printTAC(first);

	generateAssembly(first, argv[2]);

	if(getErrCount()>0) {
		fprintf(stderr, "Terminou com erros semantivos\n");
		//exit(4);
	}
	

	exit(0);
}
