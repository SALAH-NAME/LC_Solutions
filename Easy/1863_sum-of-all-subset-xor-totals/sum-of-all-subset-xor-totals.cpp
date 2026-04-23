#include <iostream>
#include <vector>
#include <iostream>

class Solution
{
public:
	int subsetXORSum(std::vector<int>& nums)
	{
		return dfs(nums, 0, 0);
	}
private:
	int dfs(const std::vector<int>& nums, int index, int currentXor)
	{
		if (index == nums.size())
		{
			return currentXor;
		}
		int include = dfs(nums, index + 1, currentXor ^ nums[index]);
		int exclude = dfs(nums, index + 1, currentXor);
		return include + exclude;
	}
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if ( i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

typedef struct testCase
{
	std::vector<int> n;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{1,3}},
		{{5,1,6}},
		{{3,4,5,6,7,8}},
	};

	for (auto& [n] : tests)
	{
		std::cout << "---\nnums: ";
		printV(n);
		std::cout << "\nsubsetXORSum: ";
		std::cout << Solution().subsetXORSum(n) << std::endl;
	}
	return 0;
}
