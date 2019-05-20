#include<iostream>
#include<string>
using namespace std;
class Child;
class Father
{
public:
	friend void Print(Father& f, Child& c);
	Father(const string& name = "张三", int age = 10)
		:name_(name)
		,age_(age)
	{
			cout << "Father()" << endl;
	}
	virtual void Func(int tmp)//函数隐藏
	{
		cout << tmp << endl;
	}
	~Father()
	{}
private:
//protected:
	string name_;
	int age_;
};

class Child : public Father
{
public:
	Child(const string& sex = "男", int grade = 90)
		:sex_(sex)
		,grade_(grade)
	{
		//Father::name_ = "李四";
		cout << "Child()" << endl;
	}
	virtual void Func()
	{
		cout << "NULL" << endl;
	}
	~Child()
	{}
private:
	string sex_;
	int grade_;
};
void Print(Father& f, Child& c)
{
	cout << f.name_ << endl;
	cout << c.name_ << endl;
}
int main()
{
	//Father f;
	//Child c;

	//f = c;
	//cout << f.name_ << endl;

	//Print(f, c);

	int a = 10;
	int* b = &a;

	cout << "a的地址：" << &a << endl;
	cout << "指针指向的地址" << b << endl;
	cout << "b的地址：" << &b << endl;
	system("pause");
	return 0;
}

class Car { public:    virtual void Drive() final {} };
 
class Benz :public Car { public:    virtual void Drive() {cout << "Benz-舒适" << endl;} };

class Car{ public:    virtual void Drive(){} }; // 2.override 修饰派生类虚函数强制完成重写，如果没有重写会编译报错 class Benz :public Car { public:    virtual void Drive() override {cout << "Benz-舒适" << endl;} };



class Base { public:    virtual void Func1()    {        cout << "Base::Func1()" << endl;    }
 
    virtual void Func2()    {        cout << "Base::Func2()" << endl;    }
 
    void Func3()    {        cout << "Base::Func3()" << endl;    }
 
private:    int _b = 1; };
 
class Derive : public Base { public:    virtual void Func1()    {        cout << "Derive::Func1()" << endl;    } private:    int _d = 2; };
 
int main() {    Base b;    Derive d;
 
    return 0; }
