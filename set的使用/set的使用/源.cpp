#include<iostream>
#include<set>
using namespace std;
void SetTest()
{
	int arr[] = { 1,5,4,9,6,3,4,7,1,8,5 };
	set<int> sarr;
	for (int i = 0; i < sizeof(arr) / 4; ++i)
	{
		sarr.insert(arr[i]);
	}
	for (const auto& e : sarr)
	{
		cout << e << endl;
	}
}
void MultisetTest()
{
	int arr[] = { 1,5,4,9,6,3,4,7,1,8,5 };
	multiset<int> sarr;
	for (int i = 0; i < sizeof(arr) / 4; ++i)
	{
		sarr.insert(arr[i]);
	}
	for (const auto& e : sarr)
	{
		cout << e << endl;
	}
}
int main()
{
	cout << "arr[]:  ";
	int arr[] = { 1,5,4,9,6,3,4,7,1,8,5 };
	for (int i = 0; i < sizeof(arr) / 4; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Set" << endl;
	SetTest();
	cout << "MultisetTest" << endl;
	MultisetTest();
	system("pause");
	return 0;
}