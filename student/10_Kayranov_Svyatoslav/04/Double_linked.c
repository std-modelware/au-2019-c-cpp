#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node2 {
    int value;
    struct Node2 *next;
    struct Node2 *prev;
} Node2;

void push2(Node2 **head, int data) {
    Node2* tmp = malloc(sizeof(Node2));
    tmp->value = data;
    tmp->next = *head;
    tmp->prev = (*head)->prev;
    (*head)->prev = tmp;
    *head = tmp;
}

int main() {
	int N = 10;

	Node2* head2 = malloc(sizeof(Node2)); 
    head2->value = N-1;
	head2->next = NULL;
	head2->prev = NULL;

	for (int i = 1; i < N; ++i)
	{
		push2(&head2, N-i-1);
	}

	Node2* tmp2 = head2;
    printf("NONE <-> ");
	for (int i = 0; i < N; ++i)
	{
		printf("%d <-> ", tmp2->value);
		if (i<N-1) tmp2 = tmp2->next;
	}
    printf("NONE ");

	printf("\n\n");

	printf("NONE <-> ");
	for (int i = N-1; i >= 0; --i)
	{
		printf("%d <-> ", tmp2->value);
		tmp2 = tmp2->prev;
	}
    printf("NONE ");
}