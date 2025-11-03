#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
	bool isLongPressedName(std::string name, std::string typed)
	{
		if (typed.size() < name.size()) return false;

		unsigned short i = 0, j = 0;
		while (i < name.size() || j < typed.size())
		{
			if (typed[j] == name[i])
			{
				i++;
				j++;
			}
			else if (i > 0 && typed[j] == name[i - 1])
				j++;
			else
				return false;
		}

		return i == name.size() && j == typed.size();
	}
};

typedef struct testCase
{
	std::string name;
	std::string typed;
} testCase;

int main()
{
	std::vector<testCase> tests = {
			{"alex", "aaleex"},
			{"saeed", "ssaaedd"},
			{"alex", "aaleexz"},
			{"alex", "aaleexx"},
		};

	for (auto& tc : tests)
	{
		std::cout << "---\nname= '" << tc.name << "' typed='" << tc.typed << "'\n";
		std::cout << "isLongPressed: " << (Solution().isLongPressedName(tc.name, tc.typed) ? "True" : "False");
		std::cout << std::endl;
	}
	return 0;
}
