#include <vector>

class Solution
{
public:
	int removeDuplicates(std::vector<int>& nums)
	{
		std::vector<int> new_nums;

		new_nums.push_back(nums[0]);
		for (auto it : nums)
		{
			if (it != new_nums.back())
				new_nums.push_back(it);
		}
		nums = new_nums;
		return nums.size();
	}
};
