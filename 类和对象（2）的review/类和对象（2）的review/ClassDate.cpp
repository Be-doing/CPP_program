#include"ClassDate.h"
#include<iostream>
using namespace std;;
Date::Date(int year = 1900, int month = 1, int day = 1)
{
	if (year<=0 && month <=0 && month>12)
	{
		judge();
	}
	else 
	{ 
		if(month == 2 )
		{
			if (!(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && day > 28)
			{
				judge();
			}
			else if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && day > 29)
			{
				judge();
			}
		}
		year_ = year;
		month_ = month;
		day_ = day;

	}
}
//拷贝构造
Date::Date(const Date& d)
{
	year_ = d.year_;
	month_ = d.month_;
	day_ = d.day_;
}
//重载 赋值=
Date& Date::operator=(const Date& d)
{
	year_ = d.year_;
	month_ = d.month_;
	day_ = d.day_;
	return *this;
}
//重载 加 + int
Date Date::operator+=(int days)
{
	//Date temp;
	if (days < 0)
	{
		return *this - (-days);
	}
	this->day_ += days;
		while (this->day_ > this->getday(this->year_, this->month_))
		{
			this->day_ -= this->getday(this->year_, this->month_);
			if (this->month_ == 12)
			{
				++this->year_;
				this->month_ =1;
			}
			else
			{
				++this->month_;
			}
		}
	return *this;
}
Date Date::operator+(int days)
{
	Date ret(*this);
	ret += days;
	return ret;
}

//重载  减 - int
Date Date::operator-=(int days)
{
	if (days < 0)
	{
		return *this + (-days);
	}
	this->day_ -= days;

		while (this->day_ <= 0)
		{
			--this->month_;
			if (this->month_ <= 0)
			{
				this->month_ = 12;
			}
			this->day_ += this->getday(this->year_, this->month_ );
			if (this->month_ == 12)
			{
				--this->year_;
				//this->month_ = 12;
			}
		}
	return *this;
}
Date Date::operator-(int days)
{
	Date ret(*this);
	ret -= days;
	return ret;
}
//重载 前自增
Date& Date::operator++()
{
	 (*this) += 1;
	return *this;
}
//重载 后自增
Date Date::operator++(int)
{
	Date ret(*this);
	(*this) + 1;
	return ret;
}
//重载 自减
Date& Date::operator--()
{
	(*this) - 1;
	return *this;
}
Date Date::operator--(int)
{
	Date ret(*this);
	(*this) - 1;
	return ret;
}
//重载 >
bool Date::operator>(const Date& d)const
{
	return this->year_ > d.year_ ||
		(this->year_ == d.year_ && this->month_ > d.month_) ||
		(this->year_ == d.year_ && this->month_ == d.month_ && this->day_ > d.day_);
}
bool Date::operator>=(const Date& d)const
{
	return (*this > d) ||
		(this->year_ == d.year_ && this->month_ == d.month_ && this->day_ == d.day_);
}
bool Date::operator<(const Date& d)const
{
	return !(*this >= d);
}
bool Date::operator<=(const Date& d)const
{
	return !(*this > d);
}
bool Date::operator==(const Date& d)const
{
	return (this->year_ == d.year_ && this->month_ == d.month_ && this->day_ == d.day_);
}
bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}
//重载 减 对象
int Date::operator-(const Date& d)
{
	int val = 0;
	Date _min(*this);
	Date _max(d);
	int flag = 1;
	if (*this > d)
	{
		_min = d;
		_max = *this;
		flag = -1;
	}
	while (_min != _max)
	{
		++_min;
		++val;
	}
	return val*flag;
}
