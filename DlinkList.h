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

	��˫������ľ������ǲ����Ԫ�ؽڵ�Ψһ

*/

//˫������Ĵ���
DLinkList *DLinkListCreate();

//��λ��pos����һ���½ڵ�
int DLinkListInsert(DLinkList *list, DLinkListNode *node, int pos);
//˫������ĳ���
int DLinkListLength(DLinkList *list);
//˫�����������
int DLinkListDestroy(DLinkList *list);

//�õ�λ��pos�Ľڵ�
DLinkListNode * DLinkListGet(DLinkList *list, int pos);

//��ȡ��ǰ�α���ָ�ڵ�,�����α����һ��
DLinkListNode * DLinkListNextNode(DLinkList *list);

//��ȡ��ǰ�α���ָ�ڵ�,�����α�ǰ��һ��
DLinkListNode * DLinkListPreNode(DLinkList *list);

//���α�ָ���һ��ҵ��ڵ�
DLinkListNode * DLinkListReset(DLinkList *list);

//ɾ��λ��pos�Ľڵ�
DLinkListNode * DLinkListDelete(DLinkList *list, int pos);

//ɾ��node�ڵ�
DLinkListNode * DLinkListDeleteNode(DLinkList *list, DLinkListNode *node);
//�õ���ǰ�α���ָ�ڵ�
DLinkListNode * DLinkListCurrentNode(DLinkList *list);

//���˫������
int DLinkListClear(DLinkList *list);


