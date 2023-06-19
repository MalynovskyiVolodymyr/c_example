#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* link;
};

typedef struct Node Node;

Node* top = NULL;

Node* GetNewNode(){
	Node* temp = (Node*)malloc(sizeof(struct Node));
	return temp;
}

void Push(int x){
	Node* temp = GetNewNode();
	temp->data = x;
	temp->link = top;
	top = temp;
}

void Pop(){
	Node* temp;
	
	if(top == NULL){
		return;
	}

	temp = top;
	top = top->link;
	free(temp);
}

int main(){
}






