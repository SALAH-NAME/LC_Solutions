#include <vector>
#include <iostream>

class Solution
{
public:
	std::vector<int> decompressRLElist(std::vector<int>& nums)
	{
		std::vector<int> result;

		for (int i = 0; i < nums.size(); i += 2)
		{
			int freq = nums[i];
			int val = nums[i + 1];

			result.insert(result.end(), freq, val);
		}
		return result;
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
	std::vector<std::vector<int>> tests = {
		{1,2,3,4},
		{1,1,2,3},
	};

	for (auto& nums : tests)
	{
		std::cout << "---\nnums: ";
		printV(nums);
		std::cout << "\ndecompressRLElist: ";
		printV(Solution().decompressRLElist(nums));
		std::cout << std::endl;
	}
	return 0;
}
