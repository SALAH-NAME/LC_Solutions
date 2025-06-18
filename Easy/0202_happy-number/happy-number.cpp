#include <climits>
#include <iostream>

class Solution
{
public:
	int next(int x)
	{
		int s = 0;
		while (x > 0)
		{
			int d = x % 10;
			s += d * d;
			x /= 10;
		}
		return s;
	}

	bool isHappy(int n)
	{
		int slow = n;
		int fast = n;
		do
		{
			slow = next(slow);
			fast = next(next(fast));
		} while (slow != fast);
		return slow == 1;
	}
};

int main()
{
	std::cout << "res: " << (Solution().isHappy(1) ? "True" : "False") << std::endl;;
	std::cout << std::endl;
	std::cout << "res: " << (Solution().isHappy(2) ? "True" : "False") << std::endl;;
	std::cout << std::endl;
	std::cout << "res: " << (Solution().isHappy(10) ? "True" : "False") << std::endl;;
	std::cout << std::endl;
	std::cout << "res: " << (Solution().isHappy(42) ? "True" : "False") << std::endl;;
	std::cout << std::endl;
	std::cout << "res: " << (Solution().isHappy(100) ? "True" : "False") << std::endl;;
	std::cout << std::endl;
	std::cout << "res: " << (Solution().isHappy(INT_MAX) ? "True" : "False") << std::endl;;
	std::cout << std::endl;
	return 0;
}
