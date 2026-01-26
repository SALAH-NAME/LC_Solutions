#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
	int minStartValue(std::vector<int>& nums)
	{
		int sum = 0;
		int minPrefix = 0;

		for (int n : nums)
		{
			sum += n;
			minPrefix = std::min(minPrefix, sum);
		}
		return 1 - minPrefix;
	}
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<int>>	tests = {
		{-3,2,-3,4,2},
		{1,2},
		{1,-2,-3},
	};

	for (auto& nums : tests)
	{
		std::cout << "---\nnums: ";
		printV(nums);
		std::cout << "\nminStartValue: " << Solution().minStartValue(nums);
		std::cout << std::endl;
	}
	return 0;
}
