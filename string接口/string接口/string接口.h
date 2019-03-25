#pragma once
#include<iostream>
#include<string>
using namespace std;

// string类对象的常见构造
void Create()
{
	//string() 构造空的string类对象，即空字符串
	string s1;
	//	string(const char* s) 用C - string来构造string类对象
	string s2("hello string!");
	//	string(size_t n, char c) string类对象中包含n个字符c
	string s3(5, 'b');
	//	string(const string&s) 拷贝构造函数
	string s4(s2);
	//	string(const string&s, size_t n) 用s中的前n个字符构造新的string类对象
	string s5(s4, 5);

	cout << "string():" << s1 << endl;
	cout << "string(const char* s):" << s2 << endl;
	cout << "string(size_t n, char c):" << s3 << endl;
	cout << "string(const string&s):" << s4 << endl;
	cout << "string(const string&s, size_t n:" << s5 << endl;
}

//迭代器的使用
void Iterator()
{
	string s1( "hello string!");

	string::iterator sit = s1.begin();//s1最开始的位置
	string::iterator sit2 = s1.end();//s1最后一个位置的后一个位置
	cout << "hello string!" << endl;

	cout << "string::iterator:" << endl;
	while (sit != sit2)//遍历字符串
	{
		cout << *sit << "  ";
		++sit;
	}
	cout << endl;


	string::reverse_iterator sit3 = s1.rbegin();//s1最后一个位置
	string::reverse_iterator sit4 = s1.rend();//s1最后一个位置的后一个位置

	cout << "string::reverse_iterator:" << endl;
	while (sit3 != sit4)
	{
		cout << *sit3<< "  ";
		++sit3;//虽然是最后一个位置，还是++操作，底层进行了重载
	}
	cout << endl;
}

// string类对象的容量操作
void Capacity()
{
	string s1("hello string!");

	//size_t size() const 返回字符串有效字符长度
	cout << "size_t size() const：" << s1.size() << endl;

	//	size_t length() const 返回字符串有效字符长度
	cout << "size_t length() const：" << s1.length() << endl;

	//	size_t capacity() const 返回空间总大小
	cout << "size_t capacity() const：" << s1.capacity() << endl;

	//	bool empty() const 检测字符串释放为空串，是返回true，否则返回false
	cout << "bool empty() const：" << s1.empty() << endl;

	//	void clear() 清空有效字符
	s1.clear();
	cout << "void clear()" << endl;

	s1 = "hello string!";
	//	void resize(size_t n, char c) 将有效字符的个数该成n个，多出的空间用字符c填充
	cout <<"s1已恢复：s1 =="<< s1 << endl;
	s1.resize(5, 'b');
	cout << "void resize(size_t n == 5, char c)：" << s1 << endl;

	//	void resize(size_t n) 将有效字符的个数改成n个，多出的空间用0填充
	s1.resize(5);
	cout << "void resize(size_t n == 5)：" << s1 << endl;

	//	void reserve(size_t res_arg = 0) 为字符串预留空间
	cout << "当前容量：" << s1.capacity() << endl;
	s1.reserve(16);
	cout << "void reserve(size_t res_arg = 16)：" << s1.capacity() << endl;

}

// string类对象的访问操作
void Visit()
{
	string s1("hello string!");
	const string s2("hello const string!");
	//char& operator[] (size_t pos) 返回pos位置的字符，const string类对象调用
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << "  " ;
	}
	cout << endl;
	//	const char& operator[] (size_t pos)const返回pos位置的字符，非const string类对象调	用
	for (size_t i = 0; i < s2.size(); ++i)
	{
		cout << s2[i] << "  ";
	}
	cout << endl;
	//用基于范围for循环
	for (auto e : s1)
	{
		cout << e << "  ";
	}
	cout << endl;
	//迭代器的运用
	string::iterator sit = s1.begin();
	while (sit != s1.end())
	{
		cout << *sit << "  ";
		++sit;
	}
	cout << endl;
}
void Change()
{
	string str("hello change!");
//void push_back(char c) 在字符串后尾插字符c
	str.push_back('!');
	cout <<"在字符串后尾插字符'!'：" <<str << endl;
//string& append(const char* s); 在字符串后追加一个字符串
	string s2("hey");
	str.append(s2);
	cout << "在字符串后追加一个字符串：" << str << endl;
//string& operator+=(const string	str)	在字符串后追加字符串str
	str += s2;
	cout << "在字符串后追加一个字符串(=+)：" << str << endl;
//	string& operator+=(const char* s) 在字符串后追加C个数字符串
	str +="string";
	cout << "在字符串后追加C个数字符串：" << str << endl;
//	string& operator+=(char c) 在字符串后追加字符c
	str += 's';
	cout << "在字符串后追加字符c：" << str << endl;
//	const char* c_str()const 返回C格式字符串
//	size_t find(char c, size_t pos = 0)const	从字符串pos位置开始往后找字符c，返回该字符在	字符串中的位置
//	size_t rfind(char c, size_t pos = npos) 从字符串pos位置开始往前找字符c，返回该字符在	字符串中的位置
//	string substr(size_t pos = 0, size_t n	= npos)const
//	在str中从pos位置开始，截取n个字符，然后将其返回

}
