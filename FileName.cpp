#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int temp;
	srand(time(NULL));
	int arr[10] = { 0, };
	printf("�ʱ� �迭:  ");
	for (int i = 0; i < 10;i++)
	{
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i = 0;i < 9;i++)
	{
		printf("\n%d��°���� ��: \n\n",i);
		for (int j = i+1 ;j <= 9;j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				printf("%d�� %d��ġ ���� ->",arr[i], arr[j]);
				for (int i = 0; i < 10;i++)
				{
					printf("%d ", arr[i]);
				}
				printf("\n");
			}

		}
	}
	printf("���ĵ� �迭:  ");
	for (int i = 0; i < 10;i++)
	{
		printf("%d ", arr[i]);
	}
}