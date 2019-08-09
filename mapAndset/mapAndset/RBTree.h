#pragma once
#include<iostream>
using namespace std;

// 节点的颜色
enum Color { 
	RED, 
	BLACK
};
// 红黑树节点的定义
template<class T>
struct RBTreeNode
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeNode<T>* pNode;

	pNode pLeft_ = nullptr; // 节点的左孩子
	pNode pRight_ = nullptr; // 节点的右孩子
	pNode pParent_ = nullptr; // 节点的双亲(红黑树需要旋转，为了实现简单给出该字段)
	T data_; // 节点的值域，自定义类型调用自己的默认构造
	Color color_ = RED; // 节点的颜色,初始化成黑色，插入时要改成红色，因为插入黑色就破坏了红黑树的性质
						//每条路径上的黑色结点数量是相同的
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
			//防止没有右子树，造成死循环
			if(node_->pRight_ != parent)
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
	//向源码对齐
	pair<iterator,bool> Insert(const V& data)
	{
		if (header_->pParent_ == nullptr)
		{//空树的情况下，互相认爹
			pNode root = new Node;
			root->pParent_ = header_;
			header_->pParent_ = root;

			root->data_ = data;
			root->color_ = BLACK;
			header_->pLeft_ = root;
			header_->pRight_ = root;

			return make_pair<iterator(root), true>;
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
				return make_pair<iterator(cur), false>;
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
		//1、叔叔存在且为红————修改颜色，将p,u改为黑，g改为红，然后把g当成cur，继续向上调整，直到遇见黑的。
		//2、	叔叔存在且为黑或者不存在，以祖父结点为轴旋转，
			//同平衡树——
				//1）p为左c为左，右旋
				//2）p为右c为右，左旋
				//3）p为左c为右，左右旋
				//4）p为右c为左，有左旋

		while (cur != header_ ->pParent_ && cur->pParent_->color_ == RED)//直到遇见黑的或者是根节点
		{
			//cur：插入时的结点
			//parent：cur的父亲结点
			//gparent：cur的祖父结点
			//uncle：cur的叔叔结点
			pNode parent = cur->pParent_;
			pNode gparent = parent->pParent_;
			if (gparent->pLeft_ == parent)//父亲在做，则叔叔在右
			{
				pNode uncle = gparent->pRight_;
				if (uncle && uncle->color_ == RED)
	//叔叔存在且为红————修改颜色，将p, u改为黑，g改为红，然后把g当成cur，继续向上调整，直到遇见黑的。
				{
					parent->color_ = uncle->color_ = BLACK;
					gparent->color_ = RED;
					cur = gparent;
				}
				else
				{
					//叔叔为空或者是黑色，都需要旋转
				//1）p为左c为左，右旋、如果p为左c为右，左右旋
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
			else     //反之父亲在右叔叔在左
			{
				pNode uncle = gparent->pLeft_;
				if (uncle && uncle->color_ == RED)
					//叔叔存在且为红————修改颜色，将p, u改为黑，g改为红，然后把g当成cur，继续向上调整，直到遇见黑的。
				{
					parent->color_ = uncle->color_ = BLACK;
					gparent->color_ = RED;
					cur = gparent;
				}
				else
				{
					//叔叔为空或者是黑色，都需要旋转
				//p为右c为右，左旋
				//4）p为右c为左，右左旋
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

		header_->pParent_->color_ = BLACK;//不管是不是根，根都是黑色
		header_->pParent_->pParent_ = header_;
		header_->pLeft_ = leftMost();//插入完左边更新
		header_->pRight_ = rightMost();//右边更新
		return make_pair<iterator(cur), true>;
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
	//右旋，以双亲结点为轴
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
	//左旋：右边的右边高	parent->bf = 2   cur->bf = 1
	//以双亲结点为轴
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

