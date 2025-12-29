#include <vector>
#include <iostream>

class Solution
{
public:
	int findSpecialInteger(std::vector<int>& arr)
	{
		int n = arr.size();
		int threshold = n / 4;

		for (int i = 0; i < n; ++i)
		{
			if (i + threshold < n && arr[i] == arr[i + threshold])
				return arr[i];
		}
		return -1;
	}
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (size_t i = 0; i < v.size(); ++i)
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
		{1,2,2,6,6,6,6,7,10},
		{1, 1},
	};

	for (auto& arr : tests)
	{
		std::cout << "---\narr: ";
		printV(arr);
		std::cout << "\nfindSpecialInteger: ";
		std::cout << Solution().findSpecialInteger(arr) << std::endl;
	}
	return 0;
}
