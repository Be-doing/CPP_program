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
	cout << "Car类的大小是：" << sizeof(Car) << "个字节" << endl;
}
typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		cout << " 第" << i << "个虚函数地址 :" << vTable[i];
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
	// 思路：取出c对象的头4bytes，就是虚表的指针，前面我们说了虚函数表本质是一个存虚函数指针的
	//指针数组，这个数组最后面放了一个nullptr
	// 1.先取b的地址，强转成一个int*的指针
	// 2.再解引用取值，就取到了c对象头4bytes的值，这个值就是指向虚表的指针
	// 3.再强转成VFPTR*，因为虚表就是一个存VFPTR类型(虚函数指针类型)的数组。
	// 4.虚表指针传递给PrintVTable进行打印虚表
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

