#include <algorithm>
#include <string>


class Solution
{
private:
		const char* _alpha = "0123456789abcdef";
public:
	std::string toHex(int num)
	{
		if (!num) return "0";

		std::string res;
		unsigned int n = static_cast<unsigned int>(num);

		while (n)
		{
			res.push_back(_alpha[n & 0xf]);
			n >>= 4;
		}
		std::reverse(res.begin(), res.end());
		return res;
	}
};
