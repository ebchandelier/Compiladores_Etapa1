#ifndef HASH_HEADER
#define HASH_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "semantic.h"

#define SYMBOL_LIT_REAL			2
#define SYMBOL_LIT_CHAR			3
#define SYMBOL_LIT_STRING		4
#define SYMBOL_ARR_IDENTIFIER 	5
#define SYMBOL_FUN_IDENTIFIER	6
#define SYMBOL_VAR_IDENTIFIER	7


HashTable *createHashTable(int size);

int ht_hash( HashTable *hashtable, char *key );

HashEntry *createPair(char *key, int value);

HashEntry *setHashValue(HashTable *hashtable, char *key, int value);

HashEntry *setHashData(HashTable *hashtable, char *key, SymbolData *value);

void printHash(HashTable *hashtable);

SymbolData *getHashValue(HashTable *hashtable, char *key);

#endif