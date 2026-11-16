
#include <stdio.h>
#include <string.h>

int main() {
    FILE *f;
    char str[100][101];
    char temp[101];
    int n, i, j, k;
    int len;

    f = fopen("../1.txt", "r");

    if (f == NULL) {
        printf("File not found");
        return 1;
    }

    fscanf(f, "%d", &len);

    n = 0;
    while (fscanf(f, "%100s", str[n]) == 1) {
        n++;
    }

    fclose(f);

    for (i = 0; i < n; i++) {
        int start = 0;

        for (j = 0; ; j++) {
            if (str[i][j] == ' ' || str[i][j] == '\0') {
                int wordLen = j - start;
                int half = wordLen / 2;

                // Меняем половины слова местами
                for (k = 0; k < half; k++) {
                    temp[k] = str[i][start + half + k];
                }

                for (k = 0; k < half; k++) {
                    str[i][start + half + k] = str[i][start + k];
                    str[i][start + k] = temp[k];
                }

                start = j + 1;
            }

            if (str[i][j] == '\0') {
                break;
            }
        }
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(str[j], str[j + 1]) > 0) {
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%s ", str[i]);
    }

    return 0;
}
