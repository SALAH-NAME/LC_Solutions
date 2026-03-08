#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	char slowestKey(std::vector<int>& releaseTimes, std::string keysPressed)
	{
		int maxDuration = releaseTimes[0];
		char slowest = keysPressed[0];

		for (int i = 1; i < releaseTimes.size(); ++i)
		{
			int duration = releaseTimes[i] - releaseTimes[i - 1];
			if (duration > maxDuration || (duration == maxDuration && keysPressed[i] > slowest))
			{
				maxDuration = duration;
				slowest = keysPressed[i];
			}
		}
		return slowest;
	}
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout <<  v[i];
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

typedef struct testCase
{
	std::vector<int> r;
	std::string k;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{9,29,49,50}, "cbcd"},
		{{12,23,36,46,62}, "spuda"},
	};

	for(auto& [r, k] : tests)
	{
		std::cout << "---\nreleaseTimes: ";
		printV(r);
		std::cout << ", keysPressed: '" << k << "'\nslowestKey: ";
		std::cout <<  Solution().slowestKey(r, k) << std::endl;
	}
	return 0;
}
