#include"MyString.h"
#include"newString.h"
int main()
{
	newString s1;
	s1.PushBack('a');
	s1.PushBack('b');
	s1.PushBack('c');
	s1.PushBack('d');
	s1.PushBack('e');
	s1.PushBack('f');
	s1.PushBack('g');
	s1.PushBack('h');
	s1.Insert(3, "hello");

	size_t res = s1.Find("cde");
	system("pause");
	return 0;
}