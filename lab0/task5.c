#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

/*
Уязвимый вариант, который выдал ошибку переполнения буффера: когда стало больше 8 символов, но при этом выдал вcю введеную строку

Необработанное исключение по адресу 0x00007FF73D061415 в Task5.exe: 0xC0000409: Обнаружено переполнение стекового буфера в данном приложении.
Это переполнение может позволить злоумышленнику получить управление над данным приложением.


int main() {
    SetConsoleOutputCP(CP_UTF8);

    char buffer[8];

    printf("Введите строку: ");
    scanf("%s", buffer);
    getchar();

    printf("Вы ввели: %s\n", buffer);
    getchar();

    return 0;
}
*/

// Один из вариантов исправление - указание максимального кол-ва символов.
// При таком использовании мы уже не получаем ошибку
/*

int main() {
    SetConsoleOutputCP(CP_UTF8);

    char buffer[8];

    printf("Введите строку: ");
    scanf("%7s", buffer);
    getchar();

    printf("Вы ввели: %s\n", buffer);
    getchar();

    return 0;
}
*/

// Второй вариант исправление - посимвольное чтение.
// Для него я уже создам отдельную функцию с получением и обработкой ввода от пользователя

void getInput(char* buffer, int size) {
    int i = 0;
    int character; // getchar вернет int

    while (i < size - 1) {
        character = getchar();

        if (character == '\n' || character == '\0') {
            break;
        }

        buffer[i] = (char)character;
        i += 1;
    }

    buffer[i] = '\0'; // добавляем конец строки

    while (character != '\n' && character != '\0') {
        character = getchar(); // если больше буфера, то чистим символы
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    char input[8];

    printf("Введите строку: ");
    getInput(input, sizeof(input));

    printf("Вы ввели: %s\n", input);
    getchar();

    return 0;
}
