#include <stdio.h>
#include <stdlib.h>
struct step {
	int number;
	struct step *next;
}a, b, c, d;

int recurs(step* w, int n) {
	if (w->next == NULL) { return 1; }
	else {
		int f = 1 + recurs(w->next, n);
		if (f == n) {
			printf("%d", w->number);
			return f;
		}
		return f;
	}
}
int main() {
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = NULL;


	a.number = 5;
	b.number = 3;
	c.number = 4;
	d.number = 1;

	recurs(&a, 4);
}