#include <algorithm>
#include <climits>
#include <vector>

class Solution
{
public:
	int findLengthOfLCIS(std::vector<int>& nums)
	{
		unsigned short count = 1;
		unsigned short longest = 1;

		for (unsigned short i = 1; i < nums.size(); ++i)
		{
			if (nums[i] > nums[i - 1])
				count++;
			else
				count = 1;
			longest = std::max(longest, count);
		}
		return longest;
	}
};
