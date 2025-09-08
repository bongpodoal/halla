#include <stdio.h>
#include <stdlib.h>

int* AppendToArray(int* array, int length, int num)
{
	int count;
	int* tempArray = (int*)malloc(sizeof(int) * (length + 1));

	for (count = 0, count < length; count++)
		tempArray[count] = array[count];

	tempArray[length] = num;

	free(array);
	return tempArray;
}
int main(void)
{
	int count;
	int array[] = { 90,70,50,80,60,85 };
	int* scores = (int*)malloc(sizeof(int) * 6);
	int length = 6;

	for (count = 0; count < length; count++)
		scores[count] = array[count];

	scores = AppendToArray(scores, length++, 75); 
	// ���� �����ڰ� �ڿ� �־� 6�� ���޵ǰ� 1�� ������

	for(count = 0; count < length; count++)
		printf("%d, ", scores[count]);

	free(scores);

	return 0;



}