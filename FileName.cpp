#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int search_binary(double list[], int n, double key) {
	int low = 0;
	int high = n - 1;
	int middle;
	while (low <= high) {
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle;
		else if (key < list[middle])
			high = middle - 1;
		else
			low = middle + 1;
	}
}
int main()
{
	srand(time(NULL));
	double scores[20][7];
	double sort_scores[20];
	int rank[20];
	int temp;
	int low = 0;
	int high = 19;
	int middle;
	double key;


	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 4;j++)
		{
			scores[i][j] = rand() % 100 + 1;
		}
	}

	printf("\n");
	for (int i = 0;i < 20;i++) // 총점계산
	{
		scores[i][5] = scores[i][0] * 0.3 + scores[i][1] * 0.4 + scores[i][2] * 0.2 + scores[i][3] * 0.1;
	} 


	for (int i = 0; i < 20;i++) // 등수 계산을 위한 배열 복사
	{
		sort_scores[i] = scores[i][5];

	} 

	for (int i = 0;i < 19;i++)  // 총점 정렬
	{
		for (int j = i + 1;j <= 19;j++)
		{
			if (sort_scores[i] > sort_scores[j])
			{
				temp = sort_scores[i];
				sort_scores[i] = sort_scores[j];
				sort_scores[j] = temp;

			}
		}
	}

	for (int i = 0; i < 20;i++)
	{
		key = scores[i][5];
		scores[i][6] = search_binary(sort_scores, 20, key);
	}

	for (int i = 0;i < 20;i++)
	{
		printf("%4d번 학생: 중간: %4.0lf, 기말: %4.0lf, 과제: %4.0lf,  출석: %4.0lf, 총점: %4.3lf, %4.0lf등   \n", i+1,scores[i][0], scores[i][1],scores[i][2], scores[i][3], scores[i][5], scores[i][6]+1);
	}


}