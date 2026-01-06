#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
	int maximum69Number (int num)
	{
		std::string s = std::to_string(num);

		for (char &c : s)
		{
			if (c == '6')
			{
				c = '9';
				break;
			}
		}
		return std::stoi(s);
	}
};

int main()
{
	std::vector<int> tests = {
		9669,
		9996,
		9999,
	};

	for (auto& n : tests)
	{
		std::cout << "---\nn: " << n << "\nmaximum69Number: ";
		std::cout << Solution().maximum69Number(n) << std::endl;
	}
	return 0;
}
