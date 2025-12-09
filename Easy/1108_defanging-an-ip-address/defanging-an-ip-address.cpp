#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	std::string defangIPaddr(std::string address)
	{
		std::string result;
		for (char c : address)
		{
			if (c == '.')
				result += "[.]";
			else
				result += c;
		}
		return result;
	}
};

int main()
{
	std::vector<std::string> tests = {
		"1.1.1.1",
		"255.100.50.0",
	};

	for (auto& adr : tests)
	{
		std::cout << "---\naddress: " << adr << std::endl;
		std::cout << "defangIPaddr: " << Solution().defangIPaddr(adr) << std::endl;
	}
	return 0;
}
