#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef void LinkQueue;

LinkQueue * LinkQueueCreate();
void LinkQueueDestroy(LinkQueue *queue);
void LinkQueueClear(LinkQueue *queue);
int LinkQueueAppend(LinkQueue *queue, void *item);
void *LinkQueueRetrieve(LinkQueue *queue);
void *LinkQueueHeader(LinkQueue *queue);
int LinkQueueLength(LinkQueue *queue);
