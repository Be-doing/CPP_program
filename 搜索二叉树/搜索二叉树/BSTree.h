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
		//1��Ҷ�ӽ��ʱ��ֱ��ɾ������������Ӧָ���ÿ�
		//	2��ɾ������Ǹ��ڵ㣬��ֻ��һ�����ڵ㣬���ڵ��ÿգ�ɾ��
		//	3������Ҷ�ӽ��
		//	����ߺ��ӣ�ָ���Һ���
		//	���ұߺ��ӣ�ָ������
		//	����
		//	�����������ģ��������Һ�������С�ġ����������������
	}

private:
	Node* root_;
};