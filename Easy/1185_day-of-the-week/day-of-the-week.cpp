#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
	std::string dayOfTheWeek(int day, int month, int year) {
		if (month < 3)
		{
			month += 12;
			year -= 1;
		}
		int K = year % 100;
		int J = year / 100;

		int h = (day + (13*(month + 1))/5 + K + K/4 + J/4 + 5*J) % 7;

		static const std::string days[] = {
			"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"
		};
		return days[h];
	}
};

typedef struct testCase
{
	int d;
	int m;
	int y;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{31, 8, 2019},
		{18, 7, 1999},
		{15, 8, 1993},
	};

	for (auto& [d, m, y] : tests)
	{
		std::cout << "---\nday: " << d << ", month: " << m << ", year: " << y;
		std::cout << "\ndayOfTheWeek: " << Solution().dayOfTheWeek(d,m,y);
		std::cout << std::endl;
	}
	return 0;
}
