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

	ListNode* prev_;
	ListNode* next_;
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
		:pnode_(pnode)
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
		return pnode_ = pnode_->next_;
	}
	Lit operator++(int)
	{
		Lit tmp(*this);
		pnode_ = pnode_->next_;
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
	//���캯��---�յ�list
	List()
	{
		Create();
	}
	//���캯��----n��val��list
	List(size_t n, const T& val = T())
	{
		Create();

	}
	//���캯��
	List(const List& list)
	{
		head_ = list.head_;
	}
	//ͨ���������Ĺ���
	List(iterator firdt, iterator end)
	{

	}
private:
	PNode head_;
	void Create()
	{
		head_ = new Node;
		head_->prev_ = head_->next_ = head_;
	}
};

