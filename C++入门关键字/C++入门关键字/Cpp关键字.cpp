#include<iostream>
//�����ռ�
namespace T 
{
	int _a;
	char _b;
}
using namespace T;
using T::_a;
using namespace std;
//�������
void cout_cin(int _num1, int _num2)
{
	cin >> _num1 >> _num2;
	cout << _num1 << endl << _num2 << endl;
}

//ȱʡ����
int sum(int _n1 = 10, int _n2 = 20);
int sum(int _n1 , int _n2 )
{
	return _n1 + _n2;
}
//��������

//extern "C" int fun(int _n1, int _n2)
//{
//	return _n1 + _n2;
//}
int fun2(int _n1, char _n2)
{
	return _n1 + _n2;
}
//����
int& retu(int& _a)
{
	_a = 10;
	return _a;
}

//auto
void my_auto()
{
	int _a = 10;
	auto _b = _a;
	cout << typeid(_b).name() << endl;
}
//���ڷ�Χ��forѭ��
void my_for()
{
	int arr[] = { 1,2,3,8,9,6,4 };
	for (auto& _a : arr)
	{
		cout << _a << "\t";
	}
	cout << endl;
}

int main()
{
	//fun(1, 3);
	fun2(2,3);
	system("pause");
	return 0;
}