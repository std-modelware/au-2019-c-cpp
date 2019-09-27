#include<stdio.h>

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
		if(a<0){
		a=-a;
	}
	while(a>=b){
     a-=b;
	}
	printf("%d",a);
	return 0;
}
