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

	//元素前移
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

	//元素后移
	for (i = length; i > pos;i--){
	
		pArray[i] = pArray[i-1];
	}

	//注意:stl元素保存时候是通过复制的机制实现的,自定义的类必须要可复制才可以这么写,否则需要重载=运算符
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