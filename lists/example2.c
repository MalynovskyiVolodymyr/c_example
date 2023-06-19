#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

typedef struct Node Node;

Node* head;

Node* GetNewNode(int x){
	Node* newNode = (Node*) malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void InsertAtHead(int x){
	Node* temp = GetNewNode(x);
	
	if(head == NULL){
		head = temp;
		return;
	}
	head->prev = temp;
	temp->next = head;
	head = temp;
}

void InsertAtTail(int x){
	Node* newNode = GetNewNode(x);
	Node* temp = head;
	if(head == NULL){
		head = temp;
		return;
	}

	while(temp->next != NULL){
		temp = temp->next;
	}

	newNode->prev = temp;
	temp->next = newNode;
}

void Print(){
	Node* temp = head;
	printf("Forward: ");
	
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void ReversePrint(){
	Node* temp = head;
	
	if(temp == NULL){
		return;
	}
	
	while(temp->next != NULL){
		temp = temp->next;
	}

	printf("Reverse: ");
	while(temp != NULL){
		printf("%d ", temp->data);
		temp  = temp->prev;
	}
	printf("\n");
}

int main(){
	head = NULL;
	InsertAtHead(2);Print();ReversePrint();
	InsertAtHead(4);Print();ReversePrint();
	InsertAtHead(6);Print();ReversePrint();
	printf("insert at tail\n");
	InsertAtTail(22);Print();ReversePrint();
	InsertAtTail(33);Print();ReversePrint();
	InsertAtTail(55);Print();ReversePrint();
}


