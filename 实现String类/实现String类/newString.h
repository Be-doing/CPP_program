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
			capacity_ = newcapacity;
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

	//插入字符串
	void Append(const char* str)
	{
		size_t leng = strlen(str);
		if (size_ + leng >= capacity_)
		{
			size_t newcapacity = (size_ + leng <= 15 ? 15 : size_ + leng);
			Reserve(newcapacity);
		}
		strcpy(str_ + leng, str);
		size_ += leng;
	}
	// 在pos位置上插入字符c/字符串str，并返回该字符的位置
	newString& Insert(size_t pos, char c)
	{
		assert(pos <= size_);
		if (size_ == capacity_)
		{
			size_t newcapacity = (size_ == 0 ? 15 : capacity_ * 2);
			Reserve(newcapacity);
		}
		size_t end = size_;
		while (pos < end)
		{
			str_[end] = str_[end - 1];
			--end;
		}
		str_[pos] = c;
		++size_;
		return *this;
	}
	newString& Insert(size_t pos, const char* str)
	{
		assert(pos <= size_);
		size_t len = strlen(str);
		if (size_ + len >= capacity_)
		{
			size_t newcapacity = (size_ + len <= 15 ? 15 : size_ + len);
			Reserve(newcapacity);
		}
		size_t end = size_ + len;
		while (pos + len - 1 < end)
		{
			str_[end] = str_[end - len];
			--end;
		}
		for (size_t i = 0; i < len; ++i)
		{
			str_[pos] = str[i];
		}
		size_ += len;
		return *this;
	}

	//尾删
	void PopBack()
	{
		if (size_ > 0)
		{
			--size_;
		}
	}

	//删除函数
	void Erase(size_t pos, size_t len)
	{
		assert(pos < size_);
		if (pos + len >= size_)
		{
			size_ = pos;
			str_[pos] = '\0';//pos后面的字符串
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

	// 返回c在newString中第一次出现的位置
	size_t Find(char c, size_t pos = 0) const
	{
		while (pos < size_)
		{
			if (str_[pos] == c)
			{
				return pos;
			}
			++pos;
		}
		return npos;
	}
	// 返回子串s在newString中第一次出现的位置
	// 判断字串
	char* SubStr( char* str)
	{
		char* dst = str_;
		char* src = str;
		while (*dst)
		{
			if (*dst == *src)
			{
				char* mathdst = dst + 1;
				char* mathsrc = src + 1;

				while (*mathdst && * mathsrc)
				{
					if (*mathdst != *mathsrc)
					{
						return 0;
					}
					++mathdst;
					++mathsrc;
				}
				if (mathsrc == '\0')
				{
					return dst;
				}
			}

			++dst;
		}
		return 0;
	}
	size_t Find(const char* str, size_t pos = 0) const
	{
		char* res = SubStr(str);
	}
	// 截取newString从pos位置开始的n个字符
	newString SubStr(size_t pos, size_t n);

	void Clear()
	{
		size_ = 0;
		str_[size_] = '\0';
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
	//字符串长度
	size_t Size() const
	{
		return size_;
	}

	//迭代器
	const_iterator begin() const
	{
		return str_;
	}
	const_iterator end() const
	{
		return str_ + size_;
	}


	//各类重载
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
	newString& operator+=(const char* str)
	{

		//size_t leng = strlen(str);
		//if (this->size_ + leng > capacity_)
		//{
		//	Reserve(this->size_ + leng);
		//}
		//strcpy(this->str_+ size_, str);
		Append(str);
		return *this;
	}
	newString& operator+=(const newString& str)
	{
		Append(str.str_);
		return *this;
	}

	bool operator<(const newString& str)
	{
		if (strcmp(str_, str.str_) + 1)
		{
			return false;
		}
		return true;
	}
	bool operator<=(const newString& str)
	{
		return !(str_ > str.str_);
	}
	bool operator>(const newString& str)
	{
		if (strcmp(str_,str.str_))
		{
			return true;
		}
		return false;
	}
	bool operator>=(const newString& str)
	{
		return !(str_ < str.str_);
	}
	bool operator==(const newString& str)
	{
		return !((str_ > str.str_) || (str_ < str.str_));
	}
	bool operator!=(const newString& str)
	{
		return !(str_ == str.str_);
	}
private:
	char* str_;
	size_t size_;
	size_t capacity_;
	static const size_t npos;
};
const size_t newString::npos = -1;
void Print(newString& str)
{
	for (size_t i = 0; i < str.Size(); i++)
	{
		cout << str[i] << "  ";
	}
}