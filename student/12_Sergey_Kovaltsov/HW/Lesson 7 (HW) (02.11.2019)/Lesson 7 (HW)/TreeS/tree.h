#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef enum BOOLEAN {
	B_FALSE,
	B_TRUE
}bool;

typedef struct node {
	int value;
	int key;
	struct node* left;
	struct node* right;
	struct node* parent;
}node;



node* create_node();
void get_last_error();
void create_root(int key, int value);


void add(int key, int value);

int find(int key);

int remove(int key);
