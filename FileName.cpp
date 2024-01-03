#include <stdio.h>
int main()
{
    for (int i = 1;i <= 10;i += 2)
    {
        for (int j = 1;j < 10 - i;j += 2)
        {
            printf(" ");
        }
        for (int j = 1;j <= i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 1;i <= 10 ;i += 2)
    {
        for (int j = 1;j <= i;j += 2)
        {
            printf(" ");
        }
        for (int j = 1;j <= (10 - i) - 2;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}