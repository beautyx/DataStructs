
#include "DlinkList.h"

//˫������Ľṹ��
typedef struct _tag_DlinkList
{
	DLinkListNode header;
	DLinkListNode* slider;
	int length;


}TDLinkList;

//˫������Ĵ���
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

//��λ��pos����һ���½ڵ�
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

	//1.����������ͷ���
	if (cur == (DLinkListNode *)tlist)
	{
		//1.������Ϊ������ʱ
		if (cur->next == NULL)
		{
			node->next = NULL;
			cur->next = node;
			node->pre = NULL;
		}
		//2.����ǿյ�ʱ��
		else {

			DLinkListNode *next = cur->next;

			node->next = next;
			cur->next = node;
			next->pre = node;
			node->pre = NULL;


		}

	}
	else{

		//2.�������λ��Ϊβ�ڵ�֮��
		if (cur->next == NULL)
		{
			node->next = NULL;
			cur->next = node;
			node->pre = cur;

		}
		//3.����node��Ϊ�м�����ڵ�(��ͷ��β)
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
	//��Ҫ�����α�����
	tlist->slider = node;

	return ret;

}

//˫������ĳ���
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
//˫�����������
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

//�õ�λ��pos�Ľڵ�
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

//��ȡ��ǰ�α���ָ�ڵ�,�����α�����һ��
DLinkListNode * DLinkListNextNode(DLinkList *list) {

	//����ָ��,ָ���ɾ�ڵ�
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

//��ȡ��ǰ�α���ָ�ڵ�,�����α�����һ��
DLinkListNode * DLinkListPreNode(DLinkList *list) {

	//����ָ��,ָ���ɾ�ڵ�
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

//���α�ָ���һ��ҵ��ڵ�
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

//ɾ��λ��pos�Ľڵ�
DLinkListNode * DLinkListDelete(DLinkList *list,  int pos) {

	//����ָ��,ָ���ɾ�ڵ�
	DLinkListNode * ret = NULL;
	TDLinkList *tlist = (TDLinkList *)list;

	if (tlist == NULL || pos<0 || pos > tlist->length )
	{
		return ret;
	}

	//curΪ����ָ��,ָ��ret��ǰһ���ڵ�
	DLinkListNode *cur = &tlist->header;
	DLinkListNode *next = NULL;//����ָ��,ָ��ret��next
	int i = 0;

	for (i = 0; i < pos; i++)
	{
		cur = cur->next;
	}


	//1.��ɾ �ڵ���ͷ�ڵ�
	if (cur == (DLinkListNode *)tlist)
	{
		ret = cur->next;
		next = ret->next;

		//1.��������ֻ��һ���ڵ�ʱ
		if (next == NULL)
		{
			cur->next = NULL;
		}
		else {

			cur->next = next;
			next->pre = NULL;

			//�����α�
			tlist->slider = next;


		}

	}
	else {
	
		//2.��ɾ�ڵ�Ϊβ�ڵ�ʱ

		ret = cur->next;
		next = ret->next;
		//2.1��ɾ�ڵ�Ϊβ�ڵ�ʱ
		if (next == NULL)
		{
			cur->next = NULL;

		}
		//2.2��ɾ�ڵ�Ϊ�м�ڵ�ʱ
		else {

			cur->next = next;
			next->pre = cur;
		}
	
	}



	tlist->length--;

	return ret;
}

//ɾ��node�ڵ�
DLinkListNode * DLinkListDeleteNode(DLinkList *list, DLinkListNode *node) {

	//����ָ��,ָ���ɾ�ڵ�
	DLinkListNode * ret = NULL;
	TDLinkList *tlist = (TDLinkList *)list;

	if (tlist == NULL || node == NULL)
	{
		return ret;
	}

	//curΪ����ָ��,ָ��ret��ǰһ���ڵ�
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

//���˫������
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

//�õ���ǰ�α���ָ�ڵ�
DLinkListNode * DLinkListCurrentNode(DLinkList *list) {

	//����ָ��,ָ���ɾ�ڵ�
	DLinkListNode * ret = NULL;
	TDLinkList *tlist = (TDLinkList *)list;

	if (tlist == NULL)
	{
		return ret;
	}

	ret = tlist->slider;

	return ret;

}

