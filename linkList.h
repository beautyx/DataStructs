#pragma 

//在插入元素时,模板类应该把每一个t保存下来
// 模板类中应该可以分配节点\缓存节点

//怎样缓存--做一个linklist
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
	Node<T>* head;//创建一个带头节点的链表
	int len;
	
};



