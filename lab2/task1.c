/*

1. передать в функцию и вывести произвольное количество символов в формате func(int count, char  c1, char c2 , ...);
2 балла

*/


#include <stdio.h>
#include <stdarg.h>

void func(int count, ...) {
	va_list argpointer;
	va_start(argpointer, count);

	char* x;

	for (int i = 0; i < count; i++) {
		x = va_arg(argpointer, char*);
		printf("%s", x);
	}
	va_end(argpointer);

}

int main() {
	func(4, "d", "2", "3", "k", "_", "e");
	getchar();
	return 0;
}
