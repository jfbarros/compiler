#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

void hashInit(){
	int i;
	for(i = 0; i < HASH_MAX_SIZE; i++)
		symbolTable[i] = NULL;
}

int hashAddress(char* key){
	int i, address = 1;
	for(i = 0; i < strlen(key); i++)
		address = (address * key[i]) % HASH_MAX_SIZE + 1;
	return address - 1;
}

HashNode* hashInsert(char* key, int type){
	HashNode* node;
	int address = hashAddress(key);

	if( (node = hashFind(key)) != NULL )
		return node;
	node = (HashNode*) malloc(sizeof(HashNode));
	node->key = (char*) malloc(strlen(key));
	strcpy(node->key, key);
	node->type = type;
	node->next = symbolTable[address];
	symbolTable[address] = node;

	return node;
}

HashNode* hashFind(char* key){
	int address = hashAddress(key);
    HashNode * node = NULL;	

	for(node = symbolTable[address]; node != NULL; node = node->next)
		if(strcmp(node->key, key) == 0)
			break;
	return node;
}

void hashPrint(){
	int i;
	HashNode* node;

	for(i = 0; i < HASH_MAX_SIZE; i++){
	    for(node = symbolTable[i]; node != NULL; node = node->next)
		    printf("Symbol Table has %s of type %d on index %d.\n", node->key, node->type, i);
    }
}
