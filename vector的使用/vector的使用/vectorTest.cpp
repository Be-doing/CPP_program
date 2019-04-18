#include<vector>
#include<iostream>

using namespace std;
#include"vector的使用.h"
template <class T1>
void Print(vector<T1>& v)
{
	for (auto& e : v)
	{
		cout << e << "  ";
	}
	cout << endl;
}
//构造函数的使用
void CreateTest()
{
	vector<int> v1;
	vector<int> v2(10, 10);
	vector<int> v3(v2);
	vector<int> v4(v2.begin(), v2.end() - 5);

	Print(v1);
	Print(v2);
	Print(v3);
	Print(v4);
}
void VectorCapacity()
{
	vector<int> v1(10, 10);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	cout << v1.empty() << endl;
	
	v1.resize(12, 11);
	cout << v1.size() << endl;
	v1.reserve(15);
	cout << v1.capacity() << endl;
}
void VectorOperator()
{
	vector<int> v1;
	//尾插
	cout << "push_back:";
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	Print(v1);
	//尾删
	cout << "pop_back:";
	v1.pop_back();
	v1.pop_back();
	v1.pop_back();
	Print(v1);
	//在结尾的地方插入
	cout << "insert:";
	v1.insert(v1.end(), 2);
	v1.insert(v1.end(), 3);
	v1.insert(v1.end(), 4);
	Print(v1);
	cout << "erase:";
	//删除最后一个数

	v1.erase(v1.end() - 1);
	Print(v1);
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
	//VectorCapacity();
	VectorOperator();
	//std::vector<string> s;
	//s = letterCombinations("234");
	//Print(s);
	//Solution s;
	//vector<int> nums = { 1,3,5,9,4,6,3,4,1,5,9 };
	//vector<int> nums2 = { 1,3,5,9,4,6,3,4,1,5,9,1,3,5,9,4,6 };
	//vector<int> nums3 = { 1,3,5,9,4,1,3,5,9,4,6,8 };
	//int res = s.SingleNumber(nums);
	//int res2 = s.SingleNumber2(nums2);

	//vector<int> res3;
	//res3 = s.SingleNumber3(nums3);
	//cout << res << endl;
	//cout << res << endl;
	//cout << res3[0] << "\t" << res3[1] << endl;
	system("pause");
	return 0;
}