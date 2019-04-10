#pragma once
#include<vector>
#include<iostream>
#include<bitset>
using namespace std;
class Solution
{
public:
	//ֻ����һ�ε�����
	int SingleNumber(vector<int>& nums)//���������ǳɶԴ��ڣ���һ����ֻ��һ��
	{
		//0 ^ x == x
		//x ^ x == 0
		//�����˳���޹�
		int tmp = 0;
		for (const auto& e : nums)
		{
			tmp ^= e;
		}
		return tmp;
	}
	int SingleNumber2(vector<int>& nums)//���������ǳ��������ڣ���һ����ֻ��һ��
	{
		char  bitarr[32] = { 0 };
		for (const auto& e : nums)
		{
			for (size_t i = 0; i < 32; i++)
			{
				if ((e >> i) & 1 == 1)
				{
					bitarr[i] += 1;
				}
			}
		}
		for (size_t i = 0; i < 32; ++i)
		{
			if (bitarr[i] >=3)
			{
				bitarr[i] %= 3;
			}
		}
		int temp = 0;
		for (size_t i = 31; i  >= 0; i--)
		{
			temp |= ((bitarr[i] - '0') << i);
		}
		return temp;
	}
	//����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ�
	//	�ҳ�ֻ����һ�ε�������Ԫ��
	int* SingleNumber3(vector<int>& nums)
	{
		int res[2] = { 0 };
		int ret = 0;
		int pos = 0;
		for (auto& e : nums)
		{
			ret ^= e;	
		}
		for (size_t i = 0; i < 32; ++i)
		{
			if (((ret >> i) & 1) == 1)
			{
				pos = i;
				break;
			}
		}
		for (auto& e : nums)
		{
			if (((e >> pos) & 1) == 1)
			{
				res[0] ^= e;
			}
			else
			{
				res[1] ^= e;
			}
		}
	}
	//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
	//	��������һ������Ϊ9������{ 1,2,3,2,2,2,5,4,2 }����������2�������г�����5�Σ�
	//	�������鳤�ȵ�һ�룬������2����������������0��
	int FindNum(vector<int> & nums)
	{
		int len = nums.size();
		int res[2] = { 0 };
		int ret = 0;
		int pos = 0;
		for (auto& e : nums)
		{
			ret ^= e;
		}
		for (size_t i = 0; i < 32; ++i)
		{
			if (((ret >> i) & 1) == 1)
			{
				pos = i;
				break;
			}
		}
		for (auto& e : nums)
		{
			if (((e >> pos) & 1) == 1)
			{
				res[0] ^= e;
			}
			else
			{
				res[1] ^= e;
			}


	}
	//��������������� OJ
};