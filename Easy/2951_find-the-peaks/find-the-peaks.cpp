#include <vector>
#include <iostream>

class Solution
{
public:
  std::vector<int> findPeaks(std::vector<int>& mountain)
  {
    std::vector<int> ans;
    for (int i = 1; i < mountain.size() - 1; i++)
    {
      if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1])
      {
        ans.push_back(i);
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
    if (i < v.size() - 1)
      std::cout << ", ";
  }
  std::cout << "}";
}

typedef struct testCase
{
  std::vector<int> m;
} testCase;

int main()
{
  std::vector<testCase> tests = {
    {{2,4,4}},
    {{1,4,3,8,5}},
  };

  for (auto& [m] : tests)
  {
    std::cout << "---\nmountain: ";
    printV(m);
    std::cout << "\nfindPeaks: ";
    printV(Solution().findPeaks(m));
    std::cout << std::endl;
  }
  return 0;
}
