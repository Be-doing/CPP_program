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
	iterator& begin()
	{
		return start_;
	}
	iterator& end()
	{
		return finish_;
	}
	const_iterator& begin() const
	{
		return start_;
	}
	const_iterator& end() const
	{
		return finish_;
	}
	//���캯��
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
	//����[]
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
	//����
	void Insert(iterator pos,const T& val)
	{
		assert(pos <= finish_ && pos >= start_);//��֤λ����Ч
		//�����ʹ������ʧЧ������pos��λ��
		size_t tmp = pos - start_;
		if (endofstorage_ == finish_)//��������
		{
			size_t capacity = start_ == nullptr ? 1 : 2 * Capacity();
			Reserve(capacity);
		}
		//����pos��λ��
		pos = start_ + tmp;
		iterator end = finish_;
		while (end > pos)
		{
			*end = *(end - 1);
			--end;
		}
		*pos = val;
		++finish_;
	}
	void Erase(iterator pos)
	{
		assert(start_<= pos && pos < finish_);
		iterator begin = pos;
		while (begin < finish_)
		{
			*begin = *(begin + 1);
			++begin;
		}
		--finish_;
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
		//Insert(end(),val);
	}
	//βɾ
	void PopBack()
	{
		assert(start_ != nullptr);
		//*(finish_ - 1) = *finish_;
		//--finish_;
		Erase(end() - 1);
	}
	//������
	void Resize(size_t size, const T& val = T())
	{
		if (finish_ + size < endofstorage_)
		{
			finish_ = start_ + size;
		}
		else
		{
			Reserve(size);
			//�����λ�ý��и�ֵ
			while (finish_ != start_ + size)
			{
				*finish_ = val;
				++finish_;
			}
		}
	}
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
template<class T>
void PrintVectorSize(MyVector<T>& v)
{
	cout << v.Size() << endl;
}