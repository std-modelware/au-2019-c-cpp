#include <stdio.h>
#include <stdlib.h> 
#include "string.h"

static size_t maxSize;
static struct cell* root;
static struct cell* treeEnd;
int lastError = 0;
int size = 0;

struct cell {
	int priority;
	char value;
};

SwapCells(struct cell* cel1, struct cell* cel2) {
	int tmpprior = cel1->priority;
	char tmpchar = cel1->value;
	cel1->priority = cel2->priority;
	cel1->value = cel2->value;
	cel2->priority = tmpprior;
	cel2->value = tmpchar;
}

struct cell* GetParentCell(int index) {
	if (index == 0) {
		lastError = 5;
		return root;
	}
	return (root + ((index - 1) / 2));
}

struct cell* GetCellByIndex(int index) {
	if (index < 0 || index > size) {
		lastError = 6;
		//printf("index is: %d\n", index);
		return NULL;
	}
	return (root + index);
}

void auqueue_init(size_t size) {
	root = calloc(size, sizeof(struct cell));
	treeEnd = root;
	maxSize = size;
}

void auqueue_release() {
	free(root);
	maxSize = 0;
	root = NULL;
	treeEnd = NULL;
}

void auqueue_enqueue(char item, int prior) {
	if ((size_t)size >= maxSize) {
		lastError = 2;
		return;
	}
	struct cell* newCell = malloc(sizeof(struct cell));
	if (newCell == NULL) exit(1);
	newCell->value = item;
	newCell->priority = prior;
	*treeEnd = *newCell;
	treeEnd++;
	size++;
	int i = size - 1;
	while (i != 0 && (GetParentCell(i)->priority < GetCellByIndex(i)->priority)) {
		SwapCells(GetCellByIndex(i), GetParentCell(i));
		i = (i - 1) / 2;
	}
}

char auqueue_dequeue() {
	if (size == 0) {
		lastError = 9;
		return NULL;
	}
	treeEnd--;
	size--;
	char value = root->value;
	printf("dequeue element \"%c\" with priority %d\n", root->value, root->priority);
	SwapCells(treeEnd, root);
	int i = 0;
	while (i < (size) / 2) { //
		int maxI = 2 * i + 1;
		if (2 * i + 2 < (size) && GetCellByIndex(2 * i + 2)->priority > GetCellByIndex(2 * i + 1)->priority)
			maxI = 2 * i + 2;
		if (GetCellByIndex(i)->priority >= GetCellByIndex(maxI)->priority)
			break;
		SwapCells(GetCellByIndex(i), GetCellByIndex(maxI));
		i = maxI;
	}
	return (value);
}
void auqueue_print() {
	if (size != 0) {
		printf("[");
		for (int i = 0; i < size - 1; i++)
			printf("%c, ", GetCellByIndex(i)->value);
		if (GetCellByIndex(size - 1) != NULL)
			printf("%c]\n", GetCellByIndex(size - 1)->value);
	}
	else printf("[]\n");

}
void auqueue_last_error() {
	if (lastError != 0)
		printf("error %d", lastError);
}


void main() {
	//tests
	auqueue_init(9);
	auqueue_last_error();
	auqueue_enqueue('q', 10);
	auqueue_print();
	auqueue_enqueue('w', 6);
	auqueue_print();
	auqueue_enqueue('e', 7);
	auqueue_last_error();
	auqueue_print();
	auqueue_enqueue('a', 21);
	auqueue_print();
	auqueue_enqueue('s', 4);
	auqueue_print();
	auqueue_enqueue('z', 5);
	auqueue_print();
	auqueue_enqueue('x', 9);
	auqueue_print();
	auqueue_enqueue('c', 12);
	auqueue_print();
	auqueue_enqueue('l', 11);
	auqueue_print();
	auqueue_enqueue('k', 15);
	auqueue_print();
	auqueue_enqueue('j', 50);
	auqueue_print();

	char c;
	c = auqueue_dequeue();
	auqueue_print();
	c = auqueue_dequeue();
	auqueue_print();
	c = auqueue_dequeue();
	auqueue_print();
	c = auqueue_dequeue();
	auqueue_print();
	c = auqueue_dequeue();
	auqueue_print();
	c = auqueue_dequeue();
	auqueue_print();
	c = auqueue_dequeue();
	auqueue_print();
	c = auqueue_dequeue();
	auqueue_print();
	c = auqueue_dequeue();
	auqueue_print();
	c = auqueue_dequeue();
	auqueue_print();


}