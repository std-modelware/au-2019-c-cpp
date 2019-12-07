
#include <stdio.h>

typedef struct Node {
	int value;
	struct Node* next;
} Node;

void push(Node** head, int data) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = data;
	tmp->next = *head;
	*head = tmp;
}


void print(Node* start) {
	while (start->next) {
		printf("%d  ", start->value);
		start = start->next;
	}
	printf("%d", start->value);
	printf("\n");
}


int f_pass(Node* head, int count) {
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}

int t_pass(Node* head, int k, int c1) {
	//for (int i = c1; i >= c1 - k + 2; i--) {
	for(int i = 0; i < c1 - k ; i++){
		head = head->next;
	}
	int final = (*head).value;
	return final;
}

///

int replay_foo(Node* head_1, int k) {
	if (head_1->next == NULL) { 
		return 0;
	} 
	int final_1 = replay_foo(head_1->next, k) + 1;
	if (final_1 == k) {
		printf("%d", head_1->value);
	}
	return final_1;
}

///

int double_start(Node* head_2, int k) {
	if (k <= 0) return 0;

	struct Node* tmp1 = head_2;
	struct Node* tmp2 = head_2;

	for (int i = 0; i < k - 1; i++) {
		if (tmp2->next == NULL) return 0; 
		tmp2 = tmp2->next;
	}

	while (tmp2 -> next != NULL) {
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	return tmp1->value;
}


int main() {
	Node* head = NULL;
	for (int i = 10; i >= 1; i--) {
		push(&head, i);
	}
	print(head);

	//////////
	int c = 0, c1, final_c;
	c1 = f_pass(head, c);
	int k = 5;
	final_c = t_pass(head,k,c1);
	printf("%d \n", c1);
	printf("%d \n\n", final_c);
	//////////
	int k1 = 7;
	replay_foo(head, k1);
	printf("\n\n");
	//////////
	int k2 = 5;
	int cc = double_start(head,k2);
	printf("%d \n", cc);
	return 0;
}
