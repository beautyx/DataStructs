
#include "DlinkList.h"

//双向链表的结构体
typedef struct _tag_DlinkList
{
	DLinkListNode header;
	DLinkListNode* slider;
	int length;


}TDLinkList;

//双向链表的创建
DLinkList *DLinkListCreate()
{

	TDLinkList *tlist = (TDLinkList *)malloc(sizeof(TDLinkList));
	if (tlist == NULL)
	{
		return NULL;
	}
	tlist->header.pre = NULL;
	tlist->header.next = NULL;
	tlist->slider = NULL;
	tlist->length = 0;


	return tlist;
}

//在位置pos插入一个新节点
int DLinkListInsert(DLinkList *list, DLinkListNode *node, int pos) {

	int ret = 0;
	TDLinkList *tlist = (TDLinkList *)list;

	if (tlist == NULL || pos<0 || pos > tlist->length )
	{
		ret = -1;
		return ret;
	}

	DLinkListNode *cur = &tlist->header;
	int i = 0;

	for (i = 0; i < pos; i++)
	{
		cur = cur->next;
	}

	//1.如果插入的是头结点
	if (cur == (DLinkListNode *)tlist)
	{
		//1.当链表为空链表时
		if (cur->next == NULL)
		{
			node->next = NULL;
			cur->next = node;
			node->pre = NULL;
		}
		//2.链表非空的时候
		else {

			DLinkListNode *next = cur->next;

			node->next = next;
			cur->next = node;
			next->pre = node;
			node->pre = NULL;


		}

	}
	else{

		//2.如果插入位置为尾节点之后
		if (cur->next == NULL)
		{
			node->next = NULL;
			cur->next = node;
			node->pre = cur;

		}
		//3.插入node作为中间任意节点(非头非尾)
		else if (cur->next != NULL)
		{
			DLinkListNode *next = cur->next;

			node->next = next;
			cur->next = node;
			next->pre = node;
			node->pre = cur;
		}
	}

	tlist->length++;
	//不要忘记游标重置
	tlist->slider = node;

	return ret;

}

//双向链表的长度
int DLinkListLength(DLinkList *list) {

	int ret = 0;
	TDLinkList *tlist = (TDLinkList *)list;

	if (list == NULL)
	{
		ret = -1;
		return ret;
	}


	ret = tlist->length;
	return ret;


}
//双向链表的销毁
int DLinkListDestroy(DLinkList *list) {

	int ret = 0;
	TDLinkList *tlist = (TDLinkList *)list;

	if (list == NULL)
	{
		ret = -1;
		return ret;
	}

	free(tlist);
	tlist = NULL;

	return ret;

}

//得到位置pos的节点
DLinkListNode * DLinkListGet(DLinkList *list, int pos) {

	DLinkListNode *ret = NULL;
	TDLinkList *tlist = (TDLinkList *)list;

	if (tlist == NULL || pos<0 || pos >(tlist->length - 1))
	{

		return ret;
	}

	DLinkListNode *cur = &tlist->header;
	int i = 0;

	for (i = 0; i < pos; i++)
	{
		cur = cur->next;
	}

	ret = cur->next;
	printf("getP = %p\n",ret);

	return ret;

}

//获取当前游标所指节点,并让游标下移一次
DLinkListNode * DLinkListNextNode(DLinkList *list) {

	//辅助指针,指向待删节点
	DLinkListNode * ret = NULL;
	TDLinkList *tlist = (TDLinkList *)list;

	if (tlist == NULL || tlist->slider == NULL)
	{
		return ret;
	}

	ret = tlist->slider;

	tlist->slider = ret->next;

	printf("nextNode = %p\n",tlist->slider);

	return ret;

}

//获取当前游标所指节点,并让游标上移一次
DLinkListNode * DLinkListPreNode(DLinkList *list) {

	//辅助指针,指向待删节点
	DLinkListNode * ret = NULL;
	TDLinkList *tlist = (TDLinkList *)list;

	if (tlist == NULL || tlist->slider == NULL)
	{
		return ret;
	}

	ret = tlist->slider;
	printf("preNode = %p\n",ret);

	tlist->slider = ret->pre;

	return ret;

}

//让游标指向第一个业务节点
DLinkListNode * DLinkListReset(DLinkList *list) {

	DLinkListNode *ret = NULL;
	TDLinkList *tlist = (TDLinkList *)list;

	if (list == NULL)
	{

		return ret;
	}

	tlist->slider = tlist->header.next;
	ret = tlist->slider;

	return ret;

}

//删除位置pos的节点
DLinkListNode * DLinkListDelete(DLinkList *list,  int pos) {

	//辅助指针,指向待删节点
	DLinkListNode * ret = NULL;
	TDLinkList *tlist = (TDLinkList *)list;

	if (tlist == NULL || pos<0 || pos > tlist->length )
	{
		return ret;
	}

	//cur为辅助指针,指向ret的前一个节点
	DLinkListNode *cur = &tlist->header;
	DLinkListNode *next = NULL;//辅助指针,指向ret的next
	int i = 0;

	for (i = 0; i < pos; i++)
	{
		cur = cur->next;
	}


	//1.待删 节点是头节点
	if (cur == (DLinkListNode *)tlist)
	{
		ret = cur->next;
		next = ret->next;

		//1.当该链表只有一个节点时
		if (next == NULL)
		{
			cur->next = NULL;
		}
		else {

			cur->next = next;
			next->pre = NULL;

			//重置游标
			tlist->slider = next;


		}

	}
	else {
	
		//2.带删节点为尾节点时

		ret = cur->next;
		next = ret->next;
		//2.1带删节点为尾节点时
		if (next == NULL)
		{
			cur->next = NULL;

		}
		//2.2带删节点为中间节点时
		else {

			cur->next = next;
			next->pre = cur;
		}
	
	}



	tlist->length--;

	return ret;
}

//删除node节点
DLinkListNode * DLinkListDeleteNode(DLinkList *list, DLinkListNode *node) {

	//辅助指针,指向待删节点
	DLinkListNode * ret = NULL;
	TDLinkList *tlist = (TDLinkList *)list;

	if (tlist == NULL || node == NULL)
	{
		return ret;
	}

	//cur为辅助指针,指向ret的前一个节点
	DLinkListNode *cur = &tlist->header;
	int i = 0;

	for (i = 0; i < tlist->length; i++)
	{
		if (node == cur->next)
		{
			ret = cur->next;
			break;
		}
		cur = cur->next;
	}

	if (ret != NULL)
	{
		DLinkListDelete(tlist,i);

	}

	return ret;
}

//清空双向链表
int DLinkListClear(DLinkList *list) {

	int ret = 0;
	TDLinkList *tlist = (TDLinkList *)list;

	if (list == NULL)
	{
		ret = -1;
		return ret;
	}

	tlist->header.pre = NULL;
	tlist->header.next = NULL;
	tlist->slider = NULL;
	tlist->length = 0;

	return ret;

}

//拿到当前游标所指节点
DLinkListNode * DLinkListCurrentNode(DLinkList *list) {

	//辅助指针,指向待删节点
	DLinkListNode * ret = NULL;
	TDLinkList *tlist = (TDLinkList *)list;

	if (tlist == NULL)
	{
		return ret;
	}

	ret = tlist->slider;

	return ret;

}

