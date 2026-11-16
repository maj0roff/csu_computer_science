#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void vecplus(const int* a, const int* b, int* result, int n) {
    for (int i = 0; i < n; i++) {
        result[i] = a[i] + b[i];
    }
}

long long vecscal(const int* a, const int* b, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (long long)a[i] * b[i];
    }
    return sum;
}

void printVector(const int* v, int n, const char* name) {
    printf("%s = (", name);
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) printf(", ");
    }
    printf(")\n");
}

int main() {
    setlocale(LC_ALL, ".UTF-8");
    srand((unsigned)time(NULL));

    int n;
    printf("Введите размерность векторов N: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Некорректная размерность!\n");
        return 1;
    }

    int* vec1 = (int*)malloc(n * sizeof(int));
    int* vec2 = (int*)malloc(n * sizeof(int));
    int* sum = (int*)malloc(n * sizeof(int));

    if (!vec1 || !vec2 || !sum) {
        printf("Ошибка выделения памяти!\n");
        free(vec1);
        free(vec2);
        free(sum);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        vec1[i] = rand() % 21 - 10;
        vec2[i] = rand() % 21 - 10;
    }

    printVector(vec1, n, "Вектор 1");
    printVector(vec2, n, "Вектор 2");

    vecplus(vec1, vec2, sum, n);
    printVector(sum, n, "Сумма   ");

    long long dot = vecscal(vec1, vec2, n);
    printf("Скалярное произведение = %lld\n", dot);

    free(vec1);
    free(vec2);
    free(sum);

    return 0;
}
