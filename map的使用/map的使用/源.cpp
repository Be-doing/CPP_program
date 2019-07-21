#include<iostream>
#include<string>
#include<map>
using namespace std;
void test1()
{
	map<int, string> mp1;
	mp1.insert(make_pair(2, "大学"));
	mp1.insert(make_pair(4, "中国"));
	mp1.insert(make_pair(3, "陕西"));
	for (const auto& e : mp1)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	mp1[5] = "中学";
	mp1[4] = "China";
	cout << "===================" << endl;
	for (const auto& e : mp1)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	// C++11 的类表初始化
	map<string, string> m2{ { "one", "1" },
	{ "two", "2" }, 
	{ "three", "3" }, 
	{ "four", "4" },
	{ "five", "5" } 
	};
	cout << "===================" << endl;
	for (const auto& e : m2)
	{
		cout << e.first << "--->" << e.second << endl;
	}
}
void test2()
{
	multimap<int, string> mulp;
	mulp.insert(make_pair(4, "四"));
	mulp.insert(make_pair(4, "4"));
	mulp.insert(make_pair(4, "four"));
	for (const auto& e : mulp)
	{
		cout << e.first << "--->" << e.second << endl;
	}

}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}