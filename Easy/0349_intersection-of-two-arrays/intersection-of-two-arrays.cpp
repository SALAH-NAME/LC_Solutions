#include <unordered_set>
#include <vector>

class Solution
{
public:
	std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		std::unordered_set<int> set1(nums1.begin(), nums1.end());
		std::unordered_set<int> result;

		for (int x : nums2)
			if (set1.erase(x))
				result.insert(x);
			
		return std::vector<int>(result.begin(), result.end());
	}
};
