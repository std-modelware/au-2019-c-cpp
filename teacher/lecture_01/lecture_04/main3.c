#include <stdio.h>

void main() {
	printf("list\n");

	struct Mt {
		int i;
		char a;
		struct Mt *next;
	} m1, m2, m3, m4;

	m1.i = 1;
	m1.a = 'a';
	m1.next = &m2;

	m2.i = 2;
	m2.a = 'b';
	m2.next = &m3;

	m3.i = 3;
	m3.a = 'c';
	m3.next = &m4;

	m4.i = 4;
	m4.a = 'd';
	m4.next = NULL;

	for (struct Mt *_tmp = &m1; _tmp != NULL; _tmp = (*_tmp).next) {
		printf("%d %c\n", (*_tmp).i, (*_tmp).a);
	}

	printf("list\n");
}