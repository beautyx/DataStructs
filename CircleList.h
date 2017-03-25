#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef void CircleList;
//环形链表节点的结构体
typedef struct _tag_CircleListNode{

	struct _tag_CircleListNode *next;

}CircleListNode;
//创建一个环形链表
CircleList *CircleListCreate();
//销毁环形链表list
void CircleListDestroy(CircleList *list);
//清空环形链表
void CircleListClear(CircleList *list);
//求出环形链表的长度
int CircleListLength(CircleList *list);
//在pos位置上插入node
int CircleListInsert(CircleList *list,CircleListNode *node,int pos);
//删除位于pos的节点
CircleListNode * CircleListDelete(CircleList *list,int pos );
//得到位于pos的节点
CircleListNode * CircleListGet(CircleList *list, int pos);
//删除node节点
CircleListNode *CircleListDeleteNode(CircleList *list,CircleListNode *node);
//重置环形链表list
CircleListNode *CircleListReset(CircleList *list);
//得到当前游标所指的node
CircleListNode *CircleListCurrent(CircleList *list);
//返回当前位置结点,同时游标下移
CircleListNode *CircleListNext(CircleList *list);


