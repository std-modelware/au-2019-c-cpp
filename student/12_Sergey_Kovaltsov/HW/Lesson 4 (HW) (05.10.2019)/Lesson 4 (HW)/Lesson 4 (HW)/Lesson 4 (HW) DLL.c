#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedList {
	int elem;
	struct DoublyLinkedList *prev;
	struct DoublyLinkedList *next;
	struct DoublyLinkedList *first;
	struct DoublyLinkedList *last;
} DLL;

DLL head = { NULL, NULL };

void GenDLL(DLL *head, int elem) {
	DLL *tmp = (DLL*)malloc(sizeof(DLL));
	(*tmp).elem = elem;
	(*tmp).next = (*head).first;
	(*tmp).prev = NULL;
	if ((*head).first) {
		(*(*head).first).prev = tmp;
	}
	(*head).first = tmp;
	if ((*head).last == NULL) {
		(*head).last = tmp;
	}
}
void PrintDLL(DLL *head) {
	DLL *first = (*head).first;
	while ((*first).next) {
		printf("%d ", (*first).elem);
		first = (*first).next;
	}
	printf("%d ", (*first).elem);
}

void PrintDLL_R(DLL *head) {
	DLL *end = (*head).last;
	while ((*end).prev) {
		printf("%d ", (*end).elem);
		end = (*end).prev;
	}
	printf("%d ", (*end).elem);
}



int main() {
	int LEN = 17;
	for (int i = 10; i <= LEN; i++) {
		GenDLL(&head, i);
	}
	PrintDLL(&head);
	printf("\n\nREVERSED\n\n");
	PrintDLL_R(&head);
	printf("\n");

	return 0;
}