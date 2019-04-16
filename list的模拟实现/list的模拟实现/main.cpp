#include"List.h"
template <class T>
void Print(List<T>& mylist)
{
	auto res = mylist.begin();
	while(res != mylist.end())
	{
		cout << *res << "   ";
		++res;
	}
	cout << endl;
}
void ListTest1()
{
	List<int>  lst;
	lst.PushBack(1);
	lst.PushBack(2);
	lst.PushBack(3);
	lst.PushBack(4);

	cout << "β�壺";
	Print(lst);

	lst.PopBack();
	lst.PopBack();
	lst.PopBack();
	cout << "βɾ��";
	Print(lst);

	cout << lst.Size() << endl;
	lst.Resize(10);
	cout << lst.Size() << endl;
	Print(lst);

	lst.Resize(2);
	cout << lst.Size() << endl;
	Print(lst);
}
void ListTest2()
{
	List<int>  lst;
	lst.PushFront(4);
	lst.PushFront(3);
	lst.PushFront(2);
	lst.PushFront(1);
	cout << "ͷ�壺";
	Print(lst);

	lst.PopFront();
	lst.PopFront();
	lst.PopFront();
	cout << "ͷɾ��";
	Print(lst);
}

void ListTest3()
{
	List<int>  lst;
	lst.PushFront(4);
	lst.PushFront(3);
	lst.PushFront(2);
	lst.PushFront(1);
	cout << "ͷ�壺";
	Print(lst);

	lst.Insert(lst.begin(), 0);
	cout << "���ܲ壺";

	Print(lst);

	lst.Erase(lst.begin());
	cout << "����ɾ��";

	Print(lst);
}
int main()
{
	ListTest1();
	//ListTest2();
	//ListTest3();
	system("pause");
	return 0;
}