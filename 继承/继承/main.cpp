#include<iostream>
#include<string>
using namespace std;
class Child;
class Father
{
public:
	friend void Print(Father& f, Child& c);
	Father(const string& name = "����", int age = 10)
		:name_(name)
		,age_(age)
	{
			cout << "Father()" << endl;
	}
private:
//protected:
	string name_;
	int age_;
};

class Child : public Father
{
public:
	Child(const string& sex = "��", int grade = 90)
		:sex_(sex)
		,grade_(grade)
	{
		//Father::name_ = "����";
		cout << "Child()" << endl;
	}
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
	Father f;
	Child c;
	f = c;
	//cout << f.name_ << endl;
	Print(f, c);
	system("pause");
	return 0;
}