#ifndef HASH_HEADER
#define HASH_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define SYMBOL_LIT_INTEGER		1
#define SYMBOL_LIT_REAL			2
#define SYMBOL_LIT_CHAR			3
#define SYMBOL_LIT_STRING		4
#define SYMBOL_ARR_IDENTIFIER 	5
#define SYMBOL_FUN_IDENTIFIER	6
#define SYMBOL_VAR_IDENTIFIER	7

#include "ast.h"

struct hash_table_entry {
    char *key;
    int value;
    AST *declarationNode;
	struct hash_table_entry *next;
};

typedef struct hash_table_entry HashEntry;

struct HashTable_s {
    int size;
	struct hash_table_entry **table;
};

typedef struct HashTable_s HashTable;


HashTable *createHashTable(int size) ;

int ht_hash( HashTable *hashtable, char *key ) ;

HashEntry *createPair(char *key, int value) ;

HashEntry *setHashValue(HashTable *hashtable, char *key, int value);

void printHash(HashTable *hashtable);
	
int getHashValue(HashTable *hashtable, char *key);

#endif