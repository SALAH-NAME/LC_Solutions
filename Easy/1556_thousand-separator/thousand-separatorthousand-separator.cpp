#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	std::string thousandSeparator(int n)
	{
		std::string s = std::to_string(n);
		std::string result;
		int count = 0;

		for (int i = s.size() - 1; i >= 0; i--)
		{
			result.push_back(s[i]);
			count++;
			if (count == 3 && i > 0)
			{
				result.push_back('.');
				count = 0;
			}
		}
		std::reverse(result.begin(), result.end());
		return result;
	}
};

int main()
{
	std::vector<int> tests = {
		987,
		1234,
	};

	for (auto& n : tests)
	{
		std::cout << "---\nn: " << n << "\nthousandSeparator: '";
		std::cout << Solution().thousandSeparator(n) << "'" << std::endl;
	}
	return 0;
}
