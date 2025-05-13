#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

class Solution {
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs)
	{
		if (strs.size() == 1) return strs[0];

		std::sort(strs.begin(), strs.end());

		size_t i = 0;
		std::string prefix = "";
		std::string& first = strs[0];
		std::string& last = strs.back();

		while (i < first.size() && i < last.size() && first[i] == last[i])
			prefix += first[i++];

		return prefix;
	}
};
