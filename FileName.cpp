#include <stdio.h>
#include <math.h>
int menu(void)
{
	int n;
	printf("\n==================\n");
	printf("1. 덧셈\n");
	printf("2. 뺄셈\n");
	printf("3. 곱셈\n");
	printf("4. 나눗셈\n");
	printf("5. 제곱근\n");
	printf("6. 팩토리얼\n");
	printf("7. 사인함수\n");
	printf("다른숫자: 나가기\n");
	printf("==================\n");
	printf("숫자를 입력하세요: ");
	scanf_s("%d", &n);
	return n;
}
void add(void)
{
	int x, y;
	printf("정수 2개를 입력하세요: ");
	scanf_s("%d %d",&x, &y);
	printf("결과 = %d", x + y);
}
void sub(void)
{
	int x, y;
	printf("정수 2개를 입력하세요: ");
	scanf_s("%d %d", &x, &y);
	printf("결과 = %d", x - y);
}
void mul(void)
{
	int x, y;
	printf("정수 2개를 입력하세요: ");
	scanf_s("%d %d", &x, &y);
	printf("결과 = %d", x * y);
}
void div(void)
{
	int x, y;
	printf("정수 2개를 입력하세요: ");
	scanf_s("%d %d", &x, &y);
	printf("결과 = %d", x / y);
}

void sqr(void)
{
	double x;
	printf("실수 1개를 입력하세요: ");
	scanf_s("%lf", &x);
	printf("결과 = %lf", sqrt(x));
}
void fac(void)
{
	int n;
	long long fac = 1;
	printf("정수 1개를 입력하세요: ");
	scanf_s("%d", &n);
	for (int i = 1; i <= n;i++)
	{
		fac *= i;
	}
	printf("결과 = %lld", fac);
}
void sn(void)
{
	double n;
	printf("실수 1개를 입력하세요: ");
	scanf_s("%lf", &n);
	printf("결과 = %lf", sin(n));
}
int main() {
	while (1) {
		switch (menu()) {
		case 1:
			add();
			break;
		case 2:
			sub();
			break;
		case 3:
			mul();
			break;
		case 4:
			div();
			break;
		case 5:
			sqr();
			break;
		case 6:
			fac();
			break;
		case 7:
			sn();
			break;
		default:
			return 0;
			break;
		}

	}
}