#include <cstdlib>
#include <vector>

class Solution
{
public:
	std::vector<int> findDisappearedNumbers(std::vector<int>& nums)
	{
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			int idx = std::abs(nums[i]) - 1;
			if (nums[idx] > 0)
				nums[idx] = -nums[idx];
		}

		std::vector<int> result;
		for (int i = 0; i < n; ++i)
		{
			if (nums[i] > 0)
				result.push_back(i + 1);
		}
		return result;
	}
};
