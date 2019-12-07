#include <stdio.h>

void row_print(char type[], void *var) {
    char *char1 = (char *) var;
    int *int1 = (int *) var;
    float *float1 = (float *) var;
    double *double1 = (double *) var;
    signed char *schar1 = (signed char *) var;
    unsigned char *uschar1 = (unsigned char *) var;
    short int *shi1 = (short int *) var;
    long int *li1 = (long int *) var;
    printf("%s:\t%18c\t%20i\t%25.2f\t%20.2f\t%15c\t%18c\t%18i\t%25li\n", type, *char1, *int1, *float1, *double1,
           *schar1, *uschar1, *shi1, *li1);
}

int main() {

    printf("============ \t%12s\t%16s\t%25s\t%22s\t%16s\t%16s\t%16s\t%16s\n", "char", "int", "float", "double",
           "s_char", "u_char", "s_int", "l_int");

    char c = 'a';
    row_print("char", &c);
    int i = 97;
    row_print("int", &i);
    float f = 97.1;
    row_print("float", &f);
    double d = 97.11;
    row_print("double", &d);
    signed char sc = -127;
    row_print("s_char", &sc);
    unsigned char uc = 255;
    row_print("u_char", &uc);
    short int shi = 1;
    row_print("s_int", &shi);
    long int li = 1;
    row_print("l_int", &li);
}
