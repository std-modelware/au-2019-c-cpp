#define _CRT_SECURE_NO_WARNINGS
#include "huffman.h"
#define LEN 255

typedef struct element {
	char symbol;
	int value;
	int bool;
	int code;
	char codechar[20];
	int bbooll;
	struct element* parent;
	struct element* left;
	struct element* right;
} element;

char a[LEN] = { 0 };
int b[LEN] = { 0 };
element* c[LEN];
int ONLY_ONCE = 0;
element* pointer;


void makeCode(element* head) {
	if (ONLY_ONCE < 1) {
		pointer = head;
		ONLY_ONCE++;
	}

	if ((pointer != NULL) && (pointer->bbooll < 1) && (pointer->left != NULL)) {
		pointer = pointer->left;
		pointer->code = head->code;
		pointer->code = pointer->code * 10;
		makeCode(pointer);
		pointer->bbooll++;
		pointer = pointer->parent;
	}

	if ((pointer != NULL) && (pointer->bbooll < 1) && (pointer->right != NULL)) {
		pointer = pointer->right;
		pointer->code = head->code;
		pointer->code = pointer->code * 10 + 1;
		makeCode(pointer);
		pointer->bbooll++;
		pointer = pointer->parent;
	}
}

int readSymbols() {
	FILE* file;
	if ((file = fopen("Text.txt", "r")) == NULL) {
		printf("ERROR: INVALID FILE OPENING");
		return;
	}

	fgets(a, LEN, file);
	fclose(file);

	for (int i = 0; i < LEN; i++) {
		b[(int)a[i]]++;
	}

	b[0] = 0;
	int j = 0;
	for (int i = 0; i < LEN; i++) {
		if (b[i] != 0) {
			element* elem = malloc(sizeof(element));
			elem->symbol = i;
			elem->value = b[i];
			elem->parent = 0;
			elem->bool = 0;
			elem->bbooll = 0;
			elem->left = NULL;
			elem->right = NULL;
			elem->code = NULL;
			c[j] = elem;
			j++;
		}
	}

	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < LEN - 1; j++) {
			if ((c[j] != NULL) && (c[j + 1] != NULL) && (c[j]->value < c[j + 1]->value)) {
				element* tmp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = tmp;
			}
		}
	}
	c;
	element* min2 = malloc(sizeof(element));
	element* min1 = c[0];
	//подсчет количества для последующего ограничения
	int count = 0;
	for (int i = 0; i < LEN; i++) {
		if (c[i] == NULL) {
			break;
		}
		count++;
	}
	for (int j = 0; j < count - 1; j++) {
		for (int i = 0; i < LEN; i++) {
			if ((c[i] != NULL) && (c[i]->bool < 1)) {
				min2 = min1;
				min1 = c[i];
			}
		}

		for (int i = 0; i < LEN; i++) {
			if ((c[i] != NULL) && (c[i]->bool < 1) && (c[i]->value <= min1->value)) {
				min2 = min1;
				min1 = c[i];
			}
		}

		min1->bool = 1;
		min2->bool = 1;
		element* par = malloc(sizeof(element));
		par->value = min1->value + min2->value;
		min1->parent = par;
		min2->parent = par;
		par->left = min2;
		par->right = min1;
		for (int l = 0; l < 255; l++) {
			if (c[l] == NULL) {
				c[l] = par;
				break;
			}
		}
	}

	c;
	min1;
	min2;
	element* head = c[(count - 1) * 2];
	head->code = 2;
	makeCode(head);
	head;

	for (int i = 0; i < count; i++) {
		sprintf(c[i]->codechar, "%d", c[i]->code);
		for (int j = 0; j < 19; j++) {
			c[i]->codechar[j] = c[i]->codechar[j + 1];
		}
	}

	FILE* file2;
	file2 = fopen("Text1.txt", "w");
	for (int i = 0; i < count; i++) {
		fprintf(file, "%c = %s\n", c[i]->symbol, c[i]->codechar);
	}

	//модуль декодера
	FILE* file3;
	FILE* file4;
	if ((file3 = fopen("decodeFrom.txt", "r")) == NULL) {
		printf("ERROR: INVALID FILE OPENING");
		return;
	}

	file4 = fopen("decodeTo.txt", "w");

	char string[LEN] = { 0 };

	for (int i = 0; i < LEN; i++) {
		string[i] = getc(file3);
	}

	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < count; j++) {
			if (!strncmp(string, c[j]->codechar, strlen(c[j]->codechar))) {
				fputc(c[j]->symbol, file4);
				for (int k = 0; k < LEN - 2; k++) {
					string[k] = string[strlen(c[j]->codechar) + k];
				}
			}
		}
	}
}