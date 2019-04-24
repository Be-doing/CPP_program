#include<iostream>
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