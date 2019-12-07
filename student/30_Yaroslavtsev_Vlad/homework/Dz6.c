#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>



typedef struct node {
	int data;
	int priority;
	struct node* next;
} Node;


Node* newNode(int data, int prior){ 
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->priority = prior;
	tmp->next = NULL;
	return tmp;
}

int min_value(Node** head){
	return (*head)->data;
}

void pop(Node** head){ 
	Node* tmp = *head;
	(*head) = (*head)->next;
	free(tmp);
}

void push(Node** head, int data, int prior){
	Node* start = (*head); 
	Node* tmp = newNode(data, prior); 

	if ((*head)->priority > prior) {
		tmp->next = *head;
		(*head) = tmp;
	} else {
		while (start->next != NULL && start->next->priority <= prior) {
			start = start->next;
		}
		tmp->next = start->next;
		start->next = tmp;
	}
}

int empty(Node** head){
	return (*head) == NULL;
}

void print(Node* head) {
	while (head != NULL) {
		printf("%d ", head ->data);
		head = head->next;
	}
	printf("\n");

}

void main(){
	int data, prior;
	scanf("%d %d", &data, &prior);
	Node* point = newNode(data, prior);
	for(int i = 1; i < 5; i++){
		scanf("%d %d", &data, &prior);
		push(&point, data, prior);	
		print(point);
	}

	while (!empty(&point)) {
		printf("%d ", min_value(&point));
		pop(&point);
	}
	
}