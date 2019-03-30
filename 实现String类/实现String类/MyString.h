#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class String
{
public:
	String(const char* str = "")
	{
		// ����string�����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
		if (nullptr == str)
		{
			assert(false);
			return;
		}

		str_ = new char[strlen(str) + 1];
		strcpy(str_, str);
	}

	~String()
	{
		if (str_)
		{
			delete[] str_;
			str_ = nullptr;
		}
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pStr = new char[strlen(s.str_) + 1];
			strcpy(pStr, s.str_);
			delete[] str_;
			str_ = pStr;
		}
		String(const char* str = "")
		{
			if (nullptr == str)
				str = "";

			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		String(const String& s)
			: _str(nullptr)
		{
			String strTmp(s._str);
			swap(_str, strTmp);
		}

		// �Ա��º�����ĸ�ֵ�Ǹ�ʵ�ֱȽϺã�
		String& operator=(String s)
		{
			swap(_str, s._str);
			return *this;
		}

		/*
		String& operator=(const String& s)
		{
		if(this != &s)
		{
		String strTmp(s);
		swap(_str, strTmp._str);
		}

		return *this;
		}
		*/

		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		return *this;
	}

private:
	char* str_;
};
class Solution
{
public:
	int StrToInt(string str)
	{
		int ret = 0;
		string::iterator sit = str.begin();
		int flag = -1;
		while (sit != str.end())
		{
			if (*sit == '-' || *sit == '+')
			{
				if (*sit == '+')
					flag = '+';
			}
			else if ('0' < *sit < '9')
			{
				ret += *sit - '0';
				ret *= 10;
			}
			else
			{
				return 0;
			}
		}
		return ret * flag;
	}
};