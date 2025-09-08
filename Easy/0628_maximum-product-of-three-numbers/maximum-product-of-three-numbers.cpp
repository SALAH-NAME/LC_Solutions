#include <algorithm>
#include <vector>

class Solution
{
public:
	int maximumProduct(std::vector<int>& nums)
	{
		int n = nums.size();
		std::sort(nums.begin(), nums.end());
		int mul1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
		int mul2 = nums[0] * nums[1] * nums[n - 1];
		return std::max(mul1, mul2);
	}
};
