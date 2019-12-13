#include <stdio.h>
#include <stdlib.h>
#include "./struct.h"

void main(int argc,char*argv[]) {
	if (argv[1][1] == 'n') {
		char* q = argv[3];
		int d = count_lines(q);
		int z = atoi(argv[2]);
		print_lines(z,d);
	}
	if (argv[1][1] == 'c') {
		char* q = argv[3];
		int d = count_bites(q);
		int z = atoi(argv[2]);
		print_bites(z, d);
	}
}
