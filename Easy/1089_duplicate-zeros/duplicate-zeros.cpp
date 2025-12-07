#include <vector>
#include <iostream>

class Solution
{
public:
	void duplicateZeros(std::vector<int>& arr)
	{
		int n = arr.size();
		int possibleDups = 0;
		int last = n - 1;

		for (int i = 0; i <= last - possibleDups; i++)
		{
			if (arr[i] == 0)
			{
				if (i == last - possibleDups)
				{
					arr[last] = 0;
					last--;
					break;
				}
				possibleDups++;
			}
		}

		int i = last - possibleDups;
		for (; i >= 0; i--)
		{
			if (arr[i] == 0)
			{
				arr[i + possibleDups] = 0;
				possibleDups--;
				arr[i + possibleDups] = 0;
			}
			else
			{
				arr[i + possibleDups] = arr[i];
			}
		}
	}
};

void printVector(const std::vector<int>& v)
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
	std::vector<std::vector<int>> tests = {
		{1,0,2,3,0,4,5,0},
		{1,2,3},
	};

	for (auto& s : tests)
	{
		std::cout << "---\narr: ";
		printVector(s);
		std::cout << "\nduplicateZeros: ";
		Solution().duplicateZeros(s);
		printVector(s);
		std::cout << std::endl;
	}
	return 0;
}
