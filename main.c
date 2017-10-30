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
	
	//yyin = fopen(argv[1], "r");
	yyin = fopen("a.txt", "r");
	
	yyparse();
	
	fclose(yyin);

	//astPrint(astRoot,0);

	//char* outuputFile = toOutput(astRoot);

	//WriteToFile(argv[2],outuputFile);

	return 0;
}
