#include <vector>
#include <iostream>

class Solution
{
public:
	int maxProduct(std::vector<int>& nums)
	{
		int first = 0, second = 0;
		for (int n : nums)
		{
			if (n > first)
			{
				second = first;
				first = n;
			}
			else if (n > second)
				second = n;
		}
		return (first - 1) * (second - 1);
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
	std::vector<std::vector<int>>tests = {
		{3,4,5,2},
		{1,5,4,5},
		{3,7},
	};

	for (auto& nums : tests)
	{
		std::cout << "---\nnums: ";
		printV(nums);
		std::cout << "\nmaxProduct: ";
		std::cout << Solution().maxProduct(nums) << std::endl;
	}
	return 0;
}
