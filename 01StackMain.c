#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "SeqStack.h"

int main(){

	int i = 0;
	int a[10];
	SeqStack *stack = SeqStackCreate(10);
	if (stack == NULL)
	{
		return -1;
	}

	for (i = 0; i < 5;i++)
	{
		a[i] = i + 1;
		SeqStackPush(stack, &a[i]);

	}

	printf("capacity = %d\n", SeqStackCapacity(stack));
	printf("size = %d\n", SeqStackSize(stack));

	if(SeqStackSize(stack) > 0 ){
	
		printf("top = %d\n", *(int *)SeqStackTop(stack));

	}

	while (SeqStackSize(stack)>0) {
	
		int temp = *(int *)SeqStackPop(stack);
		printf("temp :%d ", temp);
	
	}

	printf("\n");

	SeqStackDestroy(stack);

	system("pause");
	return EXIT_SUCCESS;
}
