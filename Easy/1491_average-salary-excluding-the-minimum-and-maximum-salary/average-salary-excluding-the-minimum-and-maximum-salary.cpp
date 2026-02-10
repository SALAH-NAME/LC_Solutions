#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>

class Solution
{
public:
	double average(std::vector<int>& salary)
	{
		int mn = *std::min_element(salary.begin(), salary.end());
		int mx = *std::max_element(salary.begin(), salary.end());
		int sum = std::accumulate(salary.begin(), salary.end(), 0);
		return static_cast<double>(sum - mn - mx) / (salary.size() - 2);
	}
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<int>> tests = {
		{4000,3000,1000,2000},
		{1000,2000,3000},
	};

	for (auto& s : tests)
	{
		std::cout << "---\nsalary: ";
		printV(s);
		std::cout << "\naverage: " << Solution().average(s) << std::endl;
	}
	return 0;
}
