#include <stdio.h>
#include <stdlib.h>

// task 0
void analyze_addresses(void)
{
    int local_var = 42;

    void (*func_addr) (void) = analyze_addresses;

    printf("Task0\n"
           "local_var = %p\n"
           "analyze_addresses(void) = %p\n",
           &local_var, func_addr);
}

// task 1
int sort_str(const void *input_1, const void *input_2)
{
    const char *str1 = *(const char **)input_1;
    const char *str2 = *(const char **)input_2;

    while (*str1 && *str2 && *str1 == *str2)
    {
        ++str1;
        ++str2;
    }

    return (unsigned char)*str1 - (unsigned char)*str2;
}

void qsort_usage()
{
    printf("Task1:\n");
    const char *words[] = {
        "github", "maltego", "shodan", "ida", "clion"
    };

    int size = sizeof(words)/sizeof(words[0]);

    printf("before: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%s ", words[i]);
    }

    qsort(words, size, sizeof(words[0]), sort_str);

    printf("\nafter: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%s ", words[i]);
    }
}

int main()
{
    analyze_addresses();
    printf("\n---------------------------------------------\n\n");
    qsort_usage();
    return 0;
}
