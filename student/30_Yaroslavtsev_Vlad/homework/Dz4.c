#include <stdio.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

void push(Node** start, int data) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = *start;
	*start = tmp;
}

void passage(Node* start) {
	while (start->next) {
		printf("%d  ", start->data);
		start = start->next;
	}
	printf("%d\n", start->data);
}

int main() {
	Node* start = NULL;
	for (int i = 1; i <= 10; i++) {
		push(&start, i);
	}
	passage(start);
	return 0;
}


