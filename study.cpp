#include <stdio.h>
#include <stdlib.h>

#ifndef _MSC_VER
#define scanf_s scanf
#endif

static int** create_matrix(int rows, int cols)
{
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL)
    {
        return NULL;
    }

    matrix[0] = (int*)calloc((size_t)rows * (size_t)cols, sizeof(int));
    if (matrix[0] == NULL)
    {
        free(matrix);
        return NULL;
    }

    for (int i = 1; i < rows; ++i)
    {
        matrix[i] = matrix[0] + (size_t)i * (size_t)cols;
    }

    return matrix;
}

static void free_matrix(int** matrix)
{
    if (matrix != NULL)
    {
        free(matrix[0]);
        free(matrix);
    }
}

static void fill_expanded_diagonal(int** expanded, int n)
{
    int big = 2 * n - 1;
    int row = 0;
    int col = n - 1;
    int max_value = n * n;

    for (int value = 1; value <= max_value; ++value)
    {
        expanded[row][col] = value;

        int next_row = row + 1;
        int next_col = col - 1;

        if (next_row == big)
        {
            next_row -= n;
        }
        if (next_col < 0)
        {
            next_col += n;
        }

        if (expanded[next_row][next_col] != 0)
        {
            row += 1;
            if (row == big)
            {
                row -= n;
            }
        }
        else
        {
            row = next_row;
            col = next_col;
        }
    }
}

static void fill_magic_square(int** magic, int n)
{
    int row = 0;
    int col = n / 2;
    int max_value = n * n;

    for (int value = 1; value <= max_value; ++value)
    {
        magic[row][col] = value;

        int next_row = (row - 1 + n) % n;
        int next_col = (col + 1) % n;

        if (magic[next_row][next_col] != 0)
        {
            row = (row + 1) % n;
        }
        else
        {
            row = next_row;
            col = next_col;
        }
    }
}

static void rotate_180(int** matrix, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int target_i = n - 1 - i;
            int target_j = n - 1 - j;

            if (target_i < i)
            {
                continue;
            }
            if (target_i == i && target_j <= j)
            {
                continue;
            }

            int temp = matrix[i][j];
            matrix[i][j] = matrix[target_i][target_j];
            matrix[target_i][target_j] = temp;
        }
    }
}

static void print_matrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int n = 0;

    printf("홀수 크기를 입력하세요: ");
    if (scanf_s("%d", &n) != 1 || n <= 0 || (n % 2) == 0)
    {
        printf("홀수 양수를 입력해야 합니다.\n");
        return 1;
    }

    int big = 2 * n - 1;

    int** expanded = create_matrix(big, big);
    int** magic = create_matrix(n, n);

    if (expanded == NULL || magic == NULL)
    {
        printf("메모리 할당에 실패했습니다.\n");
        free_matrix(expanded);
        free_matrix(magic);
        return 1;
    }

    fill_expanded_diagonal(expanded, n);
    fill_magic_square(magic, n);
    rotate_180(magic, n);

    printf("\n확장 배열 (%d x %d):\n", big, big);
    print_matrix(expanded, big, big);

    printf("\n마방진 (%d x %d):\n", n, n);
    print_matrix(magic, n, n);

    free_matrix(expanded);
    free_matrix(magic);

    return 0;
}
