#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "CircleList.h"

struct Value{

	CircleListNode circlenode;
	int v;

};

int main(int argc, char *argv[]){

	CircleList *list = CircleListCreate();

	struct Value v1;
	struct Value v2;
	struct Value v3;
	struct Value v4;
	struct Value v5;
	struct Value v6;
	struct Value v7;
	struct Value v8;

	int i = 0;

	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;
	v6.v = 6;
	v7.v = 7;
	v8.v = 8;

	CircleListInsert(list, (CircleListNode *)&v1, CircleListLength(list));
	CircleListInsert(list, (CircleListNode *)&v2, CircleListLength(list));
	CircleListInsert(list, (CircleListNode *)&v3, CircleListLength(list));
	CircleListInsert(list, (CircleListNode *)&v4, CircleListLength(list));
	CircleListInsert(list, (CircleListNode *)&v5, CircleListLength(list));
	CircleListInsert(list, (CircleListNode *)&v6, CircleListLength(list));
	CircleListInsert(list, (CircleListNode *)&v7, CircleListLength(list));
	CircleListInsert(list, (CircleListNode *)&v8, CircleListLength(list));


	for(i = 0; i < CircleList_Length(list); i++)
	{
		//获取游标所指元素,然后游标下移
		struct Value* pv = (struct Value*)CircleList_Next(list);
		printf("%d\n", pv->v);
	}

	printf("\n");


	//重置游标
	CircleList_Reset(list);

	while( CircleList_Length(list) > 0 )
	{
		struct Value* pv = NULL;
		for(i=1; i<3; i++)
		{
			CircleList_Next(list);
		}
		pv = (struct Value*)CircleList_Current(list);
		printf("%d\n", pv->v);
		CircleList_DeleteNode(list, (CircleListNode*)pv);
	}

	CircleList_Destroy(list);

	system("pause");
	return EXIT_SUCCESS;
}
