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

typedef union data_value_enum{
	int lit_int;
	float lit_real;
	char lit_char;
	char *lit_string;
}DataValue;

typedef enum data_type_enum{
	TYPE_BYTE,
	TYPE_SHORT,
	TYPE_LONG,
	TYPE_FLOAT,
	TYPE_DOUBLE
}DataType;

typedef enum data_nature_enum{
	SCALAR,
	ARRAY,
	FUNCTION
}DataNature;

typedef struct symbol_data{
	char *name;
	DataValue value;
	DataType type;
	DataNature nature;
	DataType return_type;
	AST *ast;
}SymbolData;

typedef struct hash_table_entry {
	char *key;
	SymbolData *value;
	struct hash_table_entry *next;
}HashEntry;

typedef struct HashTable_s {
	int size;
	struct hash_table_entry **table;
}HashTable;

HashTable *createHashTable(int size);

int ht_hash( HashTable *hashtable, char *key );

HashEntry *createPair(char *key, SymbolData *value);

HashEntry *setHashValue(HashTable *hashtable, char *key, SymbolData *value);

void printHash(HashTable *hashtable);
	
SymbolData *getHashValue(HashTable *hashtable, char *key);

#endif