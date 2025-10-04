#include <vector>

class Solution
{
public:
	int dominantIndex(std::vector<int>& nums)
	{
		int lg = -1;
		int sl = -1;
		int id = -1;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] > lg)
			{
				sl = lg;
				lg = nums[i];
				id = i;
			}
			else if (nums[i] > sl)
				sl = nums[i];
		}
		return (lg >= 2 * sl) ? id : -1;
	}
};
