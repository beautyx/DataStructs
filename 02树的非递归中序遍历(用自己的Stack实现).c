#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LinkStack.h"

typedef struct BiTNode{

	int data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;


}BiTNode;

BiTNode *goLeft(BiTNode *T,LinkStack *stack){

	if (T == NULL || stack == NULL)
	{
		return NULL;
	}

	while (T->lchild != NULL)
	{
		linkStackPush(stack, T);
		T = T->lchild;
	}

	return T;
}

void inorder(BiTNode *T){

	if (T == NULL)
	{
		return;
	}

	LinkStack *stack = LinkStackCreate();
	BiTNode *t = goLeft(T,stack);

	while (t != NULL)
	{
		printf("%d ", t->data);

		if (t->rchild != NULL)
		{

			t = goLeft(t->rchild, stack);
		}
		else if (t->rchild == NULL && LinkStackSize(stack) > 0)
		{
			t = LinkStackPop(stack);
		}
		else if (LinkStackSize(stack) == 0)
		{
			t = NULL;
		}
	}

}

int main(){

	BiTNode t1, t2, t3, t4, t5;

	memset(&t1, 0, sizeof(BiTNode));
	memset(&t2, 0, sizeof(BiTNode));
	memset(&t3, 0, sizeof(BiTNode));
	memset(&t4, 0, sizeof(BiTNode));
	memset(&t5, 0, sizeof(BiTNode));

	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.rchild = &t5;

	inorder(&t1);
	printf("hello...\n");


	system("pause");
	return EXIT_SUCCESS;
}