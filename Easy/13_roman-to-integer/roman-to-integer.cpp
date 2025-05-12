#include <string>
#include <unordered_map>
class Solution {
public:

	int romanToInt(std::string s)
	{
		int result = 0;
		int last = s.size() - 1;
		std::unordered_map<char, int> romanNumbers = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000}
		};

		for (int i = last; i >= 0; i--)
		{
			int num = romanNumbers[s[i]];
			if (i < last && num < romanNumbers[s[i + 1]])
			{
				result -= num;
			}
			else
				result += num;
		}
		return result;
	}
};
