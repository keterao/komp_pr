#include <stdio.h>
#include <windows.h>
#include "str_io.h"
#include "str_process.h"

#define MAX_LEN 1024

int main(void) {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    char src[MAX_LEN], dst[MAX_LEN];

    printf("Enter string up to '.':\n");
    input_string(src, sizeof(src));

    remove_las(src, dst);

    printf("Result: ");
    print_string(dst);

    return 0;
}