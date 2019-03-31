#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;
class String
{
public:
	//全缺省构造函数
	String(const char* str = " ")
	{
		//不能是空指针
		if (str == nullptr)
		{
			assert(false);
			return;
		}
		str_ = new char[strlen(str) + 1];
		strcpy(str_, str);
	}

	//析构函数
	~String()
	{
		if (str_)
		{
			delete[] str_;
			str_ = nullptr;
		}
	}
	//拷贝构造
	//String(const String& str)
	//	:str_(new char[strlen(str.str_) + 1])
	//{
	//	strcpy(str_, str.str_);
	//}
		//现代写法
	String(const String& str)//引用
		:str_(nullptr)
	{		//创建临时对象
		String tmp(str.str_);//不能直接交换指针，不能改变原对象的指针内容
		swap(str_, tmp.str_);
	}


	//重载运算符 =     &引用的目的：连续复制

	//String& operator=(const String& str)
	//{
	//	if (this != &str)		//防止给自己赋值
	//	{
	//		delete[] str_;   //为了防止空间不够
	//		str_ = new char[strlen(str.str_) + 1];
	//		strcpy(str_, str.str_);
	//	}
	//	return *this;
	//}
	//	// 现代写法
	String& operator=(String str)     //这里应景有一个临时对象
	{
		swap(str_, str.str_);
		return *this;
	}
	//
	//String& operator=(String& str)
	//{
	//	if (this != &str)
	//	{
	//		String tmp(str);
	//		swap(str_, tmp.str_);
	//	}
	//	return *this;
	//}
private:
	char* str_;
};





//class Solution
//{
//public:
//	int StrToInt(string str)
//	{
//		int ret = 0;
//		string::iterator sit = str.begin();
//		int flag = -1;
//		while (sit != str.end())
//		{
//			if (*sit == '-' || *sit == '+')
//			{
//				if (*sit == '+')
//					flag = '+';
//			}
//			else if ('0' < *sit < '9')
//			{
//				ret += *sit - '0';
//				ret *= 10;
//			}
//			else
//			{
//				return 0;
//			}
//		}
//		return ret * flag;
//	}
//};