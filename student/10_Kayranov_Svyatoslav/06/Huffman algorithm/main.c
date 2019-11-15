// C program for Huffman Coding 
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>

int maxCount = 0;
int count;
int i;
char c;
char a[255];

int main(void){
    //обнуление массива
    for (i = 0; i < 255; i++) a[i] = 0;
    
    //считывание и подсчет букв
    while ((c = getchar()) != '\n') {
		a[(int)c] += 1;
	}

    //печать полученного массива
    for (i = 65; i < 122; i++) {
        printf("%c - %d\n", i, a[i]);
    }

    //количество различных букв
    for (i = 0; i < 255; i++) {
        if (a[i] > 0) count++;
    }

    printf("count = %d\n", count);

    //максимальное количество повторений одной буквы 
    for (i = 0; i < 255; i++) {
        if (a[i] > maxCount) maxCount = a[i];
    }

    printf("maxCount = %d\n", maxCount);
    
    //создание нового массива
    char b[count+1][count];

    int pointer = 0;
    for (i = 65; i < 122; i++) {
        if (a[i] > 0) {
            b[0][pointer] = i;
            b[1][pointer] = a[i];
            pointer++;
        }
    }

    //печать нового массива
    for (i = 0; i < count; i++) {
        printf("%c - %d\n", (char)b[0][i], b[1][i]);
    }

    //поиск минимумов
    int j;
    int min0 = maxCount;
    int min1 = maxCount;
    int summOfMins = 0;
    int min1Element = 0;
    int min0Element = 0;
    for (j = 1; j < count; j++) {
        printf("%s %d\n", "Итерация по j = ", j);
        for (i = 0; i < count; i++) {
            if ((b[j][i] <= min0) && (b[j][i] > 0)) {
                min1Element = min0Element;
                min0Element = i;
                min1 = min0;
                min0 = b[j][i];
                summOfMins = min0 + min1;
                printf("(%s = %d)\n ", "min0", min0);
                printf("(%s = %d)\n ", "min1", min1);
            }
        }
        
        for (i = 0; i < count; i++){
            b[j+1][i] = b[j][i];
            if (i == min1Element) b[j+1][i] = 0;
            if (i == min0Element) b[j+1][i] = summOfMins;
        }

        min1Element = 0;
        summOfMins = 0;
        min0Element = 0;
        int min0 = INT_MAX;
        int min1 = INT_MAX;

        //распечатка массива
        printf("(%s = %d) ", "summOfMins", summOfMins);
        printf("(%s = %d) ", "min0", min0);
        printf("(%s = %d) ", "min1", min1);
        for (i = 0; i < count; i++){
            printf("%d ", b[j][i]);
        }
        printf("\n");
        //конец распечатки

//        if (min1 == 0) break;
    }
}
