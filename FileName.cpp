#include <stdio.h>
int get_integer(void)
{
	int n;
	printf("정수를 입력하세요: ");
	scanf_s("%d", &n);
	return n;
}
void is_prime(int n)
{
	for (int i = 2;i < n;i++) 
		if (n % i == 0) {
			printf("%d는 소수가 아닙니다", n);
			return;
		}
	printf("%d는 소수입니다", n);
	return;
}
int main() {
	int n = get_integer();
	is_prime(n);
}