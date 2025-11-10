#include <iostream>
#include <vector>

class Solution
{
public:
	bool validMountainArray(std::vector<int>& arr)
	{
		int n = arr.size() - 1;
		if (n < 2) return false;

		int i = 0;
		while (i < n && arr[i] < arr[i + 1])
			i++;
		if (i == 0 || i == n) return false;
		while (i < n && arr[i] > arr[i + 1])
			i++;
		return i == n ;
	}
};

void printVector(const std::vector<int>& vec)
{
	std::cout << "{";
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<int>> tests = {
			{2, 1},
			{3, 5, 5},
			{0, 3, 2, 1},
			{1,3,2},
		};

	for (auto& arr : tests)
	{
		std::cout << "---\narr: ";
		printVector(arr);
		std::cout << "\nvalidMountainArray: " << (Solution().validMountainArray(arr) ? "True" : "False");
		std::cout << std::endl;
	}
	return 0;
}
