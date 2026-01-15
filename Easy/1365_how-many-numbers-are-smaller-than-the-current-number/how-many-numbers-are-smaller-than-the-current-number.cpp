#include <vector>
#include <iostream>

class Solution
{
public:
	std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums)
	{
		int freq[101] = {0};
		for (int num : nums)
			freq[num]++;

		int prefix[101] = {0};
		for (int i = 1; i <= 100; i++)
			prefix[i] = prefix[i - 1] + freq[i - 1];

		std::vector<int> result;
		result.reserve(nums.size());
		for (int num : nums)
			result.push_back(prefix[num]);	
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
		{8,1,2,2,3},
		{6,5,4,8},
		{7,7,7,7},
	};

	for (auto& nums : tests)
	{
		std::cout << "---\nnums: ";
		printV(nums);
		std::cout << "\nsmallerNumbersThanCurrent: ";
		printV(Solution().smallerNumbersThanCurrent(nums));
		std::cout <<std::endl;
	}
	return 0;
}
