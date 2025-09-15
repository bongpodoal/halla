
#include <stdio.h>
int main()
{
	int length = 6;
	int map[5][5] = { 0, };
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			int far = i - j;
			if (far < 0)
				far *= -1;
			map[i][j] = far + 1;

		}
	}
	

	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
}