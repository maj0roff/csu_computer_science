#include <stdio.h>
#include <Windows.h>
#include <math.h>

int sqrsum(int a, int b) { return pow(a + b, 2); }''
int sqrdif(int a, int b) { return pow(a - b, 2); }

int main() {
	SetConsoleOutputCP(CP_UTF8);
	int A, B;

	printf("Введите первое и второе число через запятую (пример: 5, 10): \0");

	scanf_s("%d, %d", &A, &B);
	getchar(); // Фикс оставшегося Enter в stdin

	printf("(%d + %d)^2 = %d\n\0", A, B, sqrsum(A, B));
	printf("(%d - %d)^2 = %d\n\0", A, B, sqrdif(A, B));

	getchar();
	return 0;
}
