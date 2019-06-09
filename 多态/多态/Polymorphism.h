#pragma once
#include<iostream>
#include<string>
using namespace std;

class A
{
public:
	A(int a = int())
		:a_(a)
	{
		cout << "A()" << endl;
	}
	void func()
	{
		cout << "A�ĳ�Ա����func" << endl;
	}
	virtual void func1()
	{
		cout << "A���麯��" << endl;
	}
private:
	int a_;
};
class	B :public A
{
public:
	B(int b = int())
		:b_(b)
	{
		cout << "B()" << endl;
	}
	void func()
	{
		cout << "B�ĳ�Ա����func" << endl;
	}
	virtual void func1()
	{
		cout << "B���麯��" << endl;
	}
private:
	int b_;
};
void Poly(A& a)
{
	a.func1();
	a.func();
}
class Person
{
public:
	Person(const string name = "����")
		:name_(name)
	{}
	virtual void Print() = 0;
private:
	string name_;
};
class Student : public Person
{
public:
	Student(const int& stunum = 0)
		:Person()
		,stunum_(stunum)
	{}
	virtual void Print()
	{
		cout << "Student::Print()" << endl;
	}
private:
	int stunum_;
};
class Car
{
public:
	Car(const string& band = "������")
		:band_(band)
	{}
	virtual void Drive()
	{
		cout << "����ɽ����" << endl;
	}
	virtual void Func()
	{
		cout << "���ǲ�����д���麯��" << endl;
	}
	void Func1()
	{
		cout << "���ǻ������ͨ����" << endl;
	}
private:
	string band_;
};
class BWM : public Car
{
public:
	BWM(const string& band = "����")
		:Car(band)
	{}
	virtual void Drive()
	{
		cout << "��ʻ֮��" << endl;
	}
	virtual void Print()
	{
		cout << "��Һã����Ǳ���" << endl;
	}
};

class Base1
{
public:
		Base1(const int& b):b1(b){}
		virtual void Func1()
		{
			cout << "����Base1���麯��" << endl;
		}
private:
	int b1;
};
class Base2
{
public:
	Base2(const int& b) :b2(b) {}
	virtual void Func2()
	{
		cout << "����Base2���麯��" << endl;
	}
private:
	int b2;
};

class Child : public Base1, public Base2
{
public:
	Child()
		:Base1(1)
		, Base2(2)
		,c_(3)
	{}
	virtual void Func2()
	{
		cout << "������дBase2���麯��" << endl;
	}
	virtual void Func3()
	{
		cout << "������������麯��" << endl;
	}
private:
	int c_;
};