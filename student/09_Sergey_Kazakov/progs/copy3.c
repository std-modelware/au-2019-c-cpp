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

    fseek(to_copy, 0, SEEK_END);
    long in_size = ftell(to_copy);
    rewind(to_copy);

    char buffer[10];

    int result;
    do{
        result = fread(buffer, 1, sizeof(buffer), to_copy);
        fwrite(buffer, 1, result, to_create);
    } while( result > 0 );

    fclose(to_copy);
    fclose(to_create);

    return 0;
}
