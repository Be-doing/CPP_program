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
//���캯����ʹ��
	//list�ĸ����캯��
	//list() ����յ�list
	//list(size_type n, const value_type& val = value_type()) �����list�а���n��ֵΪval��Ԫ��
	//list(const list& x) �������캯��
	//list(InputIterator first, InputIterator last) ��[first, last)�����е�Ԫ�ع���list
void CreateUse()
{
	list<int> s1;
	list<int> s2(10, 6);
	list<int> s3(s2);
	//list�ĵ�����
	list<int> s4(s2.begin(), s2.end());
	PrintList(s1);
	PrintList(s2);
	PrintList(s3);
	PrintList(s4);
}
//list�ķ���
		//list�ķ���ֻ��ͨ������������Ϊlist���������ġ�����������list�Ľ��
		//listû��������ֻ��size����Ϊlist�Ǵ�����ǽ�㣬��һ����㣬����һ�����Ŀռ�
void Vsist()
{
	list<int> s1(10, 6);
	cout << *s1.begin() << endl;

	cout << s1.size() << endl;

	cout << s1.empty() << endl;
}
//list�Խ��Ĳ���
void Operate()
{
	list<int> s1;
	//list��β��
	s1.push_back(1);
	s1.push_back(2);
	s1.push_back(3);
	s1.push_back(4);
	cout << "push_back:";
	PrintList(s1);


	//list��βɾ
	s1.pop_back();
	s1.pop_back();
	s1.pop_back();	
	s1.pop_back();
	cout << "pop_back:";
	PrintList(s1);

	//list����λ�ò���
	s1.insert(s1.begin(), 4);
	s1.insert(s1.begin(), 3);
	s1.insert(s1.begin(), 2);
	s1.insert(s1.begin(), 1);
	cout << "insert:";
	PrintList(s1);
}