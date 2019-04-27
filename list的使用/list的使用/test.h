#pragma once
#include<list>


#include<iostream>
using namespace std;
template<class T>
void PrintList(list<T>& s)
{
	for (auto& e : s)
	{
		cout << e << '\t';
	}
	cout << endl;
}
//构造函数的使用
	//list四个构造函数
	//list() 构造空的list
	//list(size_type n, const value_type& val = value_type()) 构造的list中包含n个值为val的元素
	//list(const list& x) 拷贝构造函数
	//list(InputIterator first, InputIterator last) 用[first, last)区间中的元素构造list
void CreateUse()
{
	list<int> s1;
	list<int> s2(10, 6);
	list<int> s3(s2);
	//list的迭代器
	list<int> s4(s2.begin(), s2.end());
	PrintList(s1);
	PrintList(s2);
	PrintList(s3);
	PrintList(s4);
}
//list的访问
		//list的访问只能通过迭代器，因为list不是连续的。迭代器里是list的结点
		//list没有容量，只有size。因为list是处理的是结点，来一个结点，申请一个结点的空间
void Vsist()
{
	list<int> s1(10, 6);
	cout << *s1.begin() << endl;

	cout << s1.size() << endl;

	cout << s1.empty() << endl;
}
//list对结点的操作
void Operate()
{
	list<int> s1;
	//list的尾插
	s1.push_back(1);
	s1.push_back(2);
	s1.push_back(3);
	s1.push_back(4);
	cout << "push_back:";
	PrintList(s1);


	//list的尾删
	s1.pop_back();
	s1.pop_back();
	s1.pop_back();	
	s1.pop_back();
	cout << "pop_back:";
	PrintList(s1);

	//list任意位置插入
	s1.insert(s1.begin(), 4);
	s1.insert(s1.begin(), 3);
	s1.insert(s1.begin(), 2);
	s1.insert(s1.begin(), 1);
	int tmp = 3;
	list<int>::iterator lit = s1.begin();
	while (tmp--)
	{
		++lit;
	}
	s1.insert(lit, 3);
	cout << "insert:";
	PrintList(s1);
}

void Iterator()
{
	list<int> s1;
	s1.push_back(1);
	s1.push_back(2);
	s1.push_back(3);
	s1.push_back(4);
	cout << "push_back:";
	PrintList(s1);

	//list<int>::iterator lit = s1.begin();
	s1.erase(s1.begin());
	list<int>::iterator lit = s1.begin();

	cout << *lit << endl;
}

#include<vector>

void review()
{
	vector<int> v1;
	cout << v1.capacity() << endl;
	v1.push_back(1);
	v1.push_back(2);
	//vector<int>::iterator vit = v1.begin();后面的插入会使迭代器失效

	v1.push_back(3);
	v1.push_back(4);
	vector<int>::iterator vit = v1.begin();//这里重新获取一下
	cout << *vit << endl;

	vector<int>::iterator vit2 = v1.erase(v1.begin());//获取返回值 
}