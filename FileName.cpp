#include <stdio.h>
int get_integer(void)
{
	int n;
	printf("������ �Է��ϼ���: ");
	scanf_s("%d", &n);
	return n;
}
void is_prime(int n)
{
	for (int i = 2;i < n;i++) 
		if (n % i == 0) {
			printf("%d�� �Ҽ��� �ƴմϴ�", n);
			return;
		}
	printf("%d�� �Ҽ��Դϴ�", n);
	return;
}
int main() {
	int n = get_integer();
	is_prime(n);
}