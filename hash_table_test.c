#define SIZE 100

typedef struct{

    char* kyeIdentifier;
    int type;
    char* value;

}HASH_NODE;

typedef struct{

    HASH_NODE table[SIZE];

}HASH_TABLE;

int insert(HASH_TABLE *table, char* key, int type) {

    int i;
    for(i=0; i<SIZE; i++) {

        if(table->table[i].kyeIdentifier==NULL) {

            printf("TYPE: %d\n", type);
            table->table[i].kyeIdentifier = (char*)malloc(sizeof(key));
            strcpy(table->table[i].kyeIdentifier, key);
            table->table[i].type = type;
            printf("returning insert index: %d\n", i);
            return i;
        }
    }
    return -1;
}

int get(HASH_TABLE *table, char* key) {

    int i;
    for(i=0; i<SIZE; i++) {

        if(table->table[i].kyeIdentifier!=NULL) {

            if(strcmp(table->table[i].kyeIdentifier, key)) {

                return table->table[i].type;

            }
        }
    }
    return -1;
}

int print(HASH_TABLE *table) {

    printf("HASH TABLE: \n");
    int i;
    for(i=0; i<SIZE; i++) {

        if(table->table[i].kyeIdentifier!=NULL) {

            printf("KEY: %s\tVALUE: %d\n", table->table[i].kyeIdentifier, table->table[i].type);
        }
    }
    return -1;
}
