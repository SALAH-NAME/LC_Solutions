#include <unordered_map>
#include <vector>

class Solution
{
public:
	bool containsNearbyDuplicate(std::vector<int>& nums, int k)
	{
		std::unordered_map<int, int> seen;

		for (int i = 0; i < nums.size(); i++)
		{
			if (seen.find(nums[i])	 != seen.end())
			{
				if (i - seen[nums[i]] <= k)
					return true;
			}
			seen[nums[i]] = i;
		}
		return false;
	}
};
