#include <stdlib.h>
#include <stdio.h>

struct node{
	int key;
	struct node *next;	
};

typedef struct node node;

node *head, *z, *t;

void listInitialize(){
	head = (struct node*) malloc(sizeof *head);
	z = (struct node*) malloc(sizeof *z);
	head->next = z; 
	z->next = z;
}

void deleteNext(node *t){
	node *delNode = t->next;
	t->next = t->next->next;
	free(delNode);
}

node* insertAfter(int v, node *t){
	node *x;
	x = (struct node*) malloc(sizeof *x);
	x->key = v;
	x->next = t->next;
	t->next = x;
	return x;
}


void simpleListExample(){
	int i, N, M;
	node *t, *x;	
	scanf("%d %d", &N, &M);
	t = (struct node*) malloc(sizeof *t);
	t->key = 1;
	x = t;
	
	for(i = 2; i <= N; i++){
		t->next = (struct node*) malloc(sizeof *t);
		t = t->next;
		t->key = i;
	}

	t->next = x;

	while(t != t->next){
		for(i = 1; i < M; i++){
			t = t->next;
		}
		printf("%d ", t->next->key);	
		x = t->next;
		t->next = t->next->next;
		free(x);
	}
	printf("%d\n", t->key);
}


////stack
void stackInit(){
	head = (node*) malloc(sizeof *head);
	z = (node*) malloc(sizeof *z);
	head->next = z;
	head->key = 0;
	z->next = z;
}

void push(int v){
	t = (node *) malloc(sizeof *t);
	t->key = v;
	t->next = head->next;
	head->next = t;
}

int pop(){
	int x;
	t = head->next;
	head->next = t->next;
	x = t->key;
	free(t);
	return x;
}

int stackEmpty(){
	return head->next == z;
}

void main(void){
	
}












