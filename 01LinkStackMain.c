#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LinkStack.h"

int main(){

	int ret = 0,i = 0;
	int a[10];

	LinkStack *stack = LinkStackCreate();
	if (stack == NULL)
	{
		ret = -1;
		return ret;
	}

	for (i = 0; i < 5;i++)
	{
		a[i] = i + 1;
		linkStackPush(stack, (void *)&a[i]);
	}


	printf("length = %d\n", LinkStackSize(stack));
	printf("Top = %d\n", *(int *)(LinkStackTop(stack)));


	while (LinkStackSize(stack) > 0 )
	{
		int temp = *(int *)(LinkStackPop(stack));
		printf("Pop = %d\t", temp);

	}

	LinkStackDestroy(stack);

	printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}