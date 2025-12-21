#include <vector>
#include <iostream>

class Solution
{
public:
	int minCostToMoveChips(std::vector<int>& position)
	{
		int evenCount = 0, oddCount = 0;
		for (int p : position)
		{
			if (p % 2 == 0)
				evenCount++;
			else
				oddCount++;
		}
		return std::min(evenCount, oddCount);
	}
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0 ; i < v.size(); ++i)
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
		{1,2,3},
		{2,2,2,3,3},
		{1,1000000000},
	};

	for (auto& pos : tests)
	{
		std::cout << "---\nposition: ";
		printV(pos);
		std::cout << "\nminCostToMoveChips: " << Solution().minCostToMoveChips(pos);
		std::cout << std::endl;
	}
	return 0;
}
