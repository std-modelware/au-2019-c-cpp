#include <stdio.h>
#include <stdlib.h>
struct step {
	int number;
	struct step *next;
}a, b, c, d;

int main() {
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = NULL;

	a.number = 5;
	b.number = 3;
	c.number = 4;
	d.number = 1;
	step* k1 = &a;
	step* k2 = &a;
	int k = 10;

	for (int i = 0; i < k - 1; i++) {
		if (k2->next == NULL) { printf("ERROR"); return 0; }
		k2 = k2->next;
	}

	while (k2->next != NULL) {
		k1 = k1->next;
		k2 = k2->next;
	}

	printf("%d", (*k1).number);
}