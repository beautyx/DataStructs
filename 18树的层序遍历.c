#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LinkQueue.h"

typedef struct BitNode{

	char data;
	struct BiTNode *lchild, *rchild;

}BiTNode, *BiTree;


/*
	二叉树的层序遍历算法:
	1.从根节点开始,只要是根节点就入队列
	2.开始while循环,退出条件时队列为空:
	{
		1.从队列中获得队头元素并访问;
		2.判断队头元素的左子树是否为空,如果不空则入队列;判断右子树是否为空,如果不空也如队列
	
	}


*/
void ForEachBinaryTree(BiTNode *T){

	if (T == NULL)
	{
		return;
	}

	LinkQueue *lq = LinkQueueCreate();

	LinkQueueAppend(lq, T);

	while (LinkQueueLength(lq) > 0)
	{
		BiTNode *temp = LinkQueueHeader(lq);
		printf("%c ", temp->data);
		LinkQueueRetrieve(lq);

		if (temp->lchild != NULL)
		{
			LinkQueueAppend(lq, temp->lchild);


		}
		if (temp->rchild != NULL)
		{
			LinkQueueAppend(lq, temp->rchild);

		}
	}

}

int main(){

	BiTNode a, b, c,d, e,f,g,h;

	memset(&a, 0, sizeof(BiTNode));
	memset(&b, 0, sizeof(BiTNode));
	memset(&c, 0, sizeof(BiTNode));
	memset(&d, 0, sizeof(BiTNode));
	memset(&e, 0, sizeof(BiTNode));
	memset(&f, 0, sizeof(BiTNode));
	memset(&g, 0, sizeof(BiTNode));
	memset(&h, 0, sizeof(BiTNode));

	a.data = 'A';
	b.data = 'B';
	c.data = 'C';
	d.data = 'D';
	e.data = 'E';
	f.data = 'F';
	g.data = 'G';
	h.data = 'H';

	a.lchild = &b;
	a.rchild = &f;
	b.rchild = &c;
	c.lchild = &d;
	c.rchild = &e;
	f.rchild = &g;
	g.lchild = &h;


	ForEachBinaryTree(&a);

	system("pause");
	return EXIT_SUCCESS;
}