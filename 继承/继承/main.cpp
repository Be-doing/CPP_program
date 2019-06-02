#include"Inheritance.h"

void test1()
{
	Student stu1;
}

void test2()
{
	Person p1;
	Person* pp;

	Student stu1;

	p1 = stu1;//对象赋值
	p1.setName("李四");

	pp = &stu1;//指针赋值
	pp->setName("王五");

	Person& rp = stu1;//引用赋值
	rp.setName("赵六");

	
	Student* pstu = (Student*)pp;//强制转换
	pp->setName("周七");
}

void test3()
{
	Child c1;
}

void test4()
{
	Father f1("钱一",18);
	Father f2 = f1;

	Child c;

	Child c2 = c;
}
void test5()
{
	A a;
	B b;
	C c;
}

void test6()
{
	Self s;
}

int main()
{
	test6();
	system("pause");
	return 0;
}