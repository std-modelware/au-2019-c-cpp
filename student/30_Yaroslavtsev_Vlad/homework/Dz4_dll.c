#include <stdio.h>
#include <stdlib.h>


typedef struct list {
	int field;
	struct list* next;
	struct list* prev;
} list;


void push2(list** lst, int data) {
	list* tmp = (list*)malloc(sizeof(list));
	tmp->field = data;
	tmp->next = *lst;
	tmp->prev = (*lst)->prev = tmp;
	*lst = tmp;
}


void print(list* lst) {
	while (lst != NULL){
		printf("%d ", lst->field);
		lst = lst->next;
	}
	printf("\n");

}

void print2(list* lst, int k) {
	k = 0;
	list* lst2 = lst;
	while (lst2->next != NULL) {
		lst2 = lst2->next; // переход к концу списка
	}
	//do {
	//	printf("%d ", lst2->field); // вывод значения элемента p
	//	lst2 = lst2->prev; // переход к предыдущему узлу
	//} while (lst2 != NULL); // условие окончания обхода
	for (; lst2 != NULL; lst2 = lst2->prev) {
		printf("%d ", lst2->field);
		k++;
		if (k ==10) break;
	}
	//while (lst2 != NULL){
	//	printf("%d ", lst2->field);
	//	lst2 = lst2->prev;
	//}
	printf("\n");
}


void main() {

	list* lst = (list*)malloc(sizeof(list));
	lst->field = 10;
	lst->next = NULL;
	lst->prev = NULL;

	for (int i = 1; i < 10; ++i) {
		push2(&lst, 10 - i );
	}

	print(lst);
	print2(lst,0);

}