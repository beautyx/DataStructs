#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LinkQueue.h"

int main(){
	int i = 0, ret = 0;
	int a[10];
	LinkQueue *lq = LinkQueueCreate(10);

	if (lq == NULL)
	{
		printf("LinkQueueCreate error.\n");
	}

	for (i = 0; i < 5; i++)
	{
		a[i] = i + 1;

		LinkQueueAppend(lq, &a[i]);

	}

	printf("length = %d\n", LinkQueueLength(lq));
	printf("header:%d\n", *((int *)LinkQueueHeader(lq)));

	while (LinkQueueLength(lq) > 0)
	{
		int tmp = *(int *)LinkQueueRetrieve(lq);
		printf("tmp = %d ", tmp);
	}

	printf("\n");

	LinkQueueDestroy(lq);

	system("pause");
	return EXIT_SUCCESS;

}