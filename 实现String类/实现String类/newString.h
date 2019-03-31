#pragma once
#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class newString
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;
	//全缺省构造函数
	newString(const char* str = "")
	{
		//不能是空指针
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		size_ = strlen(str);
		capacity_ = size_;
		str_ = new char[size_ + 1];
		strcpy(str_, str);
	}

	//析构函数
	~newString()
	{
		if (str_)
		{
			size_ = 0;
			capacity_ = 0;
			delete[] str_;
			str_ = nullptr;
		}
	}
	//拷贝构造
	//现代写法
	newString(const newString& str)//引用
		:str_(nullptr),
		size_(0),
		capacity_(0)
	{		//创建临时对象
		newString tmp(str.str_);//不能直接交换指针，不能改变原对象的指针内容
		Swap(tmp);
	}
	//交换函数
	void Swap(newString& str)
	{
		swap(str_, str.str_);
		swap(size_, str.size_);
		swap(capacity_, str.capacity_);
	}

	//重载运算符 =     &引用的目的：连续复制
	newString& operator=(newString str)     //这里应景有一个临时对象
	{
		Swap(str);
	}
	void Reserve(size_t newcapacity)
	{
		if (newcapacity > capacity_)
		{
			char* tmp = new char[newcapacity + 1];
			strcpy(tmp, str_);
			delete[] str_;
			str_ = tmp;
		}
	}
	//添加字符
	void PushBack(char c)
	{
		//检查空间是否足够
		if (size_ == capacity_)
		{
			size_t newcapacity = (size_ == 0 ? 15 : capacity_ * 2);
			Reserve(newcapacity);
		}
		str_[size_++] = c;
		str_[size_] = '\0';
	}

	//删除字符
	void PopBack()
	{
		if (size_ > 0)
		{
			--size_;
		}
	}

	//改变size
		// n <= size_ ；  修改size_ = n， str[n] = '\n'
		//	size_ < n <= capacity_； size_ = n ； str[n] = '\n'    原来未用的空间按用字符填补
		//	n > capacity_ 进行扩容
	void Resize(size_t newsize)
	{
		if (newsize > capacity_)
		{
			Reserve(newsize);
		}
		if (newsize > size_)
		{
			memset(str_ + size_, '\0', newsize - size_);
		}
		size_ = newsize;
		str_[size_] = '\0';
	}

	//删除函数
	void Erase(size_t pos, size_t len)
	{
		assert(pos < size_);
		if (pos + len >=size_)
		{
			size_ = pos;
			str_[pos] = '\0';
		}
		else
		{
			for (size_t i = pos + len; i <= size_; i++)
			{
				str_[pos++] = str_[i];
			}
			size_ = pos - 1;
		}
	}

	//插入字符串
	void Append(const char* str)
	{
		size_t leng = strlen(str);
		if (size_ + leng >= capacity_)
		{
			Reserve(size_ + leng);
		}
		strcpy(str_ + leng, str);
		size_ += leng;
	}
	char& operator[](size_t pos)
	{
		assert(pos < size_);
		return str_[pos];
	}
	const char& operator[](size_t pos) const
	{
		assert(pos < size_);
		return str_[pos];
	}
	size_t Size() const
	{
		return size_;
	}
	const_iterator begin() const
	{
		return str_;
	}
	const_iterator end() const
	{
		return str_ + size_;
	}
private:
	char* str_;
	size_t size_;
	size_t capacity_;
};
void Print(newString& str)
{
	for (size_t i = 0; i < str.Size(); i++)
	{
		cout << str[i] << "  ";
	}
}