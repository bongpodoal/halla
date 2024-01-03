#include <stdio.h>

int main() {
    char str[10][10];


    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            str[i][j] = ' ';
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 5 - i - 1; j > 0; j--) {
            str[i][j] = ' ';
        }
        for (int j = 5 - i - 1; j <= 5 + i - 1; j++) {
            str[i][j] = '*';
        }
    }

    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j <= i; j++) {
            str[5 + i][j] = ' ';
        }
        for (int j = i + 1; j < 2 * 5 - i - 2; j++) {
            str[5 + i][j] = '*';
        }
    }

    for (int i = 0; i < 2 * 5 - 1; i++) {
        for (int j = 0; j < 2 * 5; j++) {
            printf("%c", str[i][j]);
        }
        printf("\n");
    }

    return 0;
}