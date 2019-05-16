#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//cin和cout/Cerro/clog本质是一个对象，每一个对象都进行了重载
//每个类型调用都调用相应的函数

void Practice1()
{
	char str[1024];
	ofstream fout("BinaryCin.txt");
	fout.write("abcd", 5);
	ifstream fin("BinaryCin.txt");
	fin.read(str, 5);
	cout << str << endl;
}
void Practice2()
{
	ofstream out("ChCin.txt");
	out << "字符流的写入" << endl;
	out << "字符流的写入" << endl;
	ifstream in("ChCin.txt");
	//char buff[100];
	//while (!in.eof())
	//{
	//	in.getline(buff,100);
	//	cout << buff << endl;
	//}

	string str;
	in >> str;
	cout << str;
}
int main()
{
	Practice2();
	system("pause");
	return 0;
}