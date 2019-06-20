#pragma once
#include<iostream>
#include<string>
using namespace std;
//�쳣��ʹ��#####################################
double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
		throw "������ 0 ��";
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

	cout << "�᲻��ִ������أ�" << endl;
}

class Student
{
public:
	Student(const string& name = "����", const string& sex = "��", const int& stunum = 12345)
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






//auto_ptr��ʵ��###################################
template <class T>
class Auto_Ptr
{
public:
	Auto_Ptr(T* ptr = nullptr)
		:autoptr_(ptr)
	{
		cout << "Auto_Ptr()" << endl;
	}
	Auto_Ptr(Auto_Ptr<T>& ptr)//������Ҫ�޸Ĳ���Ҫconst����
		:autoptr_(ptr.autoptr_)
	{
		ptr.autoptr_ = nullptr;//�����󿽱����߸�ֵ��ǰ�������ָ�������
		cout << "Auto_Ptr(&)" << endl;
	}
	~Auto_Ptr()
	{
		if (autoptr_)
		{
			delete autoptr_;//���Զ����ö������������
			cout << "~Auto_Ptr()" << endl;
		}
	}
	Auto_Ptr<T>& operator=(Auto_Ptr<T>& ptr)
	{
		if (this != &ptr)//��ֹ�Լ����Լ���ֵ
		{
			if (autoptr_)
			{
				delete autoptr_;//���ԭ��������ָ����ָ��ĳһ������ʱҪ�ͷ�ԭ������Դ
			}
			autoptr_ = ptr.autoptr_;
			ptr.autoptr_ = nullptr;
		}
		return *this;
	}
	//��Ȼ��ָ��ͻ���++��->��*�Ȳ���
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

//unique_ptr��ʵ��#########################################
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
//shared_ptr��ʵ��########################################
#include<mutex>
template <class T>
class SharePtr
{
public:
	SharePtr(T* ptr = nullptr)
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
		AddCount();
		cout << "SharePtr(&)" << endl;
	}
	~SharePtr()
	{
		cout << "~SharePtr()" << endl;
		Release();
	}
	void AddCount()
	{
		pmutex_->lock();
		++(*pcount_);
		pmutex_->unlock();
	}
	SharePtr<T> operator=(SharePtr<T>& ptr)
	{
		if (this != &ptr)
		{
			Release();//ɾ���ɵ���Դ������count��ʼ��ʱ����1�����Բ�����-1
			shareptr_ = ptr.shareptr_;
			pmutex_ = ptr.pmutex_;
			AddCount();
		}
		return *this;
	}
	T& operator*()
	{
		return *shareptr_;
	}
	T* operator->()
	{
		return shareptr_;
	}
	int UseCount()
	{
		return *pcount_;
	}
private:
	void Release()
	{
		bool mutexflag = false;
		pmutex_->lock();
		if (--(*pcount_) == 0)
		{
			delete shareptr_;
			delete pcount_;
			mutexflag = true;
		}
		pmutex_->unlock();
		if (mutexflag == true)
		{
			delete pmutex_;
		}
	}
private:
	T* shareptr_;
	int* pcount_;
	mutex* pmutex_;
};

struct ListNode
{
	int data = 0;
	shared_ptr<ListNode> prev = nullptr;
	shared_ptr<ListNode> next = nullptr;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

