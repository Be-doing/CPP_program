#pragma once
#include<vector>
#include<iostream>
#include<bitset>
#include<string>
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
		int  bitarr[32] = { 0 };//����һ������洢λ��
		for (const auto& e : nums)
		{
			for (size_t i = 0; i < 32; ++i)
			{
				if (((e >> i) & 1) == 1)
				{
					bitarr[i] += 1;//���һ������ i λ�� 1 �ͽ��м�һ��������λһ�������ı���
				}
			}
		}
		for (size_t i = 0; i < 32; ++i)
		{	
			bitarr[i] %= 3;//����������ʣ�µþ��ǵ������ֵ����Ķ�����λ��
			
		}
		int temp = 0;
		for (int i = 31; i  >= 0; i--)
		{
			temp |= (bitarr[i]  << i);
		}
		return temp;
	}
	//����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ�
	//	�ҳ�ֻ����һ�ε�������Ԫ��
	vector<int> SingleNumber3(vector<int>& nums)
	{
		vector<int> res(2);
		int ret = 0;
		int pos = 0;
		for (auto& e : nums)
		{
			ret ^= e;	//��һ����������������������������
		}
		for (size_t i = 0; i < 32; ++i)
		{
			if (((ret >> i) & 1) == 1)//1110
			{
				pos = i;//�����һ��λ���� 1 ��λֵ
				break;
			}
		}
		for (auto& e : nums)
		{
			if (((e >> pos) & 1) == 1) //�ֿ�����������һ��Ϊ1 һ��Ϊ 0
			{
				res[0] ^= e;
			}
			else
			{
				res[1] ^= e;
			}
		}
		return res;
	}
	//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
	//	��������һ������Ϊ9������{ 1,2,3,2,2,2,5,4,2 }����������2�������г�����5�Σ�
	//	�������鳤�ȵ�һ�룬������2����������������0��
	void BubbleSort(vector<int> & num)
	{
		int length = num.size();
		int flag = 1;
		for (int i = 1; i < length; ++i)
		{
			for (int j = 0; j < length - i; ++j)
			{
				if (num[j] > num[j + 1])
				{
					swap(num[j], num[j + 1]);
					flag = 0;
				}
				if (flag == 1)
				{
					break;
				}
			}
		}
	}
	int FindNum(vector<int> & nums)
	{
		int len = nums.size();
		BubbleSort(nums);
		vector<int> tmp(len,0);
		int i = 0;
		int j = 0;
		for (i = 0; i < len; ++i)
		{
			if (nums[i] == nums[i + 1])
			{
				tmp[j] += 1;
			}
			else
			{
				++j;
			}
		}
		int mid = len / 2;
		for (int k = 0; k < j; ++k)
		{
			if (tmp[k] > mid)
			{
				int sum = 0;
				for (int s = 0; s < k; ++s)
				{
					sum += tmp[s];
				}
				return nums[sum];
			}
		}
		return 0;
	}
	//��������������� OJ
};