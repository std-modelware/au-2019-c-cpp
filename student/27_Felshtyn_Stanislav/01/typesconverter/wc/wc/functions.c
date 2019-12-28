#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.c"

int Letter(char c) {
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) && (!EOF) && (!'\n')) {
		return 1;
	}
	else return 0;
}