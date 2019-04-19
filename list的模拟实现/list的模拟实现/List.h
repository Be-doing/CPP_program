#pragma once
#include<iostream>
using namespace std;
//�����
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

//list����ֱ����[]���ʣ��������Ǳ���ʵ�����ĵ�����
//��������--->ԭ��ָ��++����Ҫ�������ġ�����list����������ԭ��ָ�룬��Ϊlist���������ġ�����Ҫ��װ������
//��װ����list�Ľ��
template <class T>
class ListIterator
{
public:
	typedef ListNode<T>* PNode;
	typedef ListIterator<T> Lit;
	//�������Ĺ���
	ListIterator(PNode pnode = nullptr)
		:pnode_(pnode)
	{}
	//�������Ŀ�������
	ListIterator(const Lit& lit)
	{
		pnode_(lit.pnode_);
	}
	//�������������
		//�����ã�ȡ����ָ��ָ��ýڵ������
	T& operator *()
	{
		return pnode_->val_;
	}
		//ָ�룺->
	T* operator ->()
	{
		return &(pnode_->val_);
	}
	//�ж�
	bool operator !=(const Lit& lit)
	{
		return pnode_ != lit.pnode_;
	}
	bool operator ==(const Lit& lit)
	{
		return !(*this != lit);
	}
	//++����������*thisҲ���ԣ�++�������ķ��ػ��ǵ������ı���
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
	//�������Ĺ���
	ConstListIterator(PNode pnode = nullptr)
		:pnode_(pnode)
	{}
	//�������Ŀ�������
	ConstListIterator(const Lit& lit)
	{
		pnode_(lit.pnode_);
	}
	//�������������
		//�����ã�ȡ����ָ��ָ��ýڵ������
	const T& operator *()
	{
		return pnode_->val_;
	}
	//ָ�룺->
	const T* operator ->()
	{
		return &(pnode_->val_);
	}
	//�ж�
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


//list��
template <class T>
class List
{
public:
	//���
	typedef ListNode<T> Node;
	typedef ListNode<T>* PNode;
	//������
	typedef ListIterator<T> iterator;
	typedef ConstListIterator<T> const_iterator;
	//���캯��---�յ�list
	List()
	{
		Create();
	}
	//���캯��----n��val��list
	List(size_t n, const T& val = T())
	{
		Create();
		for (size_t i = 0; i < n; ++i)
		{
			PushBack(val);
		}
	}
	//�������캯��
	List(const List& list)
	{
		Create();
		List<T> tmp(list.cbegin(),list.cend());
		Swap(tmp);
	}
	//ͨ���������Ĺ���
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
		node->next_ = head_;//����Ľ��ĺ��ָ��ͷ���
		node->prev_ = head_->prev_;//�������ǰ��ָ��ԭ��ͷ����ǰ��
		head_->prev_->next_ = node;//ԭ��ͷ�ڵ��ǰ���ĺ��ָ���½��
		head_->prev_ = node;//ͷ�ڵ��ǰ��ָ���½��
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


	//������
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



	//����
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
	//ͷ�ڵ��ָ��
	PNode head_;

	//ListNode�Ĺ�����ȫȱʡ�Ŀ��Բ��ô�����
	void Create()
	{
		head_ = new Node;
		head_->prev_ = head_->next_ = head_;
	}
};

