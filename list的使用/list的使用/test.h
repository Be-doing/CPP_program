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
	//vector<int>::iterator vit = v1.begin();����Ĳ����ʹ������ʧЧ

	v1.push_back(3);
	v1.push_back(4);
	vector<int>::iterator vit = v1.begin();//�������»�ȡһ��
	cout << *vit << endl;

	vector<int>::iterator vit2 = v1.erase(v1.begin());//��ȡ����ֵ 
}