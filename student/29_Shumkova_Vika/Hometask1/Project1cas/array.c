#include <stdio.h>

void main() {
	printf("array\n");
	int ia1[3];

	int ia2[] = { 0,1,2 };

	//int ia3[] = { 0,1,2,3,4 };

	int ia4[] = { 15,16 };
	int ia5[3];

	//for (int i = 0; i < 10; i = i + 1) {
		//ia5[i]  = i;
	//}

	// ---------------
	printf("hello\n");
	char hello[] = { 'h', 'e', 'l', 'l', 'o', '\n',0 };
	printf("%s", hello);

	// многомерные массивы
	char matrix[3][3] = {
		{1,2,3},
	    {4,5,6},
	    {7,8,9}
	};

	printf("%d\n", matrix[1][2]);

	printf("array\n");
}