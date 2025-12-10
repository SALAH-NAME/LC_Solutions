#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
	std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2)
	{
		std::unordered_map<int, int> freq;
		for (int num : arr1)
			freq[num]++;

		std::vector<int> result;

		for (int num : arr2)
		{
			while (freq[num] > 0)
			{
				result.push_back(num);
				freq[nu]--;
			}
		}
		std::vector<int> leftovers;
		for (auto& [num, count] : freq)
		{
			while (count-- > 0)
				leftovers.push_back(num);
		}

		std::sort(leftovers.begin(), leftovers.end());
		result.insert(result.end(), leftovers.begin(), leftovers.end());
		return result;
	}
};

void printVector(const std::vector<int>& v)
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

typedef struct testCase
{
	std::vector<int> a1;
	std::vector<int> a2;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{2,3,1,3,2,4,6,7,9,2,19}, {2,1,4,3,9,6}},
		{{28,6,22,8,44,17}, {22,28,8,6}},
	};

	for (auto& [a1, a2] : tests)
	{
		std::cout << "---\narr1: ";
		printVector(a1);
		std::cout << ", arr2: ";
		printVector(a2);
		std::cout << "\nrelativeSortArray: ";
		printVector(Solution().relativeSortArray(a1, a2));
		std::cout << std::endl;
	}
	return 0;
}
