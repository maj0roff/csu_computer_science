/*

3. В цикле вывести буквы русского алфавита.
1) while
2) for
3) Цикл реализовать не с помощью условных опраторова спомощью условий if и безусловного оператора перехода goto.
3балла

*/

#include <stdio.h>
#include <Windows.h>

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int yoFlag = 0;
	int counter = 0;
	for (int i = 192; i < 224; i++) {
		counter += 1;
		if (i == 198 && yoFlag == 0) {
			printf("%c%c    ", 168, 184);
			yoFlag = 1;
		}
		printf("%c%c    ", i, i + 32);
		if (counter == 6) {
			printf("\n");
			counter = 0;
		}
		
	}
}
