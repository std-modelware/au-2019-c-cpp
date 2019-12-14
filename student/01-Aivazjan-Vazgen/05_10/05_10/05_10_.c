#include <stdio.h>
#include <stdlib.h>

const int L = 5;
const int D = 5;
typedef struct list
{
	int i;
	struct list* l;
}list;

typedef struct doblelist
{
	struct doblelist* d;
	int i;
	struct doblelist* l;
}doblelist;

list* creatl(int a)
{
	list* nl = malloc(sizeof(list));
	nl->i = a;
	nl->l = NULL;
	return nl;
}

doblelist* creatd(doblelist* d, int a)
{
	doblelist* nd = malloc(sizeof(doblelist));
	nd->i = a;
	nd->l = NULL;
	nd->d = d;
	return nd;
}


void main()
{
	list* start, *step;
	start = creatl(0);
	step = creatl(1);
	start->l = step;
	for (int i = 2; i < L+1; i++) 
	{
		step->l = creatl(i);
		step = step->l;
	}
	printf("list: ");
	while (start->l != NULL) {
		start = start->l;
		printf("%d ", start->i);
		
	}
	printf("\n");





	doblelist* dstart, * dstep;
	dstart = creatd(NULL, 0);
	dstep = creatd(dstart, 1);
	dstart->l = dstep;
	for (int i = 2; i < D + 1; i++)
	{
		dstep->l = creatd(dstep, i);
		dstep = dstep->l;
	}
	printf("doblelist: ");
	while (dstart->l != NULL) {
		dstart = dstart->l;
		printf("%d ", dstart->i);
		
	}
	printf("\n");
	printf("doblelist: ");
	while (dstart->d != NULL) {
		
		printf("%d ", dstart->i);
		dstart = dstart->d;
		
	}
	printf("\n");



}