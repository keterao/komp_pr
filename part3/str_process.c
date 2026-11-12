#include "str_process.h"
#include <string.h>

void remove_las(const char *src, char *dst) {
    const char *pat = "лас";
    size_t plen = strlen(pat);
    const char *p = src;
    char *d = dst;

    while (*p && *p != '.') {
        if (strncmp(p, pat, plen) == 0) {
            p += plen;
        } else {
            *d++ = *p++;
        }
    }

    if (*p == '.') {
        *d++ = *p++;
    }
    *d = '\0';
}