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