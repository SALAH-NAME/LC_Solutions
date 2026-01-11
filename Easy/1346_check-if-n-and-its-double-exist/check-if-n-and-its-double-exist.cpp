#include <iostream>
#include <unordered_set>
#include <vector>

class Solution
{
public:
	bool checkIfExist(std::vector<int>& arr)
	{
		std::unordered_set<int> seen;
		
		for (int num : arr)
		{
			if (seen.count(num * 2) || (num % 2 == 0 && seen.count(num / 2)))
				return true;
			seen.insert(num);
		}
		return false;
	}
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); ++i)
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
		{10,2,5,3},
		{3,1,7,11},
	};

	for (auto& arr : tests)
	{
		std::cout << "---\narr: ";
		printV(arr);
		std::cout << "\ncheckIfExist: " << Solution().checkIfExist(arr);
		std::cout << std::endl;
	}
	return 0;
}
