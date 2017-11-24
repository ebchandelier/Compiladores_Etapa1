typedef union data_value_enum DataValue;
typedef enum data_type_enum DataType;
typedef enum data_nature_enum DataNature;
typedef struct symbol_data SymbolData;
typedef struct hash_table_entry HashEntry;
typedef struct HashTable_s HashTable;
typedef struct ast_node AST;

union data_value_enum{
	int lit_int;
	float lit_real;
	char lit_char;
	char *lit_string;
};

enum data_type_enum{
	TYPE_BYTE,
	TYPE_SHORT,
	TYPE_LONG,
	TYPE_FLOAT,
	TYPE_DOUBLE
};

enum data_nature_enum{
	SCALAR,
	ARRAY,
	FUNCTION
};

struct symbol_data{
	char *name;
	DataValue value;
	DataType type;
	DataNature nature;
	DataType return_type;
	AST *ast;
};

struct hash_table_entry {
	char *key;
	SymbolData *value;
	struct hash_table_entry *next;
};

struct HashTable_s {
	int size;
	struct hash_table_entry **table;
};

struct ast_node {
    int type;
    HashEntry *symbol;
    struct ast_node* son[4];
};