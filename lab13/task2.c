#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void help(void) {
    printf("Доступные команды: help, clear, exit\n");
}

void clear(void) {
    system("clear");
}

void exit_program(void) {
    printf("Пока.\n");
    exit(0);
}

struct Command {
    const char *name;
    void (*handler)(void);
};

struct Command commands[] = {
    {"help", help},
    {"clear", clear},
    {"exit", exit_program}
};

void execute_command(const char *input) {
    int size = sizeof(commands) / sizeof(commands[0]);

    for (int i = 0; i < size; i++) {
        if (strcmp(input, commands[i].name) == 0) {
            commands[i].handler();
            return;
        }
    }

    printf("Неизвестная команда!\n");
}

int main()
{
    char input[128];
    while (1)
    {
        printf("Введите команду: ");
        scanf("%s", input);
        execute_command(input);
    }
}
