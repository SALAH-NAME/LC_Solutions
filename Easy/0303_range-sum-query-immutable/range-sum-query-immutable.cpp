#include <vector>

class NumArray
{
private:
	std::vector<int> prefix;

public:
	NumArray(std::vector<int>& nums)
	{
		int n = nums.size();
		prefix.resize(n + 1);
		prefix[0] = 0;
		
		for (int i = 0; i < n; ++i)
			prefix[i + 1] = prefix[i] + nums[i];
	}

	int sumRange(int left, int right)
	{
		if(left == 0) return prefix[right + 1];
		return prefix[right + 1] - prefix[left];
 	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
