#include <vector>

class Solution
{
public:
	char nextGreatestLetter(std::vector<char>& letters, char target)
	{
		for (char c : letters)
			if (c > target) return c;
		return letters[0];
	}
};
