#include <stdio.h>
#include <math.h>
int menu(void)
{
	int n;
	printf("\n==================\n");
	printf("1. ����\n");
	printf("2. ����\n");
	printf("3. ����\n");
	printf("4. ������\n");
	printf("5. ������\n");
	printf("6. ���丮��\n");
	printf("7. �����Լ�\n");
	printf("�ٸ�����: ������\n");
	printf("==================\n");
	printf("���ڸ� �Է��ϼ���: ");
	scanf_s("%d", &n);
	return n;
}
void add(void)
{
	int x, y;
	printf("���� 2���� �Է��ϼ���: ");
	scanf_s("%d %d",&x, &y);
	printf("��� = %d", x + y);
}
void sub(void)
{
	int x, y;
	printf("���� 2���� �Է��ϼ���: ");
	scanf_s("%d %d", &x, &y);
	printf("��� = %d", x - y);
}
void mul(void)
{
	int x, y;
	printf("���� 2���� �Է��ϼ���: ");
	scanf_s("%d %d", &x, &y);
	printf("��� = %d", x * y);
}
void div(void)
{
	int x, y;
	printf("���� 2���� �Է��ϼ���: ");
	scanf_s("%d %d", &x, &y);
	printf("��� = %d", x / y);
}

void sqr(void)
{
	double x;
	printf("�Ǽ� 1���� �Է��ϼ���: ");
	scanf_s("%lf", &x);
	printf("��� = %lf", sqrt(x));
}
void fac(void)
{
	int n;
	long long fac = 1;
	printf("���� 1���� �Է��ϼ���: ");
	scanf_s("%d", &n);
	for (int i = 1; i <= n;i++)
	{
		fac *= i;
	}
	printf("��� = %lld", fac);
}
void sn(void)
{
	double n;
	printf("�Ǽ� 1���� �Է��ϼ���: ");
	scanf_s("%lf", &n);
	printf("��� = %lf", sin(n));
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