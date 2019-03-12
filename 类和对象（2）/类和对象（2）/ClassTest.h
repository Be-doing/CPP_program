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
	//const 修饰成员函数
	void display2()	const
	{
		cout << year_ << "/" << month_ << "/" << day_ << endl;
	}
private:
	int year_;
	int month_;
	int day_;
	//const修饰成员变量
	//const int& ra;
};

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
