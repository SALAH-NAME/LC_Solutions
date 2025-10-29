#include <utility>
#include <vector>

class Solution
{
public:
	std::vector<int> sortArrayByParity(std::vector<int>& nums)
	{
		int even = 0;
		int odd = nums.size() - 1;
		
		while (even < odd)
		{
			if (nums[even] % 2 == 0)
				even++;
			else if (nums[odd] % 2 == 1)
				odd--;
			else
			{
				std::swap(nums[even], nums[odd]);
				even++;
				odd--;
			}
		}
		return nums;
	}
};
