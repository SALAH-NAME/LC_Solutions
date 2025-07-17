#include <unordered_map>
#include <vector>

class Solution
{
public:
	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		std::unordered_map<int, int> seened(nums1.size());
		std::vector<int> result;

		for (int x : nums1)
			seened[x] += 1;

		for (int x : nums2)
			if (seened[x] > 0)
				result.push_back(x), seened[x] -= 1;

		return result;
	}
};
