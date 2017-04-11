#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef void SeqList;
typedef void SeqListNode;

//�������Ա�
SeqList * SeqListCreate(int capacity);
//�������Ա�
void SeqListDestroy(SeqList *list);
//������Ա�
void SeqListClear(SeqList *list);
//��ȡ���Ա��Ԫ�ظ���
int SeqListLength(SeqList *list);
//��ȡ���Ա������
int SeqListCapacity(SeqList *list);
//��posλ�ò���Ԫ��node
int SeqListInsert(SeqList *list, SeqListNode *node, int pos);
//�õ�posλ�õ�Ԫ��
SeqListNode * SeqListGet(SeqList *list, int pos);
//ɾ��posλ�õ�Ԫ��
SeqListNode * SeqListDelete(SeqList *list, int pos);

