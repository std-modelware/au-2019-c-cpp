#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
typedef struct vertex{
	int f;
	vertex* anc;
	vertex* left;
	vertex* right;
}vertex; 
vertex CHAR[65535];

void zero() {
	for (int i = 0; i < 256; i++) {
		CHAR[i].f = 0;
		CHAR[i].left = NULL;
		CHAR[i].anc = NULL;
		CHAR[i].right = NULL;
	}
}
vertex* min(vertex* t) {
	vertex* v;
	int i = 0;
	for (; CHAR[i].anc != NULL; i++) {
		;
	}
	v = &CHAR[i];

}

int freq() {
	zero();
	FILE* f = NULL;
	f = fopen("h.txt", "r");
	if (f == NULL) {
		printf("Error: file not open\n");
		return 1;
	}
	char c;
	while (fread(&c, sizeof(char), 1, f) == 1) {
		(CHAR[c].f)++;
	}
}
 
void main() {
	freq();
}