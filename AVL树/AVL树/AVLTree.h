#pragma once
#include<iostream>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
		: pLeft_(nullptr)
		, pRight_(nullptr)
		, pParent_(nullptr)
		, data_(data)
		, bf_(0)
	{}
	AVLTreeNode<T>* pLeft_; // 该节点的左孩子
	AVLTreeNode<T>* pRight_; // 该节点的右孩子
	AVLTreeNode<T>* pParent_; // 该节点的双亲
	T data_;
	int bf_; // 该节点的平衡因子
};

template<class T>

class AVLTree
{
public:
	typedef AVLTreeNode<T> Node;
	typedef AVLTreeNode<T>* pNode;

	bool Insert(const T& val)//AVL树插入 = 插入 + 调整
	{

		//插入时和搜索树一样
		if (root_ == nullptr)
		{
			root_ = new Node(val);
		}
		pNode cur = root_;
		pNode parent = nullptr;
		while (cur)
		{
			if (cur->data_ == val)
			{
				return false;
			}
			else if (cur->data_ > val)
			{
				parent = cur;
				cur = cur->pLeft_;
			}
			else if (cur->data_ < val)
			{
				parent = cur;
				cur = cur->pRight_;
			}
		}
		cur = new Node(val);
		if (parent->data_ > val)
		{
			parent->pLeft_ = cur;
		}
		else
		{
			parent->pRight_ = cur;
		}
		//调整 = 更新平衡因子 + 旋转
		//调整平衡因子
		while (parent)//直到根节点
		{
			if (parent->pLeft_ = cur)
			{
				--parent->bf_;
			}
			else
			{
				++parent->bf_;
			}


			//此时平衡因子改变后有三种情况
			//1、bf == 0
			//2、bf == -1 或者 bf == 1
			//3、bf == -2 或者 bf == 2
			if (parent->bf_ == 0)//更新后平衡因子是0的时候，
										//说明未更新时就是1或者-1，现在补齐了，高度没有变化。上面的平衡因子不会发生改变。
			{
				break;//停止更新
			}
			else if(parent->bf_ == -1 || parent->bf_ == 1)//说明，开始的时候平衡因子是0，现在高度发生了变化，继续向上更新
			{
				cur = parent;
				parent = parent->pParent_;//继续向上更新
			}
			else if (parent->bf_ == -2 || parent->bf_ == 2)//平衡因子违反平衡树的性质，需要对其进行旋转处理
			{
				//旋转
				//1、 新节点插入到较高左子树的左侧---左左：右单旋
				//2、 新节点插入到较高右子树的右侧---右右：左单旋
				//3、 新节点插入到较高左子树的右侧---左右：先左单旋再右单旋
				//4、 新节点插入到较高右子树的左侧---右左：先右单旋再左单旋



				//1、右单旋：parent->bf == -2		cur->bf == -1
					//左边的左边高
				if (parent->bf_ == -2 && cur->bf_ == -1)
				{
					RotateR(parent);
				}
				else if (parent->bf_ == 2 && cur->bf_ == 1)
				{
					RotateL(parent);
				}

				//右左双旋：右边的左边高
				//先右旋再左旋
				//parent->bf = 2 cur->bf = -1
				else if (parent->bf_ == 2 && cur->bf_ == -1)
				{
					pNode subR = parent->pRight_;
					pNode subRL = subR->pLeft_;
					int bf = subRL->bf_;
					RotateR(subR);
					RotateL(parent);
					if (bf == -1)
					{
						parent->bf_ = 0;
						subR->bf_ = 1;
					}
					else if (bf == 1)
					{
						parent->bf_ = -1;
						subR->bf_ = 0;
					}
				}
				//左右双旋：左边的右边高
				//parent->bf = -2,cur->bf = 1
				else if (parent->bf_ == -2 && cur->bf_ == 1)
				{
					pNode subL = parent->pLeft;
					pNode subLR = subL->pRight_;
					int bf = subLR->bf_;
					RotateR(subL);
					RotateL(parent);
					if (bf == 1)
					{
						//右边高
						parent->bf_ = 1;
						subL->bf_ = 0;
					}
					else if (bf == -1)
					{
						//左边高
						parent->bf_ = 0;
						subL->bf_ = 1;
					}
				}
			}
		}
		return true;
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
			if (gpraent->pLeft_ = parent)
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
	pNode root_ = nullptr;//c++11语法
};