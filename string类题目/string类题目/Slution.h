#pragma once
#include<iostream>
using namespace std;
#include<string>

class MySolution
{
public:
	//翻转字符串
	string MyReverse(string str)
	{
		int begin = 0;
		int end = str.size();
		cout << "当前字符串：" << str << endl;
		while (begin < end)
		{
			swap(str[begin], str[end - 1]);
			++begin;
			--end;
		}
		return str;
	}
	//找到字符串第一个只出现一次的字符
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
	//字符串里面最后一个单词的长度
	int LastLength(string str)
	{
		size_t pos = str.rfind(' ');
		return str.size() - pos;
	}
	//判断回文

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
	//字符串相加
	//当前位的值 = （第一个数 + 第二个数 + 上一位的进位）% 10
	//当前位的进位 = （第一个数 + 第二个数 + 上一位的仅为） / 10 ->进位只能是 1
	string AddStrings(string str1, string str2)
	{
		int pos1 = str1.size() - 1;
		int pos2 = str2.size() - 1;
		int step = 0;
		string ret = "";
		while (pos1 >= 0 || pos2 >=0)
		{
			int sum = 0;
			sum += step;
			if (pos1 >= 0)
			{
				sum += (str1[pos1] - '0');
			}
			if (pos2 >= 0)
			{
				sum += (str2[pos2] - '0');
			}
			if (sum > 9)
			{
				sum -= 10;
				step = 1;
			}
			else
			{
				step = 0;
			}
			ret.push_back( sum + '0');
			pos1--;
			pos2--;
		}
		if (step == 1)
		{
			ret.push_back( '1');
		} 
			reverse(ret.begin(),ret.end());
			return ret;
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