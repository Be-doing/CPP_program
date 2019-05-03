#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<list>
using namespace std;

//queue的底层实现
template<class T, class containser>
class Queue
{
public:
	void Push(const T& val)
	{
		con_.push_back(val);
	}
	void Pop()
	{
		con_.pop_front();
	}
	T& Front()
	{
		return con_.front();
	}
	T& Back()
	{
		return con_.back();
	}
	bool Emtpy()
	{
		return con_.empty();
	}
private:
	containser con_;
};


  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	int treehigh(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		int left_ = treehigh(root->left);
		int right_ = treehigh(root->right);

		return left_ > right_ ? left_ + 1 : right_ + 1;
	}
	vector<vector<int>> levelOrder(TreeNode* root) {

		int height = treehigh(root);
	
		vector<vector<int>> treeVec;
		treeVec.resize(height);
		queue<TreeNode*> Pnode;
		queue<int> Index;
		TreeNode* tmp = root;
		if (!tmp)
		{
			return treeVec;
		}
		Pnode.push(tmp);
		Index.push(0);
		while (!Pnode.empty())
		{
			tmp = Pnode.front();
			Pnode.pop();
			int index = Index.front();
			Index.pop();
			treeVec[index].push_back(tmp->val);
			if (tmp->left)
			{
				Pnode.push(tmp->left);
				Index.push(index + 1);
			}
			if (tmp->right)
			{
				Pnode.push(tmp->right);
				Index.push(index + 1);
			}
		}
		return treeVec;
	}
};
class Solution2 {
public:
	int treehigh(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}
		int left_ = treehigh(root->left);
		int right_ = treehigh(root->right);

		return left_ > right_ ? left_ + 1 : right_ + 1;
	}
	vector<vector<int>> levelOrder(TreeNode* root) {

		int height = treehigh(root);

		vector<vector<int>> treeVec;
		treeVec.resize(height);
		queue<TreeNode*> Pnode;
		queue<int> Index;
		TreeNode* tmp = root;
		if (!tmp)
		{
			return treeVec;
		}
		Pnode.push(tmp);
		Index.push(0);
		while (!Pnode.empty())
		{
			tmp = Pnode.front();
			Pnode.pop();
			int index = Index.front();
			Index.pop();
			treeVec[index].push_back(tmp->val);
			if (tmp->left)
			{
				Pnode.push(tmp->left);
				Index.push(index + 1);
			}
			if (tmp->right)
			{
				Pnode.push(tmp->right);
				Index.push(index + 1);
			}
		}
		return treeVec;
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> tmp = levelOrder(root);
		vector<vector<int>> res;
		int num = 0;
		int num2 = tmp.size() - 1;
		while (num2 >= 0)
		{
			res.push_back(tmp[num2]);
			++num;
			--num2;
		}
		return res;
	}
};
class Solution3 {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for (size_t i = 0; i < tokens.size(); ++i)
		{
			string& str = tokens[i];
			// str为数字
			if (!("+" == str || "-" == str || "*" == str || "/" == str))
			{
				s.push(atoi(str.c_str()));
			}
			else
			{
				// str为操作符
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();
				switch (str[0])
				{
				case '+':
					s.push(left + right);
					break;
				case '-':
					s.push(left - right);
					break;
				case '*':
					s.push(left * right);
					break;
				case '/':
					// 题目说明了不存在除数为0的情况
					s.push(left / right);
					break;
				}
			}
		}
		return s.top();
	}
};
int main()
{
	Queue<int, list<int>> q1;
	q1.Push(1);
	q1.Push(1);
	q1.Push(1);
	q1.Push(1);

	q1.Pop();
	
	while (!q1.Emtpy())
	{
		cout << q1.Front() << endl;
		q1.Pop();
	}
	system("pause");
	return 0;
}