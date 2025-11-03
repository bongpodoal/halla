#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACKLEN 10
#define NAMELEN 20

typedef struct Stack
{
	char* data[STACKLEN];
	int idx;
}Stack;

Stack* CreateStack()
{
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	newStack->idx = 0;
	for (int cnt = 0; cnt < STACKLEN; cnt++)
		newStack->data[cnt] = NULL;

	return newStack;

}

void Push(Stack* stack, char* name)
{
	if (stack->idx == 10)
	{
		printf("stack is full\n");
		return;
	}
	char* newName = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(newName, name);
	stack->data[stack->idx] = newName;
	stack->idx++;
}
void Pop(Stack* stack)
{
	if (stack->idx == 0)
	{
		printf("stack is empty");
		return;
	}
	stack->idx--;
	printf("%s\n", stack->data[stack->idx]);
	free(stack->data[stack->idx]);	
}
void PrintStack(Stack* stack)
{
	for (int cnt = stack->idx - 1; cnt >= 0; cnt--)
		printf("%s -> ", stack->data[cnt]);
	printf("End\n\n");
}
void FreeStack(Stack* stack)
{
	while (1)
	{
		if (stack->idx == 0)
			break;
		Pop(stack);					
	}
	free(stack);
}
void PrintMenu(Stack* stack)
{
	char tmpStr[NAMELEN];
	char order[6];

	printf("Please enter Order(1, push 'string', 2.pop, 3. size, 4. print, 5. help, 6.quit)\n");
	printf("If you want to see order again than use help order\n");
	while (1)
	{
		scanf("%s", order);
		if (strcmp(order, "push") == 0)
		{
			scanf("%s", tmpStr);
			Push(stack, tmpStr);
			printf("\n");
		}
		else if (strcmp(order, "pop") == 0)
		{
			Pop(stack);
			printf("\n");
		}
		else if (strcmp(order, "size") == 0)
		{
			printf("%d\n\n", stack->idx);
		}
		else if (strcmp(order, "print") == 0)
		{
			PrintStack(stack);
		}
		else if (strcmp(order, "help") == 0)
		{
			printf("Please enter Order(1, push 'string', 2.pop, 3. size, 4. print, 5. help, 6.quit)\n");
		}
		else if (strcmp(order, "quit") == 0)
		{
			printf("\n");
			break;
		}
		else
		{
			printf("'%s' isn't decleared order \n\n", order);
		}
		printf("Please Enter Order\n");	
	}
}
int main()
{
	Stack* stack = CreateStack();

	PrintMenu(stack);

	FreeStack(stack);

	printf("Program is exited successfully\n");

	return 0;
}