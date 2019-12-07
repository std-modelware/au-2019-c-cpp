#include <stdio.h>
#include <stdlib.h>
typedef struct step {
	int number;
	struct step *next;
	struct step *prev;
}step;
step *head;
step* func1(int data) {
	step* tmp = (step*)malloc(sizeof(step));
	tmp->number = data;
	tmp->next = NULL;
	tmp->prev = NULL;
	return tmp;
}

void findzero(int data) {
	step *tmp = func1(data);
	if (head == NULL) {
		head = tmp;
		return;
	}
	head->prev = tmp;
	tmp->next = head;
	head = tmp;
}

void print(step *head) {
	step *runner = head;
	while (runner != NULL) {
		printf("%d   ", runner->number);
		runner = runner->next;
	}
	printf("\n");

}
void reversprint(step* head) {
	step *reverserunner = head;
	if (reverserunner == NULL) {
		return;
	}
	while (reverserunner->next != NULL) {
		reverserunner = reverserunner->next;
	}

	while (reverserunner != NULL)
	{
		printf("%d   ", reverserunner->number);
		reverserunner = reverserunner->prev;
	}


}
void main() {
	int n = 10;
	head = NULL;
	for (int i = 0; i < n; i++) {
		findzero(i);
	}

	print(head);
	reversprint(head);
}

