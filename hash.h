#define HASH_MAX_SIZE 997

typedef struct hash_node{
	char *key;	
	int type;
	struct hash_node *next;
} HashNode;

HashNode* symbolTable[HASH_MAX_SIZE];

void hashInit();
int hashAddress(char* key);
HashNode* hashInsert(char* key, int type);
HashNode* hashFind(char* key);
void hashPrint();
