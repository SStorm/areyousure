#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

const wchar_t warning_emoji = 0x1f62e;
const wchar_t thinking_emoji = 0x1f914;
const wchar_t thumbsup_emoji = 0x1f44d;
const wchar_t hand_right_emoji = 0x1f449;

//Regular text
#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"
#define RESETC "\033[0m"

void print_usage();
void print_argv(int, int, char**);

int main(int argc, char** argv) {
    int command_position = 1;
    if (argc < 2) {
        print_usage();
        return 1;
    }

    setlocale(LC_CTYPE,"en_US.UTF-8");

    printf("%lc "RED"DANGER"RESETC". You are about to execute: \n\n%lc "YEL, warning_emoji, hand_right_emoji);
    print_argv(command_position, argc, argv);
    printf(RESETC"\n\n");
    printf("%lc Are you sure? [Yy] ", thinking_emoji);
    int c = getchar();
    if (c != 'Y' && c != 'y') {
        printf("%lc Stopping\n", thumbsup_emoji);
        return 1;
    }

    int res = execvp(argv[command_position], argv+command_position);
    print_argv(command_position, argc, argv);
    printf(": %s\n", strerror(errno));
    return res;
}

void print_usage() {
    printf("Usage: areyousure [OPTION] command ...\n\n");
    printf("Prompt the user whether they really want to run the given command.\n\n");
}

void print_argv(int command_pos, int argc, char** argv) {
    printf("%s", argv[command_pos]);
    for (int i = command_pos + 1; i < argc; i++) {
        printf(" %s", argv[i]);
    }
}
