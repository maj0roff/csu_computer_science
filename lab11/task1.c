
#include <stdio.h>

void multiply_3x3(const int A[][3], const int B[][3], int C[][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;

            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiply_3x3_2(const int** A, const int** B, int** C)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;

            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void print_matrix(int n, int m, int p[n][m])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

void print_matrix_2(const int** matrix, int rows, int col)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int b[][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int c[3][3];

    multiply_3x3(a, b, c);
    print_matrix(3, 3, c);

    printf("\n\n");


    int a0[] = {1, 2, 3};
    int a1[] = {4, 5, 6};
    int a2[] = {7, 8, 9};
    int *a_done[] = {a0, a1, a2};

    int b0[] = {9, 8, 7};
    int b1[] = {6, 5, 4};
    int b2[] = {3, 2, 1};
    int *b_done[] = {b0, b1, b2};

    int c0[3], c1[3], c2[3];
    int *c_done[] = {c0, c1, c2};

    multiply_3x3_2(a_done, b_done, c_done);
    print_matrix_2(c_done, 3, 3);

    return 0;
}
