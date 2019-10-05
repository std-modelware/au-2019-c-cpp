#include<stdio.h>

int a,b;

int main(){
	scanf("%d %d", &a, &b);
	if(a < 0){
		a =-a;
	}
	if(b < 0){
	    b =-b;
	}
	while(a >= b){
        a -= b;
	}
	printf("%d", a);
}