#include <stdio.h>
void ReversArray(int* array, int length)
{
	int middle = length / 2;
	int temp;
	for (int i = 0; i < middle; i++)
	{
		temp = array[i];
		array[i] = array[length - 1 - i];
		array[length - 1 - i] = temp;
	}
}

int main()
{
	int scores[] = { 50,60,70,80,90 };
	int length = 5;
	ReversArray(scores, length);
	for (int i = 0; i < length; i++)
		printf("%d ", scores[i]);

	return 0;
}