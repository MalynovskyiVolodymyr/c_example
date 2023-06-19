#include <stdlib.h>
#include <stdio.h>

struct Node{
	int data;
	struct Node* link;
	struct Node* (*insert)(struct Node* head, int new);
	void (*print)(struct Node* head);
};

void Print(struct Node* head);

struct Node* Insert(struct Node* head, int x){
	struct Node* temp =(struct Node*) malloc(sizeof(struct Node));
	temp->data = x;
	temp->link = NULL;
	
	if(head != NULL){
		temp->link = head;
		temp->insert = &Insert;
		temp->print = &Print;
		head = temp;
	}
	return head;
}

void Print(struct Node* head){//do not pass a reference copy only	
	printf("List is: ");
	while(head){
		printf(" %d", head->data);
		head = head->link;
	}
	printf("\n");
}

void test2(){
	struct Node* head = malloc(sizeof(struct Node));
	head->print = &Print;
	head->insert = &Insert;
	printf("How many numbers?\n");
	
	int n; int i; int x;
	

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		printf("Enter the number \n");
		scanf("%d", &x);
		head = head->insert(head, x);
		head->print(head);
	}
}

void test(void){
	struct Node* A = NULL;
 	A = malloc(sizeof(A));
	A->data = 11;
	A->link = NULL;
	printf("A->data = %d\n",A->data);
	
	//or
	(*A).data = 12;
	printf("(*A).data = %d\n",(*A).data);
	//
	//
	//
	struct Node* A1 = malloc(sizeof(A1));
	A1->data = 123;
	A1->link = NULL;

	A->link = A1;
	
	struct Node* A2 = malloc(sizeof(A2));
	A2->data = 312;
	A2->link = NULL;
	
	A1->link = A2;
	
	struct Node* temp = A;
	
	while(temp->link){
		printf("\t value of linked list = %d\n", temp->data);
		temp = temp->link;
	}

	//free memory
	free(A);
	free(A1);
	free(A2);

}

int main(int argc, char** argv){
	//test();
	test2();
	return 0;
}
