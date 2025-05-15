#include <string>
#include <stack>

class Solution
{
public:
	bool isOpen(const char c)
	{
		return c == '(' || c == '{' || c == '[';
	}
	char isClose(const char c)
	{
		switch (c)
		{
			case ')':
				return '(';
			case '}':
				return '{';
			case ']':
				return '[';
			default:
				return '\0';
		}
	}


	bool isValid(std::string s)
	{
		std::stack<char> chars;
		
		for (size_t i = 0; i < s.size(); ++i)
		{
			if (isOpen(s[i]))
				chars.push(s[i]);
			else if (!chars.empty() && isClose(s[i]) == chars.top())
				chars.pop();
			else 
				return false;
		}
		return chars.empty();
	}
};
