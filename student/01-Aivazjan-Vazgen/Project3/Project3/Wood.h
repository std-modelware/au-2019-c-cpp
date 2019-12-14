#pragma once

typedef struct l {
	struct l* min;
	struct l* max;
	struct l* predok;
	int value;
	int key;
}l;
l a;


void create_root(int key, int velue);
int tryFind(int key);
int find(int key);
void add(int key, int value);
int remove1(int key);

void printWoods(l* t);