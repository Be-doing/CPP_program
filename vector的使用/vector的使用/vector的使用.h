#pragma once
#include<vector>
#include<iostream>
#include<bitset>
#include<string>
using namespace std;
class Solution
{
public:
	//只出现一次的数字
	int SingleNumber(vector<int>& nums)//其他数都是成对存在，有一个数只有一个
	{
		//0 ^ x == x
		//x ^ x == 0
		//异或与顺序无关
		int tmp = 0;
		for (const auto& e : nums)
		{
			tmp ^= e;
		}
		return tmp;
	}
	int SingleNumber2(vector<int>& nums)//其他数都是成三个存在，有一个数只有一个
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
	//给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。
	//	找出只出现一次的那两个元素
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
		return res;
	}
	//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
	//	例如输入一个长度为9的数组{ 1,2,3,2,2,2,5,4,2 }。由于数字2在数组中出现了5次，
	//	超过数组长度的一半，因此输出2。如果不存在则输出0。
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
		vector<int> tmp;
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
	//连续子数组的最大和 OJ
};