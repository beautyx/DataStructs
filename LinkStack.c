#include "LinkList.h"
#include "LinkStack.h"


typedef struct _tag_LinkStackNode{

	LinkListNode node;//��һ����
	void *item;// ջ��ҵ��ڵ�

}TLinkStackNode;//�����ҵ��ڵ�


//����һ����ջ�൱�ڴ���һ������
LinkStack * LinkStackCreate()
{

	return LinkListCreate();
}



void LinkStackDestroy(LinkStack *stack)
{
	LinkStackClear(stack);
	LinkListDestroy(stack);

	return;
}


//���ջ�漰��ջԪ���������ڵĹ���
/*

	����������ջԪ�ض�malloc���ڴ�,��������ջ��Ҫ������ջ��Ԫ�ص��������ͷ��ڴ�

*/
void LinkStackClear(LinkStack *stack)
{

	if (stack == NULL)
	{
		return;
	}
	while (LinkStackSize(stack) > 0)
	{
		//popʱ���ͷ��ڴ�
		LinkStackPop(stack);
	}

	return;
	

}

int LinkStackSize(LinkStack *stack)
{
	return LinkListLength(stack);

}


//��ȡջ��Ԫ���൱�ڻ�ȡ�����0��λ��
void * LinkStackTop(LinkStack *stack)
{
	TLinkStackNode *tmp = NULL;
	tmp = LinkListGet(stack, 0);

	if (tmp == NULL)
	{
		return NULL;
	}

	return tmp->item;
}



//��ջ�е���Ԫ���൱�ڴ������ͷ��ɾ��Ԫ��
void * LinkStackPop(LinkStack *stack)
{
	void *item = NULL;
	TLinkStackNode *tmp = NULL;
	tmp = LinkListDelete(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}
	
	item = tmp->item;

	//����push��ʱ��malloc�������ڴ�,������pop��ʱ����Ҫ�ͷ��ڴ�
	free(tmp);

	return item;
	

}

//��ջ��pushԪ���൱���������ͷ������Ԫ��
/*
	void *item ջ��ҵ��ڵ�------>ת��Ϊ�����ҵ��ڵ�
	
*/
int linkStackPush(LinkStack *stack, void *item)
{
	int ret = 0;

	TLinkStackNode *tmp = (TLinkStackNode *)malloc(sizeof(TLinkStackNode));
	if (tmp == NULL)
	{
		ret = -1;
		return ret;
	}

	memset(tmp, 0, sizeof(TLinkStackNode));
	tmp->item = item;

	ret =  LinkListInsert(stack, tmp, 0);

	if (ret != 0)
	{
		printf("linkStackPush error:%d .\n",ret);
		if (tmp != NULL)
		{
			free(tmp);
			tmp = NULL;
		}
		return ret;
	}

	return ret;

}
