

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
����1:�����ǰ�ڵ���������,����������ڵ���ջ,Ȼ���ָ��ָ���������������±���;
�����ǰ�ڵ�û����������,����ʸýڵ�(�ѵ�ǰ�ڵ��ӡ����);
����2:�����ǰ�ڵ���������,���ظ�����1;
�����ǰ�ڵ�û��������(˵���ýڵ�������),�����ջ��Ԫ��ָʾָ����ݵ�ջ��Ԫ���ٷ���ջ��Ԫ��,������ջ��Ԫ�ص�������,�ظ�����2;
���ջΪ�����������


*/



//һֱ������,�õ�����ߵ�һ��Ҷ�ӽڵ�,������������ĵ�һ���ڵ�
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



//ջ�Ĵ���������STLʵ��

void inOrder(BiTNode * root){

	if (root == NULL)
	{
		return;
	}

	BiTNode * t = NULL;
	stack<BiTNode *> s;

	//�ҵ���һ����������Ҷ�ӽڵ�
	t = goLeftNode(root, s);

	while (t != NULL){

		printf("%d ", t->data);

		//���t���������ظ�����1
		if (t->rchild != NULL)
		{
			//�õ�����������������������
			t = goLeftNode(root->rchild, s);
		}
		//���tû�����������ջ�ǿ�,�����ջ��ָʾ����
		else if (!s.empty()){

			t = s.top();
			s.pop();


		}
		//���tû�����������ջ����ô��������
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





