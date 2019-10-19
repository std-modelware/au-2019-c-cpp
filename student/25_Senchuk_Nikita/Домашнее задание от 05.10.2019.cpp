#include <stdio.h>
#include <stdlib.h>

typedef struct OneWayList *node;

typedef struct BothWaysList *node1;

struct OneWayList {
	int item;
	node next;
};

struct BothWaysList {
	int item;
	node1 next;
	node1 previous;
};

void CreateOneWayList(node head, int *arr, int length) {
	for (size_t i = 0; i < length; i++) {
		node newelem;
		newelem = (node)malloc(sizeof(struct OneWayList));
		newelem->item = arr[i];
		newelem->next = NULL;
		if (head == NULL) {
			head = newelem;
		}
		else {
			node temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newelem;
		}
	}
};

void CreateBothWaysList(node1 head, node1 tail, int *arr, int length) {
	for (size_t i = 0; i < length; i++) {
		node1 newelem;
		newelem = (node1)malloc(sizeof(struct BothWaysList));
		newelem->item = arr[i];
		newelem->next = NULL;
		newelem->previous = NULL;
		if (head == NULL) {
			head = newelem;
		}
		else {
			node1 temp1 = head;
			while (temp1->next != NULL) {
				temp1 = temp1->next;
			}
			newelem->previous = temp1;
			temp1->next = newelem;
		}
		tail = newelem;
	}
};

void main() {
	int arr[] = { 10, 7, 11, 38, 49, 292 };
	int l = (int) sizeof(arr) / sizeof(arr[0]);
	node list = NULL;
	CreateOneWayList(list, arr, l);
	for (node iter = list; iter != NULL; iter = iter->next) {
		printf("%d ", iter->item);
	}

	int arr[] = { 3, 494, 92, 193, 491, 292 };
	node1 head, tail = NULL;
	int l = (int) sizeof(arr) / sizeof(arr[0]);
	CreateBothWaysList(head, tail, arr, l);

	for (node1 temp = head; temp != NULL; temp = temp->next) {
		printf("%d ", temp->item);
	}
	printf("%c", '\n');
	for (node1 temp = tail; temp != NULL; temp = temp->previous) {
		printf("%d ", temp->item);
	};
}