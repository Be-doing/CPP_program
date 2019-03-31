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
	//ȫȱʡ���캯��
	newString(const char* str = "")
	{
		//�����ǿ�ָ��
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

	//��������
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
	//��������
	//�ִ�д��
	newString(const newString& str)//����
		:str_(nullptr),
		size_(0),
		capacity_(0)
	{		//������ʱ����
		newString tmp(str.str_);//����ֱ�ӽ���ָ�룬���ܸı�ԭ�����ָ������
		Swap(tmp);
	}
	//��������
	void Swap(newString& str)
	{
		swap(str_, str.str_);
		swap(size_, str.size_);
		swap(capacity_, str.capacity_);
	}

	//��������� =     &���õ�Ŀ�ģ���������
	newString& operator=(newString str)     //����Ӧ����һ����ʱ����
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
	//����ַ�
	void PushBack(char c)
	{
		//���ռ��Ƿ��㹻
		if (size_ == capacity_)
		{
			size_t newcapacity = (size_ == 0 ? 15 : capacity_ * 2);
			Reserve(newcapacity);
		}
		str_[size_++] = c;
		str_[size_] = '\0';
	}

	//ɾ���ַ�
	void PopBack()
	{
		if (size_ > 0)
		{
			--size_;
		}
	}

	//�ı�size
		// n <= size_ ��  �޸�size_ = n�� str[n] = '\n'
		//	size_ < n <= capacity_�� size_ = n �� str[n] = '\n'    ԭ��δ�õĿռ䰴���ַ��
		//	n > capacity_ ��������
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

	//ɾ������
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

	//�����ַ���
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