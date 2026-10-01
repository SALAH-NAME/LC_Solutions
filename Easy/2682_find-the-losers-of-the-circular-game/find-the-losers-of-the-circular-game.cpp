#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> circularGameLosers(int n, int k)
  {
    std::vector<bool> visited(n + 1, false);
    int current_friend = 1;
    long long turn = 1;

    while (!visited[current_friend])
    {
      visited[current_friend] = true;
      current_friend = (current_friend + turn * k - 1) % n + 1;
      turn++;
    }

    std::vector<int> losers;
    for (int i = 1; i <= n; i++)
    {
      if (!visited[i])
      {
        losers.push_back(i);
      }
    }
    return losers;
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
  int n;
  int k;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {5, 2},
    {4, 4},
  };

  for (auto& [n, k] : tests)
  {
    std::cout << "---\nn: " << n << ", k: " << k << "\ncircularGameLosers: ";
    printV(Solution().circularGameLosers(n, k));
    std::cout << std::endl;
  }
  return 0;
}
