#include <algorithm>
#include <string>

class Solution
{
public:
	std::string addStrings(std::string num1, std::string num2)
	{
		int i = static_cast<int>(num1.size() - 1);
		int j = static_cast<int>(num2.size() - 1);
		int carry = 0;
		std::string result;

		while (i >= 0 || j >= 0 || carry)
		{
			int x = (i >= 0 ? num1[i--] - '0' : 0);
			int y = (j >= 0 ? num2[j--] - '0' : 0);
			int sum = x + y + carry;
			result.push_back(static_cast<int>('0' + (sum % 10)));
			carry = sum / 10;
		}

		std::reverse(result.begin(), result.end());
		return result;
 	}
};
