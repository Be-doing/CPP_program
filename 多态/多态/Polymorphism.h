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
		cout << "A的成员函数func" << endl;
	}
	virtual void func1()
	{
		cout << "A的虚函数" << endl;
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
		cout << "B的成员函数func" << endl;
	}
	virtual void func1()
	{
		cout << "B的虚函数" << endl;
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
	Person(const string name = "张三")
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
	Car(const string& band = "五菱宏光")
		:band_(band)
	{}
	virtual void Drive()
	{
		cout << "秋名山车王" << endl;
	}
	virtual void Func()
	{
		cout << "我是不想重写的虚函数" << endl;
	}
	void Func1()
	{
		cout << "我是基类的普通函数" << endl;
	}
private:
	string band_;
};
class BWM : public Car
{
public:
	BWM(const string& band = "宝马")
		:Car(band)
	{}
	virtual void Drive()
	{
		cout << "驾驶之王" << endl;
	}
	virtual void Print()
	{
		cout << "大家好，我是宝马" << endl;
	}
};

class Base1
{
public:
		Base1(const int& b):b1(b){}
		virtual void Func1()
		{
			cout << "我是Base1的虚函数" << endl;
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
		cout << "我是Base2的虚函数" << endl;
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
		cout << "我是重写Base2的虚函数" << endl;
	}
	virtual void Func3()
	{
		cout << "我是派生类的虚函数" << endl;
	}
private:
	int c_;
};