#include<iostream>

using namespace std;


void TestC()
{
	int k_int = 10;
	double k_double = 20.0;
	k_int = k_double;
	int c_max = 129;
	char c_nor = 111;
	c_nor = c_max;
	double k_double2 = k_int;


	cout << k_int << endl;
	cout << k_double2 << endl;
	cout << c_nor << endl;
	//ȱ�ݣ� ת���Ŀ����ԱȽϲ���е�ת����ʽ������һ����ͬ��ʽ��д�����Ը��ٴ����ת��
}
class A
{};
class B : public A
{};
void StaticCast()
{
	//static_cast���ڷǶ�̬���͵�ת������̬ת��������������ʽִ�е��κ�����ת��������static_cast������
	//����������������ص����ͽ���ת��
	//����ǿ��ת�������Ǳ�ǿ��ת�����Ӱ�ȫ
	//double a = 10.0;
	//double c = 10.0;
	//c = static_cast<int>(c);
	//int b = static_cast<int>(a);
	A a;
	B b;

	a = static_cast<A>(b);

	//cout << a << endl;
	//cout << b << endl;
	//cout << c << endl;
}
typedef void(*func)();
int diff(int i)
{
	cout << "different func"  << i << endl;
	return 0;
}

void ReinterpretCast()
{
	//reinterpret_cast������ͨ��Ϊ��������λģʽ�ṩ�ϵͲ�ε����½��ͣ����ڽ�һ������ת��Ϊ��һ�ֲ�
	//ͬ������
		//
	// reinterpret_cast���Ա�������FUNC�Ķ��巽ʽȥ����DoSomething����
	// ���Էǳ���BUG������ת������ָ��Ĵ����ǲ�����ֲ�ģ����Բ�����������
	// C++����֤���еĺ���ָ�붼��һ����ʹ�ã�������������ʱ�������ȷ���Ľ��
	//
	func f = reinterpret_cast<func>(diff);
	f();
}

void ConstCast()
{
	//const_cast��õ���;����ɾ��������const���ԣ����㸳ֵ
	const int a = 10;
	//a = 20;
	int* p = const_cast<int*>(&a);
	*p = 20;

	int m = const_cast<int&>(a);
	int num = 10;
	const int* ptr = &num;
	
	ptr = const_cast<int*>(ptr);
	//*ptr = 20;
	ptr = &a;


	int* const ptrs = &num;

	//ptrs = &a;
	
}
//dynamic_cast���ڽ�һ����������ָ��ת��Ϊ��������ָ�������(��̬ת��)
//����ת�ͣ��������ָ��->����ָ�� / ����(����Ҫת������ֵ���ݹ���) ����ת�ͣ��������ָ��->����ָ�� /
//����(��dynamic_castת���ǰ�ȫ��)
//ע�⣺ 1. dynamic_castֻ�����ں����麯������ 
//			2. dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�0


int main()
{
	ReinterpretCast();
	system("pause");
	return 0;
}