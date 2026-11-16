
#include <stdio.h>

int main() {
    FILE *f;

    int A, B, C;
    int x, y;
    int count = 0;

    f = fopen("../2.txt", "r");

    if (f == NULL) {
        printf("File not found");
        return 1;
    }

    fscanf(f, "%d %d %d", &A, &B, &C);

    printf("Points:\n");

    while (fscanf(f, "%d %d", &x, &y) == 2) {
        count++;

        printf("%d %d: ", x, y);

        if (A * x + B * y + C == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    fclose(f);

    return 0;
}
