﻿#include <stdio.h>

int mod(int a, int b)
{
	return (a - ((a / b) * b) > 0 ? a - ((a / b) * b) : a - ((a / b) * b) + (b > 0 ? b : -b));
}

int main()
{
	printf("C-like style:\n27 %% 4 = %d\n-15 %% 4 = %d\n113 %% 3 = %d\n-15 %% -7 = %d\n15 %% -7: %d\n\n", 27 % 4, -15 % 4, 113 % 3, -15 % -7, 15 % -7);
	printf("Maths-like style:\n27 %% 4 = %d\n-15 %% 4 = %d\n113 %% 3 = %d\n-15 %% -7 = %d\n15 %% -7: %d\n", mod(27, 4), mod(-15, 4), mod(113, 3), mod(-15, -7), mod(15, -7)); //mod(15, -7) это дополнительная проверка
}