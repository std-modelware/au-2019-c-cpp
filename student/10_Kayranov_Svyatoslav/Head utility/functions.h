int exists(const char *fname) {
    FILE *file;
    if ((file = fopen(fname, "r"))) {
        fclose(file);
        return 1;
    }
    return 0;
}
int strncmp(const char *__s1, const char *__s2, size_t __n) {
    bool flag = 0;
    for (int i = 0; i < __n; i++) {
        if (__s1[i] != __s2[i]) flag = 1;
    }
    return(flag);
}