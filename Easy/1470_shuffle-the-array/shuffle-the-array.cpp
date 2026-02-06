#include <vector>
#include <iostream>

class Solution
{
public:
	std::vector<int> shuffle(std::vector<int>& nums, int n)
	{
		std::vector<int> result;
		result.reserve(n * 2);

		for (int i = 0; i < n; ++i)
		{
			result.push_back(nums[i]);
			result.push_back(nums[i + n]);
		}
		return result;
	}
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

typedef struct testCase 
{
	std::vector<int> nums;
	int n;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{2,5,1,3,4,7}, 3},
		{{1,2,3,4,4,3,2,1}, 4},
		{{1,1,2,2}, 2},
	};

	for (auto& [nums, n] : tests)
	{
		std::cout << "---\nnums: ";
		printV(nums);
		std::cout << ", n: " << n << "\nshuffle: ";
		printV(Solution().shuffle(nums, n));	
		std::cout << std::endl;
	}
	return 0;
}
