#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef void CircleList;

typedef struct _tag_CircleListNode{

	struct _tag_CircleListNode *next;

}CircleListNode;


CircleList *CircleListCreate();
void ListDestroy(CircleList *list);
void CircleListClear(CircleList *list);
int CircleListLength(CircleList *list);
int CircleListInsert(CircleList *list,CircleListNode *node,int pos);
CircleListNode * CircleListDelete(CircleList *list,int pos );
CircleListNode * CircleListGet(CircleList *list, int pos);

CircleListNode *CircleListDeleteNode(CircleList *list,CircleListNode *node);
CircleListNode *CircleListReset(CircleList *list);
CircleListNode *CircleListCurrent(CircleList *list);
CircleListNode *CircleListNext(CircleList *list);


