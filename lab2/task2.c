/*

2. вывести все переданные аргументы командной строки int argc, char** argv
1 балл

*/

#include <stdio.h>
#include <locale.h>

int main(int argc, char** argv[]) {
	setlocale(LC_ALL, "Russian");
	if (argc < 2) {
		printf("В командной строке не указаны аргументы \n\0");
		getchar();
		exit(1);
	}

	for (int i = 1; i != argc; i++) {
		printf("%s \n", argv[i]);
	}
	getchar();
	return 0;
}
