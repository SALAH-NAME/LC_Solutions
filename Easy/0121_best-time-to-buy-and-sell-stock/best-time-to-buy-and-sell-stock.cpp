#include <vector>
#include <algorithm>

class Solution
{
public:
	int maxProfit(std::vector<int>& prices)
	{
		int pricesSize = prices.size();
		int minPrice = prices[0];
		int maxProfit = 0;

		for (int i = 0; i < pricesSize; ++i)
		{
			if (prices[i] < minPrice)
				minPrice = prices[i];
			else
				maxProfit = std::max(maxProfit, prices[i] - minPrice);
		}
		return maxProfit;
	}
};
