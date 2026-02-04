#include <algorithm>
#include <vector>
#include <iostream>

class Solution
{
public:
	bool canBeEqual(std::vector<int>& target, std::vector<int>& arr)
	{
		std::sort(target.begin(), target.end());
		std::sort(arr.begin(), arr.end());
		return target == arr;
	}
};

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

typedef struct testCase {
	std::vector<int> t;
	std::vector<int> a;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{{1,2,3,4}, {2,4,1,3}},
		{{7}, {7}},
		{{3,7,9}, {3,7,11}},
	};

	for (auto& [t, a] : tests)
	{
		std::cout << "---\ntarget: ";
		printV(t);
		std::cout << ", arr: ";
		printV(a);
		std::cout << "\ncanBeEqual: ";
		std::cout << (Solution().canBeEqual(t, a) ? "True" : "False") << std::endl;
	}
	return 0;
}
