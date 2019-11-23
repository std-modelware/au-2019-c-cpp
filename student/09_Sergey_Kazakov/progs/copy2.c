#include <stdio.h>

int main(int argc, char **argv){
    if(argc < 3){
        printf("Usage: copy.exe file_to_copy new_file_name\n");
        return 0;
    }

    FILE *to_copy = fopen(argv[1], "r");
    if(!to_copy){
        printf("ERROR: Cannot open file to copy\n");
        return 0;
    }
    FILE *to_create = fopen(argv[2], "w");
    if(!to_copy){
        printf("ERROR: Cannot create file\n");
        return 0;
    }

    while(!feof(to_copy)){
        char line[255];
        fgets(line, sizeof(line), to_copy);
        fputs(line, to_create);
    }

    fclose(to_copy);
    fclose(to_create);

    return 0;
}


