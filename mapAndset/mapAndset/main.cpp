#include "Map.h"
#include "Set.h"
void MapTest()
{
	Map<int, int> m;
	m.Insert(make_pair(1, 9));
	m.Insert(make_pair(7, 4));
	m.Insert(make_pair(2, 3));
	m.Insert(make_pair(6, 6));
	m.Insert(make_pair(3, 1));

	for (const auto& e : m)
	{
		cout << e.first << "--" << e.second << endl;
	}
}

void SetTest()
{
	Set<int> s;
	s.Insert(9);
	s.Insert(3);
	s.Insert(2);
	s.Insert(6);
	s.Insert(8);

	for (const auto& e : s)
		cout << e << endl;

}
int main()
{
	//MapTest();
	SetTest();
	system("pause");
	return 0;
}