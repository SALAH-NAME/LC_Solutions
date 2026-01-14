#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

class Solution
{
public:
	int daysBetweenDates(std::string date1, std::string date2)
	{
		return std::abs(toDays(date1) - toDays(date2));
	}
private:
	int toDays(const std::string& date)
	{
		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));

		static int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

		int days = 0;
		for (int y = 0; y < year; ++y)
			days += isLeap(y) ? 366 : 365;

		for (int m = 1; m < month; ++m)
		{
			days += monthDays[m - 1];
			if (m == 2 && isLeap(year)) days += 1;
		}

		days += day;
		return days;
	}

	bool isLeap(int year)
	{
		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	}
};

typedef struct testCase {
	std::string d1;
	std::string d2;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"2019-06-29","2019-06-30"},
		{"2020-01-15","2019-12-31"},
	};

	for (auto& [d1, d2] : tests)
	{
		std::cout << "---\ndate1: '" << d1 << "', date2: '" << d2 << "'\n";
		std::cout << "daysBetweenDates: " << Solution().daysBetweenDates(d1, d2);
		std::cout << std::endl;
	}
	return 0;
}
