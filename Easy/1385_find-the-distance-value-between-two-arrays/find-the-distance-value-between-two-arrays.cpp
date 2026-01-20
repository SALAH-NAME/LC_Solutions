#include <cstdlib>
#include <vector>
#include <iostream>

class Solution
{
public:
	int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d)
	{
		int count = 0;
		for (int x : arr1)
		{
			bool valid = true;
			for (int y : arr2)
			{
				if (std::abs(x - y) <= d)
				{
					valid = false;
					break;
				}
			}
			if (valid) count++;
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

typedef struct testCase {
	std::vector<int> a1;
	std::vector<int> a2;
	int d;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{4,5,8}, {10,9,1,8}, 2},
		{{1,4,2,3}, {-4,-3,6,10,20,30}, 3},
		{{2,1,100,3}, {-5,-2,10,-3,7}, 6},
	};


	for (auto& [a1, a2, d] : tests)
	{
		std::cout << "---\narr1: ";
		printV(a1);
		std::cout << ", arr2: ";
		printV(a2);
		std::cout << ", d: " << d << "\nfindTheDistanceValue: ";
		std::cout << Solution().findTheDistanceValue(a1, a2, d) << std::endl;
	}
	return 0;
}
