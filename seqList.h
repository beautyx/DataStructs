#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef void SeqList;
typedef void SeqListNode;

//创建线性表
SeqList * SeqListCreate(int capacity);
//销毁线性表
void SeqListDestroy(SeqList *list);
//清空线性表
void SeqListClear(SeqList *list);
//获取线性表的元素个数
int SeqListLength(SeqList *list);
//获取线性表的容量
int SeqListCapacity(SeqList *list);
//在pos位置插入元素node
int SeqListInsert(SeqList *list, SeqListNode *node, int pos);
//得到pos位置的元素
SeqListNode * SeqListGet(SeqList *list, int pos);
//删除pos位置的元素
SeqListNode * SeqListDelete(SeqList *list, int pos);

