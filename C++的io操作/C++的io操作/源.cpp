#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//cin��cout/Cerro/clog������һ������ÿһ�����󶼽���������
//ÿ�����͵��ö�������Ӧ�ĺ���

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
	out << "�ַ�����д��" << endl;
	out << "�ַ�����д��" << endl;
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