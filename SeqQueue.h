#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef void SeqQueue;

SeqQueue * SeqQueueCreate(int capacity);
void SeqQueueDestroy(SeqQueue *queue);
void SeqQueueClear(SeqQueue *queue);
int SeqQueueAppend(SeqQueue *queue, void *item);
void *SeqQueueRetrieve(SeqQueue *queue);
void *SeqQueueHeader(SeqQueue *queue);
int SeqQueueLength(SeqQueue *queue);
int SeqQueueCapacity(SeqQueue *queue);
