#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void print_argv(int, char**);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Need arguments\n");
        return 1;
    }
    int res = execvp(argv[1], argv+1);
    print_argv(argc, argv);
    printf(": %s\n", strerror(errno));
    return res;
}

void print_argv(int argc, char** argv) {
    printf("%s", argv[1]);
    for (int i = 2; i < argc; i++) {
        printf(" %s", argv[i]);
    }
}
