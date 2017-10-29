extern FILE *yyin;

int main(void) {
	fprintf(stderr, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
	initMe();
	fprintf(stderr, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
	yyin = fopen("a.txt", "r");
	fprintf(stderr, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
	//while(isRunning()==1){
	//	printf("is running: %d\n", isRunning());
		//debud
	//	printf("get %d\n", yylex());
		//printf("number of lines: %d\n", getLineNumber());
		//printf("::::: %d\n", ht_get( hashtable, "eduardo" ));
//	}
	yyparse();
	fprintf(stderr, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
	fclose(yyin);


	fprintf(stderr, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");

	astPrint(astRoot,0);

	return 0;
}
