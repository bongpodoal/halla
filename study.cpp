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

    // ���� ��ġ
    int row = n - 1;
    int col = n / 2;
    int num;

    for (num = 1; num <= n * n; num++) 
    {
        square[row][col] = num;

        int nrow = (row + 1) % n;
        int ncol = (col - 1 + n) % n;  // ���� �Ʒ� �������� �̵�

        // ���� ��ġ���� �̹� ���� �ִٸ�, 
        if (square[nrow][ncol] != 0) 
            row = (row - 1 + n) % n; // ���� ��ġ���� �ٷ� ���� �̵�
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
    int square[MAX_SIZE][MAX_SIZE]; // ���� 2���� �迭 ����

    printf("�������� ũ�⸦ �Է��ϼ��� : ");
    scanf_s("%d", &n);
    Create_Square(square, n);
    Print_Square(square,n);

    return 0;
}
