#include <vector>
#include <string>

class Solution
{
public:
	std::vector<std::string> fizzBuzz(int n)
	{
		std::vector<std::string> res(n);

		for (short i = 1; i <= n; ++i)
		{
			if (i % 15 == 0)
				res[i - 1] = "FizzBuzz";
			else if (i % 5 == 0)
				res[i - 1] = "Buzz";
			else if (i % 3 == 0)
				res[i - 1] = "Fizz";
			else
				res[i - 1] = std::to_string(i);
		}
		return res;
	}
};
