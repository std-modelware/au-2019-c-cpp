

#include <stdio.h>
#include "Wood.h"


void main() {
	//int key, velue;
	//scanf("%d %d", &key, &velue);
	create_root(10, 2);
	
	add(20, 1);
	add(15, 6);
	add(3, 90);
	add(2, 8);
	add(22, 111);
	add(30, 12);
	add(25, 16);
	add(26, 1);
	add(201, 1);
	add(200, 1);
	printWoods(&a);
	printf("\nKey 200: Value %d\nKey 22: Value %d\nKey 25: Value %d\nKey 30: Value %d\n\n", tryFind(200), tryFind(22), tryFind(25), tryFind(30));
	
	remove1(3);
	printWoods(&a);

	printf("\n");

	remove1(30);
	printWoods(&a);
	
	//add(0, 0);

}