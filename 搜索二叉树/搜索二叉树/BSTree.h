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
		//���ǿ�����ʱ��,����ɾ��
		if (root_ == nullptr)
		{
			return false;
		}

		Node* child = root_;
		Node* parent = nullptr;
		
		//���ǿ�������Ѱ�Ҹý��
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
		//û���ҵ�
		if (child == nullptr)
		{
			return false;
		}
		//1��Ҷ�ӽ��ʱ��ֱ��ɾ������������Ӧָ���ÿ�
		if (child->left == nullptr && child->right == nullptr)
		{
			//������ֻ��һ������ʱ��
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
			else//ֻ��һ�����ڵ�ʱ
			{
				root_ = nullptr;
			}
			delete child;
			child = nullptr;
		}
		//	2������Ҷ�ӽ��
		//	���ұߺ��ӣ�ֻ������
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
		//	����ߺ��ӣ�ֻ���Һ���
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
		//	����
		//	�����������ģ��������Һ�������С�ġ����������������
		else
		{
			Node* leftMost = child->left;
			parent = cur;//��ֹleftMostû�к��ӽ��
			while (leftMost->right)
			{
				parent = leftMost;
				leftMost = leftMost->right;//�ҵ�����һ�Ľ��
			}
			child->val_ = leftMost->val_;
			parent->right = leftMost->left;
			//����leftMost�����ӣ�û���Һ��ӵ����
			delete leftMost;
			leftMost = nullptr;
		}
	}
private:
	Node* root_;
};
