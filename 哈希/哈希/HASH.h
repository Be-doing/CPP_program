#pragma once
#include<iostream>
#include<vector>
using namespace std;




/////////////////////////////////////////////////////////////////
//闭散列
////////////////////////////////////////////////////////////////
namespace closedhash
{
	enum STATUS
	{
		EMPTY,
		EXIST,
		DELETE
	};
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> kv_;
		STATUS status_ = EMPTY;
	};

	template<class K, class V>
	class HashTable
	{
		typedef HashNode<K, V> Node;
		typedef Node* pNode;

	public:
		HashTable(size_t N = 10)
		{
			ht_.resize(N);
			size_ = 0;
		}

		//插入
		bool Insert(const pair<K, V>& kv)
		{
			//首先需要检查容量
				//设置负载因子，降低哈希冲突概率
			CheckCapacity();

			size_t index = kv.first % ht_.size();
			while (ht_[index].status_ == EXIST)
			{
				if (ht_[index].kv_.first == kv.first)
					return false;
				++index;
				if (index == ht_.size())
					index = 0;
			}

			ht_[index].kv_ = kv;
			ht_[index].status_ = EXIST;
			++size_;
			return true;
		}

		pNode Find(const K& key)
		{
			size_t index = key % ht_.size();
			while (ht_[index].status_ != EMPTY)
			{
				if (ht_[index].status_ == EXIST && ht_[index].kv_.first == key)
					return &ht_[index];
				++index;
				if (index == ht_.size())
					index = 0;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			pNode ret = Find(key);
			if (ret)
			{
				ret->status_ == DELETE;
				--size_;
				return true;
			}
			return false;
		}

	private:
		void CheckCapacity()
		{
			if (size_ * 10 / ht_.size() >= 7)
			{
				size_t newsize = ht_.size() * 2;
				HashTable<K, V> tmp(newsize);
				for (size_t i = 0; i < ht_.size(); ++i)
				{
					if (ht_[i].status_ == EXIST)
					{
						tmp.Insert(ht_[i].kv_);
					}
				}
				ht_.swap(tmp.ht_);
			}
		}


	private:
		//实现简单，扩容都交给vector
		vector<Node> ht_;
		//有效元素的数量
		size_t size_;
	};
}




//////////////////////////////////////////////////////////
//开散列（哈希桶）
/////////////////////////////////////////////////////////
namespace openhash
{









	template<class V>
	struct HashNode
	{
		V data_;
		HashNode<V>* next_;
		
		HashNode(const V& data)
			:data_(data)
			,next_(nullptr)
		{}
	};

	//////////////////////////////////////////////////////////
	//哈希迭代器
	/////////////////////////////////////////////////////////
	template<class K, class V, class KeyOfVal>
	class HashTable;

	template<class K, class V, class KeyOfVal>
	struct HashItor
	{
		typedef HashNode<K> Node;
		typedef Node* pNode;
		typedef HashItor<K, V,KeyOfVal> Self;
		typedef HashTable<K, V, KeyOfVal> HashT;

		HashT* pht_;

		HashItor(pNode node, HashT* ht)
			:node_(node)
			,pht_(ht)
		{}

		V& operator*()
		{
			return node_->data_;
		}

		V* operator->()
		{
			return &(node_->data_);
		}

		bool operator!=(const Self& it)
		{
			return node_ != it.node_;
		}

		Self& operator++()
		{
			if (node_->next_)
				node_ = node_->next_;
			else
			{
				KeyOfVal kov;
				size_t index = kov(node_->data_) % pht_->ht_.size();
				++index;

				for (index; index < pht_->ht_.size(); ++index)
				{
					if (pht_->ht_[index])
					{
						node_ = pht_->ht_[index];
						return *this;
					}
						
				}
				node_ = nullptr;
			}
			return *this;
		}

		pNode node_;
	};




	template<class K, class V, class KeyOfVal>
	class HashTable
	{

		template<class K, class V, class KeyOfVal>
		friend struct HashItor;


		typedef HashNode<V> Node;
		typedef Node* pNode;

		typedef HashItor<K, V, KeyOfVal> iterator;
	public:

		iterator begin()
		{
			for (size_t i = 0; i < ht_.size(); ++i)
			{
				if (ht_[i])
					return iterator(ht_[i], this);
			}
			return iterator(nullptr, this);
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}








		HashTable(const size_t N = 10)
		{
			size_ = 0;
			ht_.resize(N);
		}

		bool Insert(const V& data)
		{
			CheckCapacity();
			//仿函数实现
			KeyOfVal kov;//获取V的K，通过数据获取key

			size_t index = kov(data) % ht_.size();
			pNode cur = ht_[index];
			while (cur)
			{
				if (kov(cur->data_) == kov(data))
					return false;
				cur = cur->next;
			}
			//头插
			cur = new Node(data);
			cur->next = ht_[index];
			ht_[index] = cur;
			++size_;
		}
	private:
		void CheckCapacity()
		{
			if (size_ == ht_.size())
			{
				size_t newsize = 2 * ht_.size();
				
				vector<pNode> newht;
				newht.resize(newsize);
				for (size_t i = 0; i < size_; ++i)
				{
					pNode cur = ht_[i];
					while (cur)
					{
						pNode next = cur->next_;
						size_t index = kov(cur->data_) % newsize;

						cur->next = newht[i];
						cur = next;
					}
					ht_[i] = nullptr;
				}
				ht_.swap(newht);
			}
		}
	private:
		size_t size_;
		vector<pNode> ht_;
	};
}