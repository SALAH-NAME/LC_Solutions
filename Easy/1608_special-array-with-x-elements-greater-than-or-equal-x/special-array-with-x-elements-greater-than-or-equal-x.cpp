#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
	int specialArray(std::vector<int>& nums)
	{
		std::sort(nums.begin(), nums.end());

		int n = nums.size();
		
		for(int x = 1; x <= n; x++)
		{
			int count = nums.end() - std::lower_bound(nums.begin(), nums.end(), x);
			if (count == x)
				return x;
		}
		return -1;
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
		{3,5},
		{0,0},
		{0,4,3,0,4},
	};

	for (auto& nums : tests)
	{
		std::cout << "---\nnums: ";
		printV(nums);
		std::cout << "\nspecialArray: " << Solution().specialArray(nums) << std::endl;
	}
	return 0;
}
