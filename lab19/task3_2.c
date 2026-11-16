
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MyStrlen(char* str);

int main() {

    FILE* in;
    char** strings = NULL;
    int strings_count = 0;

    /*
    // СТАРЫЙ КОД

    int strings_count = 1;

    if (fopen_s(&in, "input.txt", "r") == 0) {

        fseek(in, 0, SEEK_END);
        long int bytes_in_file = ftell(in);
        fseek(in, 0, SEEK_SET);

        char* buffer = (char*)malloc(bytes_in_file + 1);
        char current_symbol;

        while (fscanf_s(in, "%c", &current_symbol, 1) != EOF) {
            if (current_symbol == '\n')
                ++strings_count;
        }

        fseek(in, 0, SEEK_SET);

        strings = (char**)malloc(strings_count * sizeof(char*));

        if (strings != NULL) {
            for (int i = 0; i < strings_count; ++i) {
                fgets(buffer, bytes_in_file + 1, in);

                int length = MyStrlen(buffer) + 1;
                strings[i] = (char*)malloc(length * sizeof(char));

                for (int j = 0; j < length - 1; ++j) {
                    strings[i][j] = buffer[j];
                }

                strings[i][length - 1] = '\0';
            }
        }

        fclose(in);
        free(buffer);
    }
    */

    in = fopen("../3.txt", "r");

    if (in != NULL) {

        char chunk[256];

        while (1) {

            int capacity = 256;
            int length = 0;

            char* buffer = (char*)malloc(capacity);

            if (buffer == NULL)
                break;

            buffer[0] = '\0';

            int line_started = 0;
            int line_finished = 0;

            while (!line_finished && fgets(chunk, sizeof(chunk), in) != NULL) {

                line_started = 1;

                int chunk_length = strlen(chunk);

                if (chunk_length > 0 && chunk[chunk_length - 1] == '\n') {
                    --chunk_length;
                    line_finished = 1;
                }

                int required_size = length + chunk_length + 1;

                if (required_size > capacity)
                {
                    while (required_size > capacity) {
                        capacity *= 2;
                    }

                    char* temp = (char*)realloc(buffer, capacity);

                    if (temp == NULL) {
                        free(buffer);
                        buffer = NULL;
                        break;
                    }

                    buffer = temp;
                }

                for (int i = 0; i < chunk_length; ++i) {
                    buffer[length + i] = chunk[i];
                }

                length += chunk_length;
                buffer[length] = '\0';
            }

            if (buffer == NULL)
                break;

            if (!line_started) {
                free(buffer);
                break;
            }

            // Добавляем готовую строку в массив

            char** temp = (char**)realloc(
                strings,
                (strings_count + 1) * sizeof(char*)
            );

            if (temp == NULL) {
                free(buffer);
                break;
            }

            strings = temp;
            strings[strings_count] = buffer;

            ++strings_count;
        }

        fclose(in);
    }
    else {
        printf("Error opening file!\n");
    }

    if (strings != NULL) {

        printf("\nSTRINGS:\n");

        for (int i = 0; i < strings_count; ++i) {
            if (strings[i] != NULL)
                printf("%s\n", strings[i]);
        }
    }

    for (int i = 0; i < strings_count; ++i)
        free(strings[i]);

    free(strings);

    return 0;
}

int MyStrlen(char* str) {

    int length = 0;

    while (str[length] != '\0' && str[length] != '\n')
        ++length;

    return length;
}
