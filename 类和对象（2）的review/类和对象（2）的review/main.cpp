#include"ClassDate.h"
#include<iostream>
using namespace std;
int main()
{
	Date d1(2016,2,29);
	Date d2(2016,2,1);
	d2++;
	++d1;
	//int temp = d1 - d2;
	//cout << temp << endl;
	d1.display();

	system("pause");
	return 0;
}