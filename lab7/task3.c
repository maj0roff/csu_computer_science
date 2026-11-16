#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#include "gamma.h"

#define MAX_LEN 256

int main() {
    setlocale(LC_ALL, ".UTF-8");
    srand(time(NULL));

    char str[MAX_LEN];
    unsigned char key[MAX_LEN]; // Была проблема со знаковыми расширениями
    unsigned char buff[MAX_LEN]; // Была проблема со знаковыми расширениями
    char buff2[MAX_LEN];

    printf("Введите строку для шифрования: ");
    if (fgets(str, sizeof(str), stdin) == NULL) return 1;

    printf("Введите ключ для шифрования: ");

    int str_len = strlen(str);
    int key_len;

    if (fgets(key, sizeof(key), stdin) == NULL || key[0] == '\n') {
        key_len = str_len;
        for (int i = 0; i < key_len; i++)
            key[i] = (unsigned char)(rand() & 0xFF);

        printf("\n\nКлюч не введён. Используется случайный: ");
        for (int i = 0; i < key_len; i++) printf("%02X ", key[i]);
        printf("\n");
    }
    else {
        key_len = strlen(key);
    }


    if (str_len == 0) {
        printf("Пустая строка\n");
        return 1;
    }

    gamma_cipher(buff, str, key, str_len, key_len);

    printf("\n----------------------------------------------\n\n");
    printf("Не зашифрованная строка (hex): ");
    for (int i = 0; i < str_len; i++) printf("%02X ", str[i]);

    printf("\n");
    printf("Зашифрованная строка (hex): ");
    for (int i = 0; i < str_len; i++) printf("%02X ", buff[i]);

    printf("\n");
    gamma_cipher(buff2, buff, key, str_len, key_len);
    printf("\nРасшифрованная строка: %s\n", buff2);

    return 0;
}
