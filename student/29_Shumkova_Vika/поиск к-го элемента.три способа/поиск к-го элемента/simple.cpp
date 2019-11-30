#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//односвязный список
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

int main() {
	FILE *S1;
	int x;
	S1 = fopen("S1.txt", "r");
	int i = 0;
	while ((fscanf(S1, "%d", &x)) != EOF) {
		i++;
		push(&head, x);
	}
	fclose(S1);

	printf("%d \n", i);
	step *find = head;
	int k = 10;
	for (int j = i; j >= i - k + 2; j--) {
		find = find->next;
	}
	int c = (*find).number;
	printf("%d", c);
}