#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef void LinkStack;

/*

	Ϊ��ʡȥ��������Ĳ�������ѡ���������ͷ�������ɾ��������ģ��ջ��push��pop

*/

//������ջ�൱�ڴ�������
LinkStack *LinkStackCreate();
//������ջ
void LinkStackDestroy(LinkStack *stack);
//�����ջ
void LinkStackClear(LinkStack *stack);
//��ȡ��ջ�Ĵ�С
int LinkStackSize(LinkStack *stack);

//��ȡ��ջ������Ԫ��
void *LinkStackTop(LinkStack *stack);
//����ջ��Ԫ��
void *LinkStackPop(LinkStack *stack);
//pushԪ������ջ
int linkStackPush(LinkStack *stack, void *item);