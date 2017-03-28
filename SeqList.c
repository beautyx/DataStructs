#include "SeqList.h"


//�ڽṹ������һ��ָ��
typedef struct _tag_SeqList {

	int length;//ջ��ʵ��Ԫ�ظ���
	int capacity;//ջ������,����ܴ�Ԫ�ظ���
	unsigned int **node;

}TSeqList;

SeqList * SeqListCreate(int capacity) {

	int ret = 0;
	TSeqList *tmp = NULL;

	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		ret = -1;
		printf("SeqListCreate error:%d\n",ret);
		return NULL;
	}

	memset(tmp, 0, sizeof(TSeqList));

	//����capacity�Ĵ�С����ڵ�Ŀռ�
	tmp->node = (unsigned int *)malloc(sizeof(unsigned int *)* capacity);
	if (tmp->node == NULL)
	{
		ret = -2;
		printf("SeqListCreate error:%d\n", ret);
		return NULL;
	}

	tmp->capacity = capacity;
	tmp->length = 0;

	return tmp;

}


void SeqListDestroy(SeqList *list) {

	if (list == NULL)
	{
		return;
	}
	TSeqList *tlist = (TSeqList *)list;
	if (tlist->node != NULL)
	{
		free(tlist->node);
		tlist->node = NULL;
	}
	free(list);
	list = NULL;

	return;

}


void SeqListClear(SeqList *list) {

	if (list == NULL)
	{
		return;
	}
	TSeqList *tlist = (TSeqList *)list;
	tlist->length = 0;

	return;

}


int SeqListLength(SeqList *list) {

	if (list == NULL)
	{
		return;
	}
	TSeqList *tlist = (TSeqList *)list;

	return tlist->length;
}


int SeqListCapacity(SeqList *list) {

	if (list == NULL)
	{
		return;
	}
	TSeqList *tlist = (TSeqList *)list;

	return tlist->capacity;


}


int SeqListInsert(SeqList *list, SeqListNode *node, int pos) {

	int ret = 0,i = 0;
	TSeqList *tlist = (TSeqList *)list;

	if (list == NULL || tlist->node == NULL ||pos < 0)
	{
		ret = -1;
		return ret;
	}
	 if (tlist->length >= tlist->capacity)
	{
		ret = -2;
		return ret;
	}
	
	if (pos > tlist->length)
	{
		pos = tlist->length;
	}

	for (i = tlist->length; i >=pos;i--)
	{
		tlist->node[i+1] = tlist->node[i];
	}
	tlist->node[pos] = node;
	tlist->length++;

	return ret;
}


SeqListNode * SeqListGet(SeqList *list, int pos) {

	int  i = 0;
	TSeqList *tlist = (TSeqList *)list;
	SeqListNode *ret = NULL;

	if (list == NULL || tlist->node == NULL || pos < 0 || pos > tlist->length)
	{
		ret = -1;
		return ret;
	}

	ret = tlist->node[pos];

	return ret;

}


SeqListNode * SeqListDelete(SeqList *list, int pos) {

	int  i = 0;
	TSeqList *tlist = (TSeqList *)list;
	SeqListNode *ret = NULL;

	if (list == NULL || tlist->node == NULL || pos < 0 || pos > tlist->length)
	{
		ret = -1;
		return ret;
	}
	for (i = pos + 1; i < tlist->length;i++)
	{
		tlist->node[i] = tlist->node[i+1];
	}

	tlist->length--;

	return tlist->node[pos];

}