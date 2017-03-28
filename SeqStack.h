#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef void SeqStack;


//创建栈相当于创建线性表
SeqStack *SeqStackCreate(int capacity);
//销毁线性栈
void SeqStackDestroy(SeqStack *stack);
//获取线性栈的大小
int SeqStackSize(SeqStack *stack);
//获取线性栈的容量
int SeqStackCapacity(SeqStack *stack);
//获取线性栈顶部的元素
void *SeqStackTop(SeqStack *stack);
//弹出栈顶元素
void *SeqStackPop(SeqStack *stack);
//push元素入线性栈
int SeqStackPush(SeqStack *stack,void *item);

