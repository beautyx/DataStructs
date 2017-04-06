#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "SeqQueue.h"

int main(){

	int i = 0,ret = 0;
	int a[10];
	SeqQueue *sq = SeqQueueCreate(10);

	if (sq == NULL)
	{
		printf("SeqQueueCreate error.\n");
	}

	for (i = 0; i < 5;i++)
	{
		a[i] = i + 1;

		SeqQueueAppend(sq, &a[i]);

	}

	printf("length = %d\n", SeqQueueLength(sq));
	printf("header:%d\n", *((int *)SeqQueueHeader(sq)));

	while (SeqQueueLength(sq) > 0)
	{
		int tmp = *(int *)SeqQueueRetrieve(sq);
		printf("tmp = %d ",tmp);
	}

	printf("\n");

	SeqQueueDestroy(sq);

	system("pause");
	return EXIT_SUCCESS;
}