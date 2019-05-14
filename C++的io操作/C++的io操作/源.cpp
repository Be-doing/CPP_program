#include<iostream>
#include<fstream>
using namespace std;

//cin和cout/Cerro/clog本质是一个对象，每一个对象都进行了重载
//每个类型调用都调用相应的函数

void Practice()
{
	char str[1024];
	ofstream fout("BinaryCin.txt");
	fout.write("abcd", 5);
	ifstream fin("BinaryCin.txt");
	fin.read(str, 1024);
	cout << str << endl;
}
void Practice2()
{
	ofstream out("ChCin.txt");
	out << "字符流的写入";
	out << "字符流的写入";
	ifstream in("ChCin.txt");
	char str[1024];
	in >> str;
	cout << str << endl;
}
int main()
{
	//int tmp = 15;
	//ofstream fout;

	//fout.open("mainBin.txt");
	//fout.write((char*)&tmp, sizeof(15));
	//cout << endl;
	//fout << &tmp;
	Practice2();
	system("pause");
	return 0;
}