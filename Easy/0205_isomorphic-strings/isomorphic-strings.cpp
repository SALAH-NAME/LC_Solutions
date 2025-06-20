#include <string>
#include <unordered_map>

class Solution
{
public:
	bool isIsomorphic(std::string s, std::string t)
	{
		if (s.size() != t.size()) return false;

		std::unordered_map<char, char> prev;
		for (int i = 0; i < s.size(); ++i)
		{
			auto it = prev.find(s[i]);
			if (it != prev.end())
			{
				if (it->second != t[i])
					return false;
			}
			else 
			{
				auto pos = t.find(t[i]);
				if (pos == std::string::npos || pos < i)
					return false;
				prev[s[i]] = t[i];
			}
		}
		return true;
	}
};
