#include <iostream>
#include <vector>

class Solution
{
public:
	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
	{
		int i = m - 1, j = n - 1, k = m + n - 1;
		while(i >= 0 && j >= 0)
		{
			if(nums1[i] > nums2[j])
				nums1[k--] = nums1[i--];
			else
				nums1[k--] = nums2[j--];
		}
		while(j >= 0)
			nums1[k--] = nums2[j--];
	}
};

int main()
{
	std::vector<int> nums1({1,2,3,0,0,0});
	std::vector<int> nums2({2,5,6});
	std::vector<int> nums3({2});
	std::vector<int> nums4({});

	Solution sol;
	sol.merge(nums3, 1, nums4, 0);

	for (int i : nums3)
		std::cout << i << " ";

	std::cout << std::endl;
}
