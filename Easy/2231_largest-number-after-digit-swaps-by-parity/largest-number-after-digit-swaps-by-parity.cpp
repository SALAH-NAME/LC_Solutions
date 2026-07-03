#include <queue>
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
  int largestInteger(int num)
  {
    std::string num_str = std::to_string(num);
    std::priority_queue<int> evens;
    std::priority_queue<int> odds;

    for (char c : num_str)
    {
      int digit = c - '0';
      if (digit % 2 == 0)
      {
        evens.push(digit);
      }
      else
      {
        odds.push(digit);
      }
    }

    std::string result = "";
    for (char c : num_str)
    {
      int digit = c - '0';
      if (digit % 2 == 0)
      {
        result += std::to_string(evens.top());
        evens.pop();
      }
      else
      {
        result += std::to_string(odds.top());
        odds.pop();
      }
    }
    return std::stoi(result);
  }
};

typedef struct testCase
{
  int n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {1234},
    {65875},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: " << n << "\nlargestInteger: ";
    std::cout << Solution().largestInteger(n) << std::endl;
  }
  return 0;
}
