#include <utility>
#include <vector>

class Solution
{
public:
	void moveZeroes(std::vector<int>& nums)
	{
		int slow = 0;
		int fast = 0;
		int n = nums.size();

		while (fast < n)
		{
			if (nums[fast])
				std::swap(nums[fast], nums[slow++]);
			fast++;
		}
	}
};
