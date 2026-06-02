#include <vector>
#include <iostream>

class Solution
{
public:
  int timeRequiredToBuy(std::vector<int>& tickets, int k)
  {
    int i = 0;
    int count = 0;

    while (tickets[k] > 0)
    {
      if (tickets[i] > 0)
      {
        tickets[i]--;
        count++;
      }
      if (tickets[k] == 0)
        return count;
      i = (i + 1) % tickets.size();
    }
    return 0;
  }
};

typedef struct testCase
{
  std::vector<int> t;
  int k;
} testCase;

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
  std::vector<testCase> tests = {
    {{2,3,2}, 2},
    {{5,1,1,1}, 0},
  };
  for (auto& [t, k] : tests)
  {
    std::cout << "---\ntickets: ";
    printV(t);
    std::cout << ", k: " << k << "\ntimeRequiredToBuy: ";
    std::cout << Solution().timeRequiredToBuy(t, k) << std::endl;
  }
  return 0;
}
