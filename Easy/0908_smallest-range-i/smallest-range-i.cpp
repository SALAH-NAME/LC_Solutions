#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
	int smallestRangeI(std::vector<int>& nums, int k)
	{
		auto [minIt, maxIt] = std::minmax_element(nums.begin(), nums.end());
		int diff = (*maxIt - *minIt) - 2 * k;

		return (diff > 0 ? diff : 0);
	}
};

void printVector(const std::vector<int>& vec)
{
	std::cout << "{";
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

typedef struct testCase
{
	std::vector<int> nums;
	int k;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{1}, 0},
		{{0,10}, 2},
		{{1,3,6}, 3},
		{{1,6}, 3},
		{{3,0,6}, 0},
	};

	for (auto& tc : tests)
	{
		std::cout << "---\nnums: ";
		printVector(tc.nums);
		std::cout << " k: " << tc.k << "\nRange: ";
		std::cout << Solution().smallestRangeI(tc.nums, tc.k);
		std::cout << std::endl;
	}
	return 0;
}
