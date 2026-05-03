#include <iostream>
#include <vector>

class Solution
{
public:
	std::vector<int> buildArray(std::vector<int>& nums)
	{
		int n = nums.size();
		std::vector<int> ans(n);
		for (int i = 0; i < n; i++)
		{
			ans[i] = nums[nums[i]];
		}
		return ans;
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

typedef struct testCase
{
	std::vector<int> n;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{0,2,1,5,3,4}},
		{{5,0,1,2,3,4}},
	};

	for (auto& [n] : tests)
	{
		std::cout << "---\nnums: ";
		printV(n);
		std::cout << "\nbuildArray: ";
		printV(Solution().buildArray(n));
		std::cout << std::endl;
	}
	return 0;
}
