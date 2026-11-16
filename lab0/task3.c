#include <stdio.h>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int A, B;

    printf("Введите два числа (0 или 1): ");
    scanf_s("%d %d", &A, &B);
    getchar(); // Фикс оставшегося Enter в stdin

    A = (A == 0 || A == 1) ? A : 0;
    B = (B == 0 || B == 1) ? B : 0;

    printf("\n");
    printf("A | B | И | ИЛИ | XOR | НЕ A | НЕ B\n");
    printf("-----------------------------------\n");

    printf("%d | %d | %d |  %d  |  %d  |   %d  |   %d\n",
        A, B,
        A && B,
        A || B,
        A ^ B,
        !A,
        !B
    );

    getchar();

    return 0;
}
