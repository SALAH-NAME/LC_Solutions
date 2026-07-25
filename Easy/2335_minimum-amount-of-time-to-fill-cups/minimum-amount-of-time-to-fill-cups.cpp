#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

class Solution
{
public:
  int fillCups(std::vector<int>& amount)
  {
    std::priority_queue<int> pq;
    for (int count : amount)
    {
      if (count > 0) pq.push(count);
    }

    int seconds = 0;
    while (pq.size() > 1)
    {
      int first = pq.top(); pq.pop();
      int second = pq.top(); pq.pop();
      
      --first;
      --second;
      
      if (first > 0) pq.push(first);
      if (second > 0) pq.push(second);
      
      ++seconds;
    }

    if (!pq.empty())
    {
      seconds += pq.top();
    }

    return seconds;
  }
};

typedef struct testCase
{
  std::vector<int> amount;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{1, 4, 2}},
    {{5, 4, 4}},
    {{5, 0, 0}},
  };

  for (auto& [amount] : tests)
  {
    std::cout << "---\namount: [" << amount[0] << ", " << amount[1] << ", " << amount[2];
    std::cout << "]\nfillCups: " << Solution().fillCups(amount) << std::endl;
  }
  return 0;
}
