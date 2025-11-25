#include <iostream>
#include <vector>

class Solution
{
public:
	bool canThreePartsEqualSum(std::vector<int>& arr)
	{
		int sum = 0;
		for (int n : arr)
			sum += n;
		if (sum % 3 != 0)
			return false;

		int target = sum / 3;
		int cut = 0;
		int part = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			part += arr[i];
			if (part == target)
			{
				cut++;
				part = 0;
				if (cut == 2 && i < arr.size() - 1)
					return true;
			}
		}
		return false;
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

int main()
{
	std::vector<std::vector<int>> tests = {
			{0,2,1,-6,6,-7,9,1,2,0,1},
			{0,2,1,-6,6,7,9,-1,2,0,1},
			{3,3,6,5,-2,2,5,1,-9,4},
			{1,1,1},
			{0,0,0},
			{0,0,0,0},
			{1, -1, 1, -1, 1, -1},
		};

	for (auto& arr : tests)
	{
		std::cout << "---\narr: ";
		printVector(arr);
		std::cout << "\ncanThreePartsEqualSum: ";
		std::cout << (Solution().canThreePartsEqualSum(arr) ? "True" : "False");
		std::cout << std::endl;
	}
	return 0;
}
