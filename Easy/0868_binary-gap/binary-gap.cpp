#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
public:
	int binaryGap(int n)
	{
		int maxGap = 0;
		int prev = -1;
		for (int i = 0; i < 32; ++i)
		{
			if (n & 1)
			{
				if (prev != -1)
					maxGap = std::max(maxGap, i - prev);
				prev = i;
			}
			n >>= 1;
		}
		return maxGap;
	}
};

int main()
{
	std::vector<int> tests = {
		22,
		8,
		5,
	};

	for (int n : tests)
	{
		std::cout << "---\nn= " << n << " => binaryGap: ";
		std::cout << Solution().binaryGap(n) << std::endl;
	}
}
