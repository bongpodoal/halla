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
void ArrayInsert(int* array, int num, int idx)
{
	for (int i = length; i > idx; i--)
	{
		array[i] = array[i - 1];
	}
	array[idx] = num;
	printf("성공적으로 추가되었습니다. \n");
	length++;
}
void ArrayDelete(int* array, int idx)
{
	if (length <= 0)
	{
		printf("더이상 값을 뺄 수 없습니다.");
		return;
	}
	for (int i = idx; i < length - 1; i++)
	{
		array[i] = array[i + 1];
	}
	printf("성공적으로 삭제되었습니다. \n");
	length--;

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
	int array[50] = { 0, };
	int idx = 0;
	int num = 0;
	rand_num(array);

	printf("현재 생성된 배열값 : \n");
	print_array(array);
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
			ArrayDelete(array, idx);
			print_array(array);
		}
		else if (task == 2)
		{
			printf("원하시는 값과 인덱스를 입력하세요 (ex 35 2): \n");
			scanf_s("%d %d", &num, &idx);
			ArrayInsert(array, num, idx);
			print_array(array);
		}
		else
		{
			printf("올바른 값을 입력해주세요. \n");
			continue;
		}

	}


}