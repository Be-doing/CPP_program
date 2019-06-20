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
void ProblemTest()
{
	shared_ptr<ListNode> ptr1(new ListNode);
	shared_ptr<ListNode> ptr2(new ListNode);
	cout << ptr1.use_count() << endl;
	cout << ptr2.use_count() << endl;
	//ptr1->next = ptr2;
	//ptr2->prev = ptr1;
	cout << ptr1.use_count() << endl;
	cout << ptr2.use_count() << endl;
	ptr1 = ptr2;
}
int main()
{
	//AutoPtrTest();
	//UniquePtrTest();
	//SharePtrTest();
	ProblemTest();
	system("pause");
	return 0;
}