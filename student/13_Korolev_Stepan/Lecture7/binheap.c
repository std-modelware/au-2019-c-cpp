#include "binheap.h"
#include <stdlib.h>

node* root;
node* cur;
size_t binheap_size;
int key;
static char* last_error_string = "";

void binheap_init(size_t size, int value) {
	root = (node*)calloc(sizeof(node), size);
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;
	root->value = value;
	key = 0;
	binheap_size = size;
	cur = root;
}

void binheap_insert(int value) {
	if (cur - root >= binheap_size) {
		last_error_string = "Auqueue is full";
		binheap_last_error();
	}
	else {
		if (!(cur->left)) {
			cur->left = root + key + 1;
		}
		else {
			cur->right = root + key + 1;
		}
		cur = root + ++key / 2;
		root[key].left = NULL;
		root[key].right = NULL;
		root[key].value = value;
		root[key].parent = cur;

	}
}

void binheap_print() {
	for (int i = 0; i < key + 1; i++) {
		int _[3];
		_[0] = root[i].parent ? root[i].parent->value : -1;
		_[1] = root[i].left ? root[i].left->value : -1;
		_[2] = root[i].right ? root[i].right->value : -1;
		printf("value: %d \t parent: %d \t children: (Left: %d \t| Right: %d )\n", root[i].value, _[0], _[1], _[2]);
	}
}

void binheap_last_error() {
	printf("%s\n", last_error_string);
}