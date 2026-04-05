#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	int countMatches(std::vector<std::vector<std::string>>& items, std::string ruleKey, std::string ruleValue)
	{
		int index = 0;
		if (ruleKey == "color") index = 1;
		else if (ruleKey == "name") index = 2;

		int count = 0;
		for (auto& item : items)
		{
			if (item[index] == ruleValue)
				++count;
		}
		return count;
	}
};

typedef struct testCase
{
	std::vector<std::vector<std::string>> items;
	std::string ruleKey;
	std::string ruleValue;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{
			{{"phone","blue","pixel"},
			{"computer","silver","lenovo"},
			{"phone","gold","iphone"}},
			"color", "silver"
		},
		{
			{{"phone","blue","pixel"},
			{"computer","silver","lenovo"},
			{"phone","gold","iphone"}},
			"type", "phone"
		},
		{
			{{"phone","blue","pixel"},
			{"computer","silver","lenovo"},
			{"phone","gold","iphone"}},
			"name", "pixel"
		}
	};

	for (auto& [items, ruleKey, ruleValue] : tests)
	{
		std::cout << "---\nruleKey: '" << ruleKey << "', ruleValue: '" << ruleValue << "'\n";
		std::cout << "countMatches: " << Solution().countMatches(items, ruleKey, ruleValue) << std::endl;
	}

 	return 0;
}

