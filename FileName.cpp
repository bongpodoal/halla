#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	srand(time(NULL));
	int even[10] = { 0, };
	int odd[10] = { 0, };
	int random = 0;
	int even_num = 0;
	int odd_num = 0;
	while (odd_num != 10 && even_num != 10)
	{
		random = rand()%1000;
		if (random % 2 == 0)
		{
			even[even_num] = random;
			even_num++;
		}
		else
		{
			odd[odd_num] = random;
			odd_num++;
		}
	}
	if (odd_num == 10)
		printf("Ȧ���� ���� ä�������ϴ�. ¦���� %d�� �Դϴ�.", even_num);
	else
		printf("¦���� ���� ä�������ϴ�. Ȧ���� %d�� �Դϴ�.", odd_num);

}