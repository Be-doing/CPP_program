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
		cout << "��֪������" << endl;
	}
	cout << "�쳣������" << endl;
}

void AutoPtrTest()
{
	//auto_ptr<Student> ptr(new Student);

	//auto_ptr<Student> ptr2 = ptr;//������ʵ�൱�ڿ�������

	Auto_Ptr<Student> ptr(new Student);
	ptr->Print();
}
void UniquePtrTest()
{
	//unique_ptr<Student> ptr(new Student);

	//unique_ptr<Student> ptr2(ptr);

	//unique_ptr<Student> ptr3 = ptr;

	UniquePtr<Student> ptr(new Student);
	ptr->Print();
}
int main()
{
	//AutoPtrTest();
	UniquePtrTest();
	system("pause");
	return 0;
}