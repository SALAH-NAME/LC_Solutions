#include <unordered_map>
#include <vector>
#include <iostream>


class Solution
{
public:
	int findLucky(std::vector<int>& arr)
	{
		std::unordered_map<int, int> freq;

		for (int n : arr)
			freq[n]++;

		int result = -1;
		for (auto& [num, count] : freq)
		{
			if (num == count)
				result = std::max(result, num);
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
	std::vector<std::vector<int>>	 tests = {
		{2,2,3,4},
		{1,2,2,3,3,3},
		{2,2,2,3,3},
	};

	for (auto& arr : tests)
	{
		std::cout << "---\narr: ";
		printV(arr);
		std::cout << "\nfindLucky: " << Solution().findLucky(arr) << std::endl;
	}
	return 0;
}
