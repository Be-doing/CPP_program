#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//////////////////////////////////////
//右值引用
/////////////////////////////////////

int Add(int a, int b)
{
	return a + b;
}


void LfetAndRightVal()
{
	int a = 10;
	int b = 10;

	int& num = a;
	const int& lten = 10;

	int && rrten = 10;


	int&& sum2 = Add(a, b);
	const int& sum3 = Add(a, b);

	//int& sum = Add(a, b);
}
class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
			str = "";
		size_ = strlen(str);
		str_ = new char[size_ + 1];
		strcpy(str_, str);
		cout << "String(const char* str = \"\")" << endl;
	}

	String(const String& s)
		: str_(new char[strlen(s.str_) + 1])
	{
		size_ = strlen(s.str_);
		strcpy(str_, s.str_);
		cout << "String(const String& s)" << endl;
	}

	String(String&& s)
	{
		char* tmp = str_;
		str_ = move(s.str_);
		s.str_ = tmp;
		size_ = s.size_;
		cout << "String(String&& s)" << endl;
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s.str_) + 1];
			strcpy(pTemp, s.str_);
			delete[] str_;
			str_ = pTemp;
			size_ = strlen(s.str_);
		}
		return *this;
	}
	~String()
	{
		if (str_)
		{
			delete[] str_;
			str_ = nullptr;
			size_ = 0;
		}
		cout << "~String()" << endl;
	}
private:
	char* str_;
	size_t size_;
};

String StringTest()
{
	String strtmp("hello");
	return strtmp;
}

void Test()
{
	String str1(StringTest());
}

//////////////////////////////////////
//lambda表达式
/////////////////////////////////////


struct Person
{
	int age_;
	Person(int age = 10)
		:age_(age)
	{}
};

struct Comp
{
	bool operator()(const Person& p1, const Person& p2)
	{
		return p1.age_ > p2.age_;
	}
};

void Print(const vector<Person>& v)
{
	int i = 1;
	for (const auto& t : v)
	{
		cout << "第  " << i << "大的" << t.age_ << endl;
		++i;
	}
}
void Test2()
{
	Person p1(10);
	Person p2(20);
	Person p3(15);
	vector<Person> vp = { p1, p2, p3 };
	Print(vp);
	cout << "=排序后=============" << endl;
	sort(vp.begin(), vp.end(), [](const Person& p1, const Person& p2)
											{
												return p1.age_ > p2.age_;
											});
	Print(vp);
}
int main()
{

	Test2();
	system("pause");
	return 0;
}