#include <stdio.h>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    double A, B;

    printf("Введите два целых числа через пробел: ");
    scanf_s("%lf %lf", &A, &B);
    getchar(); // Фикс оставшегося Enter в stdin

    printf("\n");

    printf("%.2lf + %.2lf = %.2lf\n", A, B, A + B);
    printf("%.2lf - %.2lf = %.2lf\n", A, B, A - B);
    printf("%.2lf * %.2lf = %.2lf\n", A, B, A * B);
    if (B != 0) {
        printf("%.2lf / %.2lf = %.2lf\n", A, B, A / B);
        printf("%.2lf %% %.2lf = %.2lf\n", A, B, fmod(A, B));
    }
    else {
        printf("%.2lf / %.2lf = деление на ноль невозможно\n", A, B);
        printf("%.2lf %% %.2lf = деление на ноль невозможно\n", A, B);
    }

    getchar();

    return 0;
}
