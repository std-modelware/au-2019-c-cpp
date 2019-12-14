/*#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void head(int n) {

	FILE* katya888;
	char* assgard = (char*)malloc(128);
	scanf("%s", assgard);
	char u;
	u = 'a';

	katya888 = fopen(assgard, 'r');
	for (int i = 0; i < n; i++)
	{
		while (u != '\n') {
			fscanf(katya888, "%c", &u);
			printf("%c", u);
		}

	}
}

void main() {
	/*int a;
	scanf("%d", &a);*//*
	head(2);

}*/