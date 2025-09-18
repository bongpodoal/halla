#include <stdio.h>
int Absolute(int value)
{
	if (value > 0)
		return value;
	else
		return value * -1;
}
int main()
{
	int x, y;
	scanf_s("%d %d", &x, &y);
	for (int i = 0; i < x;i++)
	{
		for (int j = 0; j < y;j++)
		{
			printf("%d ", Absolute(i - j) + 1);
		}
		printf("\n");
	}
}