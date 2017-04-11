#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct BitNode{

	int data;
	struct BiTNode *lchild, *rchild;

}BiTNode,*BiTree;

// 利用#创建树(先序)
BiTNode* CreateTree(){

	char h;
	BiTNode* newNode = NULL;
	BiTNode* pL = NULL;
	BiTNode* pR = NULL;

	scanf("%c", &h);
	printf("\n h = %c\n", h);

	if (h == '#')
	{
		return NULL;
	}
	else{
	
		//构造根节点
		newNode = (BiTNode*)malloc(sizeof(BiTNode));
		memset(newNode, 0, sizeof(BiTNode));
		newNode->data = h;

		if (newNode == NULL)
		{
			exit(-1);
		}
		//构造左子树
		pL = CreateTree();
		if (pL == NULL)
		{
			newNode->lchild = NULL;
		}
		else{
			newNode->lchild = pL;
		}

		//构造右子树
		pR = CreateTree();
		if (pR == NULL)
		{
			newNode->rchild = NULL;
		}
		else{
			newNode->rchild = pR;
		}
	
	}

	return newNode;

}

//先序创建树,后序释放树,先释放局部再释放整体
void FreeTree(BiTNode *T){

	if (T == NULL)
	{
		return NULL;
	}

	if (T->lchild != NULL)
	{
		FreeTree(T->lchild);
		T->lchild = NULL;
	}
	if (T->rchild != NULL)
	{
		FreeTree(T->rchild);
		T->rchild = NULL;
	}

	free(T);
	T = NULL;
}

int main(){

	BiTNode t1, t2, t3, t4, t5;
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;

	{
		BiTNode *p = NULL;
		p = CreateTree();
	
	}

	system("pause");
	return EXIT_SUCCESS;
}