#include<stdio.h>
int main(){
    char c ='a';
    unsigned char uc ='a';
    signed char sc ='a';
    int	i = -1;
    unsigned int ui = 47;
    signed int si = 47;
    short int shi = 47;
    long int li = 47;
    float f = 0.01;
    double d = 1.1111;
    long double ld = 1.1111;

    printf("\t\t  int\tuni\tusi\tuli\tfloat\tdouble\tchar\n");

    printf("int\t \t");
    printf("%4.d\t", i);
    printf("%4.u\t", i);
    printf("%4.hu\t", i);
    printf("%4.lu\t", i);
    printf("%4.4f\t", i);
    printf("%4.4lf\t", i);
    printf("%c\t\n", i);

    printf("unsint \t\t");
    printf("%4.d\t", ui);
    printf("%4.u\t", ui);
    printf("%4.hu\t", ui);
    printf("%4.lu\t", ui);
    printf("%4.4f\t", ui);
    printf("%4.4lf\t", ui);
    printf("%c\t\n", ui);

    printf("sigint \t\t");
    printf("%4.d\t", si);
    printf("%4.u\t", si);
    printf("%4.hu\t", si);
    printf("%4.lu\t", si);
    printf("%4.4f\t", si);
    printf("%4.4lf\t", si);
    printf("%c\t\n", si);

    printf("shint \t\t");
    printf("%4.d\t", shi);
    printf("%4.u\t", shi);
    printf("%4.hu\t", shi);
    printf("%4.lu\t", shi);
    printf("%4.4f\t", shi);
    printf("%4.4lf\t", shi);
    printf("%c\t\n", shi);

    printf("lint \t\t");
    printf("%4.d\t", li);
    printf("%4.u\t", li);
    printf("%4.hu\t", li);
    printf("%4.lu\t", li);
    printf("%4.4f\t", li);
    printf("%4.4lf\t", li);
    printf("%c\t\n", li);

    printf("char \t\t");
    printf("%4.d\t", c);
    printf("%4.u\t", c);
    printf("%4.hu\t", c);
    printf("%4.lu\t", c);
    printf("%4.4f\t", c);
    printf("%4.4lf\t", c);
    printf("%c\t\n", c);

    printf("unschar \t");
    printf("%4.d\t", uc);
    printf("%4.u\t", uc);
    printf("%4.hu\t", uc);
    printf("%4.lu\t", uc);
    printf("%4.4f\t", uc);
    printf("%4.4lf\t", uc);
    printf("%c\t\n", uc);

    printf("sigchar \t");
    printf("%4.d\t", sc);
    printf("%4.u\t", sc);
    printf("%4.hu\t", sc);
    printf("%4.lu\t", sc);
    printf("%4.4f\t", sc);
    printf("%4.4lf\t", sc);
    printf("%c\t\n", sc);

    printf("float \t\t");
    printf("%4.4d\t", f);
    printf("%4.4u\t", f);
    printf("%4.4hu\t", f);
    printf("%4.4lu\t", f);
    printf("%4.4f\t", f);
    printf("%4.4lf\t", f);
    printf("%c\t\n", f);

    printf("double \t\t");
    printf("%4.4d\t", d);
    printf("%4.4u\t", d);
    printf("%4.4hu\t", d);
    printf("%4.4lu\t", d);
    printf("%4.4f\t", d);
    printf("%4.4lf\t", d);
    printf("%c\t\n", d);

    printf("ldouble \t");
    printf("%4.4d\t", ld);
    printf("%4.4u\t", ld);
    printf("%4.4hu\t", ld);
    printf("%4.4lu\t", ld);
    printf("%4.4f\t", ld);
    printf("%4.4lf\t", ld);
    printf("%c\t\n", ld);
}