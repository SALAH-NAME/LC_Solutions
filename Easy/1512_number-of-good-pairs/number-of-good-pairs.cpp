#include <unordered_map>
#include <vector>
#include <iostream>

class Solution
{
public:
	int numIdenticalPairs(std::vector<int>& nums)
	{
		std::unordered_map<int, int> freq;
		int count = 0;
		for (int n : nums)
		{
			count += freq[n];
			freq[n]++;
		}
		return count;
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
		{1,2,3,1,1,3},
		{1,1,1,1},
		{1,2,3},
	};

	for (auto& n : tests)
	{
		std::cout << "---\nnums: ";
		printV(n);
		std::cout << "\nnumIdenticalPairs: " << Solution().numIdenticalPairs(n);
		std::cout << std::endl;
	}
	return 0;
}
