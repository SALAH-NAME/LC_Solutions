#include <set>
#include <utility>
#include <vector>
#include <iostream>
#include <string>

class Solution
{
public:
	bool isPathCrossing(std::string path)
	{
		int x = 0, y = 0;
		std::set<std::pair<int, int>> visited;
		visited.insert({x, y});
		
		for (char c : path)
		{
			if (c == 'N') y++;
			else if (c == 'S') y--;
			else if (c == 'E') x++;
			else if (c == 'W') x--;
			if (visited.count({x, y})) return true;
			visited.insert({x,y});
		}
		return false;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"NES",
		"NESWW",
	};

	for (auto& s : tests)
	{
		std::cout << "---\npath: '" << s << "'\nisPathCrossing: ";
		std::cout << (Solution().isPathCrossing(s) ? "True" : "False") << std::endl;
	}
	return 0;
}
