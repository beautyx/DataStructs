#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "LinkList.cpp"
using namespace std;

struct Teacher{

	char name[64];
	int age;
};

void main_linklist_play(){

	Teacher t1, t2, t3, tmp;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	LinkList<Teacher> list;
	list.insert(t1, 0);
	list.insert(t2, 0);
	list.insert(t3, 0);

	//测试链表的遍历
	for (int i = 0; i < list.getLen();i++)
	{
		list.get(i, tmp);
		cout <<tmp.age << endl;
	}

	list.clear();
	
	list.insert(t1, 0);
	list.insert(t2, 0);
	list.insert(t3, 0);

	//测试链表的遍历
	for (int i = 0; i < list.getLen(); i++)
	{
		list.get(i, tmp);
		cout << tmp.age << endl;
	}

	while (list.getLen() > 0)
	{
		list.dele(tmp,0);
		cout << tmp.age << " ";

	}

	return ;
	
}

int main(){

	main_linklist_play();

	system("pause");
	return EXIT_SUCCESS;
}