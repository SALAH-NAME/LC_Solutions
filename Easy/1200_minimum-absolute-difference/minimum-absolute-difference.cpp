#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

class Solution
{
public:
	std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr)
	{
		std::vector<std::vector<int>> result;
		std::sort(arr.begin(), arr.end());

		int minDiff = INT_MAX;

		for (int i = 1; i < arr.size(); i++)
			minDiff = std::min(minDiff, arr[i] - arr[i - 1]);

		for (int i = 1; i < arr.size(); i++)
		{
			if (arr[i] - arr[i - 1] == minDiff)
				result.push_back({arr[i-1], arr[i]});
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
		{4,2,1,3},
		{1,3,6,10,15},
		{3,8,-10,23,19,-4,-14,27},
	};

	for (auto& arr : tests)
	{
		std::cout << "---\narr: ";
		printV(arr);
		std::cout << "\nminimumAbsDifference: {";
		std::vector<std::vector<int>> res = Solution().minimumAbsDifference(arr);
		for (int i = 0; i < res.size(); i++)
		{
			printV(res[i]);
			if (i < res.size() - 1)
				std::cout << ", ";
		}
		std::cout << "}" << std::endl;
	}
	return 0;
}
