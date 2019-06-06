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
	Node* Copy(Node* root)
	{
		if (!root)
		{
			return nullptr;
		}
		Node* newnode = new Node(root->val_);
		newnode->left = Copy(root->left);
		newnode->right = Copy(root->right);
		return newnode;
	}
	void Destroy(Node* root)
	{
		if (root)
		{
			Destroy(root->left);
			Destroy(root->right);
			delete root;
			root = nullptr;
		}
	}
	BTree(const BTree<T>& bst)
	{
		root_ = Copy(bst.root_);
	}

	BTree<T>& operator=(const BTree<T>& bst)
	{
		if (this != &bst)
		{
			if (root_)//���ԭ������������Ҫ����ԭ������
			{
				Destroy(root_);
			}
			root_ = Copy(bst.root_);
		}
		return *this;
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
		if (root_ == nullptr)//����ǿ�����ֱ�Ӳ���
		{
			root_ = new Node(val);
			return true;
		}
		//������ǿ�����ʱ�������������������
		//����ֱ�Ӳ��뵽Ҷ�ӽ�㣬�������м��
		//��Ϊ���������һ���Ǵ����С��Ҷ�ӽ���

		Node* parent = nullptr;//��parent�������

		Node* child = root_;//Ѱ��Ҷ�ӽ��

		while (child)
		{
			if (child->val_ == val)
			{
				return false; //�����������������ظ��Ľ��
			}
			if (child->val_ > val)
			{
				parent = child;
				child = child->left;	//�������
			}
			else
			{
				parent = child;
				child = child->right;//���ұ���
			}
		}
		child = new Node(val);
		if (parent->val_ > val)//�жϲ�����߻����ұ�
		{
			parent->left = child;
		}
		else
		{
			parent->right = child;
		}
		return true;//����ͨ�����������֤�Ƿ����ɹ����������������
	}

	bool Erase(const T& val)
	{
		//ɾ��ʱһ�����������
		//1��ɾ���Ľ����Ҷ�ӽ���ʱ��
		//2��ɾ���Ľ��ֻ�����ӵ�ʱ��
		//3��ɾ���Ľ��ֻ���Һ��ӵ�ʱ��
		//4��ɾ���Ľ������Һ���Ҳ�����ӵ�ʱ��


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
		//û���ҵ�������ɼ��������false
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
			else//����Ǹ��ڵ㣬parent��ָ��nullptr�ģ�������Ҫ��root_�����ÿ�
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
			if (child != root_)//���Ǹ��ڵ�ʱ��
			{
				if (parent->val_ > val)//˵��ɾ���Ľ�������ӡ�
				{
					parent->left = child->left;
				}
				else
				{
					parent->right = child->left;//ɾ�������Һ���
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
		//	�����Һ��Ӷ�����
		//	�����������ģ��������Һ�������С�ġ����Ƕ���Ҷ�ӽ���ϣ����������������
		else
		{
			Node* leftMost = child->left;
			parent = child;
			while (leftMost->right)//������leftMost�ߵ��գ���Ȼparent�޷�����
			{
				parent = leftMost;
				leftMost = leftMost->right;//�ҵ�����һ�Ľ��
			}
			child->val_ = leftMost->val_;//�ҵ�֮������û�


			//2��ֻ�����ӵ�ʱ��
			//
			if (parent->right == leftMost)//���ɾ���ڵ�����ֻ��һ������ʱ��
			{
				parent->right = leftMost->left;//leftMost��߻��������ұ߿϶���//leftMost�����Բ������Һ���
			}
			else//ɾ�����Ǹ��ڵ㣬�Ҹ��ڵ�����ֻ��һ��������parent->left == leftMost
			{
				parent->left = leftMost->left;//leftMost��߻�����
			}
			parent->right = leftMost->left;
			//����leftMost�����ӣ�û���Һ��ӵ����
			delete leftMost;
			leftMost = nullptr;
		}
		return true;
	}

	void _Inorder(Node* root)
	{
		if (root)
		{
			_Inorder(root->left);
			cout << root->val_ << " ";
			_Inorder(root->right);
		}
	}
	void Inorder()
	{
		_Inorder(root_);
		cout << endl;
	}
	
private:
	Node* root_;
};
