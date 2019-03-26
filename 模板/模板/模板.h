#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template <class T>
void MySwap(T& obj1, T& obj2)
{
	T temp = obj1;
	obj1 = obj2;
	obj2 = temp;
}

template<class T2>
class MyVector
{
public:
	MyVector(size_t capacity)
		:arr_(new T2[capacity]),
		size_(0),
		capacity_(capacity)
	{}
	void PushBack(T2 data)
	{
		arr_[size_] = data;
		++size_;
	}
	void PopBack()
	{
		--size_;
	}
	size_t getSize()
	{
		return size_;
	}
	T2& operator[] (size_t pos)
	{
		assert(pos < size_);
		return arr_[pos];
	}

private:
	T2* arr_;
	size_t size_;
	size_t capacity_;
};
template<class T3>
void Print(MyVector<T3>& v)
{
	for (size_t i = 0; i < v.getSize(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}