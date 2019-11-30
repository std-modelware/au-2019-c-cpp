#include <stdio.h>
#include "binary_tree.h"

int main() {
	/*
	create_root(10, 100);
	add(15, 10);
	add(7, 11);
	add(16, 12);
	find(16);
	add(17, 13);
	find(17);
	add(5, 14);
	find(5);
	add(8, 15);
	find(8);
	find(16);
	remove(16);
	find(8);
	*/

	create_root(20, 1);
	add(15, 2);
	add(25, 3);
	add(10, 4);
	add(17, 5);
	add(21, 6);
	add(30, 7);
	add(5, 8);
	add(16, 9);
	add(19, 10);
	add(40, 11);
	add(1, 12);
	add(1, 12);
	add(17, 5);
	add(30, 7);
	add(17, 5);
	add(30, 7);
	add(17, 5);
	add(30, 7);
	add(5, 8);
	add(19, 6);
	find(19);
	find(15);
	find(222);
	removeElem(15);
	find(15);
	find(17);
	find(19);
	find(10);

	//	removeElem(15);
	//	find(15);

	return 0;
}