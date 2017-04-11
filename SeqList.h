#pragma once

template <typename T>

class SeqList
{
public:
	SeqList(int capacity);
	~SeqList();

	int getLen();
	int getCapacity();
	int insert(T &t,int pos);
	int get(int pos, T &t);
	int dele(int pos,T &t);

private:
	int length;
	int capacity;
	T *pArray;//สýื้
};



