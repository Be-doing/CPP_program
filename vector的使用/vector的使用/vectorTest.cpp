#include<vector>
#include<iostream>

using namespace std;
#include"vector��ʹ��.h"
template <class T1>
void Print(vector<T1>& v)
{
	for (auto& e : v)
	{
		cout << e << "\t";
	}
	cout << endl;
}

//���캯����ʹ��
void CreateTest()
{
	std::vector<int> v1;
	std::vector<int> v2(10, 10);
	std::vector<int> v3(v2);
	std::vector<int> v4(v2.begin(), v2.end() - 5);

	Print(v1);
	Print(v2);
	Print(v3);
	Print(v4);
}
string letterMap[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
void combineStr(const string& digits, size_t index, const string& str, vector<string>& strs)
{
	
	if (index == digits.size())//�ߵ����һ�㣬������ɵ��ַ���
	{
		strs.push_back(str);
		return;
	}
	// ��ȡ���ֶ�Ӧ���ַ�����
	string letters = letterMap[digits[index] - '0'];
	for (size_t i = 0; i < letters.size(); ++i)
	{
		combineStr(digits, index + 1, str + letters[i], strs);
	}
}
std::vector<string> letterCombinations(string digits) {
	std::vector<string> strs;

	if (digits.empty())
		return strs;

	size_t index = 0;
	string str;
	// �ݹ�����������ַ���
	combineStr(digits, index, str, strs);

	return strs;
}

int main()
{
	//CreateTest();
	//std::vector<string> s;
	//s = letterCombinations("234");
	//Print(s);
	Solution s;
	vector<int> nums = { 1,3,5,9,4,6,3,4,1,5,9 };
	vector<int> nums2 = { 1,3,5,9,4,6,3,4,1,5,9,1,3,5,9,4,6 };
	vector<int> nums3 = { 1,3,5,9,4,1,3,5,9,4,6,8 };
	int res = s.SingleNumber(nums);
	int res2 = s.SingleNumber2(nums2);

	vector<int> res3;
	res3 = s.SingleNumber3(nums3);
	cout << res << endl;
	cout << res << endl;
	cout << res3[0] << "\t" << res3[1] << endl;
	system("pause");
	return 0;
}