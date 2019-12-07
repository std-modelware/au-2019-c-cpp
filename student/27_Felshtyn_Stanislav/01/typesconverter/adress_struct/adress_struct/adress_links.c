#include <stdio.h>
#include "Header.h"

int main() {
	int sz;
	printf("Input lenght of the list = ");
	scanf_s("%d", &sz);
	node list_1 = NULL;
	create_list_1(&list_1, sz);
		for (node iter = list_1; iter != NULL; iter = iter->next) {
			printf("%d ", iter->num);
		}
	printf("\n");
	printf("Input lenght of the list = ");
	scanf_s("%d", &sz);
	node_2 list_2 = NULL;
	create_list_2(&list_2, sz);
	node_2 temp;
	node_2 tmp=NULL;
		for (temp = list_2; temp != NULL; temp = temp->next) {
			tmp = temp;
			printf("%d ", temp->num);
		}
	printf("\n");
		for ( tmp; tmp != NULL; tmp = tmp->prev) {
			printf("%d ", tmp->num);
		}
	return 0;
}
