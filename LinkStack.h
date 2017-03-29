#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef void LinkStack;

/*

	为了省去遍历链表的操作所以选用在链表的头部插入和删除操作来模拟栈的push和pop

*/

//创建链栈相当于创建链表
LinkStack *LinkStackCreate();
//销毁链栈
void LinkStackDestroy(LinkStack *stack);
//清空链栈
void LinkStackClear(LinkStack *stack);
//获取链栈的大小
int LinkStackSize(LinkStack *stack);

//获取链栈顶部的元素
void *LinkStackTop(LinkStack *stack);
//弹出栈顶元素
void *LinkStackPop(LinkStack *stack);
//push元素入链栈
int linkStackPush(LinkStack *stack, void *item);