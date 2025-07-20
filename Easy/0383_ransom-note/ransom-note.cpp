#include <string>

class Solution
{
public:
	bool canConstruct(std::string ransomNote, std::string magazine)
	{
		if (magazine.size() < ransomNote.size()) return false;

		short freq[26] = {0};
		for (char c : magazine)
			freq[c - 'a']++;
		for (char c : ransomNote)
			if (--freq[c - 'a'] < 0) return false;
		return true;
	}
};
