#include "binary_tree.h"

element* kernel;
element* pointer;

void create_root(int key, int value) {
	element* kernel =(element*)malloc(sizeof(element));
	kernel->key = key;
	kernel->value = value;
	kernel->left = NULL;
	kernel->right = NULL;
	pointer = kernel;
	kernel = pointer;
}


/*
в моей реализации бинарного дерева данная функция нерентабельна
int tryFind(int key); // return 0 - поиск не удачен, 1 - удачи
*/

//int find(int key); // return value

int count = 0;

int add(int key, int value) {
	if (count < 1) {
		kernel = pointer;
		count++;
	}

	element* newElement = (element*)malloc(sizeof(element));
	newElement->key = key;
	newElement->value = value;
	newElement->left = NULL;
	newElement->right = NULL;
	if ((pointer != NULL) && (key == pointer->key)) {
		printf("%s%d%s", "The element '", key, "' already exist.\n");
		pointer = kernel;
		kernel = pointer;
		return(1);
	}
	//left
	if ((pointer != NULL) && (pointer->left != NULL) && (newElement->key < pointer->key)) {
		pointer = pointer->left;
		add(key, value);
		return(0);
	}
	if ((pointer->left == NULL) && (newElement->key < pointer->key)) {
		pointer->left = newElement;
		pointer = kernel;
		printf("%s%d%s", "The '", key, "' goes left.\n");
		kernel = pointer;
		return(0);
	}
	//right
	if ((pointer != NULL) && (pointer->right != NULL) && (newElement->key > pointer->key)) {
		pointer = pointer->right;
		add(key, value);
		return(0);
	}
	if ((pointer->right == NULL) && (newElement->key > pointer->key)) {
		pointer->right = newElement;
		pointer = kernel;
		printf("%s%d%s", "The '", key, "' goes right.\n");
		return(0);
	}
}

int find(int key) {
	if (count < 1) {
		kernel = pointer;
		count++;
	}

	element* newElement = (element*)malloc(sizeof(element));
	newElement->key = key;
	newElement->value = NULL;
	newElement->left = NULL;
	newElement->right = NULL;
	if ((pointer != NULL) && (key == pointer->key)) {
		printf("%s%d%s%d%s", "The element '", key, "' already exist, value = ", pointer->value, ".\n");
		pointer = kernel;
		kernel = pointer;
		return(1);
	}
	//left
	if ((pointer != NULL) && (pointer->left != NULL) && (newElement->key < pointer->key)) {
		pointer = pointer->left;
		find(key);
		return(0);
	}
	if ((pointer->left == NULL) && (newElement->key < pointer->key)) {
		pointer = kernel;
		printf("%s%d%s", "The '", key, "' didnt find.\n");
		kernel = pointer;
		return(0);
	}
	//right
	if ((pointer != NULL) && (pointer->right != NULL) && (newElement->key > pointer->key)) {
		pointer = pointer->right;
		find(key);
		return(0);
	}
	if ((pointer->right == NULL) && (newElement->key > pointer->key)) {
		pointer = kernel;
		printf("%s%d%s", "The '", key, "' didnt find.\n");
		return(0);
	}
}

int addElem(element* newElement) {
	if (count < 1) {
		kernel = pointer;
		count++;
	}

	if ((pointer != NULL) && (newElement->key == pointer->key)) {
		pointer = kernel;
		kernel = pointer;
		return(1);
	}
	//left
	if ((pointer != NULL) && (pointer->left != NULL) && (newElement->key < pointer->key)) {
		pointer = pointer->left;
		addElem(newElement);
		return(0);
	}
	if ((pointer->left == NULL) && (newElement->key < pointer->key)) {
		pointer->left = newElement;
		pointer = kernel;
		kernel = pointer;
		return(0);
	}
	//right
	if ((pointer != NULL) && (pointer->right != NULL) && (newElement->key > pointer->key)) {
		pointer = pointer->right;
		addElem(newElement);
		return(0);
	}
	if ((pointer->right == NULL) && (newElement->key > pointer->key)) {
		pointer->right = newElement;
		pointer = kernel;
		return(0);
	}
}

int removeElem(int key) {
	if (count < 1) {
		kernel = pointer;
		count++;
	}

	if ((pointer != NULL) && (key == pointer->key)) {
		printf("%s%d%s", "The element '", key, "' is going to dissapear, pip... ploops... DONE.\n");

		element* right = pointer->right;
		*pointer = *pointer->left;
		addElem(right);
		return(1);
	}
	//left
	if ((pointer != NULL) && (pointer->left != NULL) && (key < pointer->key)) {
		pointer = pointer->left;
		removeElem(key);
		return(0);
	}
	if ((pointer->left == NULL) && (key < pointer->key)) {
		pointer = kernel;
		printf("%s%d%s", "The '", key, "' didnt find for deleting.\n");
		kernel = pointer;
		return(0);
	}
	//right
	if ((pointer != NULL) && (pointer->right != NULL) && (key > pointer->key)) {
		pointer = pointer->right;
		removeElem(key);
		return(0);
	}
	if ((pointer->right == NULL) && (key > pointer->key)) {
		pointer = kernel;
		printf("%s%d%s", "The '", key, "' didnt find for deleting.\n");
		return(0);
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