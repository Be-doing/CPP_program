#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

//cin和cout/Cerro/clog本质是一个对象，每一个对象都进行了重载
//每个类型调用都调用相应的函数

void Practice1()
{
	const char bw[] = "abcde";
	ofstream fout("BinaryCin.txt");
	fout.write(bw,50);
	fout.close();

	char br[50];
	ifstream fin("BinaryCin.txt");
	fin.read(br, sizeof(br));
	cout << br << endl;
}

void Practice2()
{
	ofstream out("ChCin.txt");
	out << "字符流的写入" << endl;
	out << "字符流的写入" << endl;

	ifstream in("ChCin.txt");
	string str;
	in >> str;
	cout << str << endl;
}

int main()
{
	Practice2();
	//double num = 3.1415926;
	//cout << setprecision(8) << num << endl;
	system("pause");
	return 0;
}