#include <stdio.h>

void print_3darray_brackets(int array[3][3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%d ", array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void print_3darray_ptr(const int *p, int n0, int n1, int n2)
{
    int total = n0 * n1 * n2;
    for (int idx = 0; idx < total; idx++) {
        printf("%d ", *(p + idx));

        if ((idx + 1) % n2 == 0) printf("\n");

        if ((idx + 1) % (n1 * n2) == 0) printf("\n");
    }
}

void print_matrix(const int *p, int n, int m)
{
    int total = n * m;
    for (int idx = 0; idx < total; idx++) {
        printf("%d ", *(p + idx));

        if ((idx + 1) % m == 0) printf("\n");

        if ((idx + 1) % (n * m) == 0) printf("\n");
    }
}

void task0()
{
    int array3d[3][3][3] = {
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
        },
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    },
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
        }
    };

    printf("Print by brackets: \n");
    print_3darray_brackets(array3d);

    printf("\n\nPrint by pointer: \n");
    print_3darray_ptr(&array3d[0][0][0], 3, 3, 3);
}

void transpose_matrix(int *const *src, int *const *dst, int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            dst[j][i] = src[i][j];
}

void task1()
{
    int matrix[5][5] = {
        {10, 5, 0, 15, 20},
        {31, 12, 1, 64, 87},
        {14, 64, 0, 15, 20},
        {10, 11, 96, 12, 40},
        {55, 24, 86, 52, 14},
    };

    int *matrix_rows[] = {
        matrix[0], matrix[1], matrix[2], matrix[3], matrix[4]
    };
    print_matrix(&matrix[0][0], 5, 5);
    int transposed_matrix[5][5];
    int *transposed_rows[] = {
        transposed_matrix[0], transposed_matrix[1], transposed_matrix[2],
        transposed_matrix[3], transposed_matrix[4]
    };

    transpose_matrix(matrix_rows, transposed_rows, 5, 5);
    print_matrix(&transposed_matrix[0][0], 5, 5);
}

void task2()
{
    int m0[] = {10, 5, 0, 15, 20};
    int m1[] = {31, 12, 1, 64, 87};
    int m2[] = {14, 64, 0, 15, 20};
    int m3[] = {10, 11, 96, 12, 40};
    int m4[] = {55, 24, 86, 52, 14};

    int *doneMatrix[] = {m0, m1, m2, m3, m4};
    int t0[5], t1[5], t2[5], t3[5], t4[5];
    int *transposed_matrix[] = {t0, t1, t2, t3, t4};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%d ", doneMatrix[i][j]);
        printf("\n");
    }

    printf("\n");

    transpose_matrix(doneMatrix, transposed_matrix, 5, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%d ", transposed_matrix[i][j]);
        printf("\n");
    }
}

int main()
{
    task0();
    task1();
    task2();
    return 0;
}
