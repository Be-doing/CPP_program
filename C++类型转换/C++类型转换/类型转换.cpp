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
	//缺陷： 转换的可视性比较差，所有的转换形式都是以一种相同形式书写，难以跟踪错误的转换
}
class A
{};
class B : public A
{};
void StaticCast()
{
	//static_cast用于非多态类型的转换（静态转换），编译器隐式执行的任何类型转换都可用static_cast，但它
	//不能用于两个不相关的类型进行转换
	//类似强制转换，但是比强制转换更加安全
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
	//reinterpret_cast操作符通常为操作数的位模式提供较低层次的重新解释，用于将一种类型转换为另一种不
	//同的类型
		//
	// reinterpret_cast可以编译器以FUNC的定义方式去看待DoSomething函数
	// 所以非常的BUG，下面转换函数指针的代码是不可移植的，所以不建议这样用
	// C++不保证所有的函数指针都被一样的使用，所以这样用有时会产生不确定的结果
	//
	func f = reinterpret_cast<func>(diff);
	f();
}

void ConstCast()
{
	//const_cast最常用的用途就是删除变量的const属性，方便赋值
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
//dynamic_cast用于将一个父类对象的指针转换为子类对象的指针或引用(动态转换)
//向上转型：子类对象指针->父类指针 / 引用(不需要转换，赋值兼容规则) 向下转型：父类对象指针->子类指针 /
//引用(用dynamic_cast转型是安全的)
//注意： 1. dynamic_cast只能用于含有虚函数的类 
//			2. dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回0


int main()
{
	ReinterpretCast();
	system("pause");
	return 0;
}