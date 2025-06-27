#include <vector>
#include <string>

class Solution
{
public:
	std::vector<std::string> summaryRanges(std::vector<int>& nums)
	{
		if (nums.empty())
			return {};
		if (nums.size() == 1)
			return {std::to_string(nums[0])};

		std::vector<std::string> res;
		int size = nums.size();

		for (int i = 0; i < size; ++i)
		{
			int start = nums[i];
			int prev = nums[i];
			while (i + 1< size && static_cast<long long>(nums[i + 1]) - static_cast<long long>(nums[i]) == 1)
				prev = nums[++i];
			if (start == prev)
				res.push_back(std::to_string(start));
			else
				res.push_back(std::to_string(start) + "->" + std::to_string(prev));
		}
		return res;
	}
};
