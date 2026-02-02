#include <vector>
#include <iostream>

class Solution
{
public:
	int busyStudent(std::vector<int>& startTime, std::vector<int>& endTime, int queryTime)
	{
		int count = 0;
		for (int i = 0; i < startTime.size(); ++i)
		{
			if (startTime[i] <= queryTime && queryTime <= endTime[i])
				count++;
		}
		return count;
	}
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

typedef struct testCase
{
	std::vector<int> s;
	std::vector<int> e;
	int q;
}	testCase;

int main()
{
	std::vector<testCase>tests = {
		{{1,2,3}, {3,2,7}, 4},
		{{4}, {4}, 4},
	};

	for (auto& [s, e, q] : tests)
	{
		std::cout << "---\nstartTime: ";
		printV(s);
		std::cout << ", endTime: ";
		printV(e);
		std::cout << ", queryTime: " << q << "\nbusyStudent: ";
		std::cout << Solution().busyStudent(s, e, q) << std::endl;
	}
	return 0;
}
