#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
	std::vector<int> diStringMatch(std::string s)
	{
		int n = s.size();
		std::vector<int> result(n + 1);

		int low = 0, high = n;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'D')
				result[i] = high--;
			else
				result[i] = low++;
		}
		result[n] = low;
		return result;
	}
};

void printVector(const std::vector<int>& vec)
{
	std::cout << "{";
	for (int i = 0 ; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i < vec.size() - 1)
				std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::string> tests = {
			"IDID",
			"III",
			"DDI",
		};

	for (auto& s : tests)
	{
		std::cout << "---\ns= '" << s << "'\ndiStringMatch: ";
		printVector(Solution().diStringMatch(s));
		std::cout << std::endl;
	}
}
