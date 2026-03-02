#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	int minOperations(std::vector<std::string>& logs)
	{
		int depth = 0;
		for (const auto& log : logs)
		{
			if (log == "../")
			{
				if (depth > 0) depth--;
		 	}
			else if (log == "./")
			{}
			else
				depth++;
		}
		return depth;
	}
};

void printL(const std::vector<std::string>& l)
{
	std::cout << "{";
	for (int i = 0; i < l.size(); i++)
	{
		std::cout << l[i];
		if (i < l.size())
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<std::string>> tests = {
		{"d1/","d2/","../","d21/","./"},
		{"d1/","d2/","./","d3/","../","d31/"},
		{"d1/","../","../","../"},
	};

	for (auto& l : tests)
	{
		std::cout << "---\nlogs: ";
		printL(l);
		std::cout << "\nminOperations: " << Solution().minOperations(l) << std::endl;
	}
	return 0;
}
