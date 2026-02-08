#include <vector>
#include <iostream>

class Solution
{
public:
	std::vector<int> runningSum(std::vector<int>& nums)
	{
		std::vector<int> result(nums.size());
		if (nums.empty()) return result;

		result[0] = nums[0];
		for (int i = 1; i < nums.size(); i++)
			result[i] = result[i - 1] + nums[i];
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
		{1,2,3,4},
		{1,1,1,1,1},
		{3,1,2,10,1},
	};

	for (auto& nums : tests)
	{
		std::cout << "---\nnums: ";
		printV(nums);
		std::cout << "\nrunningSum: ";
		printV(Solution().runningSum(nums));
		std::cout << std::endl;
	}
	return 0;
}
