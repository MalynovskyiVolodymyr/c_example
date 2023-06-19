#include <stdlib.h>
#include <stdio.h>

struct Node{
	int data;
	struct Node* next;
};

typedef struct Node Node;

void insert(Node** pointerToHead, int value){
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = value;
	temp->next = NULL;
	
	if(*pointerToHead != NULL){
		temp->next = *pointerToHead;
	}
	*pointerToHead = temp;
}

void print(Node* node){	
	printf("List is: ");
	while(node){
		printf(" %d", node->data);
		node = node->next; 
	}
	printf("\n");
}

int main(int argc, char** argv){
	Node* head = NULL;

	int n; int i; int x;
	printf("How many numbers?\n");
	scanf("%d", &n);

	for(i = 0; i < n; i++){
		printf("Enter a number\n");
		scanf("%d", &x);
		insert(&head, x);
		print(head);
	}










}
