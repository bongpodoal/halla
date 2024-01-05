#include <stdio.h>

int search_binary(int list[], int n, int key) {
	int low = 0;
	int high = n - 1;
	int middle;
	while (low <= high) {
		printf("[%d %d]\n", low, high);
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle;
		else if (key < list[middle])
			high = middle - 1;
		else
			low = middle + 1;
	}
	return -1;
}
int main(void) {
	int list[9] = { 1, 3, 5, 6, 7, 9, 11, 20, 30 };
	int n;
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n\n�� �迭���� ã���� ������ �Է��ϼ���: ");
	scanf_s("%d", &n);
	int num = search_binary(list, 9, n);
	printf("�ε��� %d��°�� �ֽ��ϴ�.", num);
}