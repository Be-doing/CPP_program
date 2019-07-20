#pragma once
#include"RBTree.h"
template<class K, class V>
class Map
{

	struct KeyOfVal
	{
		const K& operator()(const pair<K, V>& data)
		{
			return data.first;
		}
	};
	typedef typename BRTree<KeyOfVal, pair<K, V>>::iterator iterator;
	
public:
	bool Insert(const pair<K, V>& data)
	{
		return bt_.Insert(data);
	}

	iterator begin()
	{
		return bt_.begin();
	}
	iterator end()
	{
		return bt_.end();
	}
private:
	BRTree<KeyOfVal, pair<K, V>> bt_;
	
};