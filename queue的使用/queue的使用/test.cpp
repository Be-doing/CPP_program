#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

//queueµÄµ×²ãÊµÏÖ
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

		return left > right ? left + 1 : right_ + 1;
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> treeVec;
		int height = treehigh(root);
		queue<TreeNode*> qTree;
		TreeNode* tmp = root;
		if (!tmp)
		{
			return treeVec;
		}
		qTree.push(tmp);
		while (!qTree.empty())
		{
		}
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