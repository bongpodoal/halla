#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
int* InsertInArray(int* array, int length, int num, int idx)
{
	int count;
	int* tempArray = (int*)malloc(sizeof(int) * (length + 1));
	for (count = 0; count < length; count++)
	{
		if (count < idx)
			tempArray[count] = array[count];
		else
			tempArray[count + 1] = array[count];
	}
	tempArray[idx] = num;
	free(array);

	return tempArray;
}
int main(void)
{
	int tempArray[] = { 90,70,50,80,60,85 };
	int* scores = (int*)malloc(sizeof(int) * 6);
	int length = 6;
	int count;

	for (count = 0; count < length; count++)
		scores[count] = tempArray[count];

	scores = InsertInArray(scores, length, 75, 2);
	length += 1;

	for (count = 0; count < length; count++)
		printf("%d, ", scores[count]);

	free(scores);
	

	return 0;



}