#include "hash.h"

HashTable *createHashTable(int size) {

	HashTable *hashtable = NULL;
	int i;

	if( size < 1 ) return NULL;

	if((hashtable = malloc(sizeof(HashTable))) == NULL) {
		return NULL;
	}

	if((hashtable->table = malloc(sizeof(HashEntry *)*size)) == NULL) {
		return NULL;
	}
	for( i = 0; i < size; i++ ) {
		hashtable->table[i] = NULL;
	}

	hashtable->size = size;

	return hashtable;	
}

/*Hash a string for a particular hash table.*/
int ht_hash( HashTable *hashtable, char *key ) {

	unsigned long int hashval;
	int i = 0;

	/* Convert our string to an integer */
	while( hashval < ULONG_MAX && i < strlen( key ) ) {
		hashval = hashval << 8;
		hashval += key[ i ];
		i++;
	}

	return hashval % hashtable->size;
}

/* Create a key-value pair. */
HashEntry *createPair(char *key, int value) {
	HashEntry *newpair;

	if( ( newpair = malloc( sizeof( HashEntry ) ) ) == NULL ) {
		return NULL;
	}

	if( ( newpair->key = strdup( key ) ) == NULL ) {
		return NULL;
	}

	newpair->value = value;

	newpair->next = NULL;

	return newpair;
}

/* Insert a key-value pair into a hash table. */
HashEntry *setHashValue(HashTable *hashtable, char *key, int value) {
	int bin = 0;
	HashEntry *newpair = NULL;
	HashEntry *next = NULL;
	HashEntry *last = NULL;

	if (key[0] == 'P'){
		printf("hehere\n");
	}

	bin = ht_hash( hashtable, key );

	next = hashtable->table[ bin ];

	while( next != NULL && next->key != NULL && strcmp( key, next->key ) > 0 ) {
		last = next;
		next = next->next;
	}

	/* There's already a pair.  Let's replace that string. */
	if( next != NULL && next->key != NULL && strcmp( key, next->key ) == 0 ) {

		next->value = value;
		return next;

	/* Nope, could't find it.  Time to grow a pair. */
	} else {
		newpair = createPair(key, value);

		/* We're at the start of the linked list in this bin. */
		if( next == hashtable->table[ bin ] ) {
			newpair->next = next;
			hashtable->table[ bin ] = newpair;
	
		/* We're at the end of the linked list in this bin. */
		} else if ( next == NULL ) {
			last->next = newpair;
	
		/* We're in the middle of the list. */
		} else  {
			newpair->next = next;
			last->next = newpair;
		}
		return newpair;
	}
}

void printHash(HashTable *hashtable){
	HashEntry *current = NULL;
	int i = 0;
	int hashSize = hashtable->size;
	for (i = 0; i < hashSize; i++){
		current = hashtable->table[i];
		if (current == NULL)
			continue;

		printf("[%d] key = %s     value = %d\n", i, current->key, current->value);
	}
}

/* Retrieve a key-value pair from a hash table. */
int getHashValue(HashTable *hashtable, char *key) {
	int bin = 0;
	HashEntry *pair;

	bin = ht_hash( hashtable, key );

	/* Step through the bin, looking for our value. */
	pair = hashtable->table[ bin ];
	while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) {
		printf("%s = %d\n", key, pair->value);		
		pair = pair->next;
	}

	/* Did we actually find anything? */
	if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) {
		return -1;

	} else {
		return pair->value;
	}
	
}

/*
int main( int argc, char **argv ) {

	HashTable *hashtable = createHashTable( 65536 );

	ht_set( hashtable, "key1", "inky" );
	ht_set( hashtable, "key2", "pinky" );
	ht_set( hashtable, "key3", "blinky" );
	setHashValue( hashtable, "key4", "floyd" );

	printf( "%s\n", ht_get( hashtable, "key1" ) );
	printf( "%s\n", ht_get( hashtable, "key2" ) );
	printf( "%s\n", ht_get( hashtable, "key3" ) );
	printf( "%s\n", getHashValue( hashtable, "key4" ) );

	return 0;
}*/
