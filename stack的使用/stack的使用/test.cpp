#include<stack>
#include<vector>
#include<iostream>
using namespace std;
//实现一个最小栈
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
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能
//为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1, 2, 3, 4, 5是
//某栈的压入顺序，序列4, 5, 3, 2, 1是该压栈序列对应的一个弹出序列，但
//4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
class Solution2 {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() != popV.size())
		{
			return false;
		}
		//记录pushV的下标
		int index = 0;
		//记录popV的下标
		int outdex = 0;
		//创建一个栈来进行入栈出栈
		stack<int> test;
		int in_size = pushV.size();
		int out_size = popV.size();
		//如果popV走完了，就说明只是一个出栈顺序。
		while (outdex < out_size)
		{
			//如果栈还是空的我们就先入栈
			//或者栈顶元素不等于我们的popV，就进行入栈
			while (test.empty() || test.top() != popV[outdex])
			{
				//如果pushV走完了，test不是空栈，说明这不是一个出栈顺序
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
//用栈实现队列
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

//stack的底层实现
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

