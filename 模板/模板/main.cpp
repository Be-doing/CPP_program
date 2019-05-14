#include"Ä£°å.h"
#include<string>
int main()
{

	//MyVector<int> t(10);
	//t.PushBack(1);
	//t.PushBack(2);
	//t.PushBack(3);
	//t.PushBack(4);
	//t.PushBack(5);
	//t.PushBack(6);

	//Print(t);
	//int a = 3;
	//int b = 4;
	//cout << Sum(a, b) << endl;

	//double c = 3.14;
	//double d = 3.52;

	//cout << Sum(c, d) << endl;

	//cout << Sum<int>(a,d) << endl;

	//string str1("string1");
	//string str2;
	char str1[] = "string";
	char str2[7];
	Copy(str2, str1, strlen(str1) + 1);
	for (auto&e : str2)
	{
		cout << e << endl;
	}
	string str3[] = { "string","string","string" };
	string str4[3];
	Copy(str4, str3, 3);

	for (auto&e : str4)
	{
		cout << e << endl;
	}
	system("pause");
	return 0;
}