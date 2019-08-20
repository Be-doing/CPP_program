#pragma once
#include"RBTree.h"
#include<map>
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
	//与源码不同
	pair<iterator,bool> Insert(const pair<K, V>& data)
	{
		return bt_.Insert(data);
	}
	//map是由[]的操作
	V& operator[](const K& key)
	{
		pair<iterator,bool> ret = bt_.Insert(make_pair(key,v()));
		return ret.first->second;
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
