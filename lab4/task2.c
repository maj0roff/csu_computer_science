#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <stddef.h>
#include <stdint.h>

int pseudo_atoi(const char* c) {
	if (c == NULL) {
		return 0;
	}

	if (*c == '\0') {
		return 0;
	}

	uint8_t sign = 1;
	if (*c == '+' || *c == '-') {
		if (*c == '-') {
			sign = -1;
		}
		c++;
	}

	int value = 0;
	for (; isdigit(*c); ++c) {
		value *= 10;
		value += (int)(*c - '0');
	}

	return value * sign;
}

int calc(int* s, int* m, int a, int b) {

	if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b))
		return -1;

	if (a != 0 && (b > INT_MAX / a || b < INT_MIN / a))
		return -1;

    int sum;
    int multiply;

    sum = a + b;
    multiply = a * b;

    *s = sum;
    *m = multiply;

	return 0;
}

int main() {
    setlocale(LC_ALL, ".UTF-8");

    char str1[128];
    char str2[128];
    int of, os;

    printf("Введите первое число: ");
    scanf_s("%s", str1, 128);

    printf("Введите второе число: ");
    scanf_s("%s", str2, 128);

	int t1 = pseudo_atoi(str1);
	int t2 = pseudo_atoi(str2);

	calc(&of, &os, t1, t2) == 0 ? printf("Сумма: %d\nПроизведение: %d", of, os) : printf("Переполнение =(");

	return 0;
}
