#include <stdio.h>
#include <stdlib.h>
typedef struct odn  {
	int value;
	struct odn * next;
} a1;
int N = 40;
 

void push1(a1** head, int data) {
	a1* nex = (a1*)malloc(sizeof(a1));
	nex->value = data;
	nex->next = (*head);
	(*head) = nex;
}

void print1(a1* head) {
	while (head->next!=NULL) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

void main() {
	a1* start = NULL;
	for (int i = 0; i <= N; i++) {
		push1(&start, N-i+1);
	}
	print1(start);
}