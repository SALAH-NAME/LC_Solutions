#include <vector>
#include <iostream>

class Solution
{
public:
	bool canBeIncreasing(std::vector<int>& nums)
	{
		int count = 0;
		int n = nums.size();

		for (int i = 1; i < n; ++i)
		{
			if (nums[i] <= nums[i - 1])
			{
				count++;
				if (count > 1) return false;
				if (i > 1 && nums[i] <= nums[i - 2])
				{
					nums[i] = nums[i - 1];
				}
			}
		}
		return count <= 1;
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
		{{1,2,10,5,7}},
		{{2,3,1,2}},
		{{1,1,1}},
	};

	for (auto& [n] : tests)
	{
		std::cout << "---\nnums: ";
		printV(n);
		std::cout << "\ncanBeIncreasing: ";
		std::cout << (Solution().canBeIncreasing(n) ? "True" : "False") << std::endl;
	}
	return 0;
}
