#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void) {
    int map[3][3] = { 0, };
    int big_map[5][5] = { 0, };
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            int row = i + j;           
            int col = 2 + (i - j);      
            int v = i * 3 + j + 1;     
            big_map[row][col] = v;
        }
    }


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int v = big_map[i][j];
            if (!v) 
                continue;
            int row = (i + 2) % 3;
            int col = (j + 2) % 3;
            map[row][col] = v; 
        }
    }


    printf("5x5 큰 배열:\n");
    for (int r = 0; r < 5; ++r) 
    {
        for (int c = 0; c < 5; ++c) printf("%2d ", big_map[r][c]);
            printf("\n");
    }

    printf("\n3x3 마방진:\n");
    for (int r = 0; r < 3; ++r) 
    {
        for (int c = 0; c < 3; ++c) printf("%2d ", map[r][c]);
        printf("\n");
    }

    return 0;
}
