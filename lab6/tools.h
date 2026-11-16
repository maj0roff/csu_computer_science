#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Задание 0

void swap(int* a, int* b) { int temp = *a; *a = *b; *b = temp; }

void selectionSort(int* a, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&a[i], &a[minIndex]);
        }
    }
}


// Задание 3

int removeInt(int* arr, int* size, int value) {
    for (int i = 0; i < *size; i++) {
        if (arr[i] == value) {
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            return 1;
        }
    }
    return 0;
}


// Задание 5

int removeInsideInt(int* arr, int* size, int value) {
    for (int i = 0; i < *size; i++) {
        if (arr[i] == value) {
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            arr[*size] = *size;
            return 1;
        }
    }
    arr[*size] = *size;
    return 0;
}
