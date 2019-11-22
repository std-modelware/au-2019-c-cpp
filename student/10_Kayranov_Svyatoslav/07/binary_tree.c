#include "binary_tree.h"

typedef struct element {
	int key;
	int value;
	struct element* left;
	struct element* right;
} element;
element* kernel;
element* temp;
element* pointer;

void create_root(int key, int value) {
	element* kernel = malloc(sizeof(element));
	kernel->key = key;
	kernel->value = value;
	kernel->left = NULL;
	kernel->right = NULL;
	pointer = kernel;
}


/*
в моей реализации бинарного дерева данная функция нерентабельна
int tryFind(int key); // return 0 - поиск не удачен, 1 - удачи
*/

//int find(int key); // return value
int add(int key, int value) {
	kernel = pointer;
	element* newElement = malloc(sizeof(element));
	newElement->key = key;
	newElement->value = value;
	newElement->left = NULL;
	newElement->right = NULL;
	if ((pointer != NULL) && (key == pointer->key)) {
		printf("%s%d%s", "The element '",key,"' already exist.\n" );
		return(1);
	}
	if ((pointer != NULL) && (pointer->left != NULL) && (newElement->key < pointer->key)) {
		pointer = pointer->left;
		add(key, value);
	}
	if ((pointer->left == NULL) && (newElement->key < pointer->key)) {
		pointer->left = newElement;
		pointer = kernel;
		printf("%s%d%s", "The '", key, "' go es left.\n");
	}

	if ((pointer != NULL) && (pointer->right != NULL) &&  (newElement->key > pointer->key)) {
		pointer = pointer->right;
		add(key, value);
	}
	if ((pointer->right == NULL) && (newElement->key > pointer->key)) {
		pointer->right = newElement;
		pointer = kernel;
		printf("%s%d%s", "The '", key, "' goes right.\n");
	}
}

//void removeElem(int key);


/*
if ((*pointer).parent == NULL) {
		if ((*pointer).left == NULL) {
			newElement -> key = key;
			newElement -> value = value;
			newElement -> parent = kernel;
			kernel -> left = newElement;
			kernel -> fullness += 1;
		}
		if ((*pointer).right == NULL) {
			newElement -> key = key;
			newElement -> value = value;
			newElement -> parent = kernel;
			kernel -> right = newElement;
			kernel -> fullness += 1;
		}
	}




	if ((*pointer).parent == NULL) {
		if (kernel -> left == NULL) {
			if (kernel -> value < newElement -> value) {
				kernel -> left = newElement;
				newElement -> parent = kernel;
				kernel -> fullness = 1;
			}
			else {
				temp = kernel;
				kernel = newElement;
				newElement = temp;
				kernel -> left = newElement;
				newElement -> parent = kernel;
				kernel -> parent = NULL;
				kernel -> fullness = 1;
			}
		}
		if
	}
*/