#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	srand(time(NULL));
	int scores[20][5];
	double total[20];

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 4;j++)
		{
			scores[i][j] = rand() % 100 + 1;
		}
		scores[i][4] = rand() % 10 + 1;
	}
	for (int i = 0;i < 20;i++)
	{
		total[i] = scores[i][0] * 0.3 + scores[i][1] * 0.4 + scores[i][2] * 0.2 + scores[i][3] * 0.1 - scores[i][4];
		printf("학생 #%2d의 최종성석 = %.2lf\n", i + 1, total[i]);
	}

}