#pragma once
#include<iostream>
using namespace std;

// �ڵ����ɫ
enum Color { 
	RED, 
	BLACK
};
// ������ڵ�Ķ���
template<class T>
struct RBTreeNode
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeNode<T>* pNode;

	pNode pLeft_ = nullptr; // �ڵ������
	pNode pRight_ = nullptr; // �ڵ���Һ���
	pNode pParent_ = nullptr; // �ڵ��˫��(�������Ҫ��ת��Ϊ��ʵ�ּ򵥸������ֶ�)
	T data_; // �ڵ��ֵ���Զ������͵����Լ���Ĭ�Ϲ���
	Color color_ = RED; // �ڵ����ɫ,��ʼ���ɺ�ɫ������ʱҪ�ĳɺ�ɫ����Ϊ�����ɫ���ƻ��˺����������
						//ÿ��·���ϵĺ�ɫ�����������ͬ��
};

template <class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T>* pNode;
	typedef RBTreeIterator<T> Self;
	pNode node_;

	RBTreeIterator(pNode node)
		:node_(node)
	{}

	T& operator*()
	{
		return node_->data_;
	}

	T* operator->()
	{
		return &operator*();
	}

	bool operator!=(Self rbt)
	{
		return node_ != rbt.node_;
	}
	Self operator++()
	{
		if (node_->pRight_)
		{
			node_ = node_->pRight_;
			while (node_->pLeft_)
			{
				node_ = node_->pLeft_;
			}
		}
		else
		{
			pNode parent = node_->pParent_;
			while (node_ == parent->pRight_)
			{
				node_ = parent;
				parent = node_->pParent_;
			}
			node_ = parent;
		}
		return *this;
	}
	Self operator++(int)
	{
		Self tmp(*this);
		++(*this);
		return tmp;
	}
};

template<class K, class V>
class BRTree
{
public:
	typedef RBTreeNode<V> Node;
	typedef RBTreeNode<V>* pNode;
	typedef RBTreeIterator<V> iterator;


	BRTree()
	{
		header_ = new Node;
		header_->pLeft_ = header_;
		header_->pRight_ = header_;
		header_->pParent_ = nullptr;
	}

