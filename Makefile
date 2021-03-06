# - Compiladores B - Marcelo Johann - 2009/2 - Etapa 1
 #
 ## Makefile for single compiler call
 # All source files must be included from code embedded in scanner.l
 # # In our case, you probably need #include "hash.c" at the beginning
 # # and #include "main.c" in the last part of the scanner.l
 # #
 #
 #


etapa1:etapa2 lex.yy.c
	gcc -o etapa4 ast.c lex.yy.c y.tab.c semantic.c

etapa2: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm lex.yy.c etapa4 y.tab.c y.tab.h
