#include <vector>
#include <iostream>

class Solution
{
public:
	std::vector<int> getConcatenation(std::vector<int>& nums)
	{

		int n = nums.size();
		std::vector<int> ans;
		ans.reserve(2 * n);

		for (int i = 0; i < 2; ++i)
		{
			for (int num : nums)
			{
				ans.push_back(num);
			}
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
		{{}},
	};

	for (auto& [n] : tests)
	{
		std::cout << "---\nnums: ";
		printV(n);
		std::cout << "\ngetConcatenation: ";
		printV(Solution().getConcatenation(n));
		std::cout << std::endl;
	}
	return 0;
}
