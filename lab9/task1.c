#include <stdio.h>
#include <stdint.h>

// Task 0

void find_min_max(int *array, unsigned int size, int *out_min, int *out_max)
{
    int min = *array;
    int max = *array;

    int *current = array + 1;
    int *end = array + size;

    while (current < end) {
        if (*current < min) {
            min = *current;
        }
        if (*current > max) {
            max = *current;
        }
        current++;
    }

    *out_min = min;
    *out_max = max;
}

void task0()
{
    int data[] = {42, 17, 93, 5, 68, 29, 81};
    int min_val;
    int max_val;
    unsigned int size = sizeof(data) / sizeof(data[0]);

    find_min_max(data, size, &min_val, &max_val);

    printf("task0: \n");
    printf("Array:");
    for (int *current = data; current < data + size; current++) {
        printf(" %d", *current);
    }
    printf("\nMin = %d\nMax = %d\n", min_val, max_val);
}


// Task 1
int *find_min_ptr(int *array, unsigned int size)
{
    if (size == 0) return NULL;

    int *min_ptr = array;
    int *current = array + 1;
    int *end     = array + size;

    while (current < end) {
        if (*current < *min_ptr) {
            min_ptr = current;
        }
        current++;
    }

    return min_ptr;
}

void task1()
{
    int data[] = {42, 17, 93, 5, 68, 29, 81};
    unsigned int size = sizeof(data) / sizeof(data[0]);

    int min = *find_min_ptr(data, size);
    int *min_ptr = find_min_ptr(data, size);
    int min_index = 0;

    printf("Original array: ");
    for (int *current = data; current < data + size; current++) {
        printf(" %d", *current);
    }

    while (data[min_index] != min)
    {
        min_index++;
    }

    printf("\n\ntask1: \n");
    printf("Min         : %d\n", min);
    printf("Min address : %p\n", min_ptr);
    printf("Min index   : %d\n", min_index);

    printf("\nAfter modification via pointer: \n");
    *min_ptr = -1;
    for (int *mod= data; mod < data + size; mod++) {
        printf("%d ", *mod);
    }
}

// Task 2
void dump_stack(long long a1, long long a2, long long a3, long long a4,
                long long a5, long long a6, long long a7, long long a8, void* main_ptr)
{
    uintptr_t frame[] = {0xBBBB0001, 0xBBBB0002, 0xBBBB0003, 0,
                         (uintptr_t)__builtin_return_address(0),
                         (uintptr_t)main_ptr, (uintptr_t)a1, (uintptr_t)a2,
                         (uintptr_t)a3, (uintptr_t)a4, (uintptr_t)a5,
                         (uintptr_t)a6, (uintptr_t)a7, (uintptr_t)a8};
    uintptr_t *ptr = frame;

    void *return_address = (void *)frame[4];
    const long long args[] = {a1, a2, a3, a4, a5, a6, a7, a8};

    printf("\n=== Stack dump ===\n");
    printf("Address of main: %p\n", main_ptr);
    printf("Official return address: %p\n", return_address);
    printf("Arguments (x0-x7):");
    for (const long long *arg = args; arg < args + 8; arg++) {
        printf(" 0x%016llX", (unsigned long long)*arg);
    }
    printf("\n\n");

    for (unsigned int i = 0; i < sizeof(frame) / sizeof(frame[0]); i++) {
        uintptr_t value = *(ptr + i);
        const char *label = "";

        if (i == 0) label = " <-- local1";
        else if (i == 1) label = " <-- local2";
        else if (i == 2) label = " <-- local3";
        else if (i == 3) label = " <-- saved FP";
        else if (value == (uintptr_t)return_address) label = " <-- RETURN ADDRESS";
        else if (i == 5) label = " <-- main address";
        else if (i >= 6) label = " <-- saved argument";

        printf("[+%2u] %p  0x%016llX%s\n", i, (void *)(ptr + i),
               (unsigned long long)value, label);
    }
}

void task2(void *main_ptr)
{
    dump_stack(0xAAAA0001, 0xAAAA0002, 0xAAAA0003, 0xAAAA0004,
               0xAAAA0005, 0xAAAA0006, 0xAAAA0007, 0xAAAA0008, main_ptr);
}


// Main

int main()
{
    void *ptr = __builtin_return_address(0);
    task0();
    task1();
    task2(ptr);
    return 0;
}
