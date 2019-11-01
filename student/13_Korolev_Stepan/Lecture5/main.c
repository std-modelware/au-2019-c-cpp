#include <stdio.h>
#include "average.h"
#include "filesys.h"

int main() {
	printf("%f\n", average(5, 4, 9, 14, 20, 11));
	createfile("Myfile.txt");
	c_copyfile("Myfile.txt", "Copy_Myfile.txt");
	s_copyfile("Myfile.txt", "Copy2_Myfile.txt");
	f_copyfile("Myfile.txt", "Copy3_Myfile.txt");
}