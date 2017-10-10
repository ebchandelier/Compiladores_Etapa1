#define SIZE 5000

typedef struct{

    char* keyIdentifier;
    int type;
    char* value;

}HASH_NODE;

typedef struct{

    HASH_NODE table[SIZE];

}HASH_TABLE;

void removeSpecialChars(char *text, int len){
    int it;
    for (it = 0; it < len; it++){
        if (text[it] == '\\')
            if (text[it+1] == 'n'){
                text[it] = ' ';
                text[it+1] = '\n';
            }

    }
}

int get(HASH_TABLE *table, char* key) {

    int i;
    for(i=0; i<SIZE; i++) {
        if(table->table[i].keyIdentifier!=NULL) {
            if(strcmp(table->table[i].keyIdentifier, key) == 0) {
                return table->table[i].type;
            }
        }
    }
    return -1;
}

int insert(HASH_TABLE *table, char* key, int type) {

    int i;
    int found = get(table, key);
    if (found > 0){
        for(i = 0; i < SIZE; i++) {
            if (strcmp(key, table->table[i].keyIdentifier) == 0){
                table->table[i].type = type;
                return i;
            }
        }
        printf("error, get() found a key but insert could not find it");
        return -1;
    }
    for(i=0; i<SIZE; i++) {
        if(table->table[i].keyIdentifier==NULL) {
            table->table[i].keyIdentifier = strdup(key);
            table->table[i].type = type;
            return i;
        }
    }
    return -1;
}

int print(HASH_TABLE *table) {

    printf("HASH TABLE: \n");
    int i;
    for(i=0; i<SIZE; i++) {
        if(table->table[i].keyIdentifier!=NULL) {
            printf("KEY: %s\tVALUE: %d\n", table->table[i].keyIdentifier, table->table[i].type);
        }
    }
    return -1;
}
