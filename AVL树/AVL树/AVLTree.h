#include<iostream>
using namespace std;
template <class T>
struct BTnode
{
	BTnode(const T& val = T())
	:val_(val)
	,left_(nullptr)
	,right_(nullptr)
	,parent_(nullptr)
	,bf_(0)
	{}
	T val_;
	BTnode<T>* left_;
	BTnode<T>* right_;
	BTnode<T>* parent_;//该节点的父结点
	int bf_;//该节点的平衡因子
};
template<class T>
class AVLTree
{
	typedef BTnode<T> Node;
	typedef BTnode<T>* pNode;
	public:
		AVLTree()
		:root_(nullptr)
		{}
		//左旋
		//父结点右边的右边高
		//即平衡因子就是
		//父结点：2
		//右孩子：1
		void RotateLeft(pNode parent)
		{
			pNode subR = parent->right_;
			pNode subRL = subR->left_;
			
			subR->left_ = parent;
			parent->right_ = subRL;
			if(subRL)//如果存在
				subRL->parent_ = parent;
			if (parent->parent_ == nullptr)
			{
				subR->parent_ = nullptr;
				root_ = subR;
			}
			else
			{
				subR->parent_ = parent->parent_;
				if (parent->parent_->left_ == parent)
					parent->parent_->left_ = subR;
				else
					parent->parent_->right_ = subR;
			}
				
			parent->parent_ = subR;
			parent->bf_ = subR->bf_ = 0;
		}
		//右旋
		//父结点的左子树的左边高
		//平衡因子：
		//父结点：-2
		//左孩子：-1
		void RotateRight(pNode parent)
		{
			pNode subL = parent->left_;
			pNode subLR = subL->right_;
			subL->right_ = parent;
			parent->left_ = subLR;
			if(subLR)
				subLR->parent_ = parent;
			if (parent->parent_ == nullptr)
			{
				subL->parent_ = nullptr;
				root_ = subL;
			}
				
			else
			{
				subL->parent_ = parent->parent_;
				if (parent->parent_->left_ == parent)
					parent->parent_->left_ = subL;
				else
					parent->parent_->right_ = subL;
			}
			parent->parent_ = subL;
			parent->bf_ = subL->bf_ = 0;
		}
		bool Insert(const T& val)
		{
			//AVL插入 = 二叉搜索树的插入 + 调整（旋转）
			//一开始就是二叉搜索树的插入
			if (!root_)
			{
				root_ = new Node(val);
				return true;
			}
			pNode cur = root_;
			pNode parent = nullptr;
			while(cur)
			{
				if(val == cur->val_)
					return false;
				parent = cur;
				if(val > cur->val_)
					cur = cur->right_;
				else
					cur = cur->left_;
			}
			cur = new Node(val);//完成插入
			if(val < parent->val_)
				parent->left_ = cur;
			else
				parent->right_ = cur;
			cur->parent_ = parent;
			//此时就开始调整
			while(parent)
			{
				if(cur == parent->left_)
					--parent->bf_;
				else
					++parent->bf_;
				if(parent->bf_ == 0)//说明未更新时就是1或者-1，现在补齐了，
					break;			//高度没有变化。上面的平衡因子不会发生改变。
				else if(parent->bf_ == 1 || parent->bf_ == -1)
				//说明，开始的时候平衡因子是0，现在高度发生了变化，继续向上更新
				{
					cur = parent;
					parent = parent->parent_;
				}
				else
				//平衡因子违反平衡树的性质，需要对其进行旋转处理
				{
					//旋转
					//1、 新节点插入到较高左子树的左侧---左左：右单旋bf:2	1
					//2、 新节点插入到较高右子树的右侧---右右：左单旋bf:-2	-1
					//3、 新节点插入到较高左子树的右侧---左右：先左单旋再右单旋bf:-2	1
					//4、 新节点插入到较高右子树的左侧---右左：先右单旋再左单旋bf:2		-1
					if(cur->bf_ == 1 && parent->bf_ == 2)//左旋
					{
						RotateLeft(parent);		
					}
					else if(cur->bf_ == -1 && parent->bf_ == -2)//右旋
					{
						RotateRight(parent);
					}
					else if(cur->bf_ == -1 && parent->bf_ == 2)//右左双旋
					{
						pNode subR = parent->right_;
						pNode subRL = subR->left_;
						int bf = subRL->bf_;
						RotateRight(subR);
						RotateLeft(parent);
						if(bf == 1)
						{
							parent->bf_ = -1;
							subR->bf_ = 0;
						}
						else if(bf == -1)
						{
							parent->bf_ = 0;
							subR->bf_ = 1;
						}
					}
					else if(cur->bf_ == 1 && parent->bf_ == -2)//左右双旋
					{
						pNode subL = parent->left_;
						pNode subLR = subL->right_;
						int bf = subLR->bf_;
						RotateLeft(subL);
						RotateRight(parent);
						if(bf == -1)//左边高
						{
							parent->bf_ = 1;
							subL->bf_ = 0;
						}
						else if(bf == 1)//右边高
						{
							parent->bf_ = 0;
							subL->bf_ = -1;
						}
					}
				}
			}
			return true;
		}
		void Print()
		{
			inorder__(this->root_);
			cout << endl;
		}
     private:
		 void inorder__(pNode root)
		 {
			 if (!root)
				 return;
			 inorder__(root->left_);
			 cout << root->val_ << " ";
			 inorder__(root->right_);
		 }

	private:
	pNode root_;
};
