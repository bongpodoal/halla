#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
void InsertInArray(int* array, int length, int num, int idx)
{
	int count;

	for (count = length; count > idx; count--)
	{
		array[count] = array[count - 1];
	}
	array[idx] = num;

}
int main(void)
{
	int scores[MAX_SIZE] = { 90,70,50,80,60,85 };
	int length = 6;
	int count;

	InsertInArray(scores, length, 75, 2);
	length += 1;

	for (count = 0; count < length; count++)
		printf("%d, ", scores[count]);

	return 0;



}