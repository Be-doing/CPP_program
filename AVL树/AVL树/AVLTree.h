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
	BTnode<T>* parent_;//�ýڵ�ĸ����
	int bf_;//�ýڵ��ƽ������
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
		//����
		//������ұߵ��ұ߸�
		//��ƽ�����Ӿ���
		//����㣺2
		//�Һ��ӣ�1
		void RotateLeft(pNode parent)
		{
			pNode subR = parent->right_;
			pNode subRL = subR->left_;
			
			subR->left_ = parent;
			parent->right_ = subRL;
			if(subRL)//�������
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
		//����
		//����������������߸�
		//ƽ�����ӣ�
		//����㣺-2
		//���ӣ�-1
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
			//AVL���� = �����������Ĳ��� + ��������ת��
			//һ��ʼ���Ƕ����������Ĳ���
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
			cur = new Node(val);//��ɲ���
			if(val < parent->val_)
				parent->left_ = cur;
			else
				parent->right_ = cur;
			cur->parent_ = parent;
			//��ʱ�Ϳ�ʼ����
			while(parent)
			{
				if(cur == parent->left_)
					--parent->bf_;
				else
					++parent->bf_;
				if(parent->bf_ == 0)//˵��δ����ʱ����1����-1�����ڲ����ˣ�
					break;			//�߶�û�б仯�������ƽ�����Ӳ��ᷢ���ı䡣
				else if(parent->bf_ == 1 || parent->bf_ == -1)
				//˵������ʼ��ʱ��ƽ��������0�����ڸ߶ȷ����˱仯���������ϸ���
				{
					cur = parent;
					parent = parent->parent_;
				}
				else
				//ƽ������Υ��ƽ���������ʣ���Ҫ���������ת����
				{
					//��ת
					//1�� �½ڵ���뵽�ϸ������������---�����ҵ���bf:2	1
					//2�� �½ڵ���뵽�ϸ����������Ҳ�---���ң�����bf:-2	-1
					//3�� �½ڵ���뵽�ϸ����������Ҳ�---���ң����������ҵ���bf:-2	1
					//4�� �½ڵ���뵽�ϸ������������---�������ҵ���������bf:2		-1
					if(cur->bf_ == 1 && parent->bf_ == 2)//����
					{
						RotateLeft(parent);		
					}
					else if(cur->bf_ == -1 && parent->bf_ == -2)//����
					{
						RotateRight(parent);
					}
					else if(cur->bf_ == -1 && parent->bf_ == 2)//����˫��
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
					else if(cur->bf_ == 1 && parent->bf_ == -2)//����˫��
					{
						pNode subL = parent->left_;
						pNode subLR = subL->right_;
						int bf = subLR->bf_;
						RotateLeft(subL);
						RotateRight(parent);
						if(bf == -1)//��߸�
						{
							parent->bf_ = 1;
							subL->bf_ = 0;
						}
						else if(bf == 1)//�ұ߸�
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
