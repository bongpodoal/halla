#include <stdio.h>
#define MAX_STACK_SIZE 10
int top = -1;
int is_full(int stack[])
{
	return (top == (MAX_STACK_SIZE - 1));
}
int is_empty(int stack[])
{
	return (top == -1);
}
void push(int stack[], int value)
{
	if (is_full(stack)) return;
	else stack[++top] = value;
}
void pop(int stack[])
{
	if (is_empty(stack)) return;
	else stack[top--];
}
int menu(void)
{
	int n;
	printf("\n================\n");
	printf("1. push\n");
	printf("2. pop\n");
	printf("3. check\n");
	printf("4. End\n");
	printf("================\n");
	printf("�۾��� �Է��ϼ���: ");
	scanf_s("%d", &n);
	return n;
}
int main()
{
	int stack[MAX_STACK_SIZE];
	int n;
	while (1) {
		switch (menu()) {

		case 1:
			printf("���� �Է��ϼ���: ");
			scanf_s("%d", &n);
			push(stack, n);
			break;
		case 2:
			if (is_empty(stack)) {
				printf("������ ����־� pop �� �� �����ϴ�.");
				break;
			}
			else {
				printf("������ ���� ���� �� %d�� pop �߽��ϴ�.", stack[top]);
				pop(stack);
				break;
			}
		case 3:
			if (is_empty(stack) == 0) {
				printf("���� ������ ���� ���� ���� %d�Դϴ�.\n", stack[top]);
				break;
			}
			else
			{
				printf("������ ����ֽ��ϴ�.");
				break;
			}
		case 4:
			printf("�����մϴ�.\n");
			return 0;
		}


	}
	
}