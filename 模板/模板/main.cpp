#include"Ä£°å.h"

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
	int a = 3;
	int b = 4;
	cout << Sum(a, b) << endl;

	double c = 3.14;
	double d = 3.52;

	cout << Sum(c, d) << endl;

	cout << Sum<int>(a,d) << endl;
	system("pause");
	return 0;
}