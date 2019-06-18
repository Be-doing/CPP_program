#pragma once
#include<iostream>
#include<string>
using namespace std;
//异常的使用#####################################
double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
		throw "除数是 0 ！";
	else
		return ((double)a / (double)b);
}

void Func()
{
	int Dividend;
	int Divisor;
	cin >> Dividend >> Divisor;
	try 
	{
		cout << Division(Dividend, Divisor) << endl;
	}
	//catch (const char* e)
	//{
	//	cout << e << endl;
	//}
	catch (int  n)
	{
		cout << n << endl;
	}

	cout << "会不会执行这儿呢？" << endl;
}

class Student
{
public:
	Student(const string& name = "张三", const string& sex = "男", const int& stunum = 12345)
		:name_(name)
		,stu_num_(stunum)
		,sex_(sex)
	{
		cout << "Student()" << endl;
	}
	~Student()
	{
		cout << "~Student()" << endl;
	}
	void Print()
	{
		cout << "name: " << name_ << "   sex: " << sex_ << "   stunum: " << stu_num_ << endl;
	}
private:
	string name_;
	string sex_;
	int stu_num_;
};






//auto_ptr的实现###################################
template <class T>
class Auto_Ptr
{
public:
	Auto_Ptr(T* ptr = nullptr)
		:autoptr_(ptr)
	{
		cout << "Auto_Ptr()" << endl;
	}
	Auto_Ptr(Auto_Ptr<T>& ptr)//这里是要修改不能要const属性
		:autoptr_(ptr)
	{
		ptr = nullptr;//当对象拷贝或者赋值后，前面的智能指针就悬空
		cout << "Auto_Ptr(&)" << endl;
	}
	~Auto_Ptr()
	{
		if (autoptr_)
		{
			delete autoptr_;//会自动调用对象的析构函数
			cout << "~Auto_Ptr()" << endl;
		}
	}
	Auto_Ptr<T>& operator=(Auto_Ptr<T>& ptr)
	{
		if (this != &ptr)//防止自己给自己赋值
		{
			if (autoptr_)
			{
				delete autoptr_;//如果原来的智能指针是指向某一个对象时要释放原来的资源
			}
			autoptr_(ptr);
		}
	}
	//既然是指针就会有++，->，*等操作
	T& operator*()
	{
		return *autoptr_;
	}
	T* operator->()
	{
		return autoptr_;
	}
private:
	T* autoptr_;
};

//unique_ptr的实现#########################################
template <class T>
class UniquePtr
{
public:
	UniquePtr(T* ptr = nullptr)
		:uniqueptr_(ptr)
	{
		cout << "UniquePtr()" << endl;
	}
	~UniquePtr()
	{
		if (uniqueptr_)
		{
			delete uniqueptr_;
		}
	}
	T& operator*()
	{
		return *uniqueptr_;
	}
	T* operator->()
	{
		return uniqueptr_;
	}
private:
	T* uniqueptr_;
	UniquePtr(UniquePtr<T>& ptr) = delete;
	UniquePtr<T>& operator=(UniquePtr<T>& ptr) = delete;
};
//shared_ptr的实现########################################
#include<mutex>
template <class T>
class SharePtr
{
public:
	SharePtr(T*& ptr)
		:shareptr_(ptr)
		,pcount_(new int(1))
		,pmutex_(new mutex)
	{
		cout << "SharePtr() " << endl;
	}
	SharePtr(SharePtr<T>& ptr)
		:shareptr_(ptr.shareptr_)
		, pcount_(ptr.pcount_)
		, pmutex_(ptr.pmutex_)
	{
		
		cout << "SharePtr(&)" << endl;
	}
private:
	T* shareptr_;
	int* pcount_;
	mutex* pmutex_;
};