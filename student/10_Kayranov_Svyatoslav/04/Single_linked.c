#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push(Node **head, int data) {
    Node* tmp = malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = *head;
    *head = tmp;
}

int main() {
	int N = 10;

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
		printf("%d -> ", tmp->value);
		tmp = tmp->next;
	}
    printf("NONE ");
}