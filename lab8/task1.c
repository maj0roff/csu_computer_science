#include <stdio.h>
#include <stdint.h>
#include <locale.h>
#include <stddef.h>

// Task 0
void longswap(long long* a, long long* b) { long long temp = *a; *a = *b; *b = temp; }

void task0(void)
{
    long long a = 1234567890123LL;
    long long b = 9876543210987LL;

    printf("task0:\nbefore swap: a = %lld, b = %lld\n", a, b);
    longswap(&a, &b);
    printf("after swap: a = %lld, b = %lld\n\n", a, b);
}

// Task 1
void inc_array(int *array, size_t size)
{
    if (array == NULL) return;

    int *p = array;
    for (size_t i = 0; i < size; i++) {
        *p = *p + 15;
        p++;
    }
}

void print_array(const int *array, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

void task1(void)
{
    printf("task1:\n");
    int numbers[] = {10, 20, 30, 40, 50};
    size_t msize = sizeof(numbers) / sizeof(numbers[0]);

    printf("orig array: ");
    print_array(numbers, msize);
    printf("\n");

    inc_array(numbers, msize);
    printf("changed array: ");
    print_array(numbers, msize);
    printf("\n\n");
}

// Task 2
size_t my_strlen(const char *str)
{
    if (str == NULL) return 0;
    size_t len = 0;
    while (str[len] != '\0') len++;
    return len;
}

void task2(void)
{
    printf("task2:\n");

    char text[] = "Hello, C!";

    printf("string: %s\nsize: %zu\n", text, my_strlen(text));
}

// Task 3
int a = 10;

/*
void check_return_address(uintptr_t main_ptr, int a)
{
    int local_var = 0;
    int b = 10;
    (void)local_var;

    printf("=== check_return_address ===\n");
    printf("main = %p\n", (void*)main_ptr);

    uintptr_t *rbp = (uintptr_t*)__builtin_frame_address(0);
    printf("RBP  = %p\n", (void*)rbp);

    for (int i = -2; i < 16; i++) {
        uintptr_t val = rbp[i];
        printf("rbp[%+3d] = %p -> 0x%016llx", i, (void*)&rbp[i],
               (unsigned long long)val);

        if (i == 3) printf("   <-- saved RIP (RET)");
        if (i == 0) printf("   <-- saved RBP");
        printf("\n");
    }

    uintptr_t saved_rip = rbp[3];
    printf("\nsaved RIP = 0x%016llx\n", (unsigned long long)saved_rip);

    if (saved_rip > 0x1000 && saved_rip < 0x0000800000000000ULL) {
        printf("Похоже на валидный адрес возврата.\n");
    } else {
        printf("НЕ похоже на адрес возврата.\n");
    }
}
*/

void check_return_address(uintptr_t main_ptr, int a)
{
    int local_var = 0;
    int b = 10;
    (void)local_var;
    (void)b;
    (void)a;

    printf("=== check_return_address ===\n");
    printf("main = %p\n", (void *)main_ptr);

    uintptr_t *fp =
        (uintptr_t *)__builtin_frame_address(0);

    printf("FP   = %p\n", (void *)fp);

    for (int i = -2; i < 10; i++) {
        uintptr_t val = fp[i];

        printf("fp[%+3d] = %p -> 0x%016llx",
               i,
               (void *)&fp[i],
               (unsigned long long)val);

        if (i == 0)
            printf("   <-- saved FP");

        if (i == 1)
            printf("   <-- saved LR");

        printf("\n");
    }

    uintptr_t saved_lr = fp[1];

    printf("\nsaved LR = 0x%016llx\n",
           (unsigned long long)saved_lr);
}

void task3(uintptr_t main_ptr)
{
    printf("\ntask3:\n");
    check_return_address(main_ptr, a);
    printf("a: %p\n", (void *)&a);
}

int main(void)
{
    uintptr_t main_ptr = (uintptr_t)&main;
    setlocale(LC_ALL, ".UTF-8");
    task0();
    task1();
    task2();
    task3(main_ptr);
    return 0;
}
