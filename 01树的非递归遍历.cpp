

#include <iostream>
using namespace std;
#include <stack>

struct BiTNode{

	int data;
	struct BiTNode *lchild, *rchild;

};

typedef struct BiTNode		BiTNode;
typedef struct BiTNode*		BiTree;

/*
步骤1:如果当前节点有左子树,则把左子树节点入栈,然后把指针指向左子树继续往下遍历;
如果当前节点没有左子树了,则访问该节点(把当前节点打印出来);
步骤2:如果当前节点有右子树,则重复步骤1;
如果当前节点没有右子树(说明该节点访问完毕),则根据栈顶元素指示指针回溯到栈顶元素,并访问栈顶元素的右子树,重复步骤2;
如果栈为空则遍历结束


*/



//一直向左走,拿到最左边的一个叶子节点,就是中序遍历的第一个节点
BiTNode * goLeftNode(BiTNode* T, stack<BiTNode* > &s){

	if (T == NULL)
	{
		return NULL;
	}

	while (T->lchild != NULL)
	{
		s.push(T);
		T = T->lchild;
	}

	return T;
}



//栈的创建部分用STL实现

void inOrder(BiTNode * root){

	if (root == NULL)
	{
		return;
	}

	BiTNode * t = NULL;
	stack<BiTNode *> s;

	//找到第一个左子树的叶子节点
	t = goLeftNode(root, s);

	while (t != NULL){

		printf("%d ", t->data);

		//如果t有右子树重复步骤1
		if (t->rchild != NULL)
		{
			//拿到右子树中中序遍历的新起点
			t = goLeftNode(root->rchild, s);
		}
		//如果t没有右子树如果栈非空,则根据栈顶指示回退
		else if (!s.empty()){

			t = s.top();
			s.pop();


		}
		//如果t没有右子树如果栈空那么结束遍历
		else{

			t = NULL;

		}

	}


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

	inOrder(&t1);


	system("pause");
	return EXIT_SUCCESS;
}





