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
template<class T4>
T4 Sum(const T4& left,const T4& right)
{
	return left + right;
}
int Sum(int left, int right)
{
	return left + right;
}

//模板特化的应用——类型萃取

//先定义两个类进行区分自定义类型和内置类型
struct TruePodType//Plain old data structure，缩写为POD
{
	static bool Get()
	{
		return true;
	}
};

struct FalsePodType
{
	static bool Get()
	{
		return false;
	}
};


template<class T>
struct TypeTraits
{
	typedef FalsePodType IsPODType;
};

template<>
struct TypeTraits<int>
{
	typedef TruePodType IsPODType;
};
template<>
struct TypeTraits<char>
{
	typedef TruePodType IsPODType;
};
template<>
struct TypeTraits<double>
{
	typedef TruePodType IsPODType;
};
template<>
struct TypeTraits<short>
{
	typedef TruePodType IsPODType;
};

template<class T>
void Copy(T* dest, T* src, size_t size)
{
	if (TypeTraits<T>::IsPODType::Get())
	{
		memcpy(dest, src, sizeof(T)*size);
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			dest[i] = src[i];
		}
	}
}