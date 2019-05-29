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
	Node* Find(const T& val)
	{
		if (root_ == nullptr)
		{
			return nullptr;
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

	}
	bool Erase()
	{
		//1、叶子结点时，直接删除，父结点的相应指针置空
		//	2、删除结点是根节点，且只有一个根节点，根节点置空，删除
		//	3、不是叶子结点
		//	无左边孩子？指向右孩子
		//	无右边孩子？指向左孩子
		//	都有
		//	在左孩子找最大的，或者在右孩子找最小的。才满足二叉搜索树
	}

private:
	Node* root_;
};