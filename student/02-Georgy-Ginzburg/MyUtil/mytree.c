#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int RECURSION_LEVEL;
int SHOW_HIDDEN;

void show_help() {
    printf("%s", "Usage: ./mytree [OPTIONS]... [ROOT DIRECTORY]\n\n"
                 "-h            Help\n"
                 "-a            Show dotfiles\n"
                 "-r            Max display depth of directory tree\n");
}

void tree_output(char *initial_path, const int level) {
    struct dirent *dp;
    char path[1000];
    DIR *current_dir = opendir(initial_path);

    if (!current_dir || (level == RECURSION_LEVEL * 2 && RECURSION_LEVEL != 0)) {
        return;
    }


    while ((dp = readdir(current_dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            if (dp->d_name[0] == '.' && !SHOW_HIDDEN) {
                continue;
            }
            for (int i = 0; i < level; i++) {
                if (i % 2 == 0 || i == 0)
                    printf("%c", '|');
                else
                    printf(" ");

            }


            printf("%c%c%s\n", '~', '~', dp->d_name);

            strcpy(path, initial_path);
            strcat(path, "/");
            strcat(path, dp->d_name);
            tree_output(path, level + 2);
        }
    }

    closedir(current_dir);
}

int main(int argc, char *argv[]) {

    int opt;
    char *ptr;
    while ((opt = getopt(argc, argv, "hr:a")) != -1) {
        switch (opt) {
            case 'h':
                show_help();
                return 0;
            case 'r':
                RECURSION_LEVEL = (int) strtol(optarg, &ptr, 10);
                break;

            case 'a':
                SHOW_HIDDEN = 1;
                break;
        }
    }

    char *dir_path = argv[argc - 1];

    DIR *relative_root = opendir(dir_path);
    if (relative_root == NULL) {
        perror("Cannot find directory\n");
        exit(-1);
    }

    tree_output(dir_path, 0);
    return 0;
}
