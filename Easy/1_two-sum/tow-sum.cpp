#include <map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
	std::map<int, int> hash;
	for(auto current = 0; current < nums.size(); ++current)
	{
		auto elm = hash.find(nums[current]);
		if (elm != hash.end() && elm->second != current)
			return std::vector<int>({elm->second, current});
		else
			hash[target - nums[current]] = current;
	}
	return std::vector<int>();
};
