#include "LinkList.h"
#include "LinkStack.h"


typedef struct _tag_LinkStackNode{

	LinkListNode node;//第一个域
	void *item;// 栈的业务节点

}TLinkStackNode;//链表的业务节点


//创建一个链栈相当于创建一个链表
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


//清空栈涉及到栈元素生命周期的管理
/*

	由于所有入栈元素都malloc了内存,所以销毁栈需要把所有栈中元素弹出并且释放内存

*/
void LinkStackClear(LinkStack *stack)
{

	if (stack == NULL)
	{
		return;
	}
	while (LinkStackSize(stack) > 0)
	{
		//pop时候释放内存
		LinkStackPop(stack);
	}

	return;
	

}

int LinkStackSize(LinkStack *stack)
{
	return LinkListLength(stack);

}


//获取栈顶元素相当于获取链表的0号位置
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



//从栈中弹出元素相当于从链表的头部删除元素
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

	//由于push的时候malloc分配了内存,所以在pop的时候需要释放内存
	free(tmp);

	return item;
	

}

//向栈中push元素相当于向链表的头部插入元素
/*
	void *item 栈的业务节点------>转换为链表的业务节点
	
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
