#include <vector>
#include <iostream>

class Solution
{
public:
	std::vector<int> finalPrices(std::vector<int>& prices)
	{
		int n = prices.size();
		std::vector<int> result(prices);

		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (prices[j] <= prices[i])
				{
					result[i] = prices[i] - prices[j];
					break;
				}
			}
		}
		return result;
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
	std::vector<std::vector<int>>tests = {
		{8,4,6,2,3},
		{1,2,3,4,5},
		{10,1,1,6},
	};

	for (auto& p : tests)
	{
		std::cout << "---\nprices: ";
		printV(p);
		std::cout << "\nfinalPrices: ";
		printV(Solution().finalPrices(p));
		std::cout << std::endl;
	}
	return 0;
}
