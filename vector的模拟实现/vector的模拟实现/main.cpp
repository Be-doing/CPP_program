#include"MyVector.h"
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

int main()
{
	TestMyVector1();
	system("pause");
	return 0;
}