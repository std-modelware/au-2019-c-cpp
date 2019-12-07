#include <stdio.h>

void main() {
	printf("structure\n");

	struct MyStruct {
		int i;
		float f;
		char c;
	} v1;

	struct MyStruct v2;

	typedef struct MyStruct MS;
	MS v3;

	v1.c = 'a';
	v1.f = 1.23f;
	v1.i = 15;

	struct MyStruct2 {
		MS s1;
		MS s2;
		int i1;
	} vs2;


	union MyUnion {
		int i;
		float f;
		char c;
	} u1;

	u1.c = 'f';
	u1.i = 45;
	u1.f = 12.45f;

	printf("%d %d %d\n", sizeof(int), sizeof(char), sizeof(float));
	printf("%d\n", sizeof(struct MyStruct));
	printf("%d\n", sizeof(union MyUnion));
	printf("structure\n");

}