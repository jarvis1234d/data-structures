




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	char name[20];
	struct node* next;
}node;

node *hashtable[26];

int hash(char *name);
void h_insert(char *name, int index);
void h_free(node *table[], int length);
void printhashtable(node *table[], int length);
bool h_search(char *word);
bool l_search(char *word, int index);

int hash_length = 26;

int main(){

	for(int i = 0; i < hash_length; i++){
		hashtable[i] = NULL; 

		 /*calloc(1, sizeof(node));*/
		// hashtable[i]->name = NULL;
		// hashtable[i]->next = NULL;
	}
	// hashtable = calloc(25, sizeof(node));
	char *charachter = malloc(20*sizeof(char));
	
	while(1){
		printf("Enter the name of Charachter to add to hashtable: ");
		scanf("%s", charachter);
		if(strcmp(charachter,"`") != 0){
			int hash_l = hash(charachter);
			h_insert(charachter, hash_l);
		}else{
			break;
		}
	}
	bool result = h_search("hagrid");
	printf("%i\n", result);
	// printhashtable(hashtable, hash_length);
	h_free(hashtable, hash_length);
	free(charachter);
	return 0;
}

int hash(char *name){
	int sum = (int) name[0] - 97;
	return sum;
}

void h_insert(char *name, int index){

	if(hashtable[index] == NULL){
		node *tmp = malloc(sizeof(node));
		// tmp->name = name;
		printf("%s inserted at array\n", name);
		strcpy(tmp->name, name);
		tmp->next = NULL;
		// tmp->word = NULL; 
		hashtable[index] = tmp;
	}else{

		node *tmp = malloc(sizeof(node));
		printf("%s inserted at list->next\n", name);
		// tmp->name = (char *) malloc(20);
		strcpy(tmp->name, name);
		// sscanf(tmp->name, "%s", name);
		// tmp->name = name;
		tmp->next = hashtable[index];
		hashtable[index] = tmp;
	}
}

bool h_search(char *word){
	int index = hash(word);

	return l_search(word, index);
}

bool l_search(char *word, int index){

	node *cursor = hashtable[index];
	while(cursor != NULL){
		if(strcmp(cursor->name, word) == 0){
			return true;
		}
		cursor = cursor->next;
	}
	return false;
}

void printhashtable(node *table[], int length){
	// int length = (int) sizeof(table)/sizeof(void *);

	for(int i = 0; i < length; i++){
		node *recv = table[i];
		printf("hashtable[%d]: ", i);
		while(recv != NULL){
			printf("%s-->",recv->name);
			recv = recv->next;
		}
		printf("NULL\n");
	}
}

void hl_free(node *list){
	if(list == NULL){
		return;
	}
	hl_free(list->next);
	free(list);
}

void h_free(node *table[], int length){
	for(int i = 0; i < length; i++){
		hl_free(table[i]);
	}
}