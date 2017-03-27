#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef void DLinkList;

typedef struct _tag_DLinklistNode{

	struct _tag_DlinklistNode *pre;
	struct _tag_DlinklistNode *next;

}DLinkListNode; 


/*

	该双向链表的局限性是插入的元素节点唯一

*/

//双向链表的创建
DLinkList *DLinkListCreate();

//在位置pos插入一个新节点
int DLinkListInsert(DLinkList *list, DLinkListNode *node, int pos);
//双向链表的长度
int DLinkListLength(DLinkList *list);
//双向链表的销毁
int DLinkListDestroy(DLinkList *list);

//得到位置pos的节点
DLinkListNode * DLinkListGet(DLinkList *list, int pos);

//获取当前游标所指节点,并让游标后移一次
DLinkListNode * DLinkListNextNode(DLinkList *list);

//获取当前游标所指节点,并让游标前移一次
DLinkListNode * DLinkListPreNode(DLinkList *list);

//让游标指向第一个业务节点
DLinkListNode * DLinkListReset(DLinkList *list);

//删除位置pos的节点
DLinkListNode * DLinkListDelete(DLinkList *list, int pos);

//删除node节点
DLinkListNode * DLinkListDeleteNode(DLinkList *list, DLinkListNode *node);
//拿到当前游标所指节点
DLinkListNode * DLinkListCurrentNode(DLinkList *list);

//清空双向链表
int DLinkListClear(DLinkList *list);


