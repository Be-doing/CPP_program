#pragma once

//结点类
template<class T>
class ListNode
{
public:
	ListNode(const T val = T())
	:val_(val),
		prev_(nullptr),
		next_(nullptr)
	{}
private:
	ListNode* prev_;
	ListNode* nxst_;
	T val_;
};


//迭代器类
//封装的是list的结点
template <class T>
class ListIterator
{
public:
	typedef ListNode<T>* PNode;
	typedef ListIterator<T> Lit;
	//迭代器的构造
	ListIterator(PNode pnode = nullptr)
		:pnode_(pnod)
	{}
	//迭代器的拷贝构造
	ListIterator(const Lit& lit)
	{
		pnode_(lit.pnode_);
	}
	//迭代器的运算符
		//解引用：取的是指针指向该节点的数据
	T& operator*()
	{
		return pnode_->val_;
	}
		//->
	T* operator ->()
	{
		return &(pnode_->val_);
	}
	//判断
	bool operator!=(const Lit& lit)
	{
		return pnode_ != lit.pnode_;
	}
	bool operator==(const Lit& lit)
	{
		return !(*this != lit);
	}
	//++操作
	Lit& operator++()
	{
		return pnode_ = pnode_->nxst_;
	}
	Lit operator++(int)
	{
		Lit tmp(*this);
		pnode_ = pnode_->nxst_;
		return tmp;
	}
private:
	PNode pnode_;//ListNode<T>*
};



//list类
template <class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef ListNode<T>* PNode;
	List(const T& val = T())
	{

	}
	List(const List& list)
	{
		head_ = list.head_;
	}
private:
	PNode head_;
	void Create(const T& val = T())
	{
		head_ = new Node;
		head->prev = head_->nxst_ = head_;
		head->val_ = val;
	}
};

