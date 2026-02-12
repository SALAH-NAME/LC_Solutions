#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
	bool canMakeArithmeticProgression(std::vector<int>& arr)
	{
		std::sort(arr.begin(), arr.end());
		int diff = arr[1] - arr[0];
		for (int i = 2; i < arr.size(); i++)
		{
			if (arr[i] - arr[i - 1] != diff)
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
		{3,5,1},
		{1,2,4},
	};

	for (auto& a : tests)
	{
		std::cout << "---\narr: ";
		printV(a);
		std::cout << "\ncanMakeArithmeticProgression: ";
		std::cout << (Solution().canMakeArithmeticProgression(a) ? "True" : "False");
		std::cout << std::endl;
	}
	return 0;
}
