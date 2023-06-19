#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

typedef struct Node Node;

Node* head;

//Insert at the position
void InsertAt(int data, int position){
	Node* temp1 = malloc(sizeof(struct Node));
	temp1->data = data;
	temp1->next = NULL;

	if(position == 1){
		temp1->next = head;
		head = temp1;//head position was changed
		return;
	}

	Node* headCopy = head;//head position was not changed temp2 is a copy
	
	for(int i = 0; i < position-2; i++){//position not incrementing!!
		headCopy = headCopy->next;
	}
	temp1->next = headCopy->next;
	headCopy->next = temp1;
}

void Delete(int position){
	Node* headCopy = head;
	
	for(int i = 0; i < position-2; i++){
		headCopy = headCopy->next;//point -1 position
	}

	Node* deleteNode = headCopy->next;//ecxac position = -1 position -> element
	headCopy->next = deleteNode->next;//-1 position -> +2 position
	free(deleteNode);
}

void DeleteAll(){	
	Node* temp;
	
	while(head){
		temp = head;
		head = head->next;
		
		if(head->next == NULL){
			free(head);
			head = NULL;
			break;
		}
		free(temp);
	}
}

void Print(){
	if(head == NULL){
		return;
	}
	Node* temp = head;
	
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void PrintRecurcive(Node* item){
	if(item == NULL){
		printf("\n");
		return;
	}
	
	printf("%d ", item->data);
	
	PrintRecurcive(item->next);
}

void PrintRecurciveReverse(Node* item){
	if(item == NULL){
		return;
	}
	PrintRecurciveReverse(item->next);
	printf("%d ", item->data);
}


void Insert(int data){
	Node* newNode = (Node*) malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

	if(head == NULL){
		head = newNode;
		return;
	}
	
	Node* headCopy = head;
	while(headCopy->next != NULL){
		headCopy = headCopy->next;
	}
	headCopy->next = newNode;
}

void Reverse(){
	Node* current; Node* prev; Node* next;
	current = head;
	prev = NULL;
	
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void RecursiveReverse(Node* pointer){
	if(pointer->next == NULL){
		head = pointer;
		return;
	}
	RecursiveReverse(pointer->next);
	Node* q = pointer->next;
	q->next = pointer;
	pointer->next = NULL;
}

int main(){
	head = NULL;
	InsertAt(22,1);
	InsertAt(33,2);
	InsertAt(44,3);
	InsertAt(55,1);
	InsertAt(66,3);
	Print();
	Insert(1);
	Insert(2);
	Insert(3);
	PrintRecurcive(head);
	PrintRecurciveReverse(head);
	printf("\n");
	Reverse();
	printf("first simple reverse\n");
	Print();
	RecursiveReverse(head);
	printf("after recursuve reverse\n");
	Print();
	Delete(2);
	Delete(5);
	Delete(0);
	Print();
	DeleteAll();
	Print();
	return 0;
}


