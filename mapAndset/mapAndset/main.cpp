#include "Map.h"

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
int main()
{
	MapTest();
	system("pause");
	return 0;
}