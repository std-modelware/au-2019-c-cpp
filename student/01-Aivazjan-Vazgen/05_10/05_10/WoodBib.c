#include <stdio.h>
#include "Wood.h"

void create_root(int key, int velue)
{
	a.key = key;
	a.value = velue;
	a.predok = NULL;
	a.max = NULL;
	a.min = NULL;
}

l* b;
int tryFind(int key) 
{
	b = &a;
	return find(key);
}

int find(int key)
{
	if (b->key == key) return b->value;
	if ((b->max != NULL) && (b->key < key)) {
		b = b->max;
		return find(key);
	}
	if ((b->min != NULL) && (b->key > key)) {
		b = b->min;
		return find(key);
	}
	print("error: file not found");
	return 0;
}

void add(int key, int value)
{
	l* c = malloc(sizeof(l));
	l* d = NULL;
	b = &a;
	while ((b->max == NULL) && (b->min == NULL)) {
		if (b->key < key)if (b->max != NULL) { d = b; b = b->max; }
		else b->max = c;
		if (b->key > key) if (b->min != NULL) { d = b; b = b->min; }
		else b->min = c;
	}
	b->predok = d;
}

/*
void remove(int key)
{
	b = &a;
	l* d;

	while (b->key != key) {
		if (b->key < key) { d = b; b = b->max; }
		if (b->key > key) { d = b; b = b->min; }
		if ((b->max == NULL) && (b->min == NULL)) break;
	}

}
*/
void printWoods(l* t)
{
	
	if (t->predok != NULL) printf("Key: %d;  Value: %d; Key predoc: %d /n", t->key, t->value, (t->predok)->key);
	else printf("Key: %d;  Value: %d; Key predoc: NULL /n", t->key, t->value);
	if (t->max != NULL) printWoods(t->max);
	if (t->min != NULL) printWoods(t->min);

}

