#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	int value;
	struct node* min;
	struct node* max;
};

node* create_root(int key, int value) {
	node* node1 = (node*)malloc(sizeof(node));
	(*node1).key = key;
	(*node1).value = value;
	(*node1).min = NULL;
	(*node1).max = NULL;
	return node1;
}
//--------------
void add(int key, int value, node* node1) {
 if (((*node1).min != NULL)&&((*node1).max != NULL)){
	if((*node1).key>key){
		add(key, value, (*node1).min);
	}
	else{add(key, value, (*node1).max);}
  return;
}
 if (((*node1).min == NULL) && ((*node1).max == NULL)) {
	 if ((*node1).key > key) {
		 (*node1).min = create_root(key,value);
	 }
	 else {(*node1).max = create_root(key, value);}
	 return;
 }
 if (((*node1).max == NULL) && ((*node1).min != NULL)) {
	 if ((*node1).key > key) {
		 add(key, value, (*node1).min);
	 }
	 else {(*node1).max = create_root(key, value);}
	 return;
 }
 if (((*node1).max != NULL) && ((*node1).min == NULL)) {
	 if ((*node1).key < key) {
		 add(key, value, (*node1).max);
	 }
	 else {	(*node1).min = create_root(key, value); }
	 return;
 }
}
//----------------------
int tryfind(int key, node* node1) {
	if ((*node1).key == key) {
		return 1;
	}
	else {
		if (((*node1).min == NULL) && ((*node1).max == NULL)) { return 0; };
		int c = 0;
		if ((*node1).min != NULL) { c=c+tryfind(key, (*node1).min); }
		if ((*node1).max != NULL) { c=c+tryfind(key, (*node1).max); }
		return c;
	}
}

int find(int key, node* node1) {
	if ((*node1).key == key) {
		return(*node1).value;
	}
	else {
		if (((*node1).min == NULL) && ((*node1).max == NULL)) { return 0; };
		int c = 0;
		if ((*node1).min != NULL) {c=c+find(key, (*node1).min); }
		if ((*node1).max != NULL) {c=c+find(key, (*node1).max); }
		return c;
	}
}
//--------------------------
node* findend(node* node1) {
	if (((*node1).min == NULL) && ((*node1).max == NULL)) { return node1; }
	else {
		if ((*node1).min != NULL) {
			return findend((*node1).min);
		}
		else { return findend((*node1).max); };
	}
}

node* remove(int key, node* node1) {
	if ((*node1).key > key) { (*node1).min = remove(key, (*node1).min); }
	else {
		if (key > (*node1).key) { (*node1).max = remove(key, (*node1).max); }
		else {
			if (((*node1).min != NULL) && ((*node1).max != NULL)) {
				(*node1).key = (*findend((*node1).max)).key;
				(*node1).value = (*findend((*node1).max)).value;
				(*node1).max = remove((*node1).key, (*node1).max);
			}
			else {
				if ((*node1).min != NULL) { node1 = (*node1).min; }
				else {
					if ((*node1).max != NULL) { node1 = (*node1).max; }
					else { node1 = NULL; return node1; }
				}
			}
		}
	}
	if ((node1->min == NULL) && (node1->max == NULL)) { return node1; }
}


//---------------------------------------------
void main() {
		node* node1 = create_root(17, 17);
		add(21, 21, node1);
		add(15, 15, node1);
		add(16, 16, node1);
		add(14, 14, node1);
		add(18, 18, node1);
		printf("%d \n", tryfind(12, node1));
		printf("%d \n", find(15, node1));
		remove(17,node1);
		printf("%d \n", tryfind(15, node1));
	}