#include <vector>
#include <iostream>

class Solution
{
public:
	std::vector<int> decrypt(std::vector<int>& code, int k)
	{
		int n = code.size();
		std::vector<int> result(n, 0);

		if (k == 0) return result;

		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			if (k > 0)
			{
				for (int j = 1; j <= k; j++)
					sum += code[(i + j) % n];
			}
			else
			{
				for (int j = 1; j <= -k; j++)
					sum += code[(i - j + n) % n];
			}
			result[i] = sum;
		}
		return result;
	}
};

typedef struct testCase
{
	std::vector<int> c;
	int k;
} testCase;

void printV(const std::vector<int>& v)
{
	std::cout << "{";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i < v.size() - 1)
			std::cout <<  ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<testCase> tests = {
		{{5,7,1,4}, 3},
		{{1,2,3,4}, 0},
		{{2,4,9,3}, -2},
	};

	for (auto& [c, k] : tests)
	{
		std::cout << "---\ncode: ";
		printV(c);
		std::cout << ", k: " << k << "\ndecrypt: ";
		printV(Solution().decrypt(c, k));
		std::cout << std::endl;
	}
	return 0;
}
