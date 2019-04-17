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
	cout << "insert:";
	PrintList(s1);
}