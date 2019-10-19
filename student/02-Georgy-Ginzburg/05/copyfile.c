#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1000

void NewFile(char *argv[]) {
    FILE *fptr = fopen(argv[2], "w");
    fprintf(fptr, "%s", argv[3]);
    fclose(fptr);
}

void SymbolWiseCopy(char *argv[]) {
    FILE *fFrom = fopen(argv[2], "r");
    FILE *fTo = fopen(argv[3], "w");
    int c;
    while (1) {
        c = fgetc(fFrom);
        if (feof(fFrom)) {
            break;
        }
        fputc(c, fTo);
    }
    fclose(fTo);
    fclose(fFrom);
}

void StringWiseCopy(char *argv[]) {
    FILE *fFrom = fopen(argv[2], "r");
    FILE *fTo = fopen(argv[3], "w");
    char chunk[128];
    while (fgets(chunk, sizeof(chunk), fFrom) != NULL) {
        fputs(chunk, fTo);
    }
    fclose(fTo);
    fclose(fFrom);
}

void FullCopy(char *argv[]) {
    FILE *fFrom = fopen(argv[2], "r");
    FILE *fTo = fopen(argv[3], "w");
    char buffer[BUFFER_SIZE];
    fread(buffer, BUFFER_SIZE, 1, fFrom);
    fwrite(buffer, strlen(buffer) - 1, 1, fTo);
    fclose(fTo);
    fclose(fFrom);
}

void ShowHelp() {
    printf("%s", "Usage: ./copyfile [OPTION] [FILE TO COPY FROM] [FILE TO COPY TO]\n\n"
                 "-h            Help\n"
                 "-n            Create new file and write CLI contents\n"
                 "-s            Copy a file symbol-wise\n"
                 "-g            Copy a file string-wise\n"
                 "-f            Make a full copy of a file\n");
}

int main(int argc, char *argv[]) {

    int opt;

    while ((opt = getopt(argc, argv, "hnsgf")) != -1) { //new, symbol-wise, line-wise, full
        switch (opt) {
            case 'h':
                ShowHelp();
                break;
            case 'n':
                NewFile(argv);
                break;
            case 's':
                SymbolWiseCopy(argv);
                break;
            case 'g':
                StringWiseCopy(argv);
                break;
            case 'f':
                FullCopy(argv);
                break;
        }
    }
    return 0;
}

