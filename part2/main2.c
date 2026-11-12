#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024

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

/* Проверяем, начинается ли слово с A, D, X или P (английские, заглавные) */
static int starts_with_required(const char *word) {
    char c = word[0];
    return (c == 'A' || c == 'D' || c == 'X' || c == 'P');
}

void filter_words(const char *src, char *dst) {
    dst[0] = '\0';
    const char *p = src;
    int first = 1;

    while (*p && *p != '.') {
        /* пропускаем пробелы */
        while (*p == ' ' || *p == '\t') {
            ++p;
        }
        if (*p == '\0' || *p == '.') {
            break;
        }

        const char *start = p;
        while (*p && *p != ' ' && *p != '\t' && *p != '.') {
            ++p;
        }

        size_t len = (size_t)(p - start);
        char word[256];
        if (len >= sizeof(word)) {
            len = sizeof(word) - 1;
        }
        memcpy(word, start, len);
        word[len] = '\0';

        if (starts_with_required(word)) {
            if (!first) {
                strcat(dst, " ");
            }
            strcat(dst, word);
            first = 0;
        }
    }
}

int main(void) {
    char src[MAX_LEN], dst[MAX_LEN];

    printf("Enter string up to '.':\n");
    input_string(src, sizeof(src));

    filter_words(src, dst);

    printf("Result: ");
    print_string(dst);

    return 0;
}