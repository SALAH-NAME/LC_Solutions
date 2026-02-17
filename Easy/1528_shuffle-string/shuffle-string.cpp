#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
	std::string restoreString(std::string s, std::vector<int>& indices)
	{
		std::string result(s.size(), ' ');

		for (int i = 0; i < s.size(); i++)
			result[indices[i]] = s[i];
		return result;
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
	std::string s;
	std::vector<int> i;
} testCase;

int main()
{
	std::vector<testCase> tests = {
		{"codeleet", {4,5,6,7,0,2,1,3}},
		{"abc", {0,1,2}},
	};

	for (auto& [s, i] : tests)
	{
		std::cout << "---\ns: '" << s << "', indices: ";
		printV(i);
		std::cout << "\nrestoreString: " << Solution().restoreString(s, i);
		std::cout << std::endl;
	}
	return 0;
}
