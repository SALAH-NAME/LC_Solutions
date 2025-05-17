#include <vector>

class Solution {
public:
	int removeElement(std::vector<int>& nums, int val)
	{
		std::vector<int> new_nums;
		for (int i : nums)
		{
			if (i != val)
				new_nums.push_back(i);
		}
		nums = new_nums;
		return new_nums.size();
	}
};
