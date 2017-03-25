

#include "CircleList.h"

//循环链表的结构体
typedef struct _tag_CircleList{

	CircleListNode header;//头结点
	CircleListNode* slider;//游标
	int length;//长度

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

//让链表恢复到初始状态
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

	//当length为0 的时候,需要重置一下游标位置
	if (cl->length == 0)
	{
		cl->slider = node;
	}

	//以下两句 对于头插尾插 刚开始链表为空的时候 都适用
	node->next = cur->next;
	cur->next = node;

	//头插的时候需要重置一下node的next形成循环链表
	if (cur == (CircleListNode *)list)
	{
		//首先拿到尾节点
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
	//待删除节点ret
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

	//1.需要判断一下del节点是否是头节点
	if (cur == (CircleListNode *)list)
	{
		CircleListNode *last = CircleListGet(list, cl->length - 1);

		//判断链表是否为空
		if (last != NULL)
		{
			cl->header.next = cur->next;
			last->next = cur->next;
		}
		
	}

	//2.删除中间的节点,中间任何一个节点和尾节点操作都相同

	ret = cur->next;
	cur->next = ret->next;
	cl->length--;

	//如果删除的元素为游标所指的元素
	if (cl->slider == ret)
	{
		cl->slider = ret->next;
	}

	//若删除元素后,链表长度为0
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

//让游标指向第一个业务节点
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

//获取游标所指的位置
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

//返回当前位置结点 同时游标下移
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
