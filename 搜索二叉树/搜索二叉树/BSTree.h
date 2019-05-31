#pragma once
#include<iostream>
using namespace std;

template<class T>
struct BTNode
{
	BTNode(const T& val = T())
		:val_(val)
		, left(nullptr)
		, right(nullptr)
	{}
	T val_;
	BTNode<T>* left;
	BTNode<T>* right;
};
template<class T>
class BTree
{
public:
	typedef BTNode<T> Node;
	BTree()
		:root_(nullptr)
	{}
	BTree(const BTree<T>& bst)
	{

	}

	BTree<T>& operator=(const BTree<T>& bst)
	{
		
	}
	Node* Find(const T& val)
	{
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return root_;
		}
		Node* cur = root_;
		while (cur)
		{
			if (cur->val == val)
			{
				return cur;
			}
			if (cur->val > val)
			{
				cur = cur->left;
			}
			if (cur->val < val)
			{
				cur = cur->right;
			}
		}
		return nullptr;
	}
	bool Insert(const T& val)
	{
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return true;
		}
		Node* parent = nullptr;
		Node* child = root_;
		while (child)
		{
			if (child->val_ == val)
			{
				return false;
			}
			if (child->val_ > val)
			{
				parent = child;
				child = child->left;
			}
			else
			{
				parent = child;
				child = child->right;
			}
		}
		child = new Node(val);
		if (parent->val_ > val)
		{
			parent->left = child;
		}
		else
		{
			parent->right = child;
		}
	}
	bool Erase(const T& val)
	{
		//当是空树的时候,不能删除
		if (root_ == nullptr)
		{
			return false;
		}

		Node* child = root_;
		Node* parent = nullptr;
		
		//不是空树，则寻找该结点
		while (child)
		{
			if (child->val_ == val)
			{
				break;
			}
			if (child->val_ > val)
			{
				parent = child;
				child = child->left;
			}
			else
			{
				parent = child;
				child = child->right;
			}
		}
		//没有找到
		if (child == nullptr)
		{
			return false;
		}
		//1、叶子结点时，直接删除，父结点的相应指针置空
		if (child->left == nullptr && child->right == nullptr)
		{
			//当不是只有一个结点的时候
			if (child != root_)
			{
				if (parent->val_ > val)
				{
					parent->left = nullptr;
				}
				else
				{
					parent->right = nullptr;
				}
			}
			else//只有一个根节点时
			{
				root_ = nullptr;
			}
			delete child;
			child = nullptr;
		}
		//	2、不是叶子结点
		//	无右边孩子，只有左孩子
		else if (child->right == nullptr)
		{
			if (child != root_)
			{
				if (parent->val_ > val)
				{
					parent->left = child->left;
				}
				else
				{
					parent->right = child->left;
				}
			}
			else
			{
				root_ = nullptr;
			}
			delete child;
			child = nullptr;
		}
		//	无左边孩子，只有右孩子
		else if (child->left == nullptr)
		{
			if (child != root_)
			{
				if (parent->val_ > val)
				{
					parent->left = child->right;
				}
				else
				{
					parent->right = child->right;
				}
			}
			else
			{
				root_ = nullptr;
			}
			delete child;
			child = nullptr;
		}
		//	都有
		//	在左孩子找最大的，或者在右孩子找最小的。才满足二叉搜索树
		else
		{
			Node* leftMost = child->left;
			parent = cur;//防止leftMost没有孩子结点
			while (leftMost->right)
			{
				parent = leftMost;
				leftMost = leftMost->right;//找到最大的一的结点
			}
			child->val_ = leftMost->val_;
			parent->right = leftMost->left;
			//存在leftMost是左孩子，没有右孩子的情况
			delete leftMost;
			leftMost = nullptr;
		}
	}
private:
	Node* root_;
};
