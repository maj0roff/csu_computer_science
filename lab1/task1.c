#include <stdio.h>

int main() {
    for (int counter = 0; counter < 128; counter++) {

        printf("(%3d|0x%02X) : ", counter, counter);

        switch (counter) {
        case 0:
            printf("\\0  ");
            break;
        case 1:
            printf("\\x01");
            break;
        case 2:
            printf("\\x02");
            break;
        case 3:
            printf("\\x03");
            break;
        case 4:
            printf("\\x04");
            break;
        case 5:
            printf("\\x05");
            break;
        case 6:
            printf("\\x06");
            break;
        case 7:
            printf("\\a  ");
            break;
        case 8:
            printf("\\b  ");
            break;
        case 9:
            printf("\\t  ");
            break;
        case 10:
            printf("\\n  ");
            break;
        case 11:
            printf("\\v  ");
            break;
        case 12:
            printf("\\f  ");
            break;
        case 13:
            printf("\\r  ");
            break;
        case 14:
            printf("\\x0E");
            break;
        case 15:
            printf("\\x0F");
            break;
        case 16:
            printf("\\x10");
            break;
        case 17:
            printf("\\x11");
            break;
        case 18:
            printf("\\x12");
            break;
        case 19:
            printf("\\x13");
            break;
        case 20:
            printf("\\x14");
            break;
        case 21:
            printf("\\x15");
            break;
        case 22:
            printf("\\x16");
            break;
        case 23:
            printf("\\x17");
            break;
        case 24:
            printf("\\x18");
            break;
        case 25:
            printf("\\x19");
            break;
        case 26:
            printf("\\x1A");
            break;
        case 27:
            printf("\\x1B");
            break;
        case 28:
            printf("\\x1C");
            break;
        case 29:
            printf("\\x1D");
            break;
        case 30:
            printf("\\x1E");
            break;
        case 31:
            printf("\\x1F");
            break;
        case 127:
            printf("\\x7F");
            break;
        default:
            printf("%c     ", counter);
            break;
        }

        if ((counter + 1) % 8 == 0) {
            printf("\n");
        }
        else {
            printf("   |   ");
        }
    }

    return 0;
}
