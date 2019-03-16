#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		//:ra(10)
	{
		year_ = year;
		month_ = month;
		day_ = day;
	}
	//Date()//无参的构造函数
	//{}
	//拷贝构造
	Date(const Date& date)
		//初始化列表
		//:ra(10)
	{
		year_ = date.year_;
		month_ = date.month_;
		day_ = date.day_;
	}
	//运算符重载
		//判断
	bool operator == (Date& d2)
	{
		return year_ == d2.year_&&month_ == d2.month_&&day_ == d2.day_;
	}
	//赋值运算符
	Date& operator = (const Date& d)
	{
		if (this != &d)
		{
			year_ = d.year_;
			month_ = d.month_;
			day_ = d.day_;
		}
		return *this;
	}
	void display()
	{
		cout << year_ << "/" << month_ << "/" << day_ << endl;
	}
	//有缘声明
	friend  ostream& operator << (ostream& _cout, Date& d);
	friend istream& operator>>(istream& _cin, const Date& d);
	//重载 << 定义的类是第一个参数，所以调用的时候需要 date << cout;
	void operator << (ostream& _cout)
	{
		_cout << year_ << "/" << month_ << "/" << day_ << endl;
	}
	//const 修饰成员函数
	void display2()	const
	{
		cout << year_ << "/" << month_ << "/" << day_ << endl;
	}
private:
	int year_;
	int month_;
	int day_;
	//static成员函数
	static int hour_;
};
//为了是数据私有化，保证数据是安全的，声明为友元
ostream& operator << (ostream& _cout, Date& d)
{
	_cout << d.year_ << "/" << d.month_ << "/" << d.day_ << endl;
	return _cout;

}
istream& operator>>(istream& _cin, const Date& d)
{
	_cin >> d.year_;
	_cin >> d.month_;
	_cin >> d.day_;

	return _cin;
}
int Date::hour_ = 12;



















class String 
{
public:
	String(const char* str = "moren")
	{
		str_ = (char*)malloc(strlen(str) + 1);
		strcpy(str_, str);
	}
	//String()
	//{
	//	
	//}
	//析构函数
	~String()
	{
		cout << "正在清空资源" << endl;
		free(str_);
	}
	void display()
	{
		cout << str_ << endl;
	}
private:
	char* str_;
};
