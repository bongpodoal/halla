#include <stdio.h>
int main()
{
	int test[10][10] = { 0, };
	for (int i = 0; i < 10;i++)
	{
		for (int j = 0; j < 10;j++)
		{
			if (i == j || 9-i == j)
				test[i][j] = i+1;
		}
	}
	for (int i = 0; i < 10;i++)
	{
		for (int j = 0; j < 10;j++)
		{
			printf("%d", test[i][j]);
		}
		printf("\n");
	}
}