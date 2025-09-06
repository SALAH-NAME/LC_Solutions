#include <vector>

class Solution
{
public:
	bool canPlaceFlowers(std::vector<int>& flowerbed, int n)
	{
		int size = flowerbed.size();
		int prev = 0;
		for (int i : flowerbed)
		{
			if (i && prev)
				n++;
			else if (!prev && !i)
				n--, prev++;
			else
				prev = i;
		}
		return n <= 0;
	}
};

