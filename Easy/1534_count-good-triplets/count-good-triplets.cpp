#include <cstdlib>
#include <vector>
#include <iostream>

class Solution
{
public:
	int countGoodTriplets(std::vector<int>& arr, int a, int b, int c)
	{
		int n = arr.size();
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (std::abs(arr[i] - arr[j]) > a) continue;
				for (int k = j + 1; k < n; k++)
				{
					if (std::abs(arr[j] - arr[k]) <= b && std::abs(arr[i] - arr[k]) <= c)
						count++;
				}
			}
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

typedef struct testCase
{
	std::vector<int> v;
	int a;
	int b;
	int c;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{3,0,1,1,9,7}, 7, 2, 3},
		{{1,1,2,2,3}, 0, 0, 1},
	};

	for (auto& [v, a, b, c] : tests)
	{
		std::cout << "---\narr: ";
		printV(v);
		std::cout << ", a: " << a << ", b: " << b << ", c: " << c << "\n";
		std::cout << "countGoodTriplets: " << Solution().countGoodTriplets(v, a, b, c);
		std::cout << std::endl;
	}
	return 0;
}
