#pragma once
//////////////////////////////////////////////////////////
//·â×°£©
/////////////////////////////////////////////////////////
#include"HASH.h"

using namespace openhash;

template<class K, class V>
class UnorderedMap
{
	typedef typename HashTable<K, pair<K, V>, KeyOfVal>::iterator iterator;

public:
	bool Insert(const pair<K,V>& data)
	{
		return tab.Insert(data);
	}
private:
	struct KeyOfVal
	{
		const K& operator()(const pair<K, V>& data)
			return data.first;
	};
private:
	HashTable<K, pair<K, V>, KeyOfVal> tab;
};