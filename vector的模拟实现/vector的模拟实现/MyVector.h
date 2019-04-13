#pragma once
#include <vector>
#include<iostream>
#include<assert.h>
using namespace std;
template <class T>
class MyVector
{
public:
	//������
	typedef T* iterator;
	typedef const T* const_iterator;

	MyVector()
	:start_(nullptr),
	finish_(nullptr),
	endofstorage_(nullptr)
	{}

	//����
	size_t Capacity()
	{
		return endofstorage_ - start_;
	}
	//��ЧԪ�ظ���
	size_t Size()
	{
		return finish_ - start_;
	}
	//��д[]
	T& operator [] (size_t pos)
	{
		assert(pos < Size());
		return start_[pos];
	}
	const T& operator [] (size_t pos) const
	{
		assert(pos < Size());
		return start_[pos];
	}
	//����
	void Reserve(size_t newcapacity)
	{
		size_t oldsize = Size();
		if (newcapacity > Capacity())
		{
			T* tmp = new T[newcapacity];
			if (start_)
			{
				for (size_t i = 0; i < Size(); ++i)
				{
				tmp[i] = start_[i];
				}
				delete[] start_;
			}
			start_ = tmp;
			finish_ = start_ + oldsize;
			endofstorage_ = start_ + newcapacity;
		}
	}
	//β��
	void PushBack(const T& val)
	{
		if (endofstorage_ == finish_)
		{
			size_t capacity = start_ == nullptr ? 1 : 2 * Capacity();
			Reserve(capacity);
		}
		*finish_ = val;
		++finish_;
	}
	//βɾ
	void PopBack()
	{
		assert(start_ != nullptr);
		*(finish_ - 1) = *finish_;
		--finish_;
	}
	//������

	~MyVector()
	{
		if (start_)
		{
			delete[] start_;
			start_ = finish_ = endofstorage_ = nullptr;
		}
	}

private:
	T* start_;
	T* finish_;
	T* endofstorage_;
};
template<class T>
void PrintVector(MyVector<T>& v) 
{
	for (size_t i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << "\t";
	}
	cout << endl;
}