#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
	int largestPerimeter(std::vector<int>& nums)
	{
		std::sort(nums.begin(), nums.end());
		for (int i = nums.size() - 1; i >= 2; i--)
		{
			if (nums[i-2] + nums[i-1] > nums[i])
				return nums[i] + nums[i-1] + nums[i-2];
		}
		return 0;
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
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<int>> tests = {
			{2,1,2},
			{1,2,1,10},
		};

	for (auto& nums : tests)
	{
		std::cout << "---\nnums: ";
		printVector(nums);
		std::cout << "\nlargestPerimeter: " << Solution().largestPerimeter(nums);
		std::cout << std::endl;
	}
}
