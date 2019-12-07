#include <stdio.h>
#include <stdlib.h>

typedef struct SinglyLinkedList {
	int elem;
	struct SinglyLinkedList *next;
} SLL;

SLL *head = NULL;
void GenSLL(SLL **head, int elem) {
	SLL *tmp = (SLL*)malloc(sizeof(SLL));
	(*tmp).elem = elem;
	(*tmp).next = *head;
	(*head) = tmp;
};

void PrintSLL(SLL *head) {
	while ((*head).next) {
		printf("%d ", (*head).elem);
		head = (*head).next;
	}
	printf("%d ", (*head).elem);
}

int main() {
	int LEN = 17;
	for (int i = 10; i <= LEN; i++) {
		GenSLL(&head, i);
	}
	PrintSLL(head);
	printf("\n");
	
	return 0;
}