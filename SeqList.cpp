#include "SeqList.h"

template <typename T>
SeqList<T>::SeqList(int capacity)
{
	pArray = new T[capacity];
	this->capacity = capacity;
	this->length = 0;
}

template <typename T>
SeqList<T>::~SeqList()
{
	delete[] pArray;

	pArray = NULL;
	this->capacity = 0;
	this->length = 0;

}

template <typename T>
int SeqList<T>::dele(int pos, T &t)
{
	int i = 0;

	if ( pos < 0)
	{
		return -1;
	}

	t = pArray[pos];

	//Ԫ��ǰ��
	for (i = pos+1; i < this->length; i++){

		pArray[i-1] = pArray[i];
	}
	this->length--;

	return 0;
}

template <typename T>
int SeqList<T>::get(int pos, T &t)
{
	int i = 0;

	if ( pos < 0)
	{
		return -1;
	}

	t =	pArray[pos];


	return 0;

}

template <typename T>
int SeqList<T>::insert(T &t, int pos)
{
	int i = 0;

	if ( pos < 0 )
	{
		return -1;
	}

	//Ԫ�غ���
	for (i = length; i > pos;i--){
	
		pArray[i] = pArray[i-1];
	}

	//ע��:stlԪ�ر���ʱ����ͨ�����ƵĻ���ʵ�ֵ�,�Զ���������Ҫ�ɸ��Ʋſ�����ôд,������Ҫ����=�����
	pArray[i] = t;
	this->length++;

	return 0;

}

template <typename T>
int SeqList<T>::getCapacity()
{
	return this->capacity;

}

template <typename T>
int SeqList<T>::getLen()
{
	return this->length;

}