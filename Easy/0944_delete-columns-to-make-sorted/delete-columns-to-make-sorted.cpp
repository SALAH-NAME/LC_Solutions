#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
	int minDeletionSize(std::vector<std::string>& strs)
	{
		int count = 0;

		for (int c = 0; c < strs[0].size(); c++)
		{
			for (int r = 1; r < strs.size(); r++)
			{
				if (strs[r][c] < strs[r-1][c])
				{
					count++;
					break;
				}
			}
		}
		return count;
	}
};

void printVector(const std::vector<std::string>& vec)
{
	std::cout << "{";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "'" << vec[i] << "'";
		if (i < vec.size() - 1)
				std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<std::string>> tests = {
			{"cba","daf","ghi"},
			{"a","b"},
			{"zyx","wvu","tsr"},
		};

	for (auto& strs : tests)
	{
		std::cout << "---\nstrs: ";
		printVector(strs);
		std::cout << "\nminDeletionSize: " << Solution().minDeletionSize(strs);
		std::cout << std::endl;
	}
}
