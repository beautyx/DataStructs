
#include "LinkList.h"

typedef struct _tag_LinkList{

	LinkListNode header;
	int length;


}TLinkList;

LinkList * LinkListCreate()
{
	TLinkList *list = (TLinkList *)malloc(sizeof(TLinkList));
	if (list == NULL)
	{
		return NULL;
	}

	memset(list, 0, sizeof(TLinkList));
	list->header.next = NULL;
	list->length = 0;
	return list;

}

void LinkListDestroy(LinkList *list)
{
	if (list == NULL)
	{
		return ;
	}

	free(list);
	list = NULL;

	return;
	
}

void LinkListClear(LinkList *list)
{
	if (list == NULL)
	{
		printf("LinkListClear error\n");

		return;
	}

	TLinkList *tlist = (TLinkList *)list;
	tlist->header.next = NULL;
	tlist->length = 0;

	return;

}


int LinkListLength(LinkList *list)
{
	int ret = 0;
	if (list == NULL)
	{
		ret = -1;
		return ret ;
	}

	TLinkList *tlist = (TLinkList *)list;

	return tlist->length;
}

int LinkListInsert(LinkList *list, LinkListNode *node, int pos)
{
	int ret = 0,i = 0;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		return ret;
	}


	TLinkList *tlist = (TLinkList *)list;

	if (pos >= tlist->length)
	{
		pos >= tlist->length;
	}

	LinkListNode *cur = &tlist->header;

	for (i = 0; i < pos && (cur->next != NULL); i++)
	{
		cur = cur->next;
	}


	LinkListNode * next = cur->next;

	node->next = next;
	cur->next = node;

	tlist->length++;

	return ret;

}

LinkListNode * LinkListGet(LinkList *list, int pos)
{
	int  i = 0;
	LinkListNode *ret = NULL;
	TLinkList *tlist = (TLinkList *)list;

	if (list == NULL || pos < 0 || pos > tlist->length)
	{

		return ret;
	}

	LinkListNode *cur = &tlist->header;

	for (i = 0; i < pos && (cur->next != NULL); i++)
	{
		cur = cur->next;
	}

	ret = cur->next;

	return ret;
}

LinkListNode * LinkListDelete(LinkList *list, int pos)
{
	int  i = 0;
	LinkListNode *ret = NULL;
	TLinkList *tlist = (TLinkList *)list;

	if (list == NULL || pos < 0 || pos > tlist->length || tlist->length == 0)
	{
		
		return ret;
	}

	LinkListNode *cur = &tlist->header;

	for (i = 0; i < pos && (cur->next != NULL); i++)
	{
		cur = cur->next;
	}

	 ret= cur->next ;
	 cur->next = ret->next;

	 tlist->length--;

	return ret;
}

LinkListNode * LinkListDeleteNode(LinkList *list, LinkListNode *node)
{
	int  i = 0,pos = 0;
	LinkListNode *ret = NULL;
	TLinkList *tlist = (TLinkList *)list;

	if (list == NULL || pos < 0 || pos > tlist->length)
	{

		return ret;
	}

	LinkListNode *cur = &tlist->header;

	for (i = 0; i < tlist->length; i++)
	{

		if (node == cur->next)
		{
			pos = i;
			break;
		}
		cur = cur->next;
	}

	ret = LinkListDelete(tlist,pos);

	return ret;
}
