#include <stdio.h>
#include <stdlib.h>
typedef struct arr1 {
	int value;
	struct arr1* next;
} a1;
int N = 10;
arr1 *head = NULL;

void push1(a1** head, int data) {
	a1* nex = (a1*)malloc(sizeof(a1));
	nex->value = data;
	nex->next = (*head);
	(*head) = nex;
}

void print1(a1* head) {
	while (head->next) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

void main() {
	arr1* start = NULL;
	for (int i = 0; i <= N; i++) {
		push1(&start, i);
	}
	print1(start);
}
