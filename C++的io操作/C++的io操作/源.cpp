#include<iostream>
#include<fstream>
using namespace std;

//cin��cout/Cerro/clog������һ������ÿһ�����󶼽���������
//ÿ�����͵��ö�������Ӧ�ĺ���

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
	out << "�ַ�����д��";
	out << "�ַ�����д��";
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