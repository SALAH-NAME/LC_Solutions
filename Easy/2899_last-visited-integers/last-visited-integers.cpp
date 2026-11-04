#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> lastVisitedIntegers(std::vector<int>& nums)
  {
    std::vector<int> ans;
    std::vector<int> seen;
    int k = 0;

    for (int x : nums)
    {
      if (x == -1)
      {
        k++;
        if (k <= seen.size())
        {
          ans.push_back(seen[seen.size() - k]);
        }
        else
        {
          ans.push_back(-1);
        }
      }
      else
      {
        k = 0;
        seen.push_back(x);
      }
    }
    return ans;
  }
};

void printV(const std::vector<int>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    std::cout << v[i];
    if ( i < v.size() - 1 )
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  std::vector<int> n;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{1,2,-1,-1,-1}},
    {{1,-1,2,-1,-1}},
  };

  for (auto& [n] : tests)
  {
    std::cout << "---\nnums: ";
    printV(n);
    std::cout << "\nlastVisitedIntegers: ";
    printV(Solution().lastVisitedIntegers(n));
    std::cout << std::endl;
  }
  return 0;
}
