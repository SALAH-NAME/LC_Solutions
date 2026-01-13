#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
	std::vector<int> sortByBits(std::vector<int>& arr)
	{
		std::sort(arr.begin(), arr.end(), [](int a, int b) {
			int bitCountA = __builtin_popcount(a);
			int bitCountB = __builtin_popcount(b);
			if (bitCountA == bitCountB)
				return a < b;
			return bitCountA < bitCountB;
		});
		return arr;
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
		{0,1,2,3,4,5,6,7,8},
		{1024,512,256,128,64,32,16,8,4,2,1},
	};

	for (auto& a : tests)
	{
		std::cout << "---\narr: ";
		printV(a);
		std::cout << "\nsortByBits: ";
		printV(Solution().sortByBits(a));
		std::cout << std::endl;
	}
	return 0;
}
