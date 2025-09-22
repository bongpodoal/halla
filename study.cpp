#include <stdio.h>
void bubble(int* arrays, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arrays[j] > arrays[j + 1])
			{
				int temp = arrays[j];
				arrays[j] = arrays[j + 1];
				arrays[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int scores[] = { 60,50,95,80,70 };
	int length = sizeof(scores) / sizeof(int);

	bubble(scores, length);

	for (int i = 0; i < length; i++)
	{
		printf("%d ", scores[i]);
	}
	return 0;
}