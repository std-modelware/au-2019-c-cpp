#include "binheap.h"

int main()
{
	binheap_init(30, 777);
	binheap_insert(123);
	binheap_insert(555);
	binheap_insert(321);
	binheap_insert(4);
	binheap_insert(51);
	binheap_insert(9991);
	binheap_insert(812);

	binheap_print();

	return 0;
}