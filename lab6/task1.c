#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#include "tools.h"

int globalArray[256];
int globalSize = 0;

int removeGlobalInt(int value) {
    for (int i = 0; i < globalSize; i++) {
        if (globalArray[i] == value) {
            for (int j = i; j < globalSize - 1; j++) {
                globalArray[j] = globalArray[j + 1];
            }
            globalSize--;
            return 1;
        }
    }
    return 0;
}

void func0() {
    int a[10] = { 312, 432, 912, 10, 832, -2, 738, 8, -1932, 93 };

    printf("Не сортированный массив A: ");
    for (int i = 0; i < 10; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");

    selectionSort(a, 10);
    printf("Сортированный массив A: ");
    for (int i = 0; i < 10; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

void func1() {
    char data[] = "Smolin Aleksander Konstantinovich";

    char* data_split[3];
    int word_count = 0;

    printf("ФИО в обычном порядке: %s\n", data);

    data_split[word_count++] = data;
    for (int i = 0; data[i] != '\0'; i++) {
        if (data[i] == ' ') {
            data[i] = '\0';
            if (word_count < 3)
                data_split[word_count++] = &data[i + 1];
        }
    }

    printf("ФИО в обратном порядке: ");
    for (int i = word_count - 1; i >= 0; i--) {
        printf("%s", data_split[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
}

void func2(char data[]) {
    char* data_split[128];
    int word_count = 0;

    printf("Строка в обычном порядке: %s\n", data);

    data_split[word_count++] = data;
    for (int i = 0; data[i] != '\0'; i++) {
        if (data[i] == ' ') {
            data[i] = '\0';
            if (word_count < 128)
                data_split[word_count++] = &data[i + 1];
        }
    }

    printf("Строка в обратном порядке: ");
    for (int i = word_count - 1; i >= 0; i--) {
        printf("%s", data_split[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
}

void func3() {
    int a[256];
    int size = 0;

    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++) {
        a[size++] = rand() % 10;
    }

    printf("Числа из массива A: ");
    for (int i = 0; i < 10; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");

    printf("Уберем первое число: %d\n", a[3]);
    if (removeInt(a, &size, a[3])) {
        printf("Число убрано: ");
        for (int i = 0; i < 10; i++) {
            printf("%d  ", a[i]);
        }
    }
    else { printf("Число не найдено"); }
}

void func4() {
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++) {
        globalArray[globalSize++] = rand() % 10;
    }

    printf("Числа из массива A: ");
    for (int i = 0; i < 10; i++) {
        printf("%d  ", globalArray[i]);
    }
    printf("\n");

    printf("Уберем первое число: %d\n", globalArray[3]);
    if (removeGlobalInt(globalArray[3])) {
        printf("Число убрано: ");
        for (int i = 0; i < 10; i++) {
            printf("%d  ", globalArray[i]);
        }
    }
    else { printf("Число не найдено"); }
}

void func5() {
    int a[256];
    int size = 0;

    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++) {
        a[size++] = rand() % 10;
    }

    printf("Числа из массива A: ");
    for (int i = 0; i < 10; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");

    printf("Уберем первое число: %d\n", a[3]);
    if (removeInsideInt(a, &size, a[3])) {
        printf("Число убрано: ");
        for (int i = 0; i < 10; i++) {
            printf("%d  ", a[i]);
        }
    }
    else { printf("Число не найдено"); }
}

void func6() {
    int a[10] = { 312, 432, 912, 10, 832, -2, 738, 8, -1932, 93 };

    printf("Не сортированный массив A: ");
    for (int i = 0; i < 10; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");


    selectionSort(a, 10);
    printf("Мин. из A: %d\nМакс. из A: %d", a[0], a[9]);
    printf("\n");
}

int main() {
    setlocale(LC_ALL, ".UTF-8");

    printf("Задание 0:\n");
    func0();
    printf("\n");

    printf("Задание 1:\n");
    func1();
    printf("\n");

    printf("Задание 2:\n");
    char str[] = "Test String Hello World";
    func2(str);
    printf("\n");

    printf("Задание 3:\n");
    func3();
    printf("\n");
    printf("\n");

    printf("Задание 4:\n");
    func4();
    printf("\n");
    printf("\n");

    printf("Задание 5:\n");
    func5();
    printf("\n");
    printf("\n");

    printf("Задание 6:\n");
    func6();
    printf("\n");
    printf("\n");

    return 0;
}
