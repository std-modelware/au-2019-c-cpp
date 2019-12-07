#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


static int ERROR = 0;
static struct node* root = NULL;
static struct node* moving = NULL;

node* create_node() {
	node* nodegen = (node*)malloc(sizeof(node));
	(*nodegen).parent = NULL;
	(*nodegen).right = NULL;
	(*nodegen).left = NULL;
	(*nodegen).value;
	(*nodegen).key;
	return nodegen;
}

void get_last_error() {
	if (ERROR == 1) {
		printf("root is already exists!");
		exit(1);
	}
	if (ERROR == 2) {
		printf("root is not created!");
		exit(2);
	}
	if (ERROR == 3) {
		printf("key cannot be negative or zero");
		exit(3);
	}
	if (ERROR == 4) {
		printf("this key is already using");
		exit(4);
	}
	if (ERROR == 5) {
		printf("value with this key cannot be deleted (doesn't exist)\n");
		exit(5);
	}
}

void create_root(int key, int value) {
	ERROR = 0;
	if (root != NULL) {
		ERROR = 1;
		get_last_error();
	}
	root = create_node();
	(*root).key = key;
	(*root).value = value;
	moving = root;
}

void start_moving() {
	if (root != moving) {
		moving = root;
	}
}

void add(int key, int value) {
	ERROR = 0;
	if (key <= 0) {
		ERROR = 3;
		get_last_error();
	}
	if (root == NULL) {
		ERROR = 2;
		get_last_error();
	}
	start_moving();
	struct node* add = create_node();
	(*add).key = key;
	(*add).value = value;
	while (((*moving).right != NULL || (*moving).left != NULL)) {
		if (key == (*moving).key) {
			ERROR = 4;
			get_last_error();
		}
		if (key < (*moving).key) {
			if ((*moving).left == NULL) {
				(*add).parent = moving;
				(*moving).left = add;
				return;
			}
			else {
				moving = (*moving).left;
				continue;
			}
		}
		if (key > (*moving).key) {
			if ((*moving).right == NULL){
				(*add).parent = moving;
				(*moving).right = add;
				return;
			}
			else {
				moving = (*moving).right;
				continue;
			}
		}
	}
	if (key > (*moving).key) {
		(*add).parent = moving;
		(*moving).right = add;
		return;
	}
	else {
		(*add).parent = moving;
		(*moving).left = add;
		return;
	}
}

bool tryfind(int key) {
	start_moving();
	do
	{
		if ((*moving).key == key) {
			return B_TRUE;
		}
		if (key < (*moving).key) {
			if ((*moving).left != NULL) {
				moving = (*moving).left;
				continue;
			}
			return B_FALSE;
		}
		if (key > (*moving).key) {
			if ((*moving).right != NULL) {
				moving = (*moving).right;
				continue;
			}
			return B_FALSE;
		}
	} while ((*moving).right != NULL || (*moving).left != NULL);
	if ((*moving).key == key) {
		return B_TRUE;
	}
	return B_FALSE;
}

int find(int key) {
	if (tryfind(key)) {
		printf("key = %d, value = %d\n", (*moving).key, (*moving).value);
		return (*moving).value;
	}
	printf("value with this key doesn't exists\n");
}

static struct node* leftbranch = NULL;
static struct node* rightbranch = NULL;

int remove(int key) {
	ERROR = 0;
	if (tryfind(key)) {
		printf("removing value = %d with key = %d\n", (*moving).value, key);
		leftbranch = (*moving).left;
		rightbranch = (*moving).right;
		if ((*(*moving).parent).left != NULL) {
			if ((*(*(*moving).parent).left).key == (*moving).key) {
				(*(*moving).parent).left = NULL;
			}
			else {
				(*(*moving).parent).right = NULL;

			}
		}
		else {
			if ((*(*moving).parent).right != NULL) {
				if ((*(*(*moving).parent).right).key == (*moving).key) {
					(*(*moving).parent).right = NULL;
				}
				else {
					(*(*moving).parent).left = NULL;
				}
			}
		}

		(*moving).parent = NULL;
		(*moving).key = 0;

		if (leftbranch != NULL) {
			add((*leftbranch).key, (*leftbranch).value);
			tryfind((*leftbranch).key);
			(*moving).left = (*leftbranch).left;
			(*moving).right = (*leftbranch).right;
		}

		if (rightbranch != NULL) {
			add((*rightbranch).key, (*rightbranch).value);
			tryfind((*rightbranch).key);
			(*moving).left = (*rightbranch).left;
			(*moving).right = (*rightbranch).right;
		}
		return;
	}
	else {
		ERROR = 5;
		get_last_error();
		return;
	}
}
