#include <vector>
#include <iostream>

class Solution
{
public:
	std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index)
	{
		std::vector<int> target;
		for (int i = 0; i < nums.size(); i++)
			target.insert(target.begin() + index[i], nums[i]);
		return target;
	}
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i - v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

typedef struct testCase
{
	std::vector<int> n;
	std::vector<int> i;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{0,1,2,3,4}, {0,1,2,2,1}},
		{{0,1,2,3,4}, {0,1,2,2,1}},
		{{0,1,2,3,4}, {0,1,2,2,1}},
	};

	for (auto& [nums, index] : tests)
	{
		std::cout << "---\nnums: ";
		printV(nums);
		std::cout << ", index: ";
		printV(index);
		std::cout << "\ncreateTargetArray: ";
		printV(Solution().createTargetArray(nums, index));
		std::cout << std::endl;
	}
	return 0;
}
