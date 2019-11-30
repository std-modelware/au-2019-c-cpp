#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int key;
	int value;
	struct element* left;
	struct element* right;
} element;

void create_root(int key, int value);

//int tryFind(int key); // return 0 - поиск не удачен, 1 - удачи

int find(int key); // return value

int add(int key, int value);

int removeElem(int key);

int addElem(element* element);
