#include <algorithm>
#include <climits>
#include <vector>

class Solution
{
public:
	int arrayPairSum(std::vector<int>& nums)
	{
		std::sort(nums.begin(), nums.end());
		int maxSum = 0;
		for (unsigned short i = 0; i < nums.size() - 1; i += 2)
			maxSum += nums[i];
		return maxSum;
	}
};
