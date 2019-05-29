#include<iostream>
#include<string>
#include<map>
using namespace std;
void test1()
{
	map<int, string> mp1;
	mp1.insert(make_pair(1, "陕科大"));
	mp1.insert(make_pair(2, "西安"));

	mp1.insert(make_pair(4, "中国"));
	mp1.insert(make_pair(3, "陕西"));
	for (const auto& e : mp1)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	/*****************************************************************/
	//是否存在这个键值
	cout << mp1.count(2) << endl;
	/*****************************************************************/
	//返回第一个大于或等于键值2的迭代器
	cout << mp1.lower_bound(2)->second << endl;
	//返回第一个大于键值2的迭代器
	cout << mp1.upper_bound(2)->second << endl;
	/*****************************************************************/
	string str("string");
	char c = str.at(3);
	cout << c << endl;
}
int main()
{
	test1();

	system("pause");
	return 0;
}