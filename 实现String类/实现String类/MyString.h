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