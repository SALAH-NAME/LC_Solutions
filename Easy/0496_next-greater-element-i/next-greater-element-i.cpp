#include <unordered_map>
#include <vector>
#include <stack>

class Solution
{
public:
	std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		std::unordered_map<int, int> nextGreater;
		std::stack<int> st;

		for (int num : nums2)
		{
			while (!st.empty() && num > st.top())
			{
				nextGreater[st.top()] = num;
				st.pop();
			}
			st.push(num);
		}

		while (!st.empty())
		{
			nextGreater[st.top()] = -1;
			st.pop();
		}
		
		std::vector<int> result;
		result.reserve(nums1.size());
		for (int num : nums1)
			result.push_back(nextGreater[num]);

		return result;
	}
};
