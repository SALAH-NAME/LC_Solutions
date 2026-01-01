#include <vector>
#include <iostream>

class Solution
{
public:
	std::vector<int> replaceElements(std::vector<int>& arr)
	{
		int maxRight = -1;

		for (int i = arr.size() - 1; i >= 0; --i)
		{
			int current = arr[i];
			arr[i] = maxRight;
			if (current > maxRight)
				maxRight = current;
		}
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
		{17,18,5,4,6,1},
		{400},
	};

	for (auto& arr : tests)
	{
		std::cout << "---\narr: ";
		printV(arr);
		std::cout << "\nreplaceElements: ";
		printV(Solution().replaceElements(arr));
		std::cout << std::endl;
	}
	return 0;
}