	iterator begin()
	{
		return iterator(header_->pLeft_);
	}
	iterator end()
	{
		return iterator(header_);
	}
	bool Insert(const V& data)
	{
		if (header_->pParent_ == nullptr)
		{//����������£������ϵ�
			pNode root = new Node;
			root->pParent_ = header_;
			header_->pParent_ = root;

			root->data_ = data;
			root->color_ = BLACK;
			header_->pLeft_ = root;
			header_->pRight_ = root;

			return true;
		}


		pNode cur = header_->pParent_;
		pNode parent = header_;

		while (cur)
		{
			if (k(data) >k(cur->data_))
			{
				parent = cur;
				cur = cur->pRight_;
			}
			else if (k(data) <k(cur->data_))
			{
				parent = cur;
				cur = cur->pLeft_;
			}
			else
			{
				return false;
			}
		}

		pNode newnode = new Node;
		newnode->data_ = data;

		if (k(parent->data_) > k(data))
		{
			parent->pLeft_ = newnode;
		}
		else
		{
			parent->pRight_ = newnode;
		}
		newnode->pParent_ = parent;
		cur = newnode;
		//1�����������Ϊ�졪�������޸���ɫ����p,u��Ϊ�ڣ�g��Ϊ�죬Ȼ���g����cur���������ϵ�����ֱ�������ڵġ�
		//2��	���������Ϊ�ڻ��߲����ڣ����游���Ϊ����ת��
			//ͬƽ��������
				//1��pΪ��cΪ������
				//2��pΪ��cΪ�ң�����
				//3��pΪ��cΪ�ң�������
				//4��pΪ��cΪ��������

		while (cur != header_ ->pParent_ && cur->pParent_->color_ == RED)//ֱ�������ڵĻ����Ǹ��ڵ�
		{
			//cur������ʱ�Ľ��
			//parent��cur�ĸ��׽��
			//gparent��cur���游���
			//uncle��cur��������
			pNode parent = cur->pParent_;
			pNode gparent = parent->pParent_;
			if (gparent->pLeft_ == parent)//��������������������
			{
				pNode uncle = gparent->pRight_;
				if (uncle && uncle->color_ == RED)
	//���������Ϊ�졪�������޸���ɫ����p, u��Ϊ�ڣ�g��Ϊ�죬Ȼ���g����cur���������ϵ�����ֱ�������ڵġ�
				{
					parent->color_ = uncle->color_ = BLACK;
					gparent->color_ = RED;
					cur = gparent;
				}
				else
				{
					//����Ϊ�ջ����Ǻ�ɫ������Ҫ��ת
				//1��pΪ��cΪ�����������pΪ��cΪ�ң�������
					if (parent->pRight_ == cur)
					{
						RotateL(parent);
						swap(cur, parent);
					}
					RotateR(gparent);
					parent->color_ = BLACK;
					gparent->color_ = RED;
					break;
				}
			}
			else     //��֮����������������
			{
				pNode uncle = gparent->pLeft_;
				if (uncle && uncle->color_ == RED)
					//���������Ϊ�졪�������޸���ɫ����p, u��Ϊ�ڣ�g��Ϊ�죬Ȼ���g����cur���������ϵ�����ֱ�������ڵġ�
				{
					parent->color_ = uncle->color_ = BLACK;
					gparent->color_ = RED;
					cur = gparent;
				}
				else
				{
					//����Ϊ�ջ����Ǻ�ɫ������Ҫ��ת
				//pΪ��cΪ�ң�����
				//4��pΪ��cΪ��������
					if (parent->pLeft_ == cur)
					{
						RotateR(parent);
						swap(cur, parent);
					}
					RotateL(gparent);
					parent->color_ = BLACK;
					gparent->color_ = RED;
					break;
				}
			}
		}

		header_->pParent_->color_ = BLACK;//�����ǲ��Ǹ��������Ǻ�ɫ
		header_->pParent_->pParent_ = header_;
		header_->pLeft_ = leftMost();//��������߸���
		header_->pRight_ = rightMost();//�ұ߸���
		return true;
	}

	pNode leftMost()
	{
		pNode cur = header_->pParent_;
		while (cur && cur->pLeft_)
		{
			cur = cur->pLeft_;
		}
		return cur;
	}

	pNode rightMost()
	{
		pNode cur = header_->pParent_;
		while (cur && cur->pRight_)
		{
			cur = cur->pRight_;
		}
		return cur;
	}
	//��������˫�׽��Ϊ��
	void RotateR(pNode parent)
	{
		pNode subL = parent->pLeft_;
		pNode subLR = subL->pRight_;

		subL->pRight_ = parent;
		parent->pLeft_ = subLR;

		if (subLR)
		{
			subLR->pParent_ = parent;
		}
		if (parent == header_->pParent_)
		{
			header_->pParent_ = subL;
			subL->pParent_ = nullptr;
		}
		else
		{
			pNode gpraent = parent->pParent_;
			if (gpraent->pLeft_ == parent)
			{
				gpraent->pLeft_ = subL;
			}
			else
			{
				gpraent->pRight_ = subL;
			}
			subL->pParent_ = gpraent;
		}

		parent->pParent_ = subL;
	}
	//�������ұߵ��ұ߸�	parent->bf = 2   cur->bf = 1
	//��˫�׽��Ϊ��
	void RotateL(pNode parent)
	{
		pNode subR = parent->pRight_;
		pNode subRL = subR->pLeft_;

		subR->pLeft_ = parent;
		parent->pRight_ = subRL;

		if (subRL)
		{
			subRL->pParent_ = parent;
		}

		if (parent == header_->pParent_)
		{
			subR->pParent_ = nullptr;
			header_->pParent_ = subR;

		}
		else
		{
			pNode gparent = parent->pParent_;

			if (gparent->pLeft_ == parent)
			{
				gparent->pLeft_ = subR;
			}
			else
			{
				gparent->pRight_ = subR;
			}
			subR->pParent_ = gparent;
		}
		parent->pParent_ = subR;
	}
private:
	pNode header_;
	K k;
};

