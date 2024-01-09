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
	else stack[--top];
}
int main()
{
	int stack[MAX_STACK_SIZE];

	push(stack, 1);
	printf("%d\n", stack[top]);
	push(stack, 2);
	printf("%d\n", stack[top]);
	pop(stack);
	printf("%d\n", stack[top]);
}