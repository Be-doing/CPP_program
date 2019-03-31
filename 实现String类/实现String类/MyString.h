#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;
class String
{
public:
	//ȫȱʡ���캯��
	String(const char* str = " ")
	{
		//�����ǿ�ָ��
		if (str == nullptr)
		{
			assert(false);
			return;
		}
		str_ = new char[strlen(str) + 1];
		strcpy(str_, str);
	}

	//��������
	~String()
	{
		if (str_)
		{
			delete[] str_;
			str_ = nullptr;
		}
	}
	//��������
	//String(const String& str)
	//	:str_(new char[strlen(str.str_) + 1])
	//{
	//	strcpy(str_, str.str_);
	//}
		//�ִ�д��
	String(const String& str)//����
		:str_(nullptr)
	{		//������ʱ����
		String tmp(str.str_);//����ֱ�ӽ���ָ�룬���ܸı�ԭ�����ָ������
		swap(str_, tmp.str_);
	}


	//��������� =     &���õ�Ŀ�ģ���������

	//String& operator=(const String& str)
	//{
	//	if (this != &str)		//��ֹ���Լ���ֵ
	//	{
	//		delete[] str_;   //Ϊ�˷�ֹ�ռ䲻��
	//		str_ = new char[strlen(str.str_) + 1];
	//		strcpy(str_, str.str_);
	//	}
	//	return *this;
	//}
	//	// �ִ�д��
	String& operator=(String str)     //����Ӧ����һ����ʱ����
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