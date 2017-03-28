#include "SeqStack.h"
#include "SeqList.h"


//����ջ�൱�ڴ������Ա�
SeqStack *SeqStackCreate(int capacity){


	return SeqListCreate(capacity);
}

//����ջ�൱���������Ա�
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

//��ջ�е���Ԫ���൱�ڴ����Ա�β��ȡ��Ԫ��
void *SeqStackPop(SeqStack *stack){

	return SeqListDelete(stack, SeqListLength(stack) - 1);

}

//��ջ��ѹ��Ԫ���൱�������Ա���β������Ԫ��
int SeqStackPush(SeqStack *stack,void *item){


	return SeqListInsert(stack, item, SeqListLength(stack));//β�巨

}

