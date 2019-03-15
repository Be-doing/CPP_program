#include"ClassTest.h"
#include<iostream>
using namespace std; 
int main()
{

	Date test2;

	//test2 = test;
	////Date test2(test);

	Date test(2019, 03, 11);
	test.display();
	test.display2();//但非const对象能调是const修饰的成员函数。
	
	//const Date test3(2019,03,12);
	//test3.display();// const对象不能调非const成员函数，
	//test3.display2();
	//String _str("hello c++!");;
	//String _str2;
	//_str2 = _str;
	//_str.display();
	//_str2.display();
	system("pause");
	return 0;
}