#include <stdio.h>

void main() {
	printf("prepro\n");

#define LINE "----------\n"

	printf(LINE);

#undef mydefine

#ifdef mydefine
	printf("mydefine\n");
#else
	printf(medefine\n);
#endif
	printf("prepro\n");
}