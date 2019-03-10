#include<iostream>
using namespace std;
#include"class_object.h"
void MyClass::set_data(int _obj1, int _obj2)
{
	obj1_ = _obj1;
	this->obj2_ = _obj1;
}
void MyClass::My_Class(int _a)
{
	cout << _a << endl;
}
int main()
{
	
	system("pause");
	return 0;
}