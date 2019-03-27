#pragma once
#include<iostream>
using namespace std;

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