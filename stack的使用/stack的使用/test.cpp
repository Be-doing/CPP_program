#include<stack>
#include<vector>
#include<iostream>
using namespace std;
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

class Solution2 {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {

	}
};
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