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

	cout << "尾插：";
	Print(lst);

	lst.PopBack();
	lst.PopBack();
	lst.PopBack();
	cout << "尾删：";
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
	cout << "头插：";
	Print(lst);

	lst.PopFront();
	lst.PopFront();
	lst.PopFront();
	cout << "头删：";
	Print(lst);
}

void ListTest3()
{
	List<int>  lst;
	lst.PushFront(4);
	lst.PushFront(3);
	lst.PushFront(2);
	lst.PushFront(1);
	cout << "头插：";
	Print(lst);

	lst.Insert(lst.begin(), 0);
	cout << "万能插：";

	Print(lst);

	lst.Erase(lst.begin());
	cout << "万能删：";

	Print(lst);
}
void ListTest4()
{
	List<int>  lst(4, 6);
	cout << "List(size_t n, const T& val = T())：";
	Print(lst);

	List<int> lst2(lst);
	cout << "List(const List& list)：";
	Print(lst2);

	List<int> lst3(lst2.begin(), lst2.end());
	cout << "List(iterator firdt, iterator end)：";
	Print(lst3);
}
int main()
{
	//ListTest1();
	//ListTest2();
	//ListTest3();
	ListTest4();
	system("pause");
	return 0;
}