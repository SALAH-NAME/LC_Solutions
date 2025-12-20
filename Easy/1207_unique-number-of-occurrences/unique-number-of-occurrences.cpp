#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

class Solution
{
public:
	bool uniqueOccurrences(std::vector<int>& arr)
	{
		std::unordered_map<int, int> freq;
		for (int n : arr)
			freq[n]++;

		std::unordered_set<int> seen;
		for (auto& p : freq)
		{
			if (!seen.insert(p.second).second)
				return false;	
		}
		return true;
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
		{1,2,2,1,1,3},
		{1,2},
		{-3,0,1,-3,1,1,1,-3,10,0},
	};

	for (auto& arr : tests)
	{
		std::cout << "---\narr: ";
		printV(arr);
		std::cout << "\nuniqueOccurrences: ";
		std::cout << (Solution().uniqueOccurrences(arr) ? "True" : "False");
		std::cout << std::endl;
	}
	return 0;
}
