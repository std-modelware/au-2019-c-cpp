#include <stdio.h>
#include <stdlib.h>

typedef struct arr {
	int value;
	struct arr* next;
	struct arr* prev;
}arr;
arr* head = NULL;

arr* push0(int data) {
	arr* tmp = (arr*)malloc(sizeof(arr));
	tmp->value = data;
	tmp->next = NULL;
	tmp->prev = NULL;
	return tmp;
}
void findNULL(int data) {
	arr* tmp = push0(data);
	if (head == NULL) {
		head = tmp;
		return;
	}
	head->prev = tmp;
	tmp->next = head;
	head = tmp;
}

void print(arr* head) {
	arr* rx = head;
	while (rx != NULL) {
		printf("%d   ", rx->value);
		rx = rx->next;
	}
	printf("\n");

}
void reversprint(arr* head) {
	arr* reversx = head;
	if (reversx == NULL) {
		return;
	}
	while (reversx->next != NULL) {
		reversx = reversx->next;
	}

	while (reversx != NULL){
		printf("%d   ", reversx->value);
		reversx = reversx->prev;
	}
}


void main() {
	head = NULL;
	int size = 10;
	for (int i = 0; i < size; i++) {
		findNULL(i);
	}

	print(head);
	reversprint(head);
}