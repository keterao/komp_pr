#include "str_io.h"
#include <stdio.h>
#include <string.h>

void input_string(char *s, int size) {
    if (fgets(s, size, stdin) == NULL) {
        s[0] = '\0';
        return;
    }
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

void print_string(const char *s) {
    printf("%s\n", s);
}