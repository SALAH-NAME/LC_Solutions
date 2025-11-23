#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class Solution
{
public:
	int largestSumAfterKNegations(std::vector<int>& nums, int k)
	{
		std::sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() && k > 0; i++)
		{
			if (nums[i] < 0)
			{
				nums[i] = -nums[i];
				k--;
			}
		}

		if (k % 2 == 1)
		{
			auto it = std::min_element(nums.begin(), nums.end());
			*it = -*it;
		}
		return std::accumulate(nums.begin(), nums.end(), 0);
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

typedef struct testCase {
	std::vector<int> nums;
	int k;
} testCase;

int main()
{
	std::vector<testCase> tests = {
			{{4,2,3}, 1},
			{{3,-1,0,2}, 3},
			{{2,-3,-1,5,-4}, 2},
		};

	for (auto& tc : tests)
	{
		std::cout << "---\nnums: ";
		printVector(tc.nums);
		std::cout << " k: " << tc.k << "\nlargestSumAfterKNegations: ";
		std::cout << Solution().largestSumAfterKNegations(tc.nums, tc.k);
		std::cout << std::endl;
	}
	return 0;
}
