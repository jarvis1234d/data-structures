#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int number;
	struct node *next;
}node;

node* create_node(int num);
node* insert_node(node *list, node *tmp);
void lfree(node *list);

node *list = NULL;
int main(){

	while(1){
		int number;
		printf("Enter number to insert in the linked list: ");
		scanf("%i", &number);
		if(list == NULL){
			list = create_node(number);
		}
		else{

			if(number == -1) break;
			list = insert_node(list, create_node(number));
		}

	}
	node *iterator = list;
	while(iterator != NULL){
		printf("%d\n", iterator->number);
		iterator = iterator->next;
	}
	lfree(list);
	return 0;
}

node * create_node(int num){
	node* tmp = malloc(sizeof(node));
	tmp->number = num;
	tmp->next = NULL;
}

node* insert_node(node *list, node *tmp){
	tmp->next = list;
	return tmp; 
}


void lfree(node *list){

	if(list == NULL){
		return;
	}
	lfree(list->next);
	// printf("freeing %i\n", list->number);
	free(list);
}