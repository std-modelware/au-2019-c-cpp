#define N 10
#include <stdlib.h>
#include <stdio.h>

int main()
{
	struct Mt {
		int i;
		struct Mt* next;
	};

	struct Mt myarray[N];
	int j = N - 1;
	struct Mt a = { j, NULL };
	myarray[j] = a;

	while (j > 0)
	{
		struct Mt _a;
		_a.next = &myarray[j];
		_a.i = --j;
		myarray[j] = _a;
		
	}

	printf("1-linked structure:\n\n");

	for (struct Mt* _tmp = &myarray[0]; _tmp != NULL; _tmp = (*_tmp).next) {
		printf("%d\n", (*_tmp).i);
	}

	struct Mt2 {
		int i;
		struct Mt2* next;
		struct Mt2* past;
	};

	struct Mt2 _myarray[N];
	j = N - 1;
	struct Mt2 _a = { j, NULL, NULL};
	_myarray[j] = _a;

	while (j > 0)
	{
		struct Mt2 __a;
		__a.next = &_myarray[j];
		__a.i = --j;
		__a.past = NULL;
		_myarray[j] = __a;
		_myarray[j + 1].past = &_myarray[j];
	}

	printf("\n2-linked structure, upto:\n\n");

	for (struct Mt2* _tmp = &_myarray[0]; _tmp != NULL; _tmp = (*_tmp).next) {
		printf("%d\n", (*_tmp).i);
	}

	printf("\n2-linked structure, downto:\n\n");

	for (struct Mt2* _tmp = &_myarray[N-1]; _tmp != NULL; _tmp = (*_tmp).past) {
		printf("%d\n", (*_tmp).i);
	}

	return 0;
}