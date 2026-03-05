#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	int maxDepth(std::string s)
	{
		int depth = 0;
		int maxDepth = 0;
		for (char c : s)
		{
			if (c == '(')
			{
				depth++;
				if (depth > maxDepth)
					maxDepth = depth;
			}
			else if (c == ')')
				depth--;
		}
		return maxDepth;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"(1+(2*3)+((8)/4))+1",
		"(1)+((2))+(((3)))",
		"()(())((()()))",
	};

	for (auto& s : tests)
	{
		std::cout << "---\ns= '" << s << "'\nmaxDepth: ";
		std::cout << Solution().maxDepth(s) << std::endl;
	}
	return 0;
}
