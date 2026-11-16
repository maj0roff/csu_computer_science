#include <stdio.h>
#include <stdlib.h>

#define ERR_ALLOC_MEM "ERROR: couldn't allocate memory\nEXIT WITH ERROR CODE 1\n"


void PrintIntArray(int*, int);
void ScanIntArray(int*, int);
void ReverseIntArray(int*, int);

int main() {

    int* iPtr = malloc(sizeof(int));
    if (iPtr == NULL) {
        printf_s(ERR_ALLOC_MEM);
        return 1;
    }
    *iPtr = 6;
    printf_s("iPtr: %p\n*iPtr: %d\n", iPtr, *iPtr);
    free(iPtr);

    int size;
    printf_s("Enter an array size: ");
    scanf_s("%d", &size);
    int* iArray = calloc(size, sizeof(int));
    if (!iArray) {
        printf_s(ERR_ALLOC_MEM);
        return 1;
    }
    printf_s("Enter values: ");
    ScanIntArray(iArray, size);

    printf_s("iArray:\n");
    PrintIntArray(iArray, size);
    ReverseIntArray(iArray, size);
    printf_s("Reversed iArray:\n");
    PrintIntArray(iArray, size);

    int* tmp;
    int newSize = size * 3 / 2;
    tmp = realloc(iArray, newSize * sizeof(int));
    if (tmp) {
        iArray = tmp;
    }
    else {
        printf_s(ERR_ALLOC_MEM);
        free(iArray);
        return 1;
    }

    printf_s("Enter %d extra values: ", newSize - size);
    ScanIntArray(iArray + size, newSize - size);
    printf_s("\n");
    PrintIntArray(iArray, newSize);
    printf_s("\n");
    free(iArray);

    return 0;
}

void ScanIntArray(int* array, int size) {

    for (unsigned int i = 0; i < size; ++i) {
        scanf_s("%d", &array[i]);
        //scanf_s("%d", array + i);
    }
}

void PrintIntArray(int* array, int size) {
    int* end = array + size;
    while (array < end) {
        printf_s("%d ", *(array++));
    }

    // аналог
    /*for (unsigned int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }*/

    printf_s("\n");
}

void ReverseIntArray(int* array, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}
