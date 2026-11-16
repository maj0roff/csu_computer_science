#include <stdio.h>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    char character;

    printf("Введите букву: ");
    scanf_s("%c", &character);

    if (character >= 'a' && character <= 'z') {
        character = character - 'a' + 'A';
    }
    else if (character >= 'A' && character <= 'Z') {
        character = character - 'A' + 'a';
    }

    printf("Результат: %c\n", character);

    return 0;
}
