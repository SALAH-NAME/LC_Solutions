#include <string>
#include <iostream>
#include <vector>

class Solution
{
public:
	std::string sortString(std::string s)
	{
		int freq[26] = {0};
		for (char c : s)
			freq[c - 'a']++;

		std::string result;
		result.reserve(s.size());

		while (result.size() < s.size())
		{
			for (int i = 0; i < 26; i++)
			{
				if (freq[i] > 0)
				{
					result.push_back('a' + i);
					freq[i]--;
				}
			}

			for (int i = 25; i >=0; i--)
			{
				if (freq[i] > 0)
				{
					result.push_back('a' + i);
					freq[i]--;
				}
			}
		}
		return result;
	}
};

int main()
{
	std::vector<std::string>tests = {
		"aaaabbbbcccc",
		"rat",
	};

	for (auto& s : tests)
	{
		std::cout << "---\ns: '" << s << "'\nsortString: ";
		std::cout << Solution().sortString(s) << std::endl;
	}
	return 0;
}
