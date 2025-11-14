#include <iostream>
#include <unordered_set>
#include <vector>

class Solution
{
public:
	int repeatedNTimes(std::vector<int>& nums)
	{
		std::unordered_set<int> seen;
		for (int n : nums)
		{
			if (seen.count(n)) return n;
			seen.insert(n);
		}
		return -1;
	}
};

void printVector(const std::vector<int>& vec)
{
	std::cout << "{";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if ( i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<int>> tests = {
			{1, 2, 3, 3},
			{2, 1, 2, 5, 3, 2},
			{5, 1, 5, 2, 5, 3, 5, 4},
		};

	for (auto& nums : tests)
	{
		std::cout << "---\nnums: ";
		printVector(nums);
		std::cout << "\nrepeatedNTimes: " << Solution().repeatedNTimes(nums);
		std::cout << std::endl;
	}
	return 0;
}
