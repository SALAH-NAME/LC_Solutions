#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

class Solution {
public:
	std::vector<int> minSubsequence(std::vector<int>& nums)
	{
		std::sort(nums.begin(), nums.end(), std::greater<int>());

		int total = 0;
		for (int n : nums) total += n;

		std::vector<int> result;
		int sum = 0;

		for (int n : nums)
		{
			result.push_back(n);
			sum += n;
			if (sum > total - sum) break;
		}
		return result;
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
	std::vector<std::vector<int>> tests = {
		{4,3,10,9,8},
		{4,4,7,6,7},
	};

	for (auto& nums : tests)
	{
		std::cout << "---\nnums: ";
		printV(nums);
		std::cout << "\nminSubsequence: ";
		printV(Solution().minSubsequence(nums));
		std::cout << std::endl;
	}
	return 0;
}
