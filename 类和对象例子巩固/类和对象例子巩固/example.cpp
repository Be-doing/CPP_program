
#include<iostream>
using namespace std;
class Solution 
{
public:
	//ÄÚ²¿Àà
	class Solution_in_
	{
	public:
		Solution_in_()
		{
			sum_ += time_;
			++time_;
		}

	};
	Solution()
	{}
	int Sum_Solution(int n)
	{
		time_ = 1;
		sum_ = 0;
		Solution_in_ arr[4];
		return sum_;
	}
	static int time_;
	static int sum_;
};
int Solution::time_ = 1;
int Solution::sum_ = 0;

class Date
{
public:
	Date(int year, int month, int day)
		:year_(year),
		month_(month),
		day_(day)
	{}
	int getday(int year, int month, int day)
	{
		static int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			arr[1] = 29;
		}
		return arr[month - 1];
	}
	int num(int year, int month, int day)
	{
		if (month == 1)
		{
			return day;
		}
		int num = 0;
		for (int i = 0; i < month-1; ++i)
		{							
			num += getday(year, month - i -1, day);
		}
		return num + day;
	}
private:
	int year_;
	int month_;
	int day_;
};

int main()
{
	Solution test;
	cout << test.Sum_Solution(4) << endl;
	Date d(2018, 2, 20);
	cout << d.num(2018, 2, 20) << endl;
	system("pause");
	return 0;
}