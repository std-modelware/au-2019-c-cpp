#include <stdio.h>

void main() {

	struct link {
		int i;
		struct link *next;
	} m1, m2, m3;

	m1.i = 1;
	m1.next = &m2;

	m2.i = 2;
	m2.next = &m3;

	m3.i = 3;
	m3.next = NULL;

	// 1
	struct link m;
	m.i = 0;
	m.next = &m1;

	while (m.next != NULL) {
		m.i = (*m.next).i;
		m.next = m.next->next;
		printf("%d ", m.i);
	}
	printf("\n");
	printf("\n");

	// 2
	struct link *p = &m1;

	while (p != NULL) {
		printf("%d ", (*p).i);
		p = (*p).next;
	}
	printf("\n");

}