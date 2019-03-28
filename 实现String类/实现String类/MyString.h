#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class String
{
public:
	String(const char* str = "")
	{
		// 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下
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