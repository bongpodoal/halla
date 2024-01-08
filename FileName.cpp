#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void random_score(double scores[][7])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 4;j++)
		{
			scores[i][j] = rand() % 100 + 1;
		}
	}
	printf("\n");
}
int search_binary(double list[], int n, double key) { // 등수 처리 함수
	int low = 0;
	int high = n - 1;
	int middle;
	int rank[20];
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
void sorting_score(double scores[][7], double sort_scores[])
{
	int temp;
	for (int i = 0;i < 20;i++) // 총점계산
	{
		scores[i][5] = scores[i][0] * 0.3 + scores[i][1] * 0.4 + scores[i][2] * 0.2 + scores[i][3] * 0.1;
	}
	for (int i = 0; i < 20;i++) // 등수 계산을 위한 배열 복사
	{
		sort_scores[i] = scores[i][5];
	}
	for (int i = 0;i < 19;i++) // 총점 정렬
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
}
void finding_rank(double scores[][7], double sort_scores[], int rank[])
{
	double key;
	for (int i = 0; i < 20;i++) // 등수 값 탐색
	{
		key = scores[i][5];
		rank[i] = search_binary(sort_scores, 20, key);
	}
}
int main()
{
	srand(time(NULL));
	double scores[20][7];
	double sort_scores[20];
	int temp;
	int low = 0;
	int high = 19;
	int rank[20];

	random_score(scores);
	sorting_score(scores, sort_scores);
	finding_rank(scores, sort_scores, rank);

	for (int i = 0;i < 20;i++) // 평균 계산, 결과값 출력
	{
		scores[i][4] = (scores[i][0] + scores[i][1] + scores[i][2] + scores[i][3]) / 4;
		printf("%4d번 학생: 중간: %4.0lf, 기말: %4.0lf, 과제: %4.0lf, 출석: %4.0lf, 총점: %4.1lf, %d등 \n", i + 1, scores[i][0], scores[i][1], scores[i][2], scores[i][3], scores[i][5], 20 - rank[i]);
	}
}