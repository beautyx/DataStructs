#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct BitNode{

	int data;
	struct BiTNode *lchild, *rchild;

}BiTNode, *BiTree;

/*
递归的用先序中序后序遍历一棵树的本质是:先序是访问第一次就输出节点的数值;中序是访问第二次输出;后序是访问第三次再输出:
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


//计算一棵树的叶子节点个数
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


//计算一棵树的叶子节点个数
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


//递归求出一棵树的高度,高度等于根节点下所有左子树的高度与所有右子树的高度+1(因为根节点算高度算1)
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

//拷贝树

BiTree copyTree(BiTree root){

	if (root == NULL)
	{
		return NULL;
	}

	BiTree newNode = NULL;
	BiTree newLp = NULL;
	BiTree newRp = NULL;



	//newNode拷贝root左子树
	if (root->lchild != NULL)
	{
		newLp = copyTree(root->lchild);
	}
	else{
	
		newLp = NULL;
	
	}

	//newNode拷贝root右子树
	if (root->rchild != NULL)
	{
		newRp = (root->rchild);
	}
	else{

		newRp = NULL;

	}

	//newNode拷贝root数据
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