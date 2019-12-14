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
	printf("error: file not found");
	return 0;
}

void add(int key, int value)
{
	l* c = malloc(sizeof(l));
	c->key = key;
	c->value = value;
	c->max = NULL;
	c->min = NULL;
	l* d = NULL;
	b = &a;
	while (!((b->max == NULL) && (b->min == NULL))) {
		if (b->key < key)if (b->max != NULL) { d = b; b = b->max; }
		else { b->max = c; }
		if (b->key > key) if (b->min != NULL) { d = b; b = b->min; }
		else { b->min = c;  }
	}
	if (b->key < key)if (b->max != NULL) { d = b; b = b->max; }
	else { d = b; b->max = c; }
	if (b->key > key) if (b->min != NULL) { d = b; b = b->min; }
	else { d = b; b->min = c; }
	c->predok = d;
}
void add_t(l* c)
{
	l* d = NULL;
	b = &a;
	while (!((b->max == NULL) && (b->min == NULL))) {
		if (b->key < c->key)if (b->max != NULL) { d = b; b = b->max; }
		else { b->max = c; }
		if (b->key > c->key) if (b->min != NULL) { d = b; b = b->min; }
		else { b->min = c; }
	}
	if (b->key < c->key)if (b->max != NULL) { d = b; b = b->max; }
	else { d = b; b->max = c; }
	if (b->key > c->key) if (b->min != NULL) { d = b; b = b->min; }
	else { d = b; b->min = c; }
	c->predok = d;

}

l* f;
int  remove1(int key)
{
	f = &a;
	l* d;

	while (f->key != key) {
		if (f->key < key) if (f->max != NULL) { d = f; f = f->max; }
		if (f->key > key) if (f->min != NULL) { d = f; f = f->min; }
		if ((f->max == NULL) && (f->min == NULL)) break;
	}
	if (f->key != key) { printf("ERROR\n"); return 1; }
	d = f->predok;

	if (d->max == f) d->max = NULL;
	if (d->min == f) d->min = NULL;

	if(f->max!=NULL)add_t(f->max);
	if (f->min != NULL)add_t(f->min);
	//free(&f);
}

void printWoods(l* t)
{

	if (t->predok != NULL) printf("Key: %d;  Value: %d; Key predoc: %d \n", t->key, t->value, (t->predok)->key);
	else printf("Key: %d;  Value: %d; Key predoc: NULL \n", t->key, t->value);
	if (t->max != NULL) printWoods(t->max);
	if (t->min != NULL) printWoods(t->min);

}