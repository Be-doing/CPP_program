#pragma once
#include<iostream>
using namespace std;


void CMemory()
{
	//malloc(size_t ize)
	//在堆上分配一块长度为size字节的连续区域。
	//参数size为需要的内存空间的长度，返回该区域的首地址
	int* p1 = (int*)malloc(sizeof(int));

	//calloc(size_t count, size_t size）
	//在堆上分配count个size字节的连续区域
	//并所分配的空间中的每一位都初始化为零
	int *p2 = (int*)calloc(1, sizeof(int));

	//realloc(void *ptr, size_t size);
	//给一个已经分配了地址的指针重新分配空间，参数ptr为原有的空间地
	int* p3 = (int*)realloc(p2, 3);
}
//内置类型
void CppMemory()
{
	int* p1 = new int;

	int * p2 = new int(10);

	int* p3 = new int[3];
}
//自定义类型
class MemoryTest
{
public:
	MemoryTest()
		:data_(0)
	{}
private:
	int data_;
};
void Test()
{
	MemoryTest* t1 = (MemoryTest*)malloc(sizeof(MemoryTest));
	new(t1) MemoryTest;//new定位表达式在已分配的原始内存空间中调用构造函数初始化一个对象。
	free(t1);

	MemoryTest* t2 = new MemoryTest;
	delete t2;

	MemoryTest* t3= new MemoryTest[3];
	delete [] t3;
}
//定位new表达式
//在已分配的原始内存空间中调用构造函数初始化一个对象
class NewPress
{
public:
	NewPress()
		:data_(0)
	{
		cout << "定位new表达式" << endl;
	}
private:
	int data_;
};
//创建一个类，该类只能在堆上创建
	//1. 将类的构造函数私有，拷贝构造声明成私有。防止别人调用拷贝在栈上生成对象。
	//2. 提供一个静态的成员函数，在该静态成员函数中完成堆对象的创建
class HeapObj
{
public:
	//定义成静态的，可用类名经行调用
	static HeapObj getObj()
	{
		HeapObj* obj = new HeapObj;//在堆上进行申请内存
		return *obj;
	}
private:
	HeapObj();
	HeapObj(const HeapObj& d);
	int data_;
};
//创建一个类，该类只能在栈上创建
	//1. 将类的构造函数私有。。
	//2. 拷贝构造不用，因为拷贝构造是根据已经有的对象在栈生成对象
	//2. 提供一个静态的成员函数，在该静态成员函数中完成栈对象的创建
class StackObj
{
	static StackObj getObj()
	{
		return StackObj();
	}
private:
	StackObj()
		:data_(0)
	{

	}
	//删除 operator new(size_t size)是其不能在堆上创建
	void* operator new(size_t size) = delete;
	void operator delete(void* p) = delete;
private:
	int data_;
};
//单例模式
//饿汉
	//构造函数和拷贝构造函数私有
	//定义一个静态单例成员，静态成员在程序运行程序之前完成初始化
	//提供一个静态方法获取单例静态成员
class Singleton
{
	static Singleton& getObj()
	{
		return obj_;
	}
private:
	static Singleton obj_;//不能直接定义一个成员，因为无法计算类的大小，非法操作
	Singleton()
	{};
	Singleton(const Singleton &) = delete;

};
Singleton Singleton::obj_ ;

#include<mutex>
class Singleton2
{
public:
	static Singleton2* getObj()
	{
		if (obj2_ = nullptr)//两次检查，提高效率
		{
			mtx_.lock();//保证内存只创建一次
			if (obj2_ == nullptr)
			{
				obj2_ = new Singleton2;
			}
			mtx_.unlock();
		}
		return obj2_;
	}
	class Gc//可有可无，程序结束，进程释放资源
	{
	public:
		~Gc()//定义一个内部类的析构，是因为不能在本类中调用自身的析构，否则会发生递归调用
		{
			if (obj2_)
			{
				delete obj2_;
				obj2_ = nullptr;
			}
		}
	};
private:
	Singleton2()
	{}
	Singleton2(const Singleton&) = delete;
	static Singleton2* obj2_;//指针只占四个字节，没有对象，当需要的时候才创建
	static mutex mtx_;
};

Singleton2* Singleton2::obj2_ = nullptr;
mutex Singleton2::mtx_;