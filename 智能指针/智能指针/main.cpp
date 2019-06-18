#include"Smartptr.h"

void test1()
{
	try
	{
		Func();
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	catch (...)
	{
		cout << "不知名错误" << endl;
	}
	cout << "异常被处理" << endl;
}

void AutoPtrTest()
{
	//auto_ptr<Student> ptr(new Student);

	//auto_ptr<Student> ptr2 = ptr;//这里其实相当于拷贝构造

	Auto_Ptr<Student> ptr(new Student);
	Auto_Ptr<Student> ptr2(new Student);
	ptr2 = ptr;
	ptr2->Print();
}
void UniquePtrTest()
{
	//unique_ptr<Student> ptr(new Student);

	//unique_ptr<Student> ptr2(ptr);

	//unique_ptr<Student> ptr3 = ptr;

	UniquePtr<Student> ptr(new Student);
	ptr->Print();
}
void SharePtrTest()
{
	SharePtr<Student> ptr(new Student);
	SharePtr<Student> ptr1(ptr);
	SharePtr<Student> ptr2(ptr);

	cout << ptr.UseCount() << endl;
}
int main()
{
	//AutoPtrTest();
	//UniquePtrTest();
	SharePtrTest();
	system("pause");
	return 0;
}