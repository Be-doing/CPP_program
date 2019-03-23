#pragma once
#include<iostream>
#include<string>
using namespace std;

// string�����ĳ�������
void Create()
{
	//string() ����յ�string����󣬼����ַ���
	string s1;
	//	string(const char* s) ��C - string������string�����
	string s2("hello string!");
	//	string(size_t n, char c) string������а���n���ַ�c
	string s3(5, 'b');
	//	string(const string&s) �������캯��
	string s4(s2);
	//	string(const string&s, size_t n) ��s�е�ǰn���ַ������µ�string�����
	string s5(s4, 5);

	cout << "string():" << s1 << endl;
	cout << "string(const char* s):" << s2 << endl;
	cout << "string(size_t n, char c):" << s3 << endl;
	cout << "string(const string&s):" << s4 << endl;
	cout << "string(const string&s, size_t n:" << s5 << endl;
}

//��������ʹ��
void Iterator()
{
	string s1( "hello string!");

	string::iterator sit = s1.begin();//s1�ʼ��λ��
	string::iterator sit2 = s1.end();//s1���һ��λ�õĺ�һ��λ��
	cout << "hello string!" << endl;

	cout << "string::iterator:" << endl;
	while (sit != sit2)//�����ַ���
	{
		cout << *sit << "  ";
		++sit;
	}
	cout << endl;


	string::reverse_iterator sit3 = s1.rbegin();//s1���һ��λ��
	string::reverse_iterator sit4 = s1.rend();//s1���һ��λ�õĺ�һ��λ��

	cout << "string::reverse_iterator:" << endl;
	while (sit3 != sit4)
	{
		cout << *sit3<< "  ";
		++sit3;//��Ȼ�����һ��λ�ã�����++�������ײ����������
	}
	cout << endl;
}

// string��������������
void Capacity()
{
	string s1("hello string!");


	//size_t size() const �����ַ�����Ч�ַ�����
	cout << "size_t size() const��" << s1.size() << endl;

	//	size_t length() const �����ַ�����Ч�ַ�����
	cout << "size_t length() const��" << s1.length() << endl;

	//	size_t capacity() const ���ؿռ��ܴ�С
	cout << "size_t capacity() const��" << s1.capacity() << endl;

	//	bool empty() const ����ַ����ͷ�Ϊ�մ����Ƿ���true�����򷵻�false
	cout << "bool empty() const��" << s1.empty() << endl;

	//	void clear() �����Ч�ַ�
	s1.clear();
	cout << "void clear()" << endl;

	s1 = "hello string!";
	//	void resize(size_t n, char c) ����Ч�ַ��ĸ����ó�n��������Ŀռ����ַ�c���
	cout <<"s1�ѻָ���s1 =="<< s1 << endl;
	s1.resize(5, 'b');
	cout << "void resize(size_t n == 5, char c)��" << s1 << endl;

	//	void resize(size_t n) ����Ч�ַ��ĸ����ĳ�n��������Ŀռ���0���
	s1.resize(5);
	cout << "void resize(size_t n == 5)��" << s1 << endl;

	//	void reserve(size_t res_arg = 0) Ϊ�ַ���Ԥ���ռ�	cout << "��ǰ������" << s1.capacity() << endl;	s1.reserve(16);	cout << "void reserve(size_t res_arg = 0)��" << s1.capacity() << endl;

}

// string�����ķ��ʲ���void Visit(){
	string s1("hello string!");	const string s2("hello const string!");	//char& operator[] (size_t pos) ����posλ�õ��ַ���const string��������
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << "  " << endl;
	}
	//	const char& operator[] (size_t pos)const����posλ�õ��ַ�����const string������	��	for (size_t i = 0; i < s2.size(); ++i)
	{
		cout << s2[i] << "  " << endl;
	}	//�û��ڷ�Χforѭ��	for (auto e : s1)
	{
		cout << e << "  " << endl;
	}	//������������	string::iterator sit = s1.begin();	while (sit != s1.end())
	{
		cout << *sit << "  " << endl;
	}}