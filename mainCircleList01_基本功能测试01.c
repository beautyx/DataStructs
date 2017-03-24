#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "CircleList.h"

struct Value{

	CircleListNode circlenode;
	int v;

};


int main(int argc,char *argv[]){

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

	CircleListInsert(list,(CircleListNode *) &v1,0);
	CircleListInsert(list, (CircleListNode *)&v2, 0);
	CircleListInsert(list, (CircleListNode *)&v3, 0);
	CircleListInsert(list, (CircleListNode *)&v4, 0);
	CircleListInsert(list, (CircleListNode *)&v5, 0);
	CircleListInsert(list, (CircleListNode *)&v6, 0);
	CircleListInsert(list, (CircleListNode *)&v7, 0);
	CircleListInsert(list, (CircleListNode *)&v8, 0);


	//如何证明是循环链表

	for (i = 0; i < 2 * CircleListLength(list);i++){
	
		struct Value * pv = (struct Value *)CircleListNext(list);
		printf("v[%d] = %d\n",pv[i+1],pv->v);
	
	}

	while (CircleListLength(list) > 0){
	
		CircleListDelete(list, 0);
	
	}
	printf("\n");

	CircleListDestroy(list);

	system("pause");
	return EXIT_SUCCESS;
}

