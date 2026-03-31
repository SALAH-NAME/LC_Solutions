#include <vector>
#include <iostream>
#include <unordered_map>

class Solution
{
public:
	int sumOfUnique(std::vector<int>& nums)
	{
		std::unordered_map<int, int> freq;
		for (int n : nums)
			freq[n]++;

		int sum = 0;
		for (auto& [num, count] : freq)
		{
			if (count == 1)
				sum += num;
		}
		return sum;
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
		{1,2,3,2},
		{1,1,1,1,1},
		{1,2,3,4,5},
	};

	for (auto& n : tests)
	{
		std::cout << "---\nnums: ";
		printV(n);
		std::cout << "\nsumOfUnique: ";
		std::cout << Solution().sumOfUnique(n) << std::endl;
	}
	return 0;
}
