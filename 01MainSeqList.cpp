#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "SeqList.cpp"//ʹ��ģ��Ӧ������cpp�ļ�����hpp
using namespace std;

struct Teacher{

	char name[64];
	int age;

};

int main_seqlist_play(){

	Teacher t1, t2, t3,tmp;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	SeqList<Teacher> list(10);
	list.insert(t1, 0);
	list.insert(t2, 0);
	list.insert(t3, 0);

	//����ı���
	for (int i = 0; i < list.getLen();i++)
	{
		list.get(i, tmp);
		cout << tmp.age << endl;
	}

	//���������
	while (list.getLen() > 0 )
	{
		list.dele(0, tmp);
		cout << tmp.age << endl;

	}


	return 0;
}



int main(){

	main_seqlist_play();

	printf("hello...\n");

	system("pause");
	return EXIT_SUCCESS;
}