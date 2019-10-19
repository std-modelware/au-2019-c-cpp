#include <stdio.h>
#include <stdlib.h>
typedef struct step {
	int number;
	struct step *next;
}step;
step *head = NULL;
void push(step**head, int data) {
	step *tmp = (step*)malloc(sizeof(step));
	tmp->number = data;
	tmp->next = *head;
	*head = tmp;
}
void write(step *head) {
	while (head->next) {
		printf("%d ", head->number);
		head = head->next;
	}
	printf("\n");
}
int main() {
	for (int i = 0; i <= 10; i++) {
		push(&head, i);
	}
	write(head);

	return 0;
}



