#include<stack>
#include<vector>
#include<iostream>
using namespace std;
//ʵ��һ����Сջ
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() 
	{

	}

	void push(int x)
	{
		if (st_min_.empty() || st_min_.top >= x)
		{
			st_min_.push(x);
		}
		st_push_.push(x);
	}

	void pop() 
	{
		if (st_push_.top() == st_min_.top())
		{
			st_min_.pop();
		}
		st_push_.pop();
	}

	int top() 
	{
		return st_push_.top();
	}

	int getMin() 
	{
		return st_min_.top();
	}
private:
	stack<int> st_push_;
	stack<int> st_min_;
};
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����
//Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ���������1, 2, 3, 4, 5��
//ĳջ��ѹ��˳������4, 5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У���
//4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
class Solution2 {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() != popV.size())
		{
			return false;
		}
		//��¼pushV���±�
		int index = 0;
		//��¼popV���±�
		int outdex = 0;
		//����һ��ջ��������ջ��ջ
		stack<int> test;
		int in_size = pushV.size();
		int out_size = popV.size();
		//���popV�����ˣ���˵��ֻ��һ����ջ˳��
		while (outdex < out_size)
		{
			//���ջ���ǿյ����Ǿ�����ջ
			//����ջ��Ԫ�ز��������ǵ�popV���ͽ�����ջ
			while (test.empty() || test.top() != popV[outdex])
			{
				//���pushV�����ˣ�test���ǿ�ջ��˵���ⲻ��һ����ջ˳��
				if (index < in_size)
				{
					test.push(pushV[index++]);
				}
				else
				{
					return false;
				}
			}
			++outdex;
			test.pop();
		}
		return true;
	}
};
//��ջʵ�ֶ���
class Myqueen {
public:
	Myqueen()
	{

	}

	void push(int x)
	{
		st_tail_.push(x);
	}

	int pop()
	{
		if (!st_front_.empty())
		{
			int tmp = st_front_.top();
			st_front_.pop();
			return tmp;
		}
		else
		{
			while (!st_tail_.empty())
			{
				st_front_.push(st_tail_.top());
				st_tail_.pop();
			}
			if (st_front_.empty())
			{
				return false;
			}
			else
			{
				int tmp = st_front_.top();
				st_front_.pop();
				return tmp;
			}
		}
	}

	int top()
	{
		if (!st_front_.empty())
		{
			
			return st_front_.top();
		}
		else
		{
			while (!st_tail_.empty())
			{
				st_front_.push(st_tail_.top());
				st_tail_.pop();
			}
			if (st_front_.empty())
			{
				return false;
			}
			else
			{
				return st_front_.top();
			}
		}
	}
private:
	stack<int> st_tail_;
	stack<int> st_front_;
	
};

//stack�ĵײ�ʵ��
template<class T,class containser = deque<T>>

class Stack
{
public:
	void Push(const T& val)
	{
		con_.push_back();
	}
	void Pop()
	{
		con_.pop();
	}
	bool Empty()
	{
		return con_.empty();
	}
	T& top()
	{
		return con_.back();
	}
private:
	containser con_;
};

