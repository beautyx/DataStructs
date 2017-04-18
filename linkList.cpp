#include "LinkList.h"


template <typename T>
LinkList<T>::LinkList()
{
	//创建一个带头节点的链表
	head = new Node<T>;
	head->next = NULL;
	this->len = 0;


}

template <typename T>
LinkList<T>::~LinkList()
{
	Node<T> *tmp = NULL;

	while (head != NULL)
	{
		tmp = head->next;//删除链表缓存后面节点

		delete head;
		head = tmp;
	}

	this->len = 0;
	head = NULL;


}


template <typename T>
int LinkList<T>::get(int pos, T &t)
{
	Node<T> *cur = NULL;
	cur = this->head;

	for (int i = 0; i < pos; i++)
	{
		cur = cur->next;
	}

	t = cur->next->t;
	return 0;

}

template <typename T>
int LinkList<T>::dele(T &t, int pos)
{
	Node<T> *cur = NULL;
	Node<T> *ret = NULL;

	cur = this->head;

	for (int i = 0; i < pos; i++)
	{
		cur = cur->next;
	}

	ret = cur->next;//被删除的元素
	t = ret->t;//把缓存的t拷贝出来

	cur->next = ret->next;
	this->len--;

	delete ret;

	return 0;

}

template <typename T>
int LinkList<T>::insert(T &t, int pos)
{
	Node<T> *cur = NULL;
	cur = this->head;

	for (int i = 0; i < pos;i++)
	{
		cur = cur->next;
	}

	Node<T>* node = new Node<T>;
	if (node == NULL)
	{
		return -1;
	}
	node->t = t;
	node->next = NULL;

	node->next = cur->next;
	cur->next = node;
	this->len++;

	return 0;

}

template <typename T>
int LinkList<T>::getLen()
{
	return this->len;
}

template <typename T>
int LinkList<T>::clear()
{
	Node<T> *tmp = NULL;

	while (head != NULL)
	{
		tmp = head->next;//删除链表缓存后面节点

		delete head;
		head = tmp;
	}

	head = new Node<T>;
	head->next = NULL;
	this->len = 0;

	return 0;
}