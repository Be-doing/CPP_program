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
			if (root_)//如果原来有树，则需要销毁原来的树
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
		if (root_ == nullptr)//如果是空树则直接插入
		{
			root_ = new Node(val);
			return true;
		}
		//如果不是空树的时候，由于搜索树是有序的
		//所以直接插入到叶子结点，不会在中间插
		//因为插入的数据一定是大与或小于叶子结点的

		Node* parent = nullptr;//在parent下面插入

		Node* child = root_;//寻找叶子结点

		while (child)
		{
			if (child->val_ == val)
			{
				return false; //二叉搜索树不能有重复的结点
			}
			if (child->val_ > val)
			{
				parent = child;
				child = child->left;	//往左边走
			}
			else
			{
				parent = child;
				child = child->right;//往右边走
			}
		}
		child = new Node(val);
		if (parent->val_ > val)//判断插入左边还是右边
		{
			parent->left = child;
		}
		else
		{
			parent->right = child;
		}
		return true;//可以通过中序遍历验证是否插入成功，搜索树是有序的
	}

	bool Erase(const T& val)
	{
		//删除时一共有四种情况
		//1、删除的结点是叶子结点的时候
		//2、删除的结点只有左孩子的时候
		//3、删除的结点只有右孩子的时候
		//4、删除的结点既有右孩子也有左孩子的时候


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
		//没有找到，则不能杉树，返回false
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
			else//如果是根节点，parent是指向nullptr的，所以需要对root_进行置空
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
			if (child != root_)//不是根节点时候
			{
				if (parent->val_ > val)//说明删除的结点是左孩子。
				{
					parent->left = child->left;
				}
				else
				{
					parent->right = child->left;//删除的是右孩子
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
		//	左孩子右孩子都存在
		//	在左孩子找最大的，或者在右孩子找最小的。它们都在叶子结点上，才满足二叉搜索树
		else
		{
			Node* leftMost = child->left;
			parent = child;
			while (leftMost->right)//不能让leftMost走到空，不然parent无法回溯
			{
				parent = leftMost;
				leftMost = leftMost->right;//找到最大的一的结点
			}
			child->val_ = leftMost->val_;//找到之后进行置换


			//2、只有左孩子的时候
			//
			if (parent->right == leftMost)//如果删除节点的左边只有一个结点的时候
			{
				parent->right = leftMost->left;//leftMost左边还有数，右边肯定比//leftMost大，所以不存在右孩子
			}
			else//删除的是根节点，且根节点的左边只有一个数，则parent->left == leftMost
			{
				parent->left = leftMost->left;//leftMost左边还有数
			}
			parent->right = leftMost->left;
			//存在leftMost是左孩子，没有右孩子的情况
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
