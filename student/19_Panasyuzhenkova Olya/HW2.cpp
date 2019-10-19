#include <stdio.h>

void main(void)
	{
	int c;
	int d;
	int l;
	int a;
    printf ("Enter a: "); 
	scanf_s("%d",&a);

	int b;
	printf("Enter b: ");
	scanf_s("%d", &b);

	

	if ((b) > 0) { printf("Result = %d\n", ((a%b) + b) % b); }
	else if ((a>0)&&(b>0)) printf("Result = %d\n", a%b) ;

	if ((a > 0) && (b < 0)) {		// > <
		c = a / b;
		if ((b * c == a)) {
			printf("%d", 0);
		}
		else {
			d = b * c;
			l = a - d;
			printf("Result = %d\n", l);
		}
	}

	if ((a < 0) && (b < 0)) {		// < <
		c = a / b;
		if ((b * c == a)) {
			printf("%d", 0);
		}
		else {
			c++;
			d = b * c;
			l = a - d;
			printf("Result = %d\n", l);
		}
	}
	
	//if ((a < 0)&(b < 0)) { printf("Result = %d\n", (abs((b%a) + a) % a)); }
 
	}