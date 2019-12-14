#include <stdio.h>
#include <stdlib.h>

typedef struct dvu {
	int value;
	struct dvu* next;
	struct dvu* prev;
}dvu;
dvu* head = NULL;

dvu* push0(int data) {
	dvu* tmp = (dvu*)malloc(sizeof(dvu));
	tmp->value = data;
	tmp->next = NULL;
	tmp->prev = NULL;
	return tmp;
}
void findNULL(int data) {
	dvu* tmp = push0(data);
	if (head == NULL) {
		head = tmp;
		return;
	}
	head->prev = tmp;
	tmp->next = head;
	head = tmp;
}

void print(dvu* head) {
	dvu* rx = head;
	while (rx != NULL) {
		printf("%d   ", rx->value);
		rx = rx->next;
	}
	printf("\n");

}
void reversprint(dvu* head) {
	dvu* reversx = head;
	if (reversx == NULL) {
		return;
	}
	while (reversx->next != NULL) {
		reversx = reversx->next;
	}

	while (reversx != NULL) {
		printf("%d   ", reversx->value);
		reversx = reversx->prev;
	}
}


void main() {
	head = NULL;
	int size = 16;
	for (int i = 1; i < size; i++) {
		findNULL(i);
	}

	print(head);
	reversprint(head);
}