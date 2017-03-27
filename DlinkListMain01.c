#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "DlinkList.h"



struct Value {

	DLinkListNode node;
	int v;


};

int main(){

	DLinkList *tlist = DLinkListCreate();

	struct Value v1, v2, v3, v4, v5;
	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5; 

	int i = 0;


	DLinkListInsert(tlist, (DLinkListNode *)&v1, DLinkListLength(tlist));
	DLinkListInsert(tlist, (DLinkListNode *)&v2, DLinkListLength(tlist));
	DLinkListInsert(tlist, (DLinkListNode *)&v3, DLinkListLength(tlist));
	//DLinkListInsert(tlist, (DLinkListNode *)&v4, DLinkListLength(tlist));
	//DLinkListInsert(tlist, (DLinkListNode *)&v5, DLinkListLength(tlist));
	DLinkListInsert(tlist, (DLinkListNode *)&v4, 1);



	for (i = 0; i < DLinkListLength(tlist);i++)
	{
		struct Value *pv = (struct Value *)DLinkListGet(tlist, i);
		printf("DLinkListGet pv[%d]=%d\n", i+1, pv->v);


	}

	printf("\n------------------------------------------------\n");

	//��Ϊ֮ǰ��λ��1��������һ��Ԫ���α�λ�ñ��ı�,�����α�λ��
	DLinkListReset(tlist);

	for (i = 0; i < DLinkListLength(tlist)-1; i++)
	{

		struct Value *pv = (struct Value *)DLinkListNextNode(tlist);

		struct Value *cv = (struct Value *)DLinkListCurrentNode(tlist);

		printf("DLinkListNextNode pv[%d]=%d\n", i + 1, pv->v);
		printf("DLinkListCurrentNode cv[%d]=%d\n", i + 1, cv->v);

	}

	printf("\n------------------------------------------------\n");


	//����Ҫע��,����ƶ�DLinkListLength(tlist)-1��,��Ϊ��DLinkListLength(tlist)��ҪΪnull
	for (i = DLinkListLength(tlist)-1; i >0; i--)
	{

		struct Value *pv = (struct Value *)DLinkListPreNode(tlist);
		printf("DLinkListPreNode pv[%d]=%d\n", i, pv->v);

	}

	printf("\n------------------------------------------------\n");

	DLinkListDeleteNode(tlist, (DLinkListNode *)&v4);

	while (DLinkListLength(tlist) > 0)
	{
		DLinkListDelete(tlist, 0);
	}



	DLinkListDestroy(tlist);

	system("pause");
	return EXIT_SUCCESS;
}