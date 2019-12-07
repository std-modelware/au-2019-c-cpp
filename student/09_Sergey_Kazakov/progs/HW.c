#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

//This is the solution for procedure concatenate that concatenates given strings

#define sum(a, b) a  + b

char* concatenate(int num, ...){
    va_list args;
    va_start(args, num);

    char* strings[num];
    int length[num];
    int length_sum = 0;

    int i;
    for(i=0;i<num;i++){
        strings[i] = va_arg(args, char*);
        length[i] = strlen(strings[i]);
        length_sum += length[i];
    }

    char *res = malloc(sizeof(char) * (length_sum + 1));
    int pos = 0;

    for(i=0;i<num;i++){
        memcpy(res + pos, strings[i], length[i]);
        pos += length[i];
    }
    res[length_sum] = '\0';

    return res;
}

int main(){

    char *result = concatenate(3, "abc", " ", "def");
    printf("%s\n", result);
    free(result);

    return 0;
}
