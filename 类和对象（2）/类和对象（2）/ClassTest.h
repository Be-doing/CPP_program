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
	//Date()//�޲εĹ��캯��
	//{}
	//��������
	Date(const Date& date)
		//��ʼ���б�
		//:ra(10)
	{
		year_ = date.year_;
		month_ = date.month_;
		day_ = date.day_;
	}
	//���������
		//�ж�
	bool operator == (Date& d2)
	{
		return year_ == d2.year_&&month_ == d2.month_&&day_ == d2.day_;
	}
	//��ֵ�����
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
	//��Ե����
	friend  ostream& operator << (ostream& _cout, Date& d);
	friend istream& operator>>(istream& _cin, const Date& d);
	//���� << ��������ǵ�һ�����������Ե��õ�ʱ����Ҫ date << cout;
	void operator << (ostream& _cout)
	{
		_cout << year_ << "/" << month_ << "/" << day_ << endl;
	}
	//const ���γ�Ա����
	void display2()	const
	{
		cout << year_ << "/" << month_ << "/" << day_ << endl;
	}
private:
	int year_;
	int month_;
	int day_;
	//static��Ա����
	static int hour_;
};
//Ϊ��������˽�л�����֤�����ǰ�ȫ�ģ�����Ϊ��Ԫ
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
	//��������
	~String()
	{
		cout << "���������Դ" << endl;
		free(str_);
	}
	void display()
	{
		cout << str_ << endl;
	}
private:
	char* str_;
};
