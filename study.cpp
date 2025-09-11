#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int length = 20;
void rand_num(int* array)
{
	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % 100 + 1;
	}
}
int* ArrayInsert(int* array, int num, int idx)
{
	int* tempArray = (int*)malloc(sizeof(int) * (length + 1));

	for (int i = 0; i < length; i++)
	{
		if (i < idx)
			tempArray[i] = array[i];
		else
			tempArray[i + 1] = array[i];
	}
	tempArray[idx] = num;
	free(array);
	printf("성공적으로 추가되었습니다. \n");
	length++;
	return tempArray;
}
int* ArrayDelete(int* array, int idx)
{
	int* tempArray = (int*)malloc(sizeof(int) * (length - 1));
	if (length <= 0)
	{
		printf("더이상 값을 뺄 수 없습니다.");
		free(array);
		return tempArray;
	}
	for (int i = 0; i < length - 1; i++)
	{
		if (i < idx)
			tempArray[i] = array[i];
		else
			tempArray[i] = array[i + 1];
	}
	free(array);
	printf("성공적으로 삭제되었습니다. \n");
	length--;
	return tempArray;

}
void print_array(int* array)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
int main()
{
	int task = 0;
	int tempArray[50] = { 0, };
	int* array = (int*)malloc(sizeof(int) * length);
	int idx = 0;
	int num = 0;
	rand_num(tempArray);

	printf("현재 생성된 배열값 : \n");
	print_array(tempArray);

	for (int i = 0; i < length; i++)
	{
		array[i] = tempArray[i];
	}

	while (1)
	{
		printf("원하는 작업을 입력하세요 : \n");
		printf("0 : 종료\n");
		printf("1 : 인덱스 삭제\n");
		printf("2 : 인덱스 추가\n");

		scanf_s("%d", &task);
		if (task == 0)
			return 0;
		else if (task == 1)
		{
			printf("원하시는 인덱스를 입력하세요 : \n");
			scanf_s("%d", &idx);
			array = ArrayDelete(array, idx);
			print_array(array);
		}
		else if (task == 2)
		{
			printf("원하시는 값과 인덱스를 입력하세요 (ex 35 2): \n");
			scanf_s("%d %d", &num, &idx);
			array = ArrayInsert(array, num, idx);
			print_array(array);
		}
		else
		{
			printf("올바른 값을 입력해주세요. \n");
			continue;
		}

	}


}