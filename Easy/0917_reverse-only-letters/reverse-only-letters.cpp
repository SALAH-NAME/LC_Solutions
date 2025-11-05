#include <cctype>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Solution
{
public:
	std::string reverseOnlyLetters(std::string s)
	{
		int i = 0, j = s.size() - 1;

		while (i < j)
		{
			while (i < j && !std::isalpha(static_cast<unsigned char>(s[i]))) i++;
			while (i < j && !std::isalpha(static_cast<unsigned char>(s[j]))) j--;
			std::swap(s[i], s[j]);
			i++;
			j--;
		}
		return s;
	}
};

int main()
{
	std::vector<std::string> tests = {
			"ab-cd",
			"a-bC-dEf-ghIj",
			"Test1ng-Leet=code-Q!",
		};

	for (auto& s : tests)
	{
		std::string reversed = Solution().reverseOnlyLetters(s);
		std::cout << "---\ns: '" << s << "'\nreversed: '" << reversed << "'" << std::endl;
	}
}
