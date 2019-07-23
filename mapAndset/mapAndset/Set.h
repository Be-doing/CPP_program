#pragma once
#pragma once
#include"RBTree.h"
#include<map>
template<class V>
class Set
{

	struct KeyOfVal
	{
		 const V& operator()(const V& data)
		{
			return data;
		}
	};
	typedef typename BRTree<KeyOfVal,  V>::iterator iterator;

public:
	bool Insert(const V& data)
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
	BRTree<KeyOfVal,  V> bt_;

};