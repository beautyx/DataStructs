#pragma 

//�ڲ���Ԫ��ʱ,ģ����Ӧ�ð�ÿһ��t��������
// ģ������Ӧ�ÿ��Է���ڵ�\����ڵ�

//��������--��һ��linklist
template <typename T>
struct Node{

	T t;
	Node<T> * next;

};

template <typename T>
class LinkList
{
public:
	LinkList();
	~LinkList();

	int clear();
	int getLen();
	int insert(T &t,int pos);
	int dele(T &t, int pos);
	int get(int pos,T &t);

private:
	Node<T>* head;//����һ����ͷ�ڵ������
	int len;
	
};



