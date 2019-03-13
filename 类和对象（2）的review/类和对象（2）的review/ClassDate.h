#pragma once
#include<iostream>
using namespace std;
class Date 
{
public:
	void display()
	{
		cout << year_ << "/" << month_ << "/" << day_  << endl;
	}
	void judge()
	{
		cout << "您输入的年份非法，已恢复至默认年份1900/1/1" << endl;
		year_ = 1900;
		month_ = 1;
		day_ = 1;
	}
	Date(int year, int month, int day);
	Date(const Date& d);
	Date& operator=(const Date& d);
	int getday(int year, int month)
	{
		static int _day;
		int _mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			_mon[1] = 29;
		}
		_day = _mon[month - 1];
		return _day;
	}
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& d);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
private:
	int year_;
	int month_;
	int day_;
};