#include <vector>

class Solution
{
public:
	int pivotIndex(std::vector<int>& nums)
	{
		int left = 0;
		int right = 0;
		std::size_t pivot = 1;

		while (pivot < nums.size())
			right += nums[pivot++];

		pivot = 0;
		while (left != right && pivot < nums.size() - 1)
		{
			left += nums[pivot];
			pivot++;
			right -= nums[pivot];
		}
		return left == right ? pivot : -1;
	}
};
