#include <algorithm>
#include <vector>

class Solution
{
public:
	int findLHS(std::vector<int>& nums)
	{
		std::sort(nums.begin(), nums.end());
		int i = 0, maxLen = 0;

		for (int j = 0; j < nums.size(); ++j)
		{
			while (nums[j] - nums[i] > 1) ++i;
			if (nums[j] - nums[i] == 1)
				maxLen = std::max(maxLen, j - i + 1);
		}
		return maxLen;
	}
};
