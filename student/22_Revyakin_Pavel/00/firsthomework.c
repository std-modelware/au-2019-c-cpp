#include<stdio.h>
int main(){
char a ='a';
unsigned char b ='b';
signed char c ='c';
int	d = 46;
unsigned int e =47;
signed int f =48;
short int g =49;
long int k =50;
float n = .11;
double o = 78.5601;
long double p =78.7777;
printf("                 int  unsint unshort unlongint  float   double char\n");
printf("char \t\t");
printf("%4.d\t",a);
printf("%4.u\t",a);
printf("%4.hu\t",a);
printf("%4.lu\t",a);
printf("%4.4f\t",a);
printf("%4.4lf\t",a);
printf("%c\t\n",a);
//111111111111111
printf("uncignedchar \t");
printf("%4.d\t",b);
printf("%4.u\t",b);
printf("%4.hu\t",b);
printf("%4.lu\t",b);
printf("%4.4f\t",b);
printf("%4.4lf\t",b);
printf("%c\t\n",b);
//111111111111111
printf("signedchar \t");
printf("%4.d\t",c);
printf("%4.u\t",c);
printf("%4.hu\t",c);
printf("%4.lu\t",c);
printf("%4.4f\t",c);
printf("%4.4lf\t",c);
printf("%c\t\n",c);
//111111111111111
printf("int\t \t");
printf("%4.d\t",d);
printf("%4.u\t",d);
printf("%4.hu\t",d);
printf("%4.lu\t",d);
printf("%4.4f\t",d);
printf("%4.4lf\t",d);
printf("%c\t\n",d);
//111111111111111
printf("unsignedint \t");
printf("%4.d\t",e);
printf("%4.u\t",e);
printf("%4.hu\t",e);
printf("%4.lu\t",e);
printf("%4.4f\t",e);
printf("%4.4lf\t",e);
printf("%c\t\n",e);
//111111111111111
printf("signedint \t");
printf("%4.d\t",f);
printf("%4.u\t",f);
printf("%4.hu\t",f);
printf("%4.lu\t",f);
printf("%4.4f\t",f);
printf("%4.4lf\t",f);
printf("%c\t\n",f);
//111111111111111
printf("shortint \t");
printf("%4.d\t",g);
printf("%4.u\t",g);
printf("%4.hu\t",g);
printf("%4.lu\t",g);
printf("%4.4f\t",g);
printf("%4.4lf\t",g);
printf("%c\t\n",g);
//111111111111111
printf("longint \t");
printf("%4.d\t",k);
printf("%4.u\t",k);
printf("%4.hu\t",k);
printf("%4.lu\t",k);
printf("%4.4f\t",k);
printf("%4.4lf\t",k);
printf("%c\t\n",k);
//111111111111111
printf("                   int          unsignedint  unsignedshort    unsignedlongint    float  double char\n");
printf("float \t\t");
printf("%4.4d\t",n);
printf("%4.4u\t",n);
printf("%4.4hu\t\t",n);
printf("%4.4lu\t",n);
printf("%4.4f\t",n);
printf("%4.4lf\t",n);
printf("%c\t\n",n);
//111111111111111
printf("double \t\t");
printf("%4.4d\t",o);
printf("%4.4u\t",o);
printf("%4.4hu\t\t",o);
printf("%4.4lu\t",o);
printf("%4.4f\t",o);
printf("%4.4lf\t",o);
printf("%c\t\n",o);
//111111111111111
printf("long double \t");
printf("%4.4d\t\t",p);
printf("%4.4u\t\t",p);
printf("%4.4hu\t\t",p);
printf("%4.4lu\t",p);
printf("%4.4f\t",p);
printf("%4.4lf\t\t",p);
printf("%c\t\n",p);
}
