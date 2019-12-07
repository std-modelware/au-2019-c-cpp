#include <stdio.h>

typedef struct Node {
	int value;
	struct Node* next;
} Node;

void push(Node** head, int data) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = data;
	tmp->next = *head;
	*head = tmp;
}

void print(Node* start) {
	while (start->next) {
		printf("%d  ", start->value);
		start = start->next;
	}
	printf("%d", start->value);
	printf("\n");
}

int main() {
	Node* head = NULL;
	for (int i = 1; i <= 10; i++) {
		push(&head, i);
	}
	print(head);
	return 0;
}


