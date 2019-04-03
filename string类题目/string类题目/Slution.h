#pragma once
#include<iostream>
using namespace std;
#include<string>

class MySolution
{
public:
	//��ת�ַ���
	string MyReverse(string str)
	{
		int begin = 0;
		int end = str.size();
		cout << "��ǰ�ַ�����" << str << endl;
		while (begin < end)
		{
			swap(str[begin], str[end - 1]);
			++begin;
			--end;
		}
		return str;
	}
	//�ҵ��ַ�����һ��ֻ����һ�ε��ַ�
	char FirstLetter(string str)
	{
		for (size_t i = 0; i < str.size(); ++i)
		{
			for (size_t j = i + 1; j < str.size(); ++j)
			{
				if (str[i] == str[j])
				{
					break;
				}
				if (j == str.size() - 1)
				{
					return str[i];
				}
			}
		}
		return -1;
	}
	//�ַ����������һ�����ʵĳ���
	int LastLength(string str)
	{
		size_t pos = str.rfind(' ');
		return str.size() - pos;
	}
	//�жϻ���

	bool isPalindrome(string str)
	{
		if (str.empty())
		{
			return true;
		}
		for (size_t i = 0; i < str.size(); ++i)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 32;
			}
		}
		size_t begin = 0;
		size_t end = str.size() - 1;
		while (begin < end)
		{
			while (begin < end)
			{
				if (isNumLetter(str[begin]))
				{
					break;
				}
				++begin;
			}
			while (begin < end)
			{
				if (isNumLetter(str[end]))
				{
					break;
				}
				--end;
			}
			if (str[begin] != str[end])
			{
				return false;
			}
		}
		return true;
	}
private:
	bool isNumLetter(char c)
	{
		if ((c >= '0' && c <= '9') ||
			(c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z'))
		{
			return true;
		}
		return false;
	}
	string str_;
};