#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int **alloc_matrix(int n) {
    int **mat = malloc(n * sizeof(int *));
    if (!mat) return NULL;
    for (int i = 0; i < n; i++) {
        mat[i] = malloc(n * sizeof(int));
        if (!mat[i]) {
            while (i-- > 0) free(mat[i]);
            free(mat);
            return NULL;
        }
    }
    return mat;
}

void free_matrix(int **mat, int n) {
    for (int i = 0; i < n; i++) free(mat[i]);
    free(mat);
}

void transpose_ptr(int **mat, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
}

void print_ptr(int **mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%2d ", mat[i][j]);
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, ".UTF-8");
    int **matrix = alloc_matrix(SIZE);
    if (!matrix) return 1;

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = i * SIZE + j + 1;

    printf("Исходная (ptr):\n");
    print_ptr(matrix, SIZE);

    transpose_ptr(matrix, SIZE);

    printf("Транспонированная (ptr):\n");
    print_ptr(matrix, SIZE);

    free_matrix(matrix, SIZE);
    return 0;
}