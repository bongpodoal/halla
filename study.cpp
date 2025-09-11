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
	printf("���������� �߰��Ǿ����ϴ�. \n");
	length++;
}
void ArrayDelete(int* array, int idx)
{
	if (length <= 0)
	{
		printf("���̻� ���� �� �� �����ϴ�.");
		return;
	}
	for (int i = idx; i < length - 1; i++)
	{
		array[i] = array[i + 1];
	}
	printf("���������� �����Ǿ����ϴ�. \n");
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

	printf("���� ������ �迭�� : \n");
	print_array(array);
	while (1)
	{
		printf("���ϴ� �۾��� �Է��ϼ��� : \n");
		printf("0 : ����\n");
		printf("1 : �ε��� ����\n");
		printf("2 : �ε��� �߰�\n");

		scanf_s("%d", &task);
		if (task == 0)
			return 0;
		else if (task == 1)
		{
			printf("���Ͻô� �ε����� �Է��ϼ��� : \n");
			scanf_s("%d", &idx);
			ArrayDelete(array, idx);
			print_array(array);
		}
		else if (task == 2)
		{
			printf("���Ͻô� ���� �ε����� �Է��ϼ��� (ex 35 2): \n");
			scanf_s("%d %d", &num, &idx);
			ArrayInsert(array, num, idx);
			print_array(array);
		}
		else
		{
			printf("�ùٸ� ���� �Է����ּ���. \n");
			continue;
		}

	}


}