#include <iostream>
#include <utility>
#include <vector>

class Solution
{
public:
	std::vector<int> sortArrayByParityII(std::vector<int>& nums)
	{
		int n = nums.size();
		int even = 0, odd = 1;
		
		while (even < n && odd < n)
		{
			if (nums[even] % 2 == 0)
				even += 2;
			else if (nums[odd] % 2 == 1)
				odd += 2;
			else
			{
				std::swap(nums[even], nums[odd]);
				even += 2;
				odd += 2;
			}
		}
		return nums;
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
		{4,2,5,7},
		{2,3},
	};

	for (auto& nums : tests)
	{
		std::cout << "---\nnums: ";
		printVector(nums);
		Solution().sortArrayByParityII(nums);
		std::cout << "\nSorted: ";
		printVector(nums);
		std::cout << std::endl;
	}
	return 0;
}
