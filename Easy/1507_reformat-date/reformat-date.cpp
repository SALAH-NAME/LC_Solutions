#include <sstream>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
public:
	std::string reformatDate(std::string date)
	{
		std::istringstream iss(date);
		std::string dayStr, monthStr, yearStr;
		iss >> dayStr >> monthStr >> yearStr;

		dayStr = dayStr.substr(0, dayStr.size() - 2);
		if (dayStr.size() == 1) dayStr = "0" + dayStr;

		static std::unordered_map<std::string, std::string> months = {
			{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
			{"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
			{"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"} };

		return yearStr + "-" + months[monthStr] + "-" + dayStr;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"20th Oct 2052",
		"6th Jun 1933",
		"26th May 1960",
	};

	for (auto& d : tests)
	{
		std::cout << "---\ndate: " << d << "\nreformatDate: ";
		std::cout << Solution().reformatDate(d) << std::endl;
	}
	return 0;
}
