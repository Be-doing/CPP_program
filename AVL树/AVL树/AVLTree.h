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
	AVLTreeNode<T>* pLeft_; // �ýڵ������
	AVLTreeNode<T>* pRight_; // �ýڵ���Һ���
	AVLTreeNode<T>* pParent_; // �ýڵ��˫��
	T data_;
	int bf_; // �ýڵ��ƽ������
};

template<class T>

class AVLTree
{
public:
	typedef AVLTreeNode<T> Node;
	typedef AVLTreeNode<T>* pNode;

	bool Insert(const T& val)//AVL������ = ���� + ����
	{

		//����ʱ��������һ��
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
		//���� = ����ƽ������ + ��ת
		//����ƽ������
		while (parent)//ֱ�����ڵ�
		{
			if (parent->pLeft_ = cur)
			{
				--parent->bf_;
			}
			else
			{
				++parent->bf_;
			}


			//��ʱƽ�����Ӹı�����������
			//1��bf == 0
			//2��bf == -1 ���� bf == 1
			//3��bf == -2 ���� bf == 2
			if (parent->bf_ == 0)//���º�ƽ��������0��ʱ��
										//˵��δ����ʱ����1����-1�����ڲ����ˣ��߶�û�б仯�������ƽ�����Ӳ��ᷢ���ı䡣
			{
				break;//ֹͣ����
			}
			else if(parent->bf_ == -1 || parent->bf_ == 1)//˵������ʼ��ʱ��ƽ��������0�����ڸ߶ȷ����˱仯���������ϸ���
			{
				cur = parent;
				parent = parent->pParent_;//�������ϸ���
			}
			else if (parent->bf_ == -2 || parent->bf_ == 2)//ƽ������Υ��ƽ���������ʣ���Ҫ���������ת����
			{
				//��ת
				//1�� �½ڵ���뵽�ϸ������������---�����ҵ���
				//2�� �½ڵ���뵽�ϸ����������Ҳ�---���ң�����
				//3�� �½ڵ���뵽�ϸ����������Ҳ�---���ң����������ҵ���
				//4�� �½ڵ���뵽�ϸ������������---�������ҵ���������



				//1���ҵ�����parent->bf == -2		cur->bf == -1
					//��ߵ���߸�
				if (parent->bf_ == -2 && cur->bf_ == -1)
				{
					RotateR(parent);
				}
				else if (parent->bf_ == 2 && cur->bf_ == 1)
				{
					RotateL(parent);
				}

				//����˫�����ұߵ���߸�
				//������������
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
				//����˫������ߵ��ұ߸�
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
						//�ұ߸�
						parent->bf_ = 1;
						subL->bf_ = 0;
					}
					else if (bf == -1)
					{
						//��߸�
						parent->bf_ = 0;
						subL->bf_ = 1;
					}
				}
			}
		}
		return true;
	}

	//��������˫�׽��Ϊ��
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
	//�������ұߵ��ұ߸�	parent->bf = 2   cur->bf = 1
	//��˫�׽��Ϊ��
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
	pNode root_ = nullptr;//c++11�﷨
};