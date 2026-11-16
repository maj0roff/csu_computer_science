#include <stdio.h>
#include <Windows.h>

int main() {
	SetConsoleOutputCP(CP_UTF8);
	int input;

	printf("Введите десятичное число: \0");

	scanf_s("%d", &input);
	getchar(); // Фикс оставшегося Enter в stdin

	printf("DEC: %d\nOCT: %o\nHEX: %X\n\0", input, input, input);
	getchar();

	return 0;
}
