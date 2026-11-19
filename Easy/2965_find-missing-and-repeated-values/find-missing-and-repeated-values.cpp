#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid)
  {
    int n = static_cast<int>(grid.size());
    int maxVal = n * n;
    std::vector<int> freq(maxVal + 1, 0);

    for (const auto& row : grid)
    {
      for (int val : row)
      {
        ++freq[val];
      }
    }

    int repeated = -1;
    int missing = -1;
    for (int num = 1; num <= maxVal; ++num)
    {
      if (freq[num] == 2)
      {
        repeated = num;
      }
      else if (freq[num] == 0)
      {
        missing = num;
      }
    }
    return {repeated, missing};
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

void printM(const std::vector<std::vector<int>>& v)
{
  std::cout << "{";
  for (int i = 0; i < v.size(); i++)
  {
    printV(v[i]);
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  std::vector<std::vector<int>> g;
} testCase;

int main()
{
  std::vector<testCase> tests ={
    {{{1,3},{2,2}}},
    {{{9,1,7},{8,9,2},{3,4,6}}},
  };

  for (auto& [g] : tests)
  {
    std::cout << "---\ngrid: ";
    printM(g);
    std::cout << "\nfindMissingAndRepeatedValues: ";
    printV(Solution().findMissingAndRepeatedValues(g));
    std::cout << std::endl;
  }
  return 0;
}
