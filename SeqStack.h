#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef void SeqStack;


//����ջ�൱�ڴ������Ա�
SeqStack *SeqStackCreate(int capacity);
//��������ջ
void SeqStackDestroy(SeqStack *stack);
//��ȡ����ջ�Ĵ�С
int SeqStackSize(SeqStack *stack);
//��ȡ����ջ������
int SeqStackCapacity(SeqStack *stack);
//��ȡ����ջ������Ԫ��
void *SeqStackTop(SeqStack *stack);
//����ջ��Ԫ��
void *SeqStackPop(SeqStack *stack);
//pushԪ��������ջ
int SeqStackPush(SeqStack *stack,void *item);

