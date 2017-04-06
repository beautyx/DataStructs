#include "LinkQueue.h"
#include "LinkList.h"

//队列的业务节点的数据结构

typedef struct _tag_LinkQueueNode{

	LinkListNode node;
	void *item;


}TLinkQueueNode;

LinkQueue * LinkQueueCreate()
{
	return LinkListCreate();
}

void LinkQueueDestroy(LinkQueue *queue)
{
	LinkQueueClear(queue);
	LinkListDestroy(queue);
}

void LinkQueueClear(LinkQueue *queue)
{
	while (LinkQueueLength(queue) > 0)
	{
		LinkQueueRetrieve(queue);
	}

	LinkListClear(queue);

	return;
}

int LinkQueueAppend(LinkQueue *queue, void *item)
{
	//需要把栈的item(栈的业务节点转化成链表的节点)
	int ret = 0;
	TLinkQueueNode *tmp = (TLinkQueueNode *)malloc(sizeof(TLinkQueueNode));
	if (tmp == NULL)
	{
		ret = -1;
		printf("LinkQueueAppend error:%d\n",ret);
		return ret;
	}
	memset(tmp, 0, sizeof(TLinkQueueNode));
	tmp->node.next = NULL;
	tmp->item = item;

	ret = LinkListInsert(queue, (TLinkQueueNode *)tmp, LinkQueueLength(queue));
	if (ret != 0)
	{
		printf("LinkListInsert error :%d\n", ret);
		if (tmp != NULL)
		{
			free(tmp);
			tmp = NULL;
		}
		return ret;
	}
	return ret;
}

void * LinkQueueRetrieve(LinkQueue *queue)
{
	TLinkQueueNode * ret = NULL;
	TLinkQueueNode *tmp = (TLinkQueueNode *)LinkListDelete(queue, 0);

	if (tmp == NULL)
	{
		printf("LinkListDelete error.\n");
		return ret;
	}
	ret = tmp->item;
	free(tmp);
	tmp = NULL;

	return ret;
}

//获取队列头部元素相当于从链表的0号位置拿出数据
void * LinkQueueHeader(LinkQueue *queue)
{
	TLinkQueueNode * ret = NULL;
	TLinkQueueNode *tmp = (TLinkQueueNode *)LinkListGet(queue, 0);

	if (tmp == NULL)
	{
		printf("LinkListGet error.\n");
		return ret;
	}
	ret = tmp->item;
	return ret;
}

int LinkQueueLength(LinkQueue *queue)
{
	return LinkListLength(queue);
}


