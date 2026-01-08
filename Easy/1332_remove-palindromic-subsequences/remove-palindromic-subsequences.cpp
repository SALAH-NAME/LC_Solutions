#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
	int removePalindromeSub(std::string s)
	{
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
			if (s[left] != s[right])
				return 2;
			left++;
			right--;
		}
		return 1;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"ababa",
		"abb",
		"baabb",
	};

	for (auto& s : tests)
	{
		std::cout << "---\ns: '" << s << "'\nremovePalindromeSub: ";
		std::cout << Solution().removePalindromeSub(s) << std::endl;
	}
	return 0;
}
