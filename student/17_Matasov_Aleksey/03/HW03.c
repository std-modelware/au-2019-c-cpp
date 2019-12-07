#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Node2 {
    int value;
    struct Node2 *next;
    struct Node2 *prev;
} Node2;


void push(Node **head, int data) {
    Node* tmp = malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = *head;
    *head = tmp;
}

void push2(Node2 **head, int data) {
    Node2* tmp = malloc(sizeof(Node2));
    tmp->value = data;
    tmp->next = *head;
    tmp->prev = (*head)->prev;
    (*head)->prev = tmp;
    *head = tmp;
}

void main() {
	int N = 15;

	Node* head = malloc(sizeof(Node));
	head->value = N-1;
	head->next = NULL;

	for (int i = 1; i < N; ++i)
	{
		push(&head, N-i-1);
	}
	Node* tmp = head;
	for (int i = 0; i < N; ++i)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}

	printf("\n\n");

	Node2* head2 = malloc(sizeof(Node2));
	head2->value = N-1;
	head2->next = NULL;
	head2->prev = NULL;

	for (int i = 1; i < N; ++i)
	{
		push2(&head2, N-i-1);
	}

	Node2* tmp2 = head2;
	for (int i = 0; i < N; ++i)
	{
		printf("%d\n", tmp2->value);
		if (i<N-1) tmp2 = tmp2->next;
	}

	printf("\n\n");
	
	for (int i = N-1; i >= 0; --i)
	{
		printf("%d\n", tmp2->value);
		tmp2 = tmp2->prev;
	}
}