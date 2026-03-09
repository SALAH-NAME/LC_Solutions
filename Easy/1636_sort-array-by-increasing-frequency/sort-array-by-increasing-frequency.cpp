#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
	std::vector<int> frequencySort(std::vector<int>& nums)
	{
		std::unordered_map<int, int> freq;
		for (int n : nums)
			freq[n]++;

		std::sort(nums.begin(), nums.end(), [&](int a, int b) {
				if (freq[a] == freq[b])
					return a > b;
				return freq[a] < freq[b];
		});
		return nums;
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

int main()
{
	std::vector<std::vector<int>> tests = {
		{1,1,2,2,2,3},
		{2,3,1,3,2},
		{-1,1,-6,4,5,-6,1,4,1},
	};

	for (auto& ns : tests)
	{
		std::cout << "---\nnums: ";
		printV(ns);
		std::cout << "\nfrequencySort: ";
		printV(Solution().frequencySort(ns));
		std::cout << std::endl;
	}
	return 0;
}
