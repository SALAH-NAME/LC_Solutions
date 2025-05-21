#include <algorithm>
#include <vector>

class Solution {
public:
	std::vector<int> plusOne(std::vector<int>& digits)
	{
		std::vector<int> res;
		int n = digits.size() - 1;
		int add = 1;

		while (n >= 0)
		{
			int sum = digits[n] + add;
			if (sum < 10)
				res.push_back(sum), add = 0;
			else
				res.push_back(0);
			n--;
		}
		if (add)
				res.push_back(1);

		std::reverse(res.begin(), res.end());
		return res;
	}
};
