#pragma once
#include<iostream>
using namespace std;
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

	ListNode<T>* prev_;
	ListNode<T>* next_;
	T val_;
};

//list不能直接用[]访问，所以我们必须实现它的迭代器
//迭代器类--->原生指针++对象要是连续的。所以list迭代器不是原生指针，因为list不是连续的。所以要封装迭代器
//封装的是list的结点
template <class T>
class ListIterator
{
public:
	typedef ListNode<T>* PNode;
	typedef ListIterator<T> Lit;
	//迭代器的构造
	ListIterator(PNode pnode = nullptr)
		:pnode_(pnode)
	{}
	//迭代器的拷贝构造
	ListIterator(const Lit& lit)
	{
		pnode_(lit.pnode_);
	}
	//迭代器的运算符
		//解引用：取的是指针指向该节点的数据
	T& operator *()
	{
		return pnode_->val_;
	}
		//指针：->
	T* operator ->()
	{
		return &(pnode_->val_);
	}
	//判断
	bool operator !=(const Lit& lit)
	{
		return pnode_ != lit.pnode_;
	}
	bool operator ==(const Lit& lit)
	{
		return !(*this != lit);
	}
	//++操作。返回*this也可以，++迭代器的返回还是迭代器的本身
	Lit& operator++()
	{
		pnode_ = pnode_->next_;
		return *this;
	}
	Lit operator++(int)
	{
		Lit tmp(*this);
		pnode_ = pnode_->next_;
		return tmp;
	}
	PNode pnode_;//ListNode<T>*
};

template <class T>
class ConstListIterator
{
public:
	typedef ListNode<T>* PNode;
	typedef ListIterator<T> Lit;
	//迭代器的构造
	ConstListIterator(PNode pnode = nullptr)
		:pnode_(pnode)
	{}
	//迭代器的拷贝构造
	ConstListIterator(const Lit& lit)
	{
		pnode_(lit.pnode_);
	}
	//迭代器的运算符
		//解引用：取的是指针指向该节点的数据
	const T& operator *()
	{
		return pnode_->val_;
	}
	//指针：->
	const T* operator ->()
	{
		return &(pnode_->val_);
	}
	//判断
	const bool operator !=(const Lit& lit)
	{
		return pnode_ != lit.pnode_;
	}
	const bool operator ==(const Lit& lit)
	{
		return !(*this != lit);
	}
	const PNode pnode_;//ListNode<T>*
};


//list类
template <class T>
class List
{
public:
	//结点
	typedef ListNode<T> Node;
	typedef ListNode<T>* PNode;
	//迭代器
	typedef ListIterator<T> iterator;
	typedef ConstListIterator<T> const_iterator;
	//构造函数---空的list
	List()
	{
		Create();
	}
	//构造函数----n个val的list
	List(size_t n, const T& val = T())
	{
		Create();
		for (size_t i = 0; i < n; ++i)
		{
			PushBack(val);
		}
	}
	//拷贝构造函数
	List(const List& list)
	{
		Create();
		List<T> tmp(list.cbegin(),list.cend());
		Swap(tmp);
	}
	//通过迭代器的构造
	template <class Iterator>
	List(Iterator firdt, Iterator end)
	{
		Create();
		while (firdt != end)
		{
			PushBack(*firdt);
			++firdt;
		}
	}

	T& Front()
	{
		return head_->next_->val_;
	}

	T& Back()
	{
		return head_->prev_->val_;
	}
	const T& Front() const
	{
		return head_->next_->val_;
	}

	const T& Back() const
	{
		return head_->prev_->val_;
	}

	void PushBack(const T& val)
	{
		PNode node = new Node(val);
		node->next_ = head_;//插入的结点的后继指向头结点
		node->prev_ = head_->prev_;//插入结点的前驱指向原本头结点的前驱
		head_->prev_->next_ = node;//原本头节点的前驱的后继指向新结点
		head_->prev_ = node;//头节点的前驱指向新结点
	}
	void PopBack()
	{
		head_->prev_->prev_->next_ = head_;
		head_->prev_ = head_->prev_->prev_;
	}
	void PushFront(const T& val)
	{
		PNode node = new Node(val);
		node->next_ = head_->next_;
		node->prev_ = head_;
		head_->next_->prev_ = node;
		head_->next_ = node;
	}
	void PopFront()
	{
		head_->next_->next_->prev_ = head_;
		head_->next_ = head_->next_->next_;
	}
	iterator Insert(iterator pos, const T& val)
	{
		PNode node = new Node(val);
		node->next_ = pos.pnode_;
		node->prev_ = pos.pnode_->prev_;
		pos.pnode_->prev_ ->next_= node;
		pos.pnode_->prev_ = node;
		return iterator(node);
	}
	iterator Erase(iterator pos)
	{
		PNode savenode = pos.pnode_->next_;
		pos.pnode_->prev_->next_ = pos.pnode_->next_;
		pos.pnode_->next_->prev_ = pos.pnode_->prev_;
		delete pos.pnode_;//????
		return iterator(savenode);
	}
	void Resize(size_t n,const T& val = T())
	{
		PNode node = new Node;
		size_t size = Size();
		if (n < size)
		{
			for (size_t i = 0; i < size - n; ++i)
			{
				PopBack();
			}
		}
		else
		{
			for (size_t i = 0; i < n; ++i)
			{
				PushBack(val);
			}
		}
	}


	//迭代器
	iterator begin()
	{
		return iterator(head_->next_);
	}
	iterator end()
	{
		return iterator(head_);
	}
	const_iterator cbegin()
	{
		return const_iterator(head_->next_);
	}
	const_iterator cend()
	{
		return const_iterator(head_);
	}

	~List()
	{
		if (head_)
		{
			PNode tmp = head_->next_;
			PNode next;
			while (tmp != head_)
			{
				next = tmp->next_;
				delete tmp;
				tmp = next;
			}
			delete head_;
			head_ = nullptr;
		}
	}



	//工具
	void Swap(List<T>& list)
	{
		swap(head_, list.head_);
	}
	size_t Size()
	{
		iterator move = begin();
		iterator lend = end();
		size_t len = 0;
		while (move != lend)
		{
			++len;
			++move;
		}
		return len;
	}


private:
	//头节点的指针
	PNode head_;

	//ListNode的构造是全缺省的可以不用传参数
	void Create()
	{
		head_ = new Node;
		head_->prev_ = head_->next_ = head_;
	}
};

