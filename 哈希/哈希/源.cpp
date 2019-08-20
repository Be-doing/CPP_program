//#include<vector>
//using namespace std;
//
//
//class BitMap
//{
//public:
//	BitMap(size_t bitCount)
//		: _bit((bitCount >> 5) + 1)
//		, _bitCount(bitCount)
//	{}
//	// 置1
//	void Set(size_t which)
//
//	{
//		if (which > _bitCount)
//			return;
//		size_t index = (which >> 5);
//		size_t pos = which % 32;
//		_bit[index] |= (1 << pos);
//	}
//	// 置0
//	void ReSet(size_t which)
//	{
//		if (which > _bitCount)
//			return;
//		size_t index = (which >> 5);
//		size_t pos = which % 32;
//		_bit[index] &= ~(1 << pos);
//	}
//	// 检测位图中which是否为1
//	bool Test(size_t which)
//	{
//		if (which > _bitCount)
//			return false;
//		size_t index = (which >> 5);
//		size_t pos = which % 32;
//		return _bit[index] & (1 << pos);
//	}
//	// 获取位图中比特位的总个数
//	size_t Size()const
//	{
//		return _bitCount;
//	}
//	// 位图中比特为1的个数
//	size_t Count()const
//	{
//		const char* pCount = "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4";
//		size_t size = _bit.size();
//		size_t count = 0;
//		for (size_t i = 0; i < size; ++i)
//		{
//			int value = _bit[i];
//			int j = 0;
//			while (j < sizeof(_bit[0]))
//			{
//				char c = value;
//				count += pCount[c & 0x0f];
//				c >>= 4;
//				count += pCount[c & 0x0f];
//				++j;
//				value >>= 8;
//			}
//		}
//		return count;
//	}
//private:
//	vector<int> _bit;
//	size_t _bitCount;
//};

#include"HASH.h"
using namespace closedhash;



void Test()
{
	HashTable<int, int> tab;
	tab.Insert(make_pair(0, 0));
	tab.Insert(make_pair(1, 1));
	tab.Insert(make_pair(2, 2));
	tab.Insert(make_pair(3, 3));
	tab.Insert(make_pair(4, 4));
}


int main()
{
	Test();
	return 0;
}



