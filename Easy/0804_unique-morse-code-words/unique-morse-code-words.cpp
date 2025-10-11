#include <unordered_set>
#include <vector>
#include <string>

class Solution
{
public:
	int uniqueMorseRepresentations(std::vector<std::string>& words)
	{
		std::vector<std::string> alphabet = {
			".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
			"-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
			"..-","...-",".--","-..-","-.--","--.."
		};

		std::unordered_set<std::string> result;

		for (auto& w : words) {
			std::string str;
			str.reserve(w.size() * 4);
			for (char c : w)
				str += alphabet[c - 'a'];
			result.insert(str);
		}
		return result.size();
	}
};
