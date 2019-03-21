#pragma once
#include<iostream>
using namespace std;


void CMemory()
{
	//malloc(size_t ize)
	//�ڶ��Ϸ���һ�鳤��Ϊsize�ֽڵ���������
	//����sizeΪ��Ҫ���ڴ�ռ�ĳ��ȣ����ظ�������׵�ַ
	int* p1 = (int*)malloc(sizeof(int));

	//calloc(size_t count, size_t size��
	//�ڶ��Ϸ���count��size�ֽڵ���������
	//��������Ŀռ��е�ÿһλ����ʼ��Ϊ��
	int *p2 = (int*)calloc(1, sizeof(int));

	//realloc(void *ptr, size_t size);
	//��һ���Ѿ������˵�ַ��ָ�����·���ռ䣬����ptrΪԭ�еĿռ��
	int* p3 = (int*)realloc(p2, 3);
}
//��������
void CppMemory()
{
	int* p1 = new int;

	int * p2 = new int(10);

	int* p3 = new int[3];
}
//�Զ�������
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
	new(t1) MemoryTest;//new��λ���ʽ���ѷ����ԭʼ�ڴ�ռ��е��ù��캯����ʼ��һ������
	free(t1);

	MemoryTest* t2 = new MemoryTest;
	delete t2;

	MemoryTest* t3= new MemoryTest[3];
	delete [] t3;
}

//����һ���࣬����ֻ���ڶ��ϴ���
	//1. ����Ĺ��캯��˽�У���������������˽�С���ֹ���˵��ÿ�����ջ�����ɶ���
	//2. �ṩһ����̬�ĳ�Ա�������ڸþ�̬��Ա��������ɶѶ���Ĵ���
class HeapObj
{
public:
	//����ɾ�̬�ģ������������е���
	static HeapObj getObj()
	{
		HeapObj* obj = new HeapObj;//�ڶ��Ͻ��������ڴ�
		return *obj;
	}
private:
	HeapObj();
	HeapObj(const HeapObj& d);
	int data_;
};
//����һ���࣬����ֻ����ջ�ϴ���
	//1. ����Ĺ��캯��˽�С���ֹ���˵��ÿ����ڶ������ɶ���
	//2. �������첻�ã���Ϊ���������Ǹ����Ѿ��еĶ�����ջ���ɶ���
	//2. �ṩһ����̬�ĳ�Ա�������ڸþ�̬��Ա���������ջ����Ĵ���
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
	//ɾ�� operator new(size_t size)���䲻���ڶ��ϴ���
	void* operator new(size_t size) = delete;
	void operator delete(void* p) = delete;
private:
	int data_;
};
//����ģʽ
//����
	//���캯���Ϳ������캯��˽��
	//����һ����̬������Ա����̬��Ա�ڳ������г���֮ǰ��ɳ�ʼ��
	//�ṩһ����̬������ȡ������̬��Ա
class Singleton
{
	static Singleton& getObj()
	{
		return data_;
	}
private:
	static Singleton data_;
	Singleton();
	Singleton(const Singleton& s) = delete;
	Singleton& operator=(Singleton const&);
};
Singleton Singleton::data_ ;