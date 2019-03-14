#include"ClassDate.h"
#include<iostream>
using namespace std;
int main()
{
	Date d1(2018,5,5);
	Date d2(2016,2,1);
	//int num = d1 - d2;

	//cout << num << endl;

	d1+= 60;
	//++d2;
	d1.display();
	//d2.display();
	//bool res = d1 != d2;

	//cout << res << endl;

	system("pause");
	return 0;
}