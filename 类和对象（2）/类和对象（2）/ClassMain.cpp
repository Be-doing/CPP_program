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
	test.display2();//����const�����ܵ���const���εĳ�Ա������
	
	//const Date test3(2019,03,12);
	//test3.display();// const�����ܵ���const��Ա������
	//test3.display2();
	//String _str("hello c++!");;
	//String _str2;
	//_str2 = _str;
	//_str.display();
	//_str2.display();
	system("pause");
	return 0;
}