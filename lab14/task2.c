#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void transpose_flat(int *mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = mat[i * n + j];
            mat[i * n + j] = mat[j * n + i];
            mat[j * n + i] = temp;
        }
    }
}

void print_flat(int *mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%2d ", mat[i * n + j]);
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, ".UTF-8");
    int *matrix = malloc(SIZE * SIZE * sizeof(int));
    if (!matrix) return 1;

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i * SIZE + j] = i * SIZE + j + 1;

    printf("Исходная (flat):\n");
    print_flat(matrix, SIZE);

    transpose_flat(matrix, SIZE);

    printf("Транспонированная (flat):\n");
    print_flat(matrix, SIZE);

    free(matrix);
    return 0;
}