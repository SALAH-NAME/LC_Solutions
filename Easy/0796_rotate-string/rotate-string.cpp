#include <string>

class Solution
{
public:
	bool equalString(std::string& s, std::string& g, int n)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			int j = (i + n) % s.size();
			if (s[i] != g[j])
				return false;
		}
		return true;
	}

	bool rotateString(std::string s, std::string goal)
	{
		if (s.size() != goal.size()) return false;

		for (int i = 0; i < s.size(); ++i)
		{
			if (equalString(s, goal, i))
				return true;
		}
		return false;
	}
};

bool rotateString(std::string s, std::string goal)
{
	return s.size() == goal.size() && (s + s).find(goal) != std::string::npos;
}
