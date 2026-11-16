/*Задание считать с клавиатуры 2 строки на английском языке. Реализовать функцию лексикографического сравнения двух строк*/


#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "en_US.UTF-8");

	char first_str[128];
	char second_str[128];
	int i;

	printf("Введите первую строку: \0");
	fgets(first_str, sizeof(first_str), stdin);

	printf("Введите вторую строку: \0");
	fgets(second_str, sizeof(second_str), stdin);

	int first_sum = 0;
	for (i = 0; first_str[i] != '\0'; i++) {
		if (first_str[i] != '\n') {
			first_sum += (int)first_str[i];
		}
	}

	int second_sum = 0;
	for (i = 0; second_str[i] != '\0'; i++) {
		if (second_str[i] != '\n') {
			second_sum += (int)second_str[i];
		}
	}

	int check = (first_sum > second_sum) ? 1 : (first_sum < second_sum) ? 2 : 3;

	switch (check) {
		case 1:
			printf("Первая строка больше");
			break;
		case 2:
			printf("Вторая строка больше");
			break;
		case 3:
			printf("Строки равны");
			break;
	}

	return 0;
}
