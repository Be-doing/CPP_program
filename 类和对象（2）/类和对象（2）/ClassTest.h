#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:ra(10)
	{
		year_ = year;
		month_ = month;
		day_ = day;
	}
	Date(const Date& date)
	{
		year_ = date.year_;
		month_ = date.month_;
		day_ = date.day_;
	}
	//运算符重载
	bool operator == (Date& d2)
	{
		return year_ == d2.year_&&month_ == d2.month_&&day_ == d2.day_;
	}
	void display()
	{
		cout << year_ << "/" << month_ << "/" << day_ << endl;
	}
private:
	int year_;
	int month_;
	int day_;
	const int& ra;
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
