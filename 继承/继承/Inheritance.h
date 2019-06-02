#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person()
		:name_("张三")
		,assess_("富有")
	{
		cout << "Person()" << endl;
	}
	void setName(const string& name)
	{
		name_ = name;
	}
protected:
	string assess_;
private:
	string name_;
};

class Student : public Person
{
public:
	Student(const string str = "123456" )
		:stunum_(str)
	{
		assess_ = "富二代";
		cout << "Student()" << endl;
	}
	void Myname(const string& name)
	{
		setName(name);
	}
private:
	string stunum_;//学号
};
class Teacher : public Person
{
public:
	Teacher(const string str = "123456")
		:edunum_(str)
	{
		assess_ = "富大代";
		cout << "Teacher()" << endl;
	}
private:
	string edunum_;
};

class Self : public Student, public Teacher
{
public:
	Self()
	{}
};

class Child;
class Father
{
public:
	Father(const string& name = "张三", int age = 10)
		:name_(name)
		, age_(age)
	{
		cout << "Father()" << endl;
	}
	void Func(int tmp)//函数隐藏
	{
		cout << tmp << endl;
	}
	Father(const Father& f)
		:name_(f.name_)
		,age_(f.age_)
	{
		cout << "Father(&)" << endl;
	}
	Father& operator=(const Father& f)
	{
		if (this != &f)
		{
			this->name_ = f.name_;
			this->age_ = f.age_;
		}
		cout << "Foperator=" << endl;
		return *this;
	}
	~Father()
	{
		cout << "~Father()" << endl;
	}
private:
	string name_;
	int age_;
};

class Child : public Father
{
public:
	Child(const string& sex = "男", int grade = 90)
		:sex_(sex)
		, grade_(grade)
	{
		cout << "Child()" << endl;
	}
	Child(const Child& c)
		:Father::Father(c)
		,sex_(c.sex_)
		, grade_(c.grade_)
	{
		cout << "Child(&)" << endl;
	}
	Child& operator=(const Child& c)
	{
		if (this != &c)
		{
			Father::operator=(c);
			this->sex_ =c.sex_;
			this->grade_ =c.grade_;
		}
		cout << "Coperator=" << endl;
		return *this;
	}
	void Func()
	{
		cout << "NULL" << endl;
	}

	~Child()
	{
		cout << "~Child()" << endl;
	}
private:
	string sex_;
	int grade_;
};

class A
{
	friend void Display(const A& a);
public:
	A(const int& a = int())
		:a_(a)
	{}
	static void Print(const A& a);
private:
	int a_;
};
void A::Print(const A& a)
{
	cout << a.a_ << endl;
}
void Display(const A& a)
{
	cout << a.a_ << endl;
}
class B : public A
{
public:
	B(const int& b = int())
		:A::A()
		,b_(b)
	{}
private:
	int b_;
};
class C : public A
{
public:
	C(const int& c = int())
		:A::A()
		, c_(c)
	{}
private:
	int c_;
};
//class Car 
//{ 
//public:    
//	virtual void Drive() final 
//	{} 
//};
//
//class Benz :public Car 
//{
//public:   
//	virtual void Drive() 
//	{ 
//		cout << "Benz-舒适" << endl; 
//	} 
//};
//
//class Car
//{
//public:  
//	virtual void Drive()
//	{}
//};
//// 2.override 修饰派生类虚函数强制完成重写，如果没有重写会编译报错 
//class Benz :public Car 
//{
//public:  
//	virtual void Drive() override 
//	{
//		cout << "Benz-舒适" << endl;
//	} 
//};
//
//
//
//class Base 
//{
//public:    
//	virtual void Func1() 
//	{
//		cout << "Base::Func1()" << endl; 
//	}
//
//		   virtual void Func2() 
//		   { 
//			   cout << "Base::Func2()" << endl;
//		   }
//
//		   void Func3()
//		   { 
//			   cout << "Base::Func3()" << endl; 
//		   }
//
//private:   
//	int _b = 1;
//};
//
//class Derive : public Base
//{ 
//public: 
//virtual void Func1()
//{
//cout << "Derive::Func1()" << endl;
//}
//private:   
//	int _d = 2;
//};

//int main() {
//	Base b;    Derive d;
//
//	return 0;
//}
