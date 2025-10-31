#include <iostream>
#include <vector>

class Solution
{
public:
	bool isMonotonic(std::vector<int>& nums)
	{
		bool increasing = true, decreasing = true;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] < nums[i - 1]) decreasing = false;
			else if (nums[i] > nums[i - 1]) increasing = false;

			if (!increasing && !decreasing) return false;
		}
		return true;
	}
};

void printVector(const std::vector<int>& vec)
{
	std::cout << "{";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << ">";
}

int main()
{
	std::vector<std::vector<int>> tests = {
			{1,2,2,3},
			{6,5,4,4},
			{1,3,2},
		};

	for (auto& nums : tests)
	{
		std::cout << "---\nnums= [";
		printVector(nums);
		std::cout << "]\nisMonotonic: ";
		std::cout << (Solution().isMonotonic(nums) ? "True" : "False") << std::endl;
	}
	return 0;
}
