#include"MyVector.h"
#include<vector>
#include<iostream>
using namespace std;

void TestMyVector1()
{
	MyVector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	PrintVector(v);

	v.PopBack();
	v.PopBack();
	v.PopBack();
	PrintVector(v);
}
void TestMyVector2()
{
	MyVector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	PrintVector(v);
	
	v.Erase(v.begin() + 1);
	v.PopBack();
	PrintVector(v);
}
void TestMyVector3()
{
	MyVector<int> v;
	PrintVectorSize(v);
	v.PushBack(1);
	PrintVectorSize(v);
	v.PushBack(2);
	v.PushBack(3);
	PrintVectorSize(v);

	v.Resize(8);
	PrintVectorSize(v);
}
int main()
{
	//TestMyVector1();
	//TestMyVector2();
	TestMyVector3();
	system("pause");
	return 0;
}