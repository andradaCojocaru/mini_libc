#include <stdio.h>	
#include <unistd.h>

int putchar(char c) {
    if (write(1, &c, 1) != 1) {
        return -1;
    }
    return c;
}

int puts(const char *s) {
    int num = 0;
    while (*s != '\0') {
        putchar(*s);
        s++;
        num++;
    }
    putchar('\n');
    num++;
    return num;
}