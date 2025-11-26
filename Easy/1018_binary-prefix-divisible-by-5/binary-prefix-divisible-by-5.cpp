#include <iostream>
#include <vector>

class Solution
{
public:
	std::vector<bool> prefixesDivBy5(std::vector<int>& nums)
	{
		std::vector<bool> result;
		result.reserve(nums.size());

		int res = 0;
		for (int n : nums)
		{
			res = ((res <<= 1) | n) % 5;
			result.push_back(res == 0);
		}
		return result;
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

void printVecBool(const std::vector<bool>& vec)
{
	std::cout << "{";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << (vec[i] ? "true" : "false");
		if (i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<int>> tests = {
			{0,1,1},
			{1,1,1},
		};

	for (auto& nums : tests)
	{
		std::cout << "---\nnums: ";
		printVector(nums);
		std::cout << "\nprefixesDivBy5: ";
		printVecBool(Solution().prefixesDivBy5(nums));
		std::cout << std::endl;
	}
	return 0;
}
