/*

1. Написать калькулятор для комплексных чисел. Должны быть реализованы операции: +, -, *.
Комплексное число вводится в виде заключенной в скобки пары чисел (вещественная и мнимая части) разделённых запятой:

(23,-14) соответствует  23 - 14i
(0,-7)    <->      -7i
(-11,0)    <->      -11

+1 балл
вынести операции как указатели на функцию внутрь структуры (подобно методам) (см. пример)
 void (*print)(PUser);

*/

#include <locale.h>
#include <stdio.h>
#include "complex_t.h"

int main()
{
    setlocale(LC_ALL, ".UTF-8");
    int a, b, c, d;

    printf("Введите первое комплексное число (a,b): ");
    if (scanf("%d, %d", &a, &b) != 2)
    {
        printf("Ошибка ввода!\n");
        return 1;
    }

    printf("Введите второе комплексное число (c,d): ");
    if (scanf("%d, %d", &c, &d) != 2)
    {
        printf("Ошибка ввода!\n");
        return 1;
    }

    complex_t x = c_create(a, b);
    complex_t y = c_create(c, d);

    complex_t result;

    printf("\nПервое число: ");
    x.print(x);

    printf("\nВторое число: ");
    y.print(y);

    result = x.add(x, y);
    printf("\nСумма: ");
    result.print(result);

    result = x.sub(x, y);
    printf("\nРазность: ");
    result.print(result);

    result = x.mul(x, y);
    printf("\nПроизведение: ");
    result.print(result);

    printf("\n");

    return 0;
}