#pragma once

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
private:
	ListNode* prev_;
	ListNode* nxst_;
	T val_;
};


//��������
//��װ����list�Ľ��
template <class T>
class ListIterator
{
public:
	typedef ListNode<T>* PNode;
	typedef ListIterator<T> Lit;
	//�������Ĺ���
	ListIterator(PNode pnode = nullptr)
		:pnode_(pnod)
	{}
	//�������Ŀ�������
	ListIterator(const Lit& lit)
	{
		pnode_(lit.pnode_);
	}
	//�������������
		//�����ã�ȡ����ָ��ָ��ýڵ������
	T& operator*()
	{
		return pnode_->val_;
	}
		//->
	T* operator ->()
	{
		return &(pnode_->val_);
	}
	//�ж�
	bool operator!=(const Lit& lit)
	{
		return pnode_ != lit.pnode_;
	}
	bool operator==(const Lit& lit)
	{
		return !(*this != lit);
	}
	//++����
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



//list��
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

