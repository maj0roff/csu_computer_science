#include <stdio.h>
#include <Windows.h>

int CalcFactorial(int num) {
	int doneNum = 1;
	for (int i = 1; i <= num; i++) {
		doneNum *= i;
	}
	return doneNum;
}

int main() {
	SetConsoleOutputCP(65001);
	int input;

	printf("Введите цифру для подсчета факториала: ");
	scanf_s("%d", &input);

	printf("Факториал числа %d: %d", input, CalcFactorial(input));

	return 0;
}
