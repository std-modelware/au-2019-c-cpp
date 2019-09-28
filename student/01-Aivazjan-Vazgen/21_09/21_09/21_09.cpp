#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//ввод делимого
int read_dividend() {
	int a;
	printf("Enter the dividend: ");
	scanf("%d", &a);
	return a;
}

//ввод делителя
int read_divider() {
	int a;
	printf("Enter the divider: ");
	scanf("%d", &a);
	return a;
}

// деление с остатком
// a-делимое  b-делитель
int mod(int a, int b) {
	int c = a % b;
	if (c < 0) if (b > 0) c += b; else c -= b;
	return (c);
}

// целая часть от деления
// a-делимое  b-делитель
/*int div(int a, int b) {
	return (a / b);
}
*/
//вывод результата
void write_result(int a, int b) {
	printf("Whole part: %d\n", a);
	printf("Remainder: %d\n", b);
	printf("\n");
}

void work_cycle() {
	int a; int b;
	while (true)
	{
		a = read_dividend();
		b = read_divider();
		if (b != 0) write_result(a / b, mod(a,b));
		else
		{
			printf("Error \"Zero can't be a divisor\"");
			break;
		}
	}
}


int main()
{
	work_cycle();
	return 0;
}
