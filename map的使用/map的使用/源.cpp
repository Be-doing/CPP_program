#include<iostream>
#include<string>
#include<map>
using namespace std;
void test1()
{
	map<int, string> mp1;
	mp1.insert(make_pair(1, "�¿ƴ�"));
	mp1.insert(make_pair(2, "����"));

	mp1.insert(make_pair(4, "�й�"));
	mp1.insert(make_pair(3, "����"));
	for (const auto& e : mp1)
	{
		cout << e.first << "--->" << e.second << endl;
	}
	/*****************************************************************/
	//�Ƿ���������ֵ
	cout << mp1.count(2) << endl;
	/*****************************************************************/
	//���ص�һ�����ڻ���ڼ�ֵ2�ĵ�����
	cout << mp1.lower_bound(2)->second << endl;
	//���ص�һ�����ڼ�ֵ2�ĵ�����
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