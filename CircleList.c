

#include "CircleList.h"

typedef struct _tag_CircleList{

	CircleListNode header;//ͷ���
	CircleListNode* slider;//�α�
	int length;//����

}TCircleList;

CircleList *CircleListCreate(){

	TCircleList *cl = (TCircleList *)malloc(sizeof(TCircleList));
	if (cl == NULL)
	{
		return NULL;
	}
	cl->header.next = NULL;
	cl->slider = NULL;
	cl->length = 0;

	return cl;
}


void CircleListDestroy(CircleList *list){

	if (list == NULL)
	{
		return;
	}
	
	free(list);
	list = NULL;

	return ;

}

//������ָ�����ʼ״̬
void CircleListClear(CircleList *list){

	if (list == NULL)
	{
		return;
	}

	TCircleList *cl = (TCircleList *)list;
	cl->header.next = NULL;
	cl->slider = NULL;
	cl->length = 0;
	
	return ;

}
int CircleListLength(CircleList *list){

	int ret = 0;
	if (list == NULL)
	{
		ret = -1;
		return ret;
	}

	TCircleList *cl = (TCircleList *)list;

	ret =  cl->length;

	return ret;


}


int CircleListInsert(CircleList *list, CircleListNode *node, int pos){

	int ret = 0,i =0;

	if (list == NULL || node == NULL || pos < 0 )
	{
		ret = -1;
		return ret;
	}

	TCircleList *cl = (TCircleList *)list;
	CircleListNode * cur = (CircleListNode *)list;

	for (i = 0; i < pos;i++)
	{
		cur = cur->next;
	}

	//��lengthΪ0 ��ʱ��,��Ҫ����һ���α�λ��
	if (cl->length == 0)
	{
		cl->slider = node;
	}

	//�������� ����ͷ��β�� �տ�ʼ����Ϊ�յ�ʱ�� ������
	node->next = cur->next;
	cur->next = node;

	//ͷ���ʱ����Ҫ����һ��node��next�γ�ѭ������
	if (cur == (CircleListNode *)list)
	{
		//�����õ�β�ڵ�
		CircleListNode * last = CircleListGet(list, cl->length - 1);
		if (last != NULL)
		{
			last->next = cur->next;

		}
	}
	 
	cl->length++;

	return ret;

}
CircleListNode * CircleListDelete(CircleList *list, int pos){

	TCircleList *cl = (TCircleList *)list;
	//��ɾ���ڵ�ret
	CircleListNode *ret = NULL;

	if (list == NULL || pos > cl->length -1 )
	{
		
		return ret;
	}

	CircleListNode *cur = (CircleListNode *) &cl->header;
	int i = 0;

	for (i = 0; i < pos;i++)
	{
		cur = cur->next;
	}

	//1.��Ҫ�ж�һ��del�ڵ��Ƿ���ͷ�ڵ�
	if (cur == (CircleListNode *)list)
	{
		CircleListNode *last = CircleListGet(list, cl->length - 1);

		//�ж������Ƿ�Ϊ��
		if (last != NULL)
		{
			cl->header.next = cur->next;
			last->next = cur->next;
		}
		
	}

	//2.ɾ���м�Ľڵ�,�м��κ�һ���ڵ��β�ڵ��������ͬ

	ret = cur->next;
	cur->next = ret->next;
	cl->length--;

	//���ɾ����Ԫ��Ϊ�α���ָ��Ԫ��
	if (cl->slider == ret)
	{
		cl->slider = ret->next;
	}

	//��ɾ��Ԫ�غ�,������Ϊ0
	if (cl->length == 0)
	{
		cl->header.next = NULL;
		cl->slider = NULL;
	}
	

	return ret;

}
CircleListNode * CircleListGet(CircleList *list, int pos){

	TCircleList *cl = (TCircleList *)list;

	if (cl == NULL || pos > (cl->length -1) || pos < 0)
	{
		return NULL;
	}


	CircleListNode *cur = &cl->header;
	CircleListNode *ret = NULL;
	int i = 0;

	for (i = 0; i < pos;i++)
	{
		cur = cur->next;

	}

	if (cur != NULL)
	{
		ret = cur->next;
	}


	return ret;

}

CircleListNode *CircleListDeleteNode(CircleList *list, CircleListNode *node){

	TCircleList *cl = (TCircleList *)list;

	if (cl == NULL || node == NULL)
	{
		return NULL;
	}


	CircleListNode *cur = &cl->header;
	CircleListNode *ret = NULL;
	int i = 0,pos = 0;


	for (i = 0; i < cl->length;i++)
	{
		if (cur->next == node)
		{
			ret = cur->next;
			pos = i;

			break;
		}
		
		cur = cur->next;
	}

	if (ret != NULL)
	{
	
		CircleListDelete(cl, pos);
	}

	return ret;

}

//���α�ָ���һ��ҵ��ڵ�
CircleListNode *CircleListReset(CircleList *list){

	TCircleList *cl = (TCircleList *)list;
	CircleListNode *ret = NULL;

	if (cl == NULL )
	{
		return ret;
	}

	CircleListNode *cur = &cl->header;
	cl->slider = cur->next;
	ret = cl->slider;

	return ret;

}

//��ȡ�α���ָ��λ��
CircleListNode *CircleListCurrent(CircleList *list){

	TCircleList *cl = (TCircleList *)list;
	CircleListNode *ret = NULL;

	if (cl == NULL)
	{
		return ret;
	}

	ret = cl->slider;

	return ret;

}

//���ص�ǰλ�ý�� ͬʱ�α�����
CircleListNode *CircleListNext(CircleList *list){

	TCircleList *cl = (TCircleList *)list;
	CircleListNode *ret = NULL;

	if (cl == NULL || cl->slider == NULL)
	{
		return ret;
	}

	ret = cl->slider;
	cl->slider = ret->next;


	return ret;

}