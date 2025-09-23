#include <stdio.h>

#define MAX_SIZE 50

void Print_Square(int square[MAX_SIZE][MAX_SIZE],int n )
{
    int i, j;
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            printf("%4d", square[i][j]);
        }
        printf("\n");
    }
}
void Create_Square(int square[MAX_SIZE][MAX_SIZE], int n)
{
    int i, j;
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            square[i][j] = 0;
        }
    }

    // 시작 위치
    int row = n - 1;
    int col = n / 2;
    int num;

    for (num = 1; num <= n * n; num++) 
    {
        square[row][col] = num;

        int nrow = (row + 1) % n;
        int ncol = (col - 1 + n) % n;  // 왼쪽 아래 방향으로 이동

        // 다음 위치가에 이미 값이 있다면, 
        if (square[nrow][ncol] != 0) 
            row = (row - 1 + n) % n; // 현재 위치에서 바로 위로 이동
        else 
        {
            row = nrow;
            col = ncol;
        }
    }
}

int main() 
{
    int n;
    int square[MAX_SIZE][MAX_SIZE]; // 정적 2차원 배열 선언

    printf("마방진의 크기를 입력하세요 : ");
    scanf_s("%d", &n);
    Create_Square(square, n);
    Print_Square(square,n);

    return 0;
}
