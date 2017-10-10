extern FILE *yyin;

int main(void) {

	initMe();

	yyin = fopen("a.txt", "r");
	//while(isRunning()==1){
	//	printf("is running: %d\n", isRunning());
		//debud
	//	printf("get %d\n", yylex());
		//printf("number of lines: %d\n", getLineNumber());
		//printf("::::: %d\n", ht_get( hashtable, "eduardo" ));
//	}
    yyparse();
	fclose(yyin);


	printf("here\n");
	return 0;
}
