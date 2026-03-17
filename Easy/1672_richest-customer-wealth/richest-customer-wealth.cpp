#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
  int maximumWealth(std::vector<std::vector<int>>& accounts)
  {
    int maxWealth = 0;
    for (auto& customer : accounts)
    {
      int wealth = 0;
      for (int money : customer)
        wealth += money;
      maxWealth = std::max(maxWealth, wealth);
    }
    return maxWealth;
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

void printMat(const std::vector<std::vector<int>>& m)
{
	std::cout << "{";
	for (int i = 0; i < m.size(); ++i)
	{
		printV(m[i]);
		if (i < m.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
  std::vector<std::vector<std::vector<int>>> tests = {
    {{1,2,3},{3,2,1}},
    {{1,5},{7,3},{3,5}},
    {{2,8,7},{7,1,3},{1,9,5}},
  };

  for (auto& a : tests)
  {
    std::cout << "---\naccounts: ";
    printMat(a);
    std::cout << "\nmaximumWealth: ";
    std::cout << Solution().maximumWealth(a) << std::endl;
  }
  return 0;
}
