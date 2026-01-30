#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	std::string destCity(std::vector<std::vector<std::string>>& paths)
	{
		std::unordered_set<std::string> starts;

		for (auto& p : paths)
			starts.insert(p[0]);

		for (auto& p : paths)
			if (starts.find(p[1]) == starts.end())
				return p[1];
		return {};
	}
};

void printP(const std::vector<std::vector<std::string>>& p)
{
	std::cout << "{";
	for (int i = 0; i < p.size(); i++)
	{
		std::cout << "{";
		for (int j = 0; j < p[i].size(); j++)
		{
			std::cout << p[i][j];
			if (j < p[i].size() - 1)
				std::cout << ", ";
		}
		std::cout << "}";
		if (i < p.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<std::vector<std::string>>> tests = {
			{{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}},
			{{"B","C"},{"D","B"},{"C","A"}},
			{{"A","Z"}},
		};

	for (auto& p : tests)
	{
		std::cout << "---\npaths: ";
		printP(p);
		std::cout << "\ndestCity: " << Solution().destCity(p);
		std::cout << std::endl;
	}
	return 0;
}
