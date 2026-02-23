#include <iostream>
#include <vector>

class Solution
{
public:
	std::vector<int> mostVisited(int n, std::vector<int>& rounds)
	{
		std::vector<int> result;
		int start = rounds.front();
		int end = rounds.back();

		if (start <= end)
		{
			for (int i = start; i <= end; i++)
				result.push_back(i);
		}
		else
		{
			for (int i = 1; i <= end; i++)
				result.push_back(i);
			for (int i = start; i <= n; i++)
				result.push_back(i);
		}
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

int main()
{
	std::vector<std::pair<int, std::vector<int>>> tests = {
		{4, {1,3,1,2}},
		{2, {2,1,2,1,2,1,2,1,2}},
		{7, {1,3,5,7}},
	};

	for (auto& t : tests)
	{
		std::cout << "---\nn: " << t.first << ", rounds: ";
		printV(t.second);
		std::cout << "\nmostVisited: ";
		printV(Solution().mostVisited(t.first, const_cast<std::vector<int>&>(t.second)));
		std::cout << std::endl;
	}
	return 0;
}
