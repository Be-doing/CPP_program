#include"Polymorphism.h"

void test1()
{
	A* pa = new B(1);
	pa->func();
	pa->func1();

	B b;
	pa = &b;
	pa->func();
	pa->func1();

	//A a;
	A& a = b;
	
	a.func();
	a.func1();

	A x = b;
	x.func();
	x.func1();

	b.func1();
}
void test2()
{
	A a;
	B b;
	Poly(a);
	Poly(b);
}
void test3()
{
	//Person p;

	Student s;

}
void test4()
{
	Car car;
	BWM w;
	cout << "Car��Ĵ�С�ǣ�" << sizeof(Car) << "���ֽ�" << endl;
}
typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	// ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		cout << " ��" << i << "���麯����ַ :" << vTable[i];
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
void test5()
{
	Base1 b1(1);
	Base2 b2(2);
	Child c;
	// ˼·��ȡ��c�����ͷ4bytes����������ָ�룬ǰ������˵���麯��������һ�����麯��ָ���
	//ָ�����飬���������������һ��nullptr
	// 1.��ȡb�ĵ�ַ��ǿת��һ��int*��ָ��
	// 2.�ٽ�����ȡֵ����ȡ����c����ͷ4bytes��ֵ�����ֵ����ָ������ָ��
	// 3.��ǿת��VFPTR*����Ϊ������һ����VFPTR����(�麯��ָ������)�����顣
	// 4.���ָ�봫�ݸ�PrintVTable���д�ӡ���
	VFPTR* vTableb = (VFPTR*)(*(int*)&c);
	PrintVTable(vTableb);
	VFPTR* vTabled = (VFPTR*)(*(int*)((char*)&c+ sizeof(b1)));
	PrintVTable(vTabled);

}
int main()
{
	test5();
	system("pause");
	return 0;
}

