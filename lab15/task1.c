#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void free_matrix(int **matrix, int rows)
{
    if (matrix == NULL) return;

    for (int i = 0; i < rows; ++i) free(matrix[i]);
    free(matrix);
}

int alloc_matrix(int ***matrix, int rows, int cols)
{
    *matrix = malloc((size_t)rows * sizeof(**matrix));
    if (*matrix == NULL) {
        printf("Ошибка выделения памяти\n");
        return -1;
    }

    for (int i = 0; i < rows; ++i) {
        (*matrix)[i] = malloc((size_t)cols * sizeof(*(*matrix)[i]));
        if ((*matrix)[i] == NULL) {
            free_matrix(*matrix, i);
            printf("Ошибка выделения памяти\n");
            return -1;
        }
    }

    return 0;
}

void print_matrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) printf("%d%c", matrix[i][j], j + 1 == cols ? '\n' : ' ');
    }
}

int row_sum(const int *row, int cols)
{
    int sum = 0;
    for (int i = 0; i < cols; ++i) sum += row[i];
    return sum;
}

int sort_cols;

int compare(const void *a, const void *b)
{
    const int *row_a = *(const int *const *)a;
    const int *row_b = *(const int *const *)b;
    int sum_a = row_sum(row_a, sort_cols);
    int sum_b = row_sum(row_b, sort_cols);
    return (sum_a > sum_b) - (sum_a < sum_b);
}

int main()
{
    srand(time(NULL));
    int rows, cols;

    printf("Введите размеры матрицы (N, M)\n");
    if (scanf("%d%d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("Размеры матрицы не корректны\n");
        return -1;
    }

    int **matrix;
    if (alloc_matrix(&matrix, rows, cols) != 0)
        return -1;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            matrix[i][j] = rand() % 20 + 1;

    printf("Начальная матрица:\n");
    print_matrix(matrix, rows, cols);

    sort_cols = cols;
    qsort(matrix, (size_t)rows, sizeof(*matrix), compare);
    printf("Отсортированная матрица:\n");
    print_matrix(matrix, rows, cols);

    free_matrix(matrix, rows);

    return 0;
}
