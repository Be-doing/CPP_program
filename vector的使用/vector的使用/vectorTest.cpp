#include<vector>
#include<iostream>

using namespace std;
#include"vector的使用.h"
template <class T1>
void Print(vector<T1>& v)
{
	for (auto& e : v)
	{
		cout << e << "\t";
	}
	cout << endl;
}

//构造函数的使用
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
	
	if (index == digits.size())//走到最后一层，保存组成的字符串
	{
		strs.push_back(str);
		return;
	}
	// 获取数字对应的字符数组
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
	// 递归子问题组合字符串
	combineStr(digits, index, str, strs);

	return strs;
}

int main()
{
	//CreateTest();
	std::vector<string> s;
	s = letterCombinations("234");

	Print(s);
	
	system("pause");
	return 0;
}