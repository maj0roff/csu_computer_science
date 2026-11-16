#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "cvec.h"

int main() {
	setlocale(LC_ALL, ".UTF-8");

	srand(time(NULL));

	vec3_t vec1 = vec3_new(rand() % 10, rand() % 10, rand() % 10);
	vec3_t vec2 = vec3_new(rand() % 10, rand() % 10, rand() % 10);

	printf("Рандомные вектора\nvec1 = (%.2f, %.2f, %.2f)\nvec2 = (%.2f, %.2f, %.2f)\n\n",
		vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z);

	vec3_t	 vec_plus = vec3_plus(vec1, vec2);
	float	 vec_scal = vec3_scal(vec1, vec2);

	printf("Сумма векторов: (%.2f; %.2f; %.2f)\nСкалярное произведение векторов: %.2f\n",
		vec_plus.x, vec_plus.y, vec_plus.z, vec_scal);

	return 0;
}
