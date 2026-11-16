#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <locale.h>

int calc(int *s, int *m, int a, int b, int c) {
	int sum;
	int multiply;

	sum = a + b + c;
	multiply = a * b * c;

	if (b && a > UINT_MAX / b) return -1;

	*s = sum;
	*m = multiply;
	return 0;
}

int main() {
	setlocale(LC_ALL, ".UTF-8");
	int a, b, c;
	int s, m;

	printf("Ввод чисел: ");
	scanf_s("%d %d %d", &a, &b, &c);

	calc(&s, &m, a, b, c) == 0 ? printf("Сумма: %d\nПроизведение: %d", s, m) : printf("Переполнение");

	return 0;
}
