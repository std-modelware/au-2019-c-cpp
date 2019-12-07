#include <stdio.h>

void main() {
	printf("preprocessor\n");

#define LINE "---------------------\n"

	printf(LINE);

#ifdef MYDEFINE
	printf("MYDEFINE\n");
#else
	printf("NOT MYDEFINE\n");
#endif

#undef MYDEFINE

#ifdef MYDEFINE
	printf("MYDEFINE\n");
#else
	printf("NOT MYDEFINE\n");
#endif

	printf("preprocessor\n");
}