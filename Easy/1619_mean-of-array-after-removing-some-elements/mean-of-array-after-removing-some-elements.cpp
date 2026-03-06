#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>

class Solution
{
public:
	double trimMean(std::vector<int>& arr)
	{
		std::sort(arr.begin(), arr.end());
		int n = arr.size();
		int trim = n / 20;
		double sum = std::accumulate(arr.begin() + trim, arr.end() - trim, 0.0);
		return sum / (n - 2 * trim);
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
		{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3},
		{6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0},
		{6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4},
	};

	for (auto& arr : tests)
	{
		std::cout << "---\narr: ";
		printV(arr);
		std::cout << "\ntrimMean: " << Solution().trimMean(arr) << std::endl;
	}
	return 0;
}
