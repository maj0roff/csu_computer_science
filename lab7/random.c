#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, ".UTF-8");
    int x = 3, y = 3, z = 3;

    int*** arr = (int***)malloc(x * sizeof(int**));
    if (arr == NULL) return 1;

    for (int i = 0; i < x; i++) {
        arr[i] = (int**)malloc(y * sizeof(int*));
        if (arr[i] == NULL) return 1;

        for (int j = 0; j < y; j++) {
            arr[i][j] = (int*)malloc(z * sizeof(int));
            if (arr[i][j] == NULL) return 1;
        }
    }

    printf("Трехмерный массив 3x3x3:\n");
    int counter = 1;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                arr[i][j][k] = counter++;
                printf("%2d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    counter = 1;
    int* ptr = &arr[0][0][0];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                *ptr = counter++;
                printf("%2d ", *ptr);
                ptr++;
            }
            printf("\n");
        }
        printf("\n");
    }


    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);

    return 0;
}
