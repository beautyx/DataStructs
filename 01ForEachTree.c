#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct BitNode{

	int data;
	struct BiTNode *lchild, *rchild;

}BiTNode, *BiTree;

/*
�ݹ������������������һ�����ı�����:�����Ƿ��ʵ�һ�ξ�����ڵ����ֵ;�����Ƿ��ʵڶ������;�����Ƿ��ʵ����������:
*/

void preOrder(BiTree root){

	if (root == NULL)
	{
		return ;
	}

	printf("%d ", root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);

}

void inOrder(BiTree root){

	if (root == NULL)
	{
		return ;
	}

	inOrder(root->lchild);
	printf("%d ", root->data);
	inOrder(root->rchild);

}

void postOrder(BiTree root){

	if (root == NULL)
	{
		return ;
	}

	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d ", root->data);

}


//����һ������Ҷ�ӽڵ����
void  countLeaf(BiTree root,int *sum){

	if (root == NULL)
	{
		return;
	}

	if (root->lchild == NULL && root->rchild == NULL)
	{
		(*sum)++;
	}
	if (root->lchild != NULL)
	{
		countLeaf(root->lchild,sum);
	}

	if (root->rchild != NULL)
	{
		countLeaf(root->rchild,sum);
	}

}


//����һ������Ҷ�ӽڵ����
void  countLeaf2(BiTree root,int *sum){

	if (root == NULL)
	{
		return;
	}


	if (root->lchild != NULL)
	{
		countLeaf2(root->lchild,sum);
	}

	if (root->lchild == NULL && root->rchild == NULL)
	{
		(*sum)++;
	}

	if (root->rchild != NULL)
	{
		countLeaf2(root->rchild,sum);
	}

}


//�ݹ����һ�����ĸ߶�,�߶ȵ��ڸ��ڵ��������������ĸ߶��������������ĸ߶�+1(��Ϊ���ڵ���߶���1)
int depth(BiTree root){

	int h = 0;

	if (root == NULL)
	{
		return h;
	}

	int hl = depth(root->lchild);
	int hr = depth(root->rchild);

	h = 1 + (hl > hr ? hl : hr);

	return h;

}

//������

BiTree copyTree(BiTree root){

	if (root == NULL)
	{
		return NULL;
	}

	BiTree newNode = NULL;
	BiTree newLp = NULL;
	BiTree newRp = NULL;



	//newNode����root������
	if (root->lchild != NULL)
	{
		newLp = copyTree(root->lchild);
	}
	else{
	
		newLp = NULL;
	
	}

	//newNode����root������
	if (root->rchild != NULL)
	{
		newRp = (root->rchild);
	}
	else{

		newRp = NULL;

	}

	//newNode����root����
	newNode = (BiTree)malloc(sizeof(BiTNode));
	newNode->lchild = newLp;
	newNode->rchild = newRp;
	newNode->data = root->data;

	return newNode;
}


int main(){

	BiTNode t1, t2, t3, t4, t5;
	int sum = 0;

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
	t3.lchild = &t5;


	/*
	
	printf("\n preOrder \n");
	preOrder(&t1);

	printf("\n inOrder \n");
	inOrder(&t1);

	printf("\n postOrder \n");
	postOrder(&t1);
	
	
	*/

	countLeaf(&t1,&sum);

	printf("sum = %d\n",sum);

	printf("depth = %d \n", depth(&t1));

	printf("\n postOrder \n");
	postOrder(&t1);

	{
	
		BiTree tree = copyTree(&t1);
	
		printf("\n postOrder \n");
		postOrder(tree);

	}

	system("pause");
	return EXIT_SUCCESS;
}