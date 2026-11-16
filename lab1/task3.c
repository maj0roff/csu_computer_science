#include <stdio.h>

int main() {
    int scanNum;
    int condition;

    scanf_s("%d", &scanNum);
    printf("Value = %d\n", scanNum);

    condition = scanNum > 100 ? 1 : scanNum > 10 ? 2 : scanNum > 0 ? 3 : 4; // использую тернарный оператор чтобы записать в одну строку

    switch (condition) {
        case 1:
            printf("Num greater than 100!\n");
            goto error_exit;  // один единтсвенный раз в качестве примера так делаем, больше не будем !!!
        case 2:
            printf("Num greater than 10!\n");
            break;
        case 3:
            printf("Num less than 10!\n");
            break;
        case 4:
            printf("Num less than 0!\n");
            break;
    }

    /*
    if (scanNum > 100) {
        printf("Num greater than 100!\n");
        goto error_exit;  // один единтсвенный раз в качестве примера так делаем, больше не будем !!!
    }
    else if (scanNum <= 100 && scanNum > 10) {
        printf("Num greater than 10!\n");
    }
    else if (scanNum > 0) {
        printf("Num less than 10!\n");
    }
    else {
        printf("Num less than 0!\n");
    }
    */

error_exit:
    exit(1);
}
