#include "SeqStack.h"
#include "SeqList.h"


//创建栈相当于创建线性表
SeqStack *SeqStackCreate(int capacity){


	return SeqListCreate(capacity);
}

//销毁栈相当于销毁线性表
void SeqStackDestroy(SeqStack *stack){


	return SeqListDestroy(stack);

}


void SeqStackClear(SeqStack *stack){


	return SeqListClear(stack);

}


int  SeqStackSize(SeqStack *stack){

	return SeqListLength(stack);

}


int SeqStackCapacity(SeqStack *stack)
{

	return SeqListCapacity(stack);
}

void *SeqStackTop(SeqStack *stack){

	return SeqListGet(stack, SeqListLength(stack) - 1);

}

//从栈中弹出元素相当于从线性表尾部取出元素
void *SeqStackPop(SeqStack *stack){

	return SeqListDelete(stack, SeqListLength(stack) - 1);

}

//向栈中压入元素相当于向线性表中尾部插入元素
int SeqStackPush(SeqStack *stack,void *item){


	return SeqListInsert(stack, item, SeqListLength(stack));//尾插法

}

