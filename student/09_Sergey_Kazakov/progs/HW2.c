#include <stdio.h>
#include <string.h>

int main(){

    FILE *file = fopen("output.txt", "w");

    char line[255];
    char c;
    while(1){
        scanf("%[^\n]", &line);
        scanf("%c", &c); /// also scan \n
        if(strcmp(line, "#stoptyping") == 0)
            break;
        fprintf(file, "%s\n", line);
    }


    fclose(file);
    return 0;
}
