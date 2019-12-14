#include <stdio.h>
#include <stdlib.h>

struct list
{
	int i;
	list* l;
};

struct doblelist
{
	doblelist* d;
	int i;
	doblelist* l;
};

list* creat(int a)
{
	list *nl = malloc(sizeof( list));
	nl->i = a;
	
	return nl;
}



int main()
{
	list l1, l2, l3, l4, l5;
	doblelist d1, d2, d3, d4, d5;
	l1.l = &l2;
	l2.l = &l3;
	l3.l = &l4;
	l4.l = &l5;
	l5.l = NULL;

	d1.l = &d2;
	d2.l = &d3;
	d3.l = &d4;
	d4.l = &d5;
	d5.l = NULL;

	d1.d = NULL;
	d2.d = &d1;
	d3.d = &d2;
	d4.d = &d3;
	d5.d = &d4;
	
	list* a = &l1;
	doblelist* b = &d1;

	int i = 0;
	while (a!=NULL)
	{
		i++;
		(*a).i = i;
		a = (*a).l;
	}
	a = &l1;
	i = 0;
	while (a != NULL)
	{
		i++;
		printf("l%d = %d\n", i, (*a).i);
		a = (*a).l;
	}

	printf("\n");



	i = 0;
	while (b != NULL)
	{
		i++;
		(*b).i = i;
		b = (*b).l;
	}
	b = &d1;
	i = 0;
	while (b != NULL)
	{
		i++;
		printf("d%d = %d\n", i, (*b).i);
		b = (*b).l;

	}
	printf("\n");
	b = &d5;
	while (b != NULL)
	{
		i--;
		printf("d%d = %d\n", i, (*b).i);
		b = (*b).d;

	}
	printf("\n");

}

