#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
	int dayOfYear(std::string date)
	{
		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));

		std::vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			daysInMonth[1] = 29;

		int dayOfYear = 0;
		for (int i = 0; i < month - 1; ++i)
			dayOfYear += daysInMonth[i];

		dayOfYear += day;
		return dayOfYear;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"2019-01-09",
		"2019-02-10",
	};

	for (auto& date : tests)
	{
		std::cout << "---\ndate: " << date << "\ndayOfYear: ";
		std::cout << Solution().dayOfYear(date) << std::endl;
	}
	return 0;
}
