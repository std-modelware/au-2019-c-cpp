#include <stdio.h>

void main() {
	printf("structure\n");

	struct MyStruct {
		int i;
		float f;
		char c;
	} v1;

	v1.c = 'a';
	v1.f = 1.1f;
	v1.i = 126;

	struct MyStruct v2;

	typedef struct MyStruct MS;
	MS v3;


	struct MyStruct2 {
		MS s1;
		MS s2;
		int d;
	} ms2;





	union MyUnion {
		int i;
		float f;
		char c;
	} u1;

	printf("1: %d %d %d\n", sizeof(int), sizeof(float), sizeof(char)); // 4 4 1
	printf("2: %d\n", sizeof(struct MyStruct)); // 9 
	printf("3: %d\n", sizeof(union MyUnion)); // 4

	u1.c = '1';
	u1.i = 65;
	u1.f = 12.3f;

	printf("structure\n");
}