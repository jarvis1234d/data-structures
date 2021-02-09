#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int number;
	struct node* left;
	struct node* right;
}node;

bool search(int num, node *tree);

void t_insert(int num, node *tree);
void t_free(node *tree);

node *root = NULL;

int main(){
	int input;
	node *tmp = malloc(sizeof(node));
	tmp->number = 4;
	tmp->left = NULL;
	tmp->right = NULL;
	root = tmp;
	while(true){
		printf("enter a number to insert into the tree: ");
		scanf("%i", &input);
		if(input == -1){
			break;
		}else{
			t_insert(input, root);
		}
	}

	if(search(0, root)){
		printf("found\n");
	}else{
		printf("not fount\n");
	}

	t_free(root);

	return 0;
}

void t_insert(int num, node *tree){

	if(search(num, tree)){
		return;
	}

	node *recv = tree;
	node *tmp = malloc(sizeof(node));
	tmp->number = num;
	tmp->left = NULL;
	tmp->right = NULL;

	while(recv != NULL){

		if(num < recv->number){

			if(recv->left == NULL){
				recv->left = tmp;
			}
			recv = recv->left;

		}else if(num > recv->number){
			
			if(recv->right == NULL){
				recv->right = tmp;
			}
			recv = recv->right;

		}else{
				
			return;
		}

		
	}


}

bool search(int num, node *tree){

	if(tree == NULL){
		return false;
	}

	if(num < tree->number){
		return search(num, tree->left);
	}else if(num > tree->number){
		return search(num, tree->right);
	}else{
		return true;
	}

}

void t_free(node *tree){

	if(tree == NULL){
		return;
	}
	
	if(tree->left != NULL){
		t_free(tree->left);

	}

	if(tree->right != NULL){
		t_free(tree->right);
	}

	
	printf("Freeing %i\n", tree->number);
	free(tree);
	

}