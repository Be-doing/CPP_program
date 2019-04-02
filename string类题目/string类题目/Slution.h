#pragma once
#include<iostream>
using namespace std;
#include<string>

class MySolution
{
public:
	//·­×ª×Ö·û´®
	void MyReverse(string str)
	{
		int begin = 0;
		int end = str.size();
		cout << "µ±Ç°×Ö·û´®£º" << str << endl;
		while (begin < end)
		{
			swap(str[begin], str[end - 1]);
			++begin;
			--end;
		}
		cout << "·­×ªºó×Ö·û´®£º" << str << endl;
	}
	//ÅÐ¶Ï»ØÎÄ
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
	string str_;
};