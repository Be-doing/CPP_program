#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

//cin��cout/Cerro/clog������һ������ÿһ�����󶼽���������
//ÿ�����͵��ö�������Ӧ�ĺ���

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
	out << "�ַ�����д��" << endl;
	out << "�ַ�����д��" << endl;

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