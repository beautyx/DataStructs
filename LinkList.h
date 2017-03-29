#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef void LinkList;
typedef struct _tag_LinkListNode{

	struct _tag_LinkListNode *next;

}LinkListNode;




LinkList *LinkListCreate();
void LinkListDestroy(LinkList *list);
void LinkListClear(LinkList *list);
int LinkListLength(LinkList *list);
int LinkListInsert(LinkList *list, LinkListNode *node, int pos);
LinkListNode * LinkListGet(LinkList *list, int pos);
LinkListNode * LinkListDelete(LinkList *list, int pos);
LinkListNode * LinkListDeleteNode(LinkList *list, LinkListNode *node);
