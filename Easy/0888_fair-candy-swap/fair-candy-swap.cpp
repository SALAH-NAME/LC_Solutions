#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution
{
public:
	std::vector<int> fairCandySwap(std::vector<int>& aliceSizes, std::vector<int>& bobSizes)
	{
		int sumA = 0;
		int sumB = 0;

		for (int n : aliceSizes)
			sumA += n;
		for (int n : bobSizes)
			sumB += n;

		int dleta = (sumB - sumA) / 2;
		std::unordered_set<int> setB(bobSizes.begin(), bobSizes.end());

		for (int a : aliceSizes)
		{
			int b = a + dleta;
			if (setB.count(b))
				return {a, b};
		}
		return {};
	}
};

void printVector(const std::vector<int>& vec)
{
	std::cout << "{";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

typedef struct testCase
{
	std::vector<int> a;
	std::vector<int> b;
} testCase;

int main()
{
	std::vector<testCase> tests = {
			{{1,1}, {2,2}},
			{{1,2}, {2,3}},
			{{2}, {1,3}},
		};

	for (auto& tc : tests)
	{
		std::cout << "---\n[";
		printVector(tc.a);
		printVector(tc.b);
		std::cout << "]\nresult: ";
		printVector(Solution().fairCandySwap(tc.a, tc.b));
		std::cout << std::endl;
	}
	return 0;
}
