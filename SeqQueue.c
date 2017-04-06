#include "SeqQueue.h"
#include "SeqList.h"

//
SeqQueue * SeqQueueCreate(int capacity)
{

	return SeqListCreate(capacity);
}

void SeqQueueDestroy(SeqQueue *queue)
{

	return SeqListDestroy(queue);
}

void SeqQueueClear(SeqQueue *queue)
{
	return SeqListClear(queue);
}

int  SeqQueueAppend(SeqQueue *queue, void *item)
{
	return SeqListInsert(queue, item, SeqListLength(queue));
}

void * SeqQueueRetrieve(SeqQueue *queue)
{
	return SeqListDelete(queue, 0);
}

void * SeqQueueHeader(SeqQueue *queue)
{
	return SeqListGet(queue, 0);
}

int SeqQueueLength(SeqQueue *queue)
{

	return SeqListLength(queue);
}

int SeqQueueCapacity(SeqQueue *queue)
{

	return SeqListCapacity(queue);
}
